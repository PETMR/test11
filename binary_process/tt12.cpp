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
//int elementsize = 3;//�ں˾���ߴ�
//
//void ElementsizechangeOPEN(int, void*) {//������ʵ��
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(elementsize * 2 + 1, elementsize * 2 + 1));//��֤������
//	morphologyEx(src, dst1, MORPH_OPEN, kernel);
//	imshow("OPEN", dst1);
//}
//
//void ElementsizechangeCLOSE(int, void*) {//������ʵ��
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(elementsize * 2 + 1, elementsize * 2 + 1));//��֤������
//	morphologyEx(src, dst2, MORPH_CLOSE, kernel);
//	imshow("CLOSE", dst2);
//}
//
//void ElementsizechangeGRADIENT(int, void*) {//��̬ѧ�ݶ�ʵ��
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(elementsize * 2 + 1, elementsize * 2 + 1));//��֤������
//	morphologyEx(src, dst3, MORPH_GRADIENT, kernel);
//	imshow("GRADIENT", dst3);
//}
//
//void ElementsizechangeTOPHAT(int, void*) {//��ñʵ��
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(elementsize * 2 + 1, elementsize * 2 + 1));//��֤������
//	morphologyEx(src, dst4, MORPH_TOPHAT, kernel);
//	imshow("TOPHAT", dst4);
//}
//
//void ElementsizechangeBLACKHAT(int, void*) {//��ñ��ʵ��
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(elementsize * 2 + 1, elementsize * 2 + 1));//��֤������
//	morphologyEx(src, dst5, MORPH_BLACKHAT, kernel);
//	imshow("BLACKHAT", dst5);
//}
//
//int main() {
//	src = imread("E:\\1.jpg");
//	imshow("ԭͼ", src);
//
//	ElementsizechangeOPEN(0, 0);
//	createTrackbar("�ں˳ߴ磺", "OPEN", &elementsize, 21, ElementsizechangeOPEN);//21�����ߴ���
//
//	ElementsizechangeCLOSE(0, 0);
//	createTrackbar("�ں˳ߴ磺", "CLOSE", &elementsize, 21, ElementsizechangeCLOSE);//21�����ߴ���
//
//	ElementsizechangeGRADIENT(0, 0);
//	createTrackbar("�ں˳ߴ磺", "GRADIENT", &elementsize, 21, ElementsizechangeGRADIENT);//21�����ߴ���
//
//	ElementsizechangeTOPHAT(0, 0);
//	createTrackbar("�ں˳ߴ磺", "TOPHAT", &elementsize, 21, ElementsizechangeTOPHAT);//21�����ߴ���
//
//	ElementsizechangeBLACKHAT(0, 0);
//	createTrackbar("�ں˳ߴ磺", "BLACKHAT", &elementsize, 21, ElementsizechangeBLACKHAT);//21�����ߴ���
//
//	waitKey(0);
//}
