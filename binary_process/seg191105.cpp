////#include<iostream>
//
//#include<vector>
//#include<io.h>
//#include<fstream>
//#include<assert.h>
//#include<string>
//#include <opencv2/highgui/highgui_c.h>
//#include <opencv2/opencv.hpp>
//
//using namespace std;
//using namespace cv;
//
//int boneSeg(float* inPut, float*outPut, int num, float thres1 = 180, float thres2 = 1000) {
//	for (int i = 0; i != num; i++) {
//		if (inPut[i] < 180) {
//			outPut[i] = 0;
//		}
//		else if (inPut[i] < 1000) {
//			outPut[i] = 1;
//		}
//		else {
//			outPut[2] = 2;
//		}
//	}
//	return 0;
//}
//
//
//
//int main() {
//	std::fstream fr;
//	std::fstream fw;
//	//for (int i = 1;i < 4;i++) {
//	//for (int j = 1;j < 6;j++) {
//		//std::string ii = std::to_string(i);
//		//ii = '0' + ii;
//		//std::string jj = std::to_string(j);
//		//std::string jjj = std::to_string(j - 1);
//
//		fr.open("E:\\test\\PET_MIP.raw", std::ios::binary | std::ios::in);
//		//fr.open("E:\\paste_bone\\mrUmap\\bed" + jj + "\\mumap_bed_" + jjj + ".map", std::ios::binary | std::ios::in);
//
//		Mat image = Mat(488, 150, CV_8UC1);
//		Mat image2 = Mat(488, 150, CV_8UC1);
//		unsigned char * data00 = image.ptr<unsigned char>(0);
//
//		unsigned char* pRead = new unsigned char[150 * 488 * 1 * 1]();
//		unsigned char* pwrite = new unsigned char[150 * 488 * 1 * 1]();
//		fr.read((char*)&pRead[0], 150 * 488 * 1 * 1);
//		fr.close();
//		float* pfloatR, *pfloatW;
//		pfloatR = (float*)pRead;
//		pfloatW = (float*)pwrite;
//		
//		//for (int i = 0; i < image.rows; i++)
//		//{
//		//	unsigned char* pxvec = image.ptr<unsigned char>(i);
//		//	//三通道数据都在第一行依次排列，按照BGR顺序
//		//	//依次赋值为1
//		//	for (int j = 0; j < image.cols; j++)
//		//	{
//		//		pxvec[j] = pRead[i*image.cols +j];
//		//		//cout << pxvec[j] << endl;
//		//	}
//		//}
//
//		//for (int i = 0; i != 150 * 488 * 1; i++) {
//		//	if ((pRead[i])<50 ) {
//		//		pRead[i] = pRead[i] + 50;
//		//	}
//		//}
//		memcpy(data00, pRead, 150 * 488 * 1 * 1);
//		Mat kernel = getStructuringElement(MORPH_RECT, Size(7, 7));
//		morphologyEx(image, image, CV_MOP_OPEN, kernel);
//		//namedWindow("CLOSE", CV_WINDOW_AUTOSIZE);
//		imshow("CLOSE", image);
//		fw.open("E:\\test\\PET_MIP2.raw", std::ios::binary | std::ios::out);
//		fw.write((char*)&image.ptr<unsigned char>(0)[0], 150 * 488 * 1 * 1);
//		fw.close();
//
//
//
//	//}
//	//}
//
//	waitKey(10000);
//	system("pause");
//}
//
//
