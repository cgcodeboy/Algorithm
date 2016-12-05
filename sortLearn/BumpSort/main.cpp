#include <iostream>

using namespace std;

void bubbleSort(int a[],int n)
{
	int temp;
	for(int i = 0;i<n-1;i++)
	{
		for(int j = 0;j<n-i-1;j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

int main()
{
	int arr[] = {2,4,6,3,5,12,42,7,46,32,8,13,37};
	bubbleSort(arr,13);
	for(int i = 0;i<13;i++)
	{
		cout<<arr[i]<<" ";
	}
	system("pause");
	return 0;
}