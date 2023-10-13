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
//����ð������(�ɹ�)
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
		cout << "ʧ��========" << endl;
	}
	else
	{
		cout << "�ɹ�" << endl;
	}
	cout << "ð������ʱ��:" << (endtime - starttime) << "ms" << endl;
	return 0;
}
//���Բ�������
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
		cout << "ʧ��========" << endl;
	}
	else
	{
		cout << "�ɹ�" << endl;
	}
	cout << "��������ʱ��:" << (endtime - starttime) << "ms" << endl;
	return 1;
}
//����ϣ������
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
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	ShellSort(a, large);
	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	int k = UPTrue(a, large);
	if (!k)
	{
		cout << "ʧ��========" << endl;
	}
	else
	{
		cout << "�ɹ�" << endl;
	}
	cout << "ϣ������ʱ��:" << time*1000 << "ms" << endl;
	return 1;
}
//���Կ�������
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
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	QuickSort(a, 0, large-1);
	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	int k = UPTrue(a, large);
	if (!k)
	{
		cout << "ʧ��" << endl;
	}
	else
	{
		cout << "�ɹ�" << endl;
	}
	cout << "��������ʱ��:" << time*1000 << "ms" << endl;
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
//������
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
		cout << "ʧ��==================" << endl;
	}
	else
	{
		cout << "�ɹ�" << endl;
	}
	cout << "����ʱ��:" << (endtime - starttime) << "ms" << endl;
}
//С����ʵ�ֽ�������
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
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	HeapSort(a, large);
	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	int k = UPTrue(a, large);
	if (!k)
	{
		cout << "ʧ��==========================================" << endl;
	}
	else
	{
		cout << "�ɹ�" << endl;
	}
	cout << "��������ʱ��:" <<time*1000 << "ms" << endl;
}
//���ţ��ǵݹ飬ջʵ��
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
		cout <<":��δ����:" << endl;
	}
	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	DWORD starttime = clock();
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	StackQS(a, 0, large - 1);
	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	int k = UPTrue(a, large);
	if (!k)
	{
		cout << "ʧ��==========================================" << endl;
	}
	else
	{
		cout << "�ɹ�" << endl;
	}
	cout << "��������ջ����ʱ��:" << time * 1000 << "ms" << endl;

}


int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}


int main3()
{
	cout << "===================" << (large)/10000 << "������ݲ���====================" << endl;
	srand((unsigned int)time(0));
	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	test8();
	test7();
	test4();
	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cout << "xxxxxxxxxxxxxxxxxxxxxxxx����������ʱ��" << time * 1000 << "ms" <<"xxxxxxxxxxxxxxxxxxxx" << endl;
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
	cout << "������Ϊ:" << num;
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
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	for (ll x = 0; x < large; x++)
	{
		a[x] = rand() % large;
	}

	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	allin(a, 0, large - 1);//===================
	QueryPerformanceCounter(&nEndTime);

	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cout << "�鲢��������ʱ��:" << time * 1000 << "ms" << endl;

	system("pause");
	int k = UPTrue(a, large);
	if (!k)
	{
		cout << "ʧ��==========================================" << endl;
	}
	else
	{
		cout << "�ɹ�" << endl;
	}
	return 0;
}

int mainnixushu()
{
	int lenth;
	int key;
	while (1)
	{
		cout << "�����������ݵĳ���(�ж��ٸ����־������)" << endl;
		cin >> lenth;
		int* arr = new int[lenth];
		cout << "���������������ݵ�ÿһ�����֣�����һ����һ�λس�" << endl;
		for (int i = 0; i < lenth; i++)
		{
			cin >> key;
			arr[i] = key;
		}
		cout << "������Ϊ" << endl;
		cout<<LSMSB(arr, lenth)<<endl;
	}
	return 0;
}