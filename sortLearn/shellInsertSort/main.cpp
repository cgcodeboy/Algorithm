/*
ϣ������
	˼�룺
		ÿһ��ȡһ����������һ��ȡ�ܳ��Ķ���֮һ���Ժ�ÿ��ȡ��һ�β����Ķ���֮һ����Ȼ���ղ���������ֳ�
		�����飬��ÿһ�����ֱ�Ӳ�������ֱ������Ϊ0���ɡ�
	ʱ�临���ԣ�
		��ã�
		���
		ƽ����
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
