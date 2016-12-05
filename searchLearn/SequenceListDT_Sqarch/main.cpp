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
	cout<<"\n元素15的下标是："<<list->locateElement(15);
	system("pause");
	return 0;
}