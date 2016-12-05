#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int sort(int a[],int low,int high)
{
	while(low<high)//�߽�����
	{
		int flag = a[low];
		while(low<high&&a[high]>=flag)//�ҵ������Ԫ��С�ľͽ�������Ȼ����ָ���ǰ��
			high--;
		{
			int temp;
			temp = a[low];
			a[low] =  a[high];
			a[high] = temp;
		}
		while(low<high&&a[low]<=flag)//�ҵ����ұ�Ԫ�ش�ľͽ�������Ȼ����ָ��ͺ���
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
		int pos = sort(a,low,high);//��ʱpos���Ԫ��һ��С���ұߵ�Ԫ�أ�ֻ��Ҫ�ֱ�pos�������߼����ź��򼴿�
		quickSort(a,low,pos-1);
		quickSort(a,pos+1,high);
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
	quickSort(arr,0,199999);

	cout<<"\n�����"<<endl;
	for(int i = 0;i<200000;i++)
	{
		file2<<arr[i]<<" ";
	}
	system("pause");
	return 0;
}