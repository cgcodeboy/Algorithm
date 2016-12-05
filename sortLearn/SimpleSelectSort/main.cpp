#include <iostream>

using namespace std;

void simpleSelectSort(int a[],int n)
{
	int min ,temp;
	for(int i = 0;i<n -1;i++)
	{
		min = i;
		for(int j = i+1;j<n ;j++)
		{
			if(a[j]<a[min])
			{
				min = j;
			}
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}

int main()
{
	int arr[] = {2,4,6,3,5,12,42,7,46,32,8,13,37};
	simpleSelectSort(arr,13);
	for(int i = 0;i<13;i++)
	{
		cout<<arr[i]<<" ";
	}
	system("pause");
	return 0;
}