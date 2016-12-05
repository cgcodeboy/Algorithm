#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

//ð������
void bubbleSort(int a[],int left,int right)
{
	int temp;
	for(int i = left;i<right-1;i++)
	{
		for(int j = left;j<right-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

//��������
int partition(int a[],int left,int right,int mid)
{
	int i = left,j = right + 1;
	int x = a[left];
	while(true)
	{
		while(a[++i] <x);
		while(a[--j] <x);
		if(i>=j)
		{
			break;
		}
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	a[left] = a[j];
	a[j] =x;
	return j;
}

int sequenceTimeSelect(int a[],int left,int right,int k)
{
	if(right-left<75)//������ҳ���С��һ�����ȣ������ټ�����ֱ�Ӳ���һ���򵥵�ð�����򷽷�����
	{
		bubbleSort(a,left,right);
		return a[left+k-1];
	}
	/*
	ÿ5��Ԫ�ط�Ϊһ�飬������Ϊһ��Ĳ��ơ�Ȼ����λ��ȫ���Ƶ���ǰ���1/5��
	*/
	for(int i = 0;i<=(right-left-4)/5;i++)
	{
		bubbleSort(a,left+i*5,left+i*5+4);
		int _temp = a[left+i];
		a[left+i] = a[left+5*i+2];
		a[left+5*i+2] = _temp;
	}

	int mid = sequenceTimeSelect(a,left,left+(right-left-4)/5,(right-left-4)/10);//�ҳ���λ������λ����Ϊ��׼
	int i = partition(a,left,right,mid);//�������򲢷��ػ�׼�±�
	int j = i-left+1;//��j����߶��Ǳ�a[k]С�ģ���j���ұߵĶ��Ǳ�a[K]���
	if(k <= i)
		return sequenceTimeSelect(a,left,i,k);//�ڱ�a[k]С�������м�����
	else
		return sequenceTimeSelect(a,i+1,right,k);//�ڱ�a[k]��������м�����
}

int main()
{
	srand(time(0));
	ofstream file1("�����ļ�.txt",ios::in);
	int arr[200000];
	for(int i = 0;i<200000;i++)
	{
		arr[i] =rand()%10000;
		file1<<arr[i]<<" ";
	}
	cout<<sequenceTimeSelect(arr,0,199999,1345);
	file1.close();
	system("pause");
	return 0;
}