#pragma once
#include<iostream>
#include<vector>
#include<stack>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include<ctime>
using namespace std;
//��ӡ
void myprintf(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
//�ж�һ��ʼ�����Ƿ�Ϊ����
bool UPTrue(int* arr, int len)
{
	int i = 0;
	while (i < len-1)
	{
		if (arr[i] > arr[i + 1])
		{
			return false;
		}
		else
		{
			i++;
		}
	}
	return true;
}
//�ж�һ�������Ƿ�Ϊ����
bool DownTrue(int* arr, int len)
{
	int i = 0;
	while (i < len - 1)
	{
		if (arr[i] < arr[i + 1])
		{
			return false;
		}
		else
		{
			i++;
		}
	}
	return true;
}
//��ӡ����
void print(int * arr,int len)
{
	for (int m = 0; m < len; m++)
	{
		cout << arr[m] << " ";
	}
}
//ð������(����һ������) ������������鳤��(�������ݲ���ʧ��
void BubbleSort(int* arr,int len)
{
	int end = len;//������Ԫ��λ�ã���������
	for (int i = 0; i < len-1;i++)//ÿ��ð��һ��Ԫ�أ���Ҫð�ݾŸ���������ѭ����len-1;
	{
		for (int t = 0; t < end-1; t++)//ÿ����Ҫ�Ƚϵĸ����Ǳ�Ǵ�-1
		{
			if (arr[t] > arr[t + 1])
			{
				int temp = arr[t];
				arr[t] = arr[t + 1];
				arr[t + 1] = temp;
			}
		}
		end--;
	}
}
//ֱ�Ӳ�������(���)
void InsertionSort(int* arr, int len)
{
	for (int i = 1; i < len; i+=1)
	{
		int temp = arr[i];
		int j = i - 1;
		while(true)//ע�⣬��arr[j]С��tempʱ��������������Ӧ��д���ں��Ǽ�������
		{
			if (arr[j] >= temp && j >= 0)
			{
				break;
			}
			else
			{
				arr[j + 1] = arr[j];
				j -= 1;
			}
		}
		arr[j + 1] = temp;
	}
}
//ϣ������(gap�ǲ���)
void ShellSort(int* arr, int len)
{
	int gap;
	for (gap = len / 2; gap >= 1; gap /= 2)
	{
		for (int i = gap; i < len; i++)
		{   
			int temp = arr[i];
			int j = i - gap;//��j���arr[i]��ǰgap��
			while (j >= 0 && arr[j] > temp)//��ǰgap������arr[i],��ô��jλ�����ݺ���һλ���ٽ�j�Լ�һ��gap,�����Ƚ�,������¼�����ȥ
			{
				arr[j+gap] = arr[j];//��jλ�������ƶ���j+gap,�൱������Ų��
				j -= gap;
			}
			arr[j + gap] = temp;//������whileѭ��������jָ����һ����tempС��������ôӦ����j+gapλ�ò���gap
		}

	}
}
//��������
//����ȡ���Ż���������
void ChoseMid(int*arr,int start,int end)
{
	int mid = (start + end) * 0.618;
	if (arr[start] < arr[end]&&arr[mid]<arr[end])
	{
		if (arr[start] > arr[mid])
		{
			return;
		}
		else
		{
			swap(arr[start], arr[mid]);
		}
	}
	if (arr[end] < arr[start] && arr[mid] < arr[start])
	{
		if (arr[end] > arr[mid])
		{
			swap(arr[end], arr[start]);
		}
		else
		{
			swap(arr[mid], arr[start]);
		}
	}
	if (arr[start] < arr[mid] && arr[end] < arr[mid])
	{
		if (arr[start] > arr[end])
		{
			return;
		}
		else
		{
			swap(arr[start], arr[end]);
		}
	}
}
int div(int* arr, int L, int R)//RӦ�ô���len-1;
{
	int base = arr[L];
	while (L < R)
	{
		while (arr[R] >= base && R > L)
		{
			R--;
		}
		arr[L] = arr[R];
		while (arr[L] <= base && R > L)
		{
			L++;
		}
		arr[R] = arr[L];
	}
	arr[L] = base;
	return L;

}
void QuickSort(int *arr,int start,int end)
{
	if (start>end)
	{
		return;//����Ӧ��ֱ��return������Ӧ�ô���������Ϊ���ǽ����ݹ������
	}
	int base = div(arr, start, end);
	QuickSort(arr, start, base - 1);
	QuickSort(arr, base + 1, end);
}
//ʹ��ջʵ�ֵݹ飬�Կ���Ϊ��
//��ʵ��ջ
void StackQS(int* arr, int start, int end)
{
	//����һ��ջ
	int* Stack = (int*)malloc((end / 2) * sizeof(int));
	//����ȡ������ȡ������λ���м������
	int tempstart = start;
	int tempend = end;
	//ָ��ջ�Ķ���,��ʾջ�ĳ���
	int base =-1;//ָ�����λ���±�
	ChoseMid(arr, tempstart, tempend);
	int key = div(arr, start, end);//��һ�ηָ�
	if (key + 1 < tempend)
	{
		base++;
		Stack[base] = key + 1;
		base++;
		Stack[base] = tempend;
	}
	if (key - 1 > tempstart)
	{
		base++;
		Stack[base] = tempstart;
		base++;
		Stack[base] = key-1;
	}
	while (base > -1)
	{
		tempend = Stack[base];
		base--;
		tempstart = Stack[base];
		base--; 
		int key = div(arr, tempstart, tempend);
		if (key + 1 < tempend)
		{
			base++;
			Stack[base] = key + 1;
			base++;
			Stack[base] = tempend;
		}
		if (key - 1 > tempstart)
		{
			base++;
			Stack[base] = tempstart;
			base++;
			Stack[base] = key - 1;
		}
	}
	free(Stack);
}
//������
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void HeapAdjust(int*arr, int parent,int len)
{		
	//startΪ����Ҷ�ڵ�
	int temp = arr[parent];//����ýڵ��ֵ
	for (int child=parent*2+1; child <len; child=child*2+1)//�ҵ�����Ҷ�ڵ�ĺ��ӣ�����̽�齻�����Ƿ��ƻ������ӽڵ�Ĵ���ѽṹ
	{
		if (arr[child] < arr[child + 1] && child+1 < len)//�ж��Ƿ����Һ���,���ұ�֤childΪ���Һ�������ߵ��±�,child�ж�ʱһֱ�����������Կ�ʼֻ������ڵ�
		{
			child++;
		}
		if (arr[child] > temp)//�ȽϺ����������ýڵ��ֵ
		{
			arr[parent] = arr[child];//����ֵ���Ͻ���
			parent = child;//���½ڵ㣬����ά������ѽṹ
		}
		else
		{
			break;
		}
	}
	arr[parent] = temp;
	
}
void HeapSort(int* arr,int len)
{
	
	int key = UPTrue(arr, len);//�ж������Ƿ�Ϊ���򣬷�key����false,���������
	if (!key)
	{
		for (int i = (len / 2) - 1; i >= 0; i--)
			HeapAdjust(arr, i, len);
		//֮���ٴӽ�����βԪ�أ��������������;
		int tail=len-1;
		while (tail > 0)
		{
			//��ʱ��tail��ֵ�ϵ�����һ�θ��ĵ����鳤�ȣ�����tailָ���������һλ,�ʶ���������պú��ʣ������++;
			swap(arr[0], arr[tail]);
			HeapAdjust(arr, 0, tail);
			tail--;
		
		}
		
		
		
		//tailָʾ�Ѿ���λ�����ֵ,
		//������βԪ��  tailָʾ��λ����
		//��������Ϊ�����   ��Ϊ�ȹ��λ����������-1,��tail��û��++
		
	}
	else
	{
		cout << "����������" << endl;
		return;
	}
	
}
//�����򣬽�������С����ʵ��
//˳��:
//����˵��:
//1.start�ǳ�ʼ�ڵ�,���Լ�����
//2.child�ǳ�ʼ�ڵ�ĺ��ӣ�����childͨ��ѭ�������ҵ��Լ��ĺ���
//3.��������Ƿ��γ�С���ѣ����γɾ�ʹ���γɡ�
//��һ��������arr[parent]��ֵΪtemp
//�ڶ������ж����Һ��ӵĴ�С���õ��ϴ�С�����ӵ��±�
//���������Ƚ�temp�뺢�ӵĴ�С��������if�ж���ʹarr[parent]=��ֵ,temp��������
//���Ĳ���ʹparent=child,���ú��ӱ�Ϊ��ĸ�ڵ㣬�������²鿴�����д�ֵ����ŵ���parent�ϣ����ֱ����Ϊ���ѣ�(����ѭ��)���ճ���arr[parent]=temp
//���� Adjust�����������;

//��һ�����ȴ����һ������Ҷ�ڵ㿪ʼ�������Ӹ��ѣ�ֱ�����������齨�ɸ���
//�ڶ�������βԪ�ؽ������ٴӵ�һ���ڵ㿪ʼ��������
//��������ѭ���������裬ֱ���ѹ�ΪԪ�ظ���ָʾ��num-1=len,����;
//�鲢����
//right = len-1
void MergeBecome(int* arr, int left,int mid,int right,int*temp)
{
	//ע�����λ�ã��������
	int red = left;
	int blue = mid+1;
	int i = 0;//temp��ָʾ��
	while (red <= mid && blue <= right)
	{
		if (arr[red] < arr[blue])
		{
			temp[i++] = arr[red++];
		}
		else
		{
			temp[i++] = arr[blue++];
		}
	}
	while (red <= mid)
	{
		temp[i++] = arr[red++];
	}
	while (blue <= right)
	{
		temp[i++] = arr[blue++];
	}
	i = 0;
	while (left <= right)
	{
		arr[left++] = temp[i++];
	}
}
//�֣����ǵݹ飬���ǽ�һ���Լ��ֳ����룬д��ݹ�
void MergeDiv(int *arr, int left,int right, int* temp)
{
	//ע��ݹ��������,left�ϸ�С��right
	if (left < right)
	{
		int mid = (left + right) / 2;//��ǰ����׶ε�mid��Ҫ������ǰ��mergebecome
		MergeDiv(arr, left, mid, temp);
		MergeDiv(arr, mid + 1, right, temp);//�ֳ����룬���ϲ�
		MergeBecome(arr, left,mid, right, temp);
	}
}
//�ܺͲ�
void MergeSort(int* arr, int left, int right)
{
	int* temp = new int[right + 1];
	MergeDiv(arr, left, right, temp);
	delete[]temp;
}

//��������

//���ֲ���(��������������Կ������������㷨���ö��ֲ���)
bool TJtrue(int a,int b)
{
	if (a < b)
		return true;
	else
		return false;
}
int BinarySearch(int *arr,int len,int b)
{
	int left = -1;
	int right = len;
	int mid = (left + right) /2;
	while (left + 1 != right)
	{
		int mid = (left + right) / 2;//�ǵ���ѭ���������mid
		if (arr[mid]<b)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	return right;
}

//��������
int LSMSB(int *arr,int len)
{
	int key=0;
	for (int i = 0; i < len-1; i++)
	{
		for (int t = i+1; t < len; t++)
		{
			if (arr[i] > arr[t])
			{
				key++;
			}
		}
	}
	return key;
}




//����д�Ĺ鲢
void zhi(int *arr,int left,int mid,int right,int*temp)
{
	int Rptr = mid + 1;
	int Lptr = left;
	int i = 0;
	while (Lptr <= mid && Rptr <= right)
	{
		if (arr[Lptr] < arr[Rptr])
		{
			temp[i++] = arr[Lptr++];
		}
		else
		{
			temp[i++] = arr[Rptr++];
		}
	}
	while (Lptr <= mid)
	{
		temp[i++] = arr[Lptr++];
	}
	while (Rptr <= right)
	{
		temp[i++] = arr[Rptr++];
	}
	i = 0;
	while (left <= right)
	{
		arr[left++] = temp[i++];
	}
}

void fen(int *arr ,int left ,int right , int *temp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right)/2;
	fen(arr, left, mid, temp);
	fen(arr, mid + 1, right, temp);
	zhi(arr, left, mid, right, temp);
}


void allin(int *arr,int left,int right)
{
	int* temp = new int[right + 1];
	fen(arr, left, right, temp);
	delete[]temp;
}
