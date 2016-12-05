/*
�鲢����
	˼�룺
		��ʵ��˼���ǻ��������ź�������кϲ�Ϊһ���������е��㷨�ͷ��εݹ�˼��
		��һ������ƽ��Ϊ���룬�ٵ��������������ã��ٵ��������ұ�����ã�Ȼ��
		���������ߵ������ź������кϲ��ķ����ϲ���
	ʱ�临�Ӷȣ�
		��ã�
*/
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void mergeArray(int a[],int first,int mid,int last)
{
	int *temp;
	temp = new int[last-first+1];//������ʱ����ռ�
	int i = first,j = mid+1;
	int m = mid,n = last;
	int k  = 0;
	while (i<=m&&j<=n)//�������κ�һ��δ����β��һֱ����
	{
		if(a[i]<a[j])
		{
			temp[k] = a[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = a[j];
			j++;
			k++;
		}
	}

	//�������κ�һ���Ѿ�û��Ԫ��ʱ�ͽ�δ�����ȫ�����뵽��ʱ����β��
	while(i<=m)
	{
		temp[k] = a[i];
		i++;
		k++;
	}
	while (j<=n)
	{
		temp[k] = a[j];
		j++;
		k++;
	}
	//���ź���ĸ��Ƶ�ԭ������
	for(int i = 0;i<k;i++)
	{
		a[first+i] = temp[i];
	}
	delete temp;
}

//�������
void mergeSort(int a[],int first,int last)
{
	if(first<last)
	{
		int mid = (first+last)/2;
		mergeSort(a,first,mid);//�ź����
		mergeSort(a,mid+1,last);//�ź��ұ�
		mergeArray(a,first,mid,last);
	}
}

int main()
{
	srand(time(0));
	ofstream file1("����ǰ.txt",ios::in);
	ofstream file2("�����.txt",ios::in);
	int arr[200000];
	for(int i = 0;i<200000;i++)
	{
		arr[i] = rand()%10000;
		file1<<arr[i]<<" ";
	}
	mergeSort(arr,0,199999);
	for(int i = 0;i<200000;i++)
	{
		file2<<arr[i]<<" ";
	}

	file1.close();
	file2.close();
	cout<<"ok!"<<endl;
	system("pause");
	return 0;
}