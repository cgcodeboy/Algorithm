/*
堆排序
	思想：
		将数组先按照大顶堆的方式排列好，具体做法是从倒数第一个非叶子节点开始，将其与其两个叶子节点比较，如果
		较大的那个叶子节点的值大于它的值，就将其与这个较大的叶子节点交换。按照这种方式一致进行下去。当交换后
		叶子树发生改变，就需要从新将叶子节点从新排序。
		当fieltUp进行完后，就可以进行fieltDown，将根节点放到尾部。将尾部移到根位置，执行从上到下的fielt工作，就是
		逆向的执行上述的操作。
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