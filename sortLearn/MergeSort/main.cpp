/*
归并排序
	思想：
		其实现思想是基于两个排好序的序列合并为一个有序序列的算法和分治递归思想
		将一个数组平分为两半，再调用自身将左边排序好，再调用自身将右边排序好，然后
		将左右两边调用两排好序序列合并的方法合并。
	时间复杂度：
		最好：
*/
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void mergeArray(int a[],int first,int mid,int last)
{
	int *temp;
	temp = new int[last-first+1];//申请零时数组空间
	int i = first,j = mid+1;
	int m = mid,n = last;
	int k  = 0;
	while (i<=m&&j<=n)//在左右任何一边未到达尾部一直排序
	{
		if(a[i]<a[j])
		{
			temp[k] = a[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = a[j];
			j++;
			k++;
		}
	}

	//当左右任何一边已经没有元素时就将未排完的全部插入到零时数组尾部
	while(i<=m)
	{
		temp[k] = a[i];
		i++;
		k++;
	}
	while (j<=n)
	{
		temp[k] = a[j];
		j++;
		k++;
	}
	//将排好序的复制到原数组中
	for(int i = 0;i<k;i++)
	{
		a[first+i] = temp[i];
	}
	delete temp;
}

//函数入口
void mergeSort(int a[],int first,int last)
{
	if(first<last)
	{
		int mid = (first+last)/2;
		mergeSort(a,first,mid);//排好左边
		mergeSort(a,mid+1,last);//排好右边
		mergeArray(a,first,mid,last);
	}
}

int main()
{
	srand(time(0));
	ofstream file1("排序前.txt",ios::in);
	ofstream file2("排序后.txt",ios::in);
	int arr[200000];
	for(int i = 0;i<200000;i++)
	{
		arr[i] = rand()%10000;
		file1<<arr[i]<<" ";
	}
	mergeSort(arr,0,199999);
	for(int i = 0;i<200000;i++)
	{
		file2<<arr[i]<<" ";
	}

	file1.close();
	file2.close();
	cout<<"ok!"<<endl;
	system("pause");
	return 0;
}