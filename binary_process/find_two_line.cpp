//  Author:  www.icvpr.com    
//  Blog  :  http://blog.csdn.net/icvpr   
#include <iostream>  
#include<fstream>
#include<stack>
#include<vector>
#include<algorithm>
#include<functional>
#include<io.h>
using namespace std;
struct Components {
	vector<int> pixelX;
	vector<int> pixelY;
};
struct point {
	float pointX;
	float pointY;
};
int findConnected(float* image, int* label, vector<Components> &connectedComponents, int width, int height, float doseBase);

int main(int argc, char** argv)
{

	std::fstream fr, fw;

	fr.open("E:\\yanggang\\PET.raw", std::ios::binary | std::ios::in);
	

	fr.seekg(0, ios::end); //设置文件指针到文件流的尾部
	streampos ps = fr.tellg(); //读取文件指针的位置
	cout << "File size: " << ps << endl;
	fr.seekg(0, ios::beg);

	const int width = 256;
	const int height = 256;
	const int depth = ps/width/height/4;

	float* pRead = new float[width * height * depth]();
	fr.read((char*)pRead, width * height * depth * 4);
	fr.close();
	float* image = new float[width * height]();
	memcpy(image, pRead + width*height*depth / 2, width * height * 4);

	sort(image, image + width*height, greater<float>());

	float doseBase = 0;
	for (int i = 0;i < 20;i++) {
		doseBase += image[i];

	}
	doseBase /= 20; //for mean
	doseBase /= 40; //for threshold

	int* label = new int[width * height]();
	vector<point> point1;
	vector<point> point2;

	for (int i = 70;i < depth - 70;i = i + 2) {
		vector<Components> connectedComponents;
		findConnected(pRead + width*height*i, label, connectedComponents, width, height, doseBase);
		if (connectedComponents.size() != 2) continue;
		float pointX1 = 0, pointY1 = 0;
		for (int j = 0;j < connectedComponents[0].pixelX.size();j++) {
			pointX1 += connectedComponents[0].pixelX[j];
			pointY1 += connectedComponents[0].pixelY[j];
		}
		pointX1 /= connectedComponents[0].pixelX.size();
		pointY1 /= connectedComponents[0].pixelX.size();
		point pointTemp1;
		pointTemp1.pointX = pointX1;
		pointTemp1.pointY = pointY1;

		float pointX2 = 0, pointY2 = 0;
		for (int j = 0;j < connectedComponents[1].pixelX.size();j++) {
			pointX2 += connectedComponents[1].pixelX[j];
			pointY2 += connectedComponents[1].pixelY[j];
		}
		pointX2 /= connectedComponents[1].pixelX.size();
		pointY2 /= connectedComponents[1].pixelX.size();
		point pointTemp2;
		pointTemp2.pointX = pointX2;
		pointTemp2.pointY = pointY2;


		if (point1.size() == 0) {
			point1.push_back(pointTemp1);
			point2.push_back(pointTemp2);
		}
		else {
			float dist11 = (pointTemp1.pointX - point1[point1.size() - 1].pointX)*(pointTemp1.pointX - point1[point1.size() - 1].pointX) +
				(pointTemp1.pointY - point1[point1.size() - 1].pointY)*(pointTemp1.pointY - point1[point1.size() - 1].pointY);
			float dist12 = (pointTemp1.pointX - point2[point1.size() - 1].pointX)*(pointTemp1.pointX - point2[point1.size() - 1].pointX) +
				(pointTemp1.pointY - point2[point1.size() - 1].pointY)*(pointTemp1.pointY - point2[point1.size() - 1].pointY);
			if (dist11 < dist12) {
				point1.push_back(pointTemp1);
				point2.push_back(pointTemp2);
			}
			else {
				point2.push_back(pointTemp1);
				point1.push_back(pointTemp2);
			}
		}
		
	}
	


	//for (int i = 0; i < width * height * depth;i++) {
	//	if (label[i] == 0) continue;
	//	cout << label[i] << endl;
	//}
	fw.open("E:\\zhangshuangyue\\new_reg\\test.raw", std::ios::binary | std::ios::out);
	fw.write((char*)label + width*height*depth / 2, width * height * depth * 4);
	fw.close();

	return 0;
}

int findConnected(float* image, int* label, vector<Components> &connectedComponents, int width, int height, float doseBase) {
	
	int ttt = 0;
	for (int i = 0;i < width * height;i++) {
		if (image[i] > doseBase) {
			label[i] = 1;
			//cout << image[i] << endl;
			//ttt += 1;
		}
		else {
			label[i] = 0;
		}
	}

	int currentLabel = 1;
	std::stack<int> neighborPixelsX;
	std::stack<int> neighborPixelsY;
	for (int j = 0; j < height; j++) {
		for (int k = 0; k < width; k++) {

			if (label[j*width + k] != 1) continue;
			currentLabel++;
			neighborPixelsX.push(k);
			neighborPixelsY.push(j);
			label[j*width + k] = currentLabel;
			Components currentComponent;
			currentComponent.pixelX.push_back(k);
			currentComponent.pixelY.push_back(j);

			while (!neighborPixelsX.empty()) {
				int curPixelX = neighborPixelsX.top();
				int curPixelY = neighborPixelsY.top();
				neighborPixelsX.pop();
				neighborPixelsY.pop();
					for (int y = -1;y < 2;y++) {
						for (int x = -1;x < 2;x++) {
							if (x == 0 && y == 0) continue;
							int curPixelNeighborX = curPixelX + x;
							int curPixelNeighborY = curPixelY + y;

							if (curPixelNeighborX < 0 || curPixelNeighborX >= width) continue;
							if (curPixelNeighborY < 0 || curPixelNeighborY >= height) continue;

							if (label[curPixelNeighborX + curPixelNeighborY*width] == 1) {
								neighborPixelsX.push(curPixelNeighborX);
								neighborPixelsY.push(curPixelNeighborY);
								label[curPixelNeighborX + curPixelNeighborY*width] = currentLabel;
							}
							currentComponent.pixelX.push_back(curPixelNeighborX);
							currentComponent.pixelY.push_back(curPixelNeighborY);
						}
					}
			}
			if (currentComponent.pixelX.size() > 5) {
				connectedComponents.push_back(currentComponent);
			}
		}
	}
	return 0;
}













//int* label = new int[width * height * depth]();
//for (int i = 0;i < width * height * depth;i++) {
//	if (pRead[i] > doseBase) {
//		label[i] = 1;
//	}
//}

//vector<vector<int>> connectedComponents;
//int currentLabel = 1;
//std::stack<int> neighborPixelsX;
//std::stack<int> neighborPixelsY;
//std::stack<int> neighborPixelsZ;
//for (int i = 0; i < depth; i++) {
//	for (int j = 0; j < height; j++) {
//		for (int k = 0; k < width; k++) {
//
//			if (label[i*width*height + j*width + k] != 1) continue;
//			currentLabel++;
//			neighborPixelsX.push(k);
//			neighborPixelsY.push(j);
//			neighborPixelsZ.push(i);
//			label[i*width*height + j*width + k] = currentLabel;
//			vector<int> currentComponent;
//			currentComponent.push_back(i*width*height + j*width + k);
//
//			while (!neighborPixelsX.empty()) {
//				int curPixelX = neighborPixelsX.top();
//				int curPixelY = neighborPixelsY.top();
//				int curPixelZ = neighborPixelsZ.top();
//				neighborPixelsX.pop();
//				neighborPixelsY.pop();
//				neighborPixelsZ.pop();
//				for (int z = -1;z < 2;z++) {
//					for (int y = -1;y < 2;y++) {
//						for (int x = -1;x < 2;x++) {
//							if (x == 0 && y == 0 && z == 0) continue;
//							int curPixelNeighborX = curPixelX + x;
//							int curPixelNeighborY = curPixelY + y;
//							int curPixelNeighborZ = curPixelZ + z;
//
//							if (curPixelNeighborX < 0 || curPixelNeighborX >= width) continue;
//							if (curPixelNeighborY < 0 || curPixelNeighborY >= height) continue;
//							if (curPixelNeighborZ < 0 || curPixelNeighborZ >= depth) continue;
//
//							if (label[curPixelNeighborX + curPixelNeighborY*width + curPixelNeighborZ*width*height] == 1) {
//								neighborPixelsX.push(curPixelNeighborX);
//								neighborPixelsY.push(curPixelNeighborY);
//								neighborPixelsZ.push(curPixelNeighborZ);
//								label[curPixelNeighborX + curPixelNeighborY*width + curPixelNeighborZ*width*height] = currentLabel;
//							}
//							currentComponent.push_back(curPixelNeighborX + curPixelNeighborY*width + curPixelNeighborZ*width*height);
//						}
//					}
//				}
//			}
//			if (currentComponent.size() > 5) {
//				connectedComponents.push_back(currentComponent);
//			}
//		}
//	}
//}



