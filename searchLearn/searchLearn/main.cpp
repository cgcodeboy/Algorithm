/*
����������
	˼�룺
		�����������м���Ǹ������Ƚ��������Ҫ���ҵ���������ǣ��ͷ�����������±꣬����������С��������ߵ�������
		�㷨���ң���������󣬾����ұߵ���������ң�����Ҳ����ͷ���-1
	ʱ�临�Ӷȣ�
		��ã�
		���
		ƽ����
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
			return mid;//��������м�Ԫ�ؾͷ��أ�ֹͣ����
		}
		else if(element>a[mid])
		{
			return binarySearch(a,mid+1,right,element);//��������м�Ԫ�ؾ������ұߵ�
		}
		else
		{
			return binarySearch(a,left,mid-1,element);//��������м�Ԫ�ؾ������ұߵ�
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
	ofstream file1("�������������ļ�.txt",ios::in);
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