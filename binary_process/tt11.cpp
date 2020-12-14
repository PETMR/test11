//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <math.h>
//#include <opencv2/highgui/highgui_c.h>
//
//using namespace std;
//using namespace cv;
//
//string window_name = "open img";
//Mat src, dst;
//int main() {
//	src = imread("E:\\1.jpg");
//	if (!src.data) {
//		printf("cannot load image ...");
//		system("pause");
//		return -1;
//	}
//	auto ttt = src.type();
//	cout << ttt << endl;
//	namedWindow("src img", CV_WINDOW_AUTOSIZE);
//	imshow("src img", src);
//
//	//Mat src1()
//
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(7, 7)); //设置核
//	    //morphologyEx(src, dst, CV_MOP_OPEN, kernel); //CV_MOP_OPEN表示开操作
//	//    morphologyEx(src, dst, CV_MOP_CLOSE, kernel); //CV_MOP_CLOSE表示闭操作
//	//    morphologyEx(src, dst, CV_MOP_GRADIENT, kernel); //CV_MOP_GRADIENT表示梯度
//	//    morphologyEx(src, dst, CV_MOP_TOPHAT, kernel); //CV_MOP_TOPHAT表示顶帽
//	//morphologyEx(src, dst, CV_MOP_BLACKHAT, kernel); //CV_MOP_BLACKHAT表示黑帽
//		erode(src, dst, kernel);
//	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
//	imshow(window_name, dst);
//
//	Mat image = Mat(400, 600, CV_8UC1);
//
//	waitKey(0);
//	system("pause");
//	return 0;
//}
