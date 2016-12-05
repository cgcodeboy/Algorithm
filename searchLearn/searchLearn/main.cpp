/*
二分搜索：
	思想：
		求出数组的最中间的那个数，比较这个数和要查找的数。如果是，就返回这个数的下标，如果比这个数小，就在左边调用自身
		算法查找，如果比它大，就在右边调用自身查找，如果找不到就返回-1
	时间复杂度：
		最好：
		最坏：
		平均：
*/
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int binarySearch(int a[],int left,int right,int element)
{
	if(left<right)
	{		
		int mid = (left+right)/2;
		if(element == a[mid])
		{
			return mid;//如果等于中间元素就返回，停止搜索
		}
		else if(element>a[mid])
		{
			return binarySearch(a,mid+1,right,element);//如果大于中间元素就搜索右边的
		}
		else
		{
			return binarySearch(a,left,mid-1,element);//如果大于中间元素就搜索右边的
		}
	}
	if(element == a[left])
	{
		return left;
	}
	return -1;
}

int main()
{
	srand(time(0));
	ofstream file1("二分搜索生成文件.txt",ios::in);
	int arr[200000];
	for(int i = 0;i<200000;i++)
	{
		arr[i] =2*i;
		file1<<arr[i]<<" ";
	}
	cout<<binarySearch(arr,0,199999,358);
	file1.close();
	system("pause");
	return 0;
}