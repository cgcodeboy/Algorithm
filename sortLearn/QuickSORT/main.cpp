#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int sort(int a[],int low,int high)
{
	while(low<high)//边界条件
	{
		int flag = a[low];
		while(low<high&&a[high]>=flag)//找到比左边元素小的就交换，不然数组指针就前移
			high--;
		{
			int temp;
			temp = a[low];
			a[low] =  a[high];
			a[high] = temp;
		}
		while(low<high&&a[low]<=flag)//找到比右边元素大的就交换，不然数组指针就后移
			low++;
		{
			int temp;
			temp = a[low];
			a[low] =  a[high];
			a[high] = temp;
		}
	}
	return low;
}

void quickSort(int a[],int low,int high)
{
	if(low<high)
	{
		int pos = sort(a,low,high);//此时pos左边元素一定小于右边的元素，只需要分别将pos左右两边继续排好序即可
		quickSort(a,low,pos-1);
		quickSort(a,pos+1,high);
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
	quickSort(arr,0,199999);

	cout<<"\n排序后："<<endl;
	for(int i = 0;i<200000;i++)
	{
		file2<<arr[i]<<" ";
	}
	system("pause");
	return 0;
}