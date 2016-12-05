#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

//冒泡排序
void bubbleSort(int a[],int left,int right)
{
	int temp;
	for(int i = left;i<right-1;i++)
	{
		for(int j = left;j<right-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

//快速排序
int partition(int a[],int left,int right,int mid)
{
	int i = left,j = right + 1;
	int x = a[left];
	while(true)
	{
		while(a[++i] <x);
		while(a[--j] <x);
		if(i>=j)
		{
			break;
		}
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	a[left] = a[j];
	a[j] =x;
	return j;
}

int sequenceTimeSelect(int a[],int left,int right,int k)
{
	if(right-left<75)//如果查找长度小于一定长度，不必再继续，直接采用一个简单的冒泡排序方法即可
	{
		bubbleSort(a,left,right);
		return a[left+k-1];
	}
	/*
	每5个元素分为一组，不够成为一组的不计。然后将中位数全部移到最前面的1/5；
	*/
	for(int i = 0;i<=(right-left-4)/5;i++)
	{
		bubbleSort(a,left+i*5,left+i*5+4);
		int _temp = a[left+i];
		a[left+i] = a[left+5*i+2];
		a[left+5*i+2] = _temp;
	}

	int mid = sequenceTimeSelect(a,left,left+(right-left-4)/5,(right-left-4)/10);//找出中位数的中位数作为基准
	int i = partition(a,left,right,mid);//快速排序并返回基准下标
	int j = i-left+1;//在j的左边都是比a[k]小的，在j的右边的都是比a[K]大的
	if(k <= i)
		return sequenceTimeSelect(a,left,i,k);//在比a[k]小的数组中继续找
	else
		return sequenceTimeSelect(a,i+1,right,k);//在比a[k]大的数组中继续找
}

int main()
{
	srand(time(0));
	ofstream file1("生成文件.txt",ios::in);
	int arr[200000];
	for(int i = 0;i<200000;i++)
	{
		arr[i] =rand()%10000;
		file1<<arr[i]<<" ";
	}
	cout<<sequenceTimeSelect(arr,0,199999,1345);
	file1.close();
	system("pause");
	return 0;
}