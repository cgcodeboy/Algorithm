#include <iostream>

using namespace std;

void binarySelectSort(int a[],int n)
{
	int min,max,temp;
	for(int i = 0;i<= n>>1;i++)
	{
		min = i;
		max = n-i-1;
		for(int j = i+1;j<n-i;j++)
		{
			if(a[j]<a[min])
			{
				min = j;
			}
			if(a[n-j]>a[max])
			{
				max = n-j;
			}
		}
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
		{
			temp = a[n-i-1];
			a[n-i-1] = a[max];
			a[max] = temp;
		}
	}
}

int main()
{
	int arr[] = {12,3,5,2,53,6,35,64,35,7,21,42,54,78};
	binarySelectSort(arr,14);
	for(int i = 0;i<14;i++)
	{
		cout<<arr[i]<<" ";
	}
	system("pause");
	return 0;
}