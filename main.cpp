#include<iostream>
using namespace std;
#include<stdlib.h>
#include<vector>
#include"ok.h"
#include<assert.h>
#include<time.h>
#include<ctime>
#include<Windows.h>
typedef long long ll;
#define large 1000000
#define mysmall 10000
//测试冒泡排序(成功)
int test1()
{
	int* a = (int*)malloc(sizeof(int) * large);
	srand((unsigned int)time(0));
	for (ll x = 0; x < large; x++)
	{
		a[x] = rand() % large;
	}
	DWORD starttime = clock();
	BubbleSort(a, large);
	DWORD endtime = clock();
	int k = UPTrue(a,large);
	if (!k)
	{
		cout << "失败========" << endl;
	}
	else
	{
		cout << "成功" << endl;
	}
	cout << "冒泡运行时间:" << (endtime - starttime) << "ms" << endl;
	return 0;
}
//测试插入排序
int test2()
{
	int* a = (int*)malloc(sizeof(int) * large);
	srand((unsigned int)time(0));
	for (int x = 0; x < large; x++)
	{
		a[x] = rand() % large;
	}
	DWORD starttime = GetTickCount64();
	InsertionSort(a,large);
	DWORD endtime = GetTickCount64();
	int k = UPTrue(a, large);
	if (!k)
	{
		cout << "失败========" << endl;
	}
	else
	{
		cout << "成功" << endl;
	}
	cout << "插入运行时间:" << (endtime - starttime) << "ms" << endl;
	return 1;
}
//测试希尔排序
int test3()
{
	int* a = (int*)malloc(sizeof(int) * large);
	srand((unsigned int)time(0));
	for (int x = 0; x < large; x++)
	{
		a[x] = rand() % large;
	}
	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	ShellSort(a, large);
	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	int k = UPTrue(a, large);
	if (!k)
	{
		cout << "失败========" << endl;
	}
	else
	{
		cout << "成功" << endl;
	}
	cout << "希尔运行时间:" << time*1000 << "ms" << endl;
	return 1;
}
//测试快速排序
void test4()
{
	int* a = (int*)malloc(sizeof(int) * large);
	srand((unsigned int)time(0));
	for (int x = 0; x < large; x++)
	{
		a[x] = rand() % large;
	}
	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	QuickSort(a, 0, large-1);
	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	int k = UPTrue(a, large);
	if (!k)
	{
		cout << "失败" << endl;
	}
	else
	{
		cout << "成功" << endl;
	}
	cout << "快排运行时间:" << time*1000 << "ms" << endl;
}
void test5()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	StackQS(a,0,9);
		for (int i = 0; i < 10; i++)
		{
			cout << a[i] << " ";
		}
}
//堆排序
void test6()
{
	int* a = (int*)malloc(sizeof(int) * large);
	srand((unsigned int)time(0));
	for (int x = 0; x < large; x++)
	{
		a[x] = rand() % large;
	}
	DWORD starttime = GetTickCount64();
	HeapSort(a, large);
	DWORD endtime = GetTickCount64();
	int k = UPTrue(a, large);
	if (!k)
	{
		cout << "失败==================" << endl;
	}
	else
	{
		cout << "成功" << endl;
	}
	cout << "运行时间:" << (endtime - starttime) << "ms" << endl;
}
//小根堆实现降序排列
void test7()
{
	int* a = (int*)malloc(sizeof(int) * large);
	srand((unsigned int)time(0));
	for (int x = 0; x < large; x++)
	{
		a[x] = rand() % large;
	}
	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	DWORD starttime = clock();
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	HeapSort(a, large);
	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	int k = UPTrue(a, large);
	if (!k)
	{
		cout << "失败==========================================" << endl;
	}
	else
	{
		cout << "成功" << endl;
	}
	cout << "堆排运行时间:" <<time*1000 << "ms" << endl;
}
//快排，非递归，栈实现
void test8()
{
	int* a = (int*)malloc(sizeof(int) * large);
	srand((unsigned int)time(0));
	for (int x = 0; x < large; x++)
	{
		a[x] = rand() % large;
	}
	int u = UPTrue(a, large);
	if (!u)
	{
		cout <<":还未排序:" << endl;
	}
	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	DWORD starttime = clock();
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	StackQS(a, 0, large - 1);
	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	int k = UPTrue(a, large);
	if (!k)
	{
		cout << "失败==========================================" << endl;
	}
	else
	{
		cout << "成功" << endl;
	}
	cout << "快速排序栈运行时间:" << time * 1000 << "ms" << endl;

}


int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}


int main3()
{
	cout << "===================" << (large)/10000 << "万个数据测试====================" << endl;
	srand((unsigned int)time(0));
	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	test8();
	test7();
	test4();
	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cout << "xxxxxxxxxxxxxxxxxxxxxxxx程序运行总时间" << time * 1000 << "ms" <<"xxxxxxxxxxxxxxxxxxxx" << endl;
	system("pause");
	return 0;
}


int mains()
{
	int a[10] = {10,9,8,7,6,5,4,3,2,1};
	int num=LSMSB(a, 10);
	for (int t = 0; t < 10; t++)
	{
		cout << a[t] << " ";
		if (t == 9)
		{
			cout << endl;
		}
	}
	cout << "逆序数为:" << num;
	return 0;
}


int test9()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	int m=BinarySearch(a, 10, 8);
	cout << m;
	return 0;
}

int main()
{
	int* a = (int*)malloc(sizeof(int) * large);
	srand((unsigned int)time(0));
	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	for (ll x = 0; x < large; x++)
	{
		a[x] = rand() % large;
	}

	QueryPerformanceCounter(&nBeginTime);//开始计时  
	allin(a, 0, large - 1);//===================
	QueryPerformanceCounter(&nEndTime);

	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cout << "归并排序运行时间:" << time * 1000 << "ms" << endl;

	system("pause");
	int k = UPTrue(a, large);
	if (!k)
	{
		cout << "失败==========================================" << endl;
	}
	else
	{
		cout << "成功" << endl;
	}
	return 0;
}

int mainnixushu()
{
	int lenth;
	int key;
	while (1)
	{
		cout << "输入这组数据的长度(有多少个数字就输多少)" << endl;
		cin >> lenth;
		int* arr = new int[lenth];
		cout << "依次输入这组数据的每一个数字，输入一个按一次回车" << endl;
		for (int i = 0; i < lenth; i++)
		{
			cin >> key;
			arr[i] = key;
		}
		cout << "逆序数为" << endl;
		cout<<LSMSB(arr, lenth)<<endl;
	}
	return 0;
}