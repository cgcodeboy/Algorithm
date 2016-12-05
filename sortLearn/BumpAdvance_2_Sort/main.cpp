#include <iostream>

using namespace std;

void bubbleSort(int a[],int n)
{
	int temp;
	int low = 0,high = n-1;
	while(low<high)
	{
		int j;
		for(j = low;j<high;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
		--high;
		for(j = high;j>low;j--)
		{
			if(a[j-1]>a[j])
			{
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
		++low;
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