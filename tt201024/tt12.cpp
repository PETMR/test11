//// SemaphoreControl.cpp : �������̨Ӧ�ó������ڵ㡣
//// �߳�ͬ��----�ź�������
//
////#include "stdafx.h"
//#include "windows.h"
//#include <iostream>
//
//using namespace std;
//HANDLE g_hSemaphore = nullptr; //����ȫ���ź���
//LONG tt1=100;
////�Զ���
//void WINAPI eatFood(LPVOID lpParams)
//{
//	int i = 0;
//	for (i = 0; i < 20; i++)
//	{
//		WaitForSingleObject(g_hSemaphore, INFINITE);
//		cout << "����" << i + 1 << "����ʳ" << endl;
//		ReleaseSemaphore(g_hSemaphore, 1, &tt1);
//		cout << tt1 << endl;
//		//int Count = readStateSemaphore(&g_hSemaphore);
//		//cout << tt1 << endl;
//	}
//
//}
//
//int main(int argc, CHAR* argv[])
//{
//	//�����ź���
//	//g_hSemaphore = CreateSemaphore(NULL, 1, 1, NULL);
//	//if (!g_hSemaphore)
//	//{
//	//	cout << "�ź�������ʧ��" << endl;
//	//}
//	//DWORD threadId = 0;
//	//HANDLE hThread = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)eatFood, nullptr, 0, &threadId);
//	//HANDLE h1Thread = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)eatFood, nullptr, 0, &threadId);
//	//WaitForSingleObject(hThread, INFINITE);
//	//CloseHandle(hThread);
//
//	UCHAR ttt = 0x04;
//
//	BOOL tt1 = 0b00001111 & 0x00;
//
//	if (tt1) cout << "true" << endl;
//
//	while (tt1);
//
//	system("pause");
//	return 0;
//}
//
//
