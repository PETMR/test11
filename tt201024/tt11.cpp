//#include <windows.h>
//#include <stdio.h>
//#include<time.h>
//
//DWORD WINAPI Threadproc(PVOID Context)
//{
//	PHANDLE phEvent = (PHANDLE)Context;
//	Sleep(5000);
//	printf("进入到线程函数里\n");
//	SetEvent(*phEvent); 
//	SetEvent(*phEvent);
//	printf("线程函数结束\n");
//
//	return 0;
//}
//
//int main()
//{
//	HANDLE hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
//	if (NULL == hEvent)
//	{
//		printf("创建事件失败%d\n", GetLastError());
//		return -1;
//	}
//
//	CreateThread(NULL, 0, Threadproc, &hEvent, 0, NULL);
//	//Sleep(8000);
//	printf("开始等待线程\n");
//	
//	auto tt11 = WaitForSingleObject(hEvent, 1000);
//	//SetEvent(hEvent);
//	//ResetEvent(hEvent);
//
//	//WaitForSingleObject(hEvent, 100000000);
//	printf("进程结束\n");
//	return 0;
//}