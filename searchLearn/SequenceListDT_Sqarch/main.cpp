#include <iostream>
#include "SeqList.h"

using namespace std;

int main()
{
	SeqList<int> *list = new SeqList<int>(10);
	for(int i = 0;i<10;i++)
	{
		list->insertElement(20-i,i);
	}
	for(int i = 0;i<list->getLength();i++)
	{
		cout<<list->getElement(i)<<" ";
	}
	cout<<"\nԪ��15���±��ǣ�"<<list->locateElement(15);
	system("pause");
	return 0;
}