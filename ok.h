#pragma once
#include<iostream>
#include<vector>
#include<stack>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include<ctime>
using namespace std;
//打印
void myprintf(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
//判断一开始数组是否为升序
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
//判断一个数组是否为降序
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
//打印数组
void print(int * arr,int len)
{
	for (int m = 0; m < len; m++)
	{
		cout << arr[m] << " ";
	}
}
//冒泡排序(对于一个数组) 传入数组和数组长度(超大数据测试失败
void BubbleSort(int* arr,int len)
{
	int end = len;//标记最大元素位置，起标记作用
	for (int i = 0; i < len-1;i++)//每次冒泡一个元素，需要冒泡九个，所以外循环是len-1;
	{
		for (int t = 0; t < end-1; t++)//每轮需要比较的个数是标记处-1
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
//直接插入排序(解决)
void InsertionSort(int* arr, int len)
{
	for (int i = 1; i < len; i+=1)
	{
		int temp = arr[i];
		int j = i - 1;
		while(true)//注意，当arr[j]小于temp时结束，控制条件应该写大于号是继续条件
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
//希尔排序(gap是步长)
void ShellSort(int* arr, int len)
{
	int gap;
	for (gap = len / 2; gap >= 1; gap /= 2)
	{
		for (int i = gap; i < len; i++)
		{   
			int temp = arr[i];
			int j = i - gap;//用j标记arr[i]的前gap个
			while (j >= 0 && arr[j] > temp)//当前gap个大于arr[i],那么将j位置数据后推一位，再将j自减一个gap,继续比较,如此向下检索下去
			{
				arr[j+gap] = arr[j];//将j位置数据移动至j+gap,相当于往后挪动
				j -= gap;
			}
			arr[j + gap] = temp;//当上述while循环结束，j指向了一个比temp小的数，那么应该在j+gap位置插入gap
		}

	}
}
//快速排序
//三点取样优化快速排序
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
int div(int* arr, int L, int R)//R应该传入len-1;
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
		return;//这里应该直接return而不是应该触发报错，因为这是结束递归的条件
	}
	int base = div(arr, start, end);
	QuickSort(arr, start, base - 1);
	QuickSort(arr, base + 1, end);
}
//使用栈实现递归，以快排为例
//先实现栈
void StackQS(int* arr, int start, int end)
{
	//申请一个栈
	int* Stack = (int*)malloc((end / 2) * sizeof(int));
	//三点取样法，取中三点位于中间的数字
	int tempstart = start;
	int tempend = end;
	//指向栈的顶部,表示栈的长度
	int base =-1;//指向最顶端位置下标
	ChoseMid(arr, tempstart, tempend);
	int key = div(arr, start, end);//第一次分割
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
//堆排序
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void HeapAdjust(int*arr, int parent,int len)
{		
	//start为非子叶节点
	int temp = arr[parent];//储存该节点的值
	for (int child=parent*2+1; child <len; child=child*2+1)//找到非子叶节点的孩子，并且探查交换后是否破坏了其子节点的大根堆结构
	{
		if (arr[child] < arr[child + 1] && child+1 < len)//判断是否有右孩子,并且保证child为左右孩子最大者的下标,child判断时一直是奇数，所以开始只能是左节点
		{
			child++;
		}
		if (arr[child] > temp)//比较孩子最大者与该节点的值
		{
			arr[parent] = arr[child];//将大值往上交换
			parent = child;//更新节点，向下维护大根堆结构
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
	
	int key = UPTrue(arr, len);//判断数组是否为升序，否，key返回false,则进入排序
	if (!key)
	{
		for (int i = (len / 2) - 1; i >= 0; i--)
			HeapAdjust(arr, i, len);
		//之后再从交换首尾元素，继续调整大根堆;
		int tail=len-1;
		while (tail > 0)
		{
			//此时，tail数值上等于下一次更改的数组长度，而且tail指向数组最后一位,故而放在这里刚好合适，最后再++;
			swap(arr[0], arr[tail]);
			HeapAdjust(arr, 0, tail);
			tail--;
		
		}
		
		
		
		//tail指示已经归位的最大值,
		//交换首尾元素  tail指示归位个数
		//继续调整为大根堆   因为先归的位，长度率先-1,而tail还没有++
		
	}
	else
	{
		cout << "数组已升序" << endl;
		return;
	}
	
}
//堆排序，降序排序，小根堆实现
//顺序:
//数据说明:
//1.start是初始节点,由自己输入
//2.child是初始节点的孩子，并且child通过循环自增找到自己的孩子
//3.检查子树是否形成小根堆，不形成就使其形成·
//第一步，储存arr[parent]的值为temp
//第二步，判断左右孩子的大小，得到较大（小）孩子的下标
//第三步，比较temp与孩子的大小，若满足if判断则使arr[parent]=该值,temp继续保留
//第四步，使parent=child,将该孩子变为父母节点，继续向下查看，若有大值将其放到该parent上，最后直到成为根堆，(跳出循环)将空出的arr[parent]=temp
//以上 Adjust调整函数完成;

//第一步，先从最后一个非子叶节点开始，建立子根堆，直到将整个数组建成根堆
//第二步，首尾元素交换，再从第一个节点开始建立根堆
//第三步，循环上述步骤，直到已归为元素个数指示器num-1=len,即可;
//归并排序
//right = len-1
void MergeBecome(int* arr, int left,int mid,int right,int*temp)
{
	//注意红蓝位置，左红右蓝
	int red = left;
	int blue = mid+1;
	int i = 0;//temp的指示器
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
//分，就是递归，就是将一个自己分成两半，写入递归
void MergeDiv(int *arr, int left,int right, int* temp)
{
	//注意递归结束条件,left严格小于right
	if (left < right)
	{
		int mid = (left + right) / 2;//当前这个阶段的mid就要传给当前的mergebecome
		MergeDiv(arr, left, mid, temp);
		MergeDiv(arr, mid + 1, right, temp);//分成两半，最后合并
		MergeBecome(arr, left,mid, right, temp);
	}
}
//总和并
void MergeSort(int* arr, int left, int right)
{
	int* temp = new int[right + 1];
	MergeDiv(arr, left, right, temp);
	delete[]temp;
}

//基数排序

//二分查找(数组必须有序，所以可以先用排序算法再用二分查找)
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
		int mid = (left + right) / 2;//记得在循环里面更新mid
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

//求逆序数
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




//随手写的归并
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
