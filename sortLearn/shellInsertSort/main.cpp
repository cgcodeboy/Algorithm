/*
希尔排序：
	思想：
		每一次取一个步长（第一次取总长的二分之一，以后每次取上一次步长的二分之一），然后按照步长将数组分成
		若干组，对每一组进行直接插入排序直到步长为0即可。
	时间复杂性：
		最好：
		最坏：
		平均：
*/


#include <iostream>

using namespace std;

void shellSort(int a[],int n)
{
	int dk  = n>>1;
	while(dk>0)
	{
		for(int i = dk;i<n;i++)
		{
			int x = a[i];
			int j = i-dk;
			while(j>=0&&a[j]>x)
			{
				a[j+dk] = a[j];
				j -= dk;
			}
			a[j+dk] = x;
		}
		dk = dk>>1;
	}
}

int main()
{
	int arr[] = {12,3,5,2,53,6,35,64,35,7,21,42,54};
	shellSort(arr,13);
	for(int i = 0;i<13;i++)
	{
		cout<<arr[i]<<" ";
	}
	system("pause");
	return 0;
}
