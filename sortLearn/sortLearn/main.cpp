/*
直接插入排序
	思想：
		从第二个元素开始，依次向后遍历，如果遇到一个元素比它前面的一个元素小，就将它插入到前面
		插入方法是挨个元素向后移，直到遇到比它小的停下来，插入进去！
	时间复杂度：
		最好：n
		最差：n'2
		平均：n'2
	空间复杂度：
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
	cout<<"排序前："<<endl;
	for(int i = 0;i<10;i++)
	{
		cout<<arr[i]<< "  ";
	}
	cout<<"\n";
	straightInsertSort(arr,10);
	cout<<"\n排序后："<<endl;
	for(int i = 0;i<10;i++)
	{
		cout<<arr[i]<< "  ";
	}
	system("pause");
	return 0;
}