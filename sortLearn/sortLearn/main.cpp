/*
ֱ�Ӳ�������
	˼�룺
		�ӵڶ���Ԫ�ؿ�ʼ���������������������һ��Ԫ�ر���ǰ���һ��Ԫ��С���ͽ������뵽ǰ��
		���뷽���ǰ���Ԫ������ƣ�ֱ����������С��ͣ�����������ȥ��
	ʱ�临�Ӷȣ�
		��ã�n
		��n'2
		ƽ����n'2
	�ռ临�Ӷȣ�
		1
*/



#include <iostream> 

using namespace std;

void straightInsertSort(int a[],int size)
{
	for(int i = 1;i<size;i++)
	{
		if(a[i]<a[i-1])
		{
			int temp = a[i];
			int j = i-1;
			while(temp<a[j])
			{
				a[j+1] = a[j];
				j--;
			}
			a[j+1] = temp;
		}
	}
}

int main()
{
	int arr[10] = {1,5,3,8,4,9,25,15,21,10};
	cout<<"����ǰ��"<<endl;
	for(int i = 0;i<10;i++)
	{
		cout<<arr[i]<< "  ";
	}
	cout<<"\n";
	straightInsertSort(arr,10);
	cout<<"\n�����"<<endl;
	for(int i = 0;i<10;i++)
	{
		cout<<arr[i]<< "  ";
	}
	system("pause");
	return 0;
}