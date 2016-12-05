#include <iostream>

using namespace std;

int sequenceSearch(int a[],int n,int element)
{
	for(int i = 0;i<n;i++)
	{
		if(a[i] == element)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int arr[] = {12,45,34,68,94,63,74,65,88,14,72,44};
	int index = sequenceSearch(arr,12,6);
	cout<<"Ҫ���ҵ�Ԫ�ص��±�Ϊ��"<<index;
	system("pause");
	return 0;
}
