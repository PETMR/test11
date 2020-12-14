//#include<iostream>
//#include<vector>
//#include<io.h>
//#include<fstream>
//#include<assert.h>
//#include<string>
//#include <opencv2/highgui/highgui_c.h>
//#include <opencv2/opencv.hpp>
//
//
//
//using namespace std;
//using namespace cv;
//
//Mat src, dst1, dst2, dst3, dst4, dst5;
//int elementsize = 3;//内核矩阵尺寸
//
//void ElementsizechangeOPEN(int, void*) {//开操作实例
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(elementsize * 2 + 1, elementsize * 2 + 1));//保证是奇数
//	morphologyEx(src, dst1, MORPH_OPEN, kernel);
//	imshow("OPEN", dst1);
//}
//
//void ElementsizechangeCLOSE(int, void*) {//闭运算实例
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(elementsize * 2 + 1, elementsize * 2 + 1));//保证是奇数
//	morphologyEx(src, dst2, MORPH_CLOSE, kernel);
//	imshow("CLOSE", dst2);
//}
//
//void ElementsizechangeGRADIENT(int, void*) {//形态学梯度实例
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(elementsize * 2 + 1, elementsize * 2 + 1));//保证是奇数
//	morphologyEx(src, dst3, MORPH_GRADIENT, kernel);
//	imshow("GRADIENT", dst3);
//}
//
//void ElementsizechangeTOPHAT(int, void*) {//顶帽实例
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(elementsize * 2 + 1, elementsize * 2 + 1));//保证是奇数
//	morphologyEx(src, dst4, MORPH_TOPHAT, kernel);
//	imshow("TOPHAT", dst4);
//}
//
//void ElementsizechangeBLACKHAT(int, void*) {//黑帽作实例
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(elementsize * 2 + 1, elementsize * 2 + 1));//保证是奇数
//	morphologyEx(src, dst5, MORPH_BLACKHAT, kernel);
//	imshow("BLACKHAT", dst5);
//}
//
//int main() {
//	src = imread("E:\\1.jpg");
//	imshow("原图", src);
//
//	ElementsizechangeOPEN(0, 0);
//	createTrackbar("内核尺寸：", "OPEN", &elementsize, 21, ElementsizechangeOPEN);//21是最大尺寸了
//
//	ElementsizechangeCLOSE(0, 0);
//	createTrackbar("内核尺寸：", "CLOSE", &elementsize, 21, ElementsizechangeCLOSE);//21是最大尺寸了
//
//	ElementsizechangeGRADIENT(0, 0);
//	createTrackbar("内核尺寸：", "GRADIENT", &elementsize, 21, ElementsizechangeGRADIENT);//21是最大尺寸了
//
//	ElementsizechangeTOPHAT(0, 0);
//	createTrackbar("内核尺寸：", "TOPHAT", &elementsize, 21, ElementsizechangeTOPHAT);//21是最大尺寸了
//
//	ElementsizechangeBLACKHAT(0, 0);
//	createTrackbar("内核尺寸：", "BLACKHAT", &elementsize, 21, ElementsizechangeBLACKHAT);//21是最大尺寸了
//
//	waitKey(0);
//}
