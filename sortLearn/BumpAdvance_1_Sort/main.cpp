/*
�Ľ���ð������
	˼�룺ÿһ����δ���ֽ����ĵط����±�־λ����һ�α���ʱ�������˼��ɣ�
	��Ϊ�����δ���ֽ����ˣ�˵���Ѿ����ź���ġ�
*/
#include <iostream>

using namespace std;

void bubbleSort(int a[],int n)
{
	int temp;
	int pos;
	int i = n-1;
	while(i>0)
	{
		pos = 0;
		for(int j = 0;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				pos = j;
			}
		}
		i = pos;
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