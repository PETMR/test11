//#include <windows.h>
//#include <stdio.h>
//#include<time.h>
//
//DWORD WINAPI Threadproc(PVOID Context)
//{
//	PHANDLE phEvent = (PHANDLE)Context;
//	Sleep(5000);
//	printf("���뵽�̺߳�����\n");
//	SetEvent(*phEvent); 
//	SetEvent(*phEvent);
//	printf("�̺߳�������\n");
//
//	return 0;
//}
//
//int main()
//{
//	HANDLE hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
//	if (NULL == hEvent)
//	{
//		printf("�����¼�ʧ��%d\n", GetLastError());
//		return -1;
//	}
//
//	CreateThread(NULL, 0, Threadproc, &hEvent, 0, NULL);
//	//Sleep(8000);
//	printf("��ʼ�ȴ��߳�\n");
//	
//	auto tt11 = WaitForSingleObject(hEvent, 1000);
//	//SetEvent(hEvent);
//	//ResetEvent(hEvent);
//
//	//WaitForSingleObject(hEvent, 100000000);
//	printf("���̽���\n");
//	return 0;
//}