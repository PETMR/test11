//////  Author:  www.icvpr.com    
////  Blog  :  http://blog.csdn.net/icvpr   
//#include <iostream>  
//#include<fstream>
//#include<stack>
//#include<vector>
//
//
//using namespace std;
//
//struct Components {
//	vector<int> pixels;
//	int minX = 9999;
//	int minY = 9999;
//	int minZ = 9999;
//	int maxX = 0;
//	int maxY = 0;
//	int maxZ = 0;
//};
//void getFiles(string, vector<string>&, vector<string>&);
//int main(int argc, char** argv)
//{
//	//cv::Mat binImage = cv::imread("E:\\zhangshuangyue\\new_reg\\549_T0001_wfi3d_100.raw", 0);
//	std::fstream fr, fw;
//
//	vector<string> files;
//	vector<string> fileNames;
//	char * filePath = "E:\\zhangshuangyue\\new_reg2";
//	////获取该路径下的所有文件  
//	getFiles(filePath, files, fileNames);
//	int size = files.size();
//
//	vector<string> filesUse;
//	vector<string> filesNameUse;
//	string::size_type position;
//	string::size_type position2;
//
//	for (int i = 0;i < size;i++)
//	{
//		position = files[i].find(".raw");
//		if (position != files[i].npos) {
//			filesUse.push_back(files[i]);
//		}
//		position = fileNames[i].find(".raw");
//		if (position != fileNames[i].npos) {
//			filesNameUse.push_back(fileNames[i]);
//		}
//	}
//
//	fr.open(filesUse[i], std::ios::binary | std::ios::in);
//
//	const int width = 549;
//	const int height = 384;
//	const int depth = 1188;
//
//	float* pRead = new float[width * height * depth]();
//	fr.read((char*)pRead, width * height * depth * 4);
//	fr.close();
//	float* label = new float[width * height * depth]();
//	for (int i = 0;i < width * height * depth;i++) {
//		if (pRead[i] > 100) {
//			label[i] = 1;
//		}
//	}
//
//	vector<Components> connectedComponents;
//	int currentLabel = 1;
//	std::stack<int> neighborPixelsX;
//	std::stack<int> neighborPixelsY;
//	std::stack<int> neighborPixelsZ;
//	for (int i = 0; i < depth; i++) {
//		for (int j = 0; j < height; j++) {
//			for (int k = 0; k < width; k++) {
//
//				if (label[i*width*height + j*width + k] != 1) continue;
//				currentLabel++;
//				neighborPixelsX.push(k);
//				neighborPixelsY.push(j);
//				neighborPixelsZ.push(i);
//				label[i*width*height + j*width + k] = currentLabel;
//				Components currentComponent;
//				currentComponent.pixels.push_back(i*width*height + j*width + k);
//				if (currentComponent.minX > k) currentComponent.minX = k;
//				if (currentComponent.minY > j) currentComponent.minY = j;
//				if (currentComponent.minZ > i) currentComponent.minZ = i;
//				if (currentComponent.maxX < k) currentComponent.maxX = k;
//				if (currentComponent.maxY < j) currentComponent.maxY = j;
//				if (currentComponent.maxZ < i) currentComponent.maxZ = i;
//
//				while (!neighborPixelsX.empty()) {
//					int curPixelX = neighborPixelsX.top();
//					int curPixelY = neighborPixelsY.top();
//					int curPixelZ = neighborPixelsZ.top();
//					neighborPixelsX.pop();
//					neighborPixelsY.pop();
//					neighborPixelsZ.pop();
//					for (int z = -1;z < 2;z++) {
//						for (int y = -1;y < 2;y++) {
//							for (int x = -1;x < 2;x++) {
//								if (x == 0 && y == 0 && z == 0) continue;
//								int curPixelNeighborX = curPixelX + x;
//								int curPixelNeighborY = curPixelY + y;
//								int curPixelNeighborZ = curPixelZ + z;
//
//								if (curPixelNeighborX < 0 || curPixelNeighborX >= width) continue;
//								if (curPixelNeighborY < 0 || curPixelNeighborY >= height) continue;
//								if (curPixelNeighborZ < 0 || curPixelNeighborZ >= depth) continue;
//
//								if (label[curPixelNeighborX + curPixelNeighborY*width + curPixelNeighborZ*width*height] == 1) {
//									neighborPixelsX.push(curPixelNeighborX);
//									neighborPixelsY.push(curPixelNeighborY);
//									neighborPixelsZ.push(curPixelNeighborZ);
//									label[curPixelNeighborX + curPixelNeighborY*width + curPixelNeighborZ*width*height] = currentLabel;
//								}
//								currentComponent.pixels.push_back(curPixelNeighborX + curPixelNeighborY*width + curPixelNeighborZ*width*height);
//								if (currentComponent.minX > curPixelNeighborX) currentComponent.minX = curPixelNeighborX;
//								if (currentComponent.minY > curPixelNeighborY) currentComponent.minY = curPixelNeighborY;
//								if (currentComponent.minZ > curPixelNeighborZ) currentComponent.minZ = curPixelNeighborZ;
//								if (currentComponent.maxX < curPixelNeighborX) currentComponent.maxX = curPixelNeighborX;
//								if (currentComponent.maxY < curPixelNeighborY) currentComponent.maxY = curPixelNeighborY;
//								if (currentComponent.maxZ < curPixelNeighborZ) currentComponent.maxZ = curPixelNeighborZ;
//							}
//						}
//					}
//				}
//				if (currentComponent.pixels.size() > 100) {
//					if ((currentComponent.maxZ - currentComponent.minZ) < 16) {
//						for (int p = 0;p < currentComponent.pixels.size();p++) {
//							label[currentComponent.pixels[p]] = 0;
//						}
//						continue;
//					}
//					connectedComponents.push_back(currentComponent);
//				}
//
//
//			}
//		}
//	}
//
//
//	//for (int i = 0; i < width * height * depth;i++) {
//	//	if (label[i] == 0) continue;
//	//	cout << label[i] << endl;
//	//}
//	//fw.open("E:\\zhangshuangyue\\new_reg\\test.raw", std::ios::binary | std::ios::out);
//	//fw.write((char*)label, width * height * depth * 4);
//	//fw.close();
//
//	return 0;
//}