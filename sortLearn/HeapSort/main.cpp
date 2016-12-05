/*
������
	˼�룺
		�������Ȱ��մ󶥶ѵķ�ʽ���кã����������Ǵӵ�����һ����Ҷ�ӽڵ㿪ʼ��������������Ҷ�ӽڵ�Ƚϣ����
		�ϴ���Ǹ�Ҷ�ӽڵ��ֵ��������ֵ���ͽ���������ϴ��Ҷ�ӽڵ㽻�����������ַ�ʽһ�½�����ȥ����������
		Ҷ���������ı䣬����Ҫ���½�Ҷ�ӽڵ��������
		��fieltUp������󣬾Ϳ��Խ���fieltDown�������ڵ�ŵ�β������β���Ƶ���λ�ã�ִ�д��ϵ��µ�fielt����������
		�����ִ�������Ĳ�����
*/
#include <iostream>

using namespace std;

void fieltUp(int a[],int n)
{
	int temp;
	for(int i = n/2-1;i>=0;i--)
	{
		while(2 * i + 1<n)
		{
			int j = 2*i+1;
			if(j+1<n)
			{
				if(a[j] < a[j+1])
				{
					j++;
				}
			}
			if(a[i]<a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				i = j;
			}
			else
			{
				break;
			}
		}
	}
}

void fieltDown(int a[],int n)
{
	for(int i = n-1;i>0;i--)
	{
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		int j = 0;
		while(2*j +1<i)
		{
			int k = 2*j +1;
			if(k +1<i)
			{
				if(a[k] <a[k+1])
				{
					k++;
				}
			}
			if(a[j] <a[k])
			{
				temp = a[j];;
				a[j] = a[k];
				a[k] = temp;
				j = k;
			}
			else
			{
				break;
			}
		}
	}
}

void heapSort(int a[],int n)
{
	fieltUp(a,n);
	for(int i = 0;i<13;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	fieltDown(a,n);
	for(int i = 0;i<13;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int arr[] = {12,3,5,2,53,6,35,64,35,7,21,42,54};
	heapSort(arr,13);
	system("pause");
	return 0;
}