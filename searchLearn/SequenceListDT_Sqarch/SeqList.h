#ifndef SEQLIST_H
#define SEQLIST_H

#include <iostream>

using namespace std;

template<typename type>
class SeqList{
public:
	SeqList(int len);
	~SeqList();
	int insertElement(type item,int i);
	int deleteElement(int i);
	int getLength() const;
	type getElement(int i) const;
	int locateElement(type item) const;
	bool isEmpty() const;
	void clearList();
private:
	type *data;
	int length;
	int maxLength;
};
//���캯��
template <typename type> SeqList<type>::SeqList(int len):length(0),maxLength(len)
{
	data = new type[len];
}
//��������
template <typename type> SeqList<type>::~SeqList()
{

}
//�������,
template <typename type> int SeqList<type>::insertElement(type item,int i)
{
	if(length == maxLength)
	{
		cout<<"�޿��ÿռ�"<<endl;
		return 0;
	}
	if(i<0||i>length)
	{
		cout<<"��ַ���Ϸ�"<<endl;
		return 0;
	}
	for(int j= length;j>i;j--)
	{
		data[j] = data[j-1];
	}
	data[i] = item;
	length ++;
	return 1;
}
//ɾ������
template <typename type> int SeqList<type>::deleteElement(int i)
{
	if(length == 0)
	{
		cout<<"�޿�ɾ��Ԫ��"<<endl;
		return 0;
	}
	if(i<0||i>length)
	{
		cout<<"��ַ���Ϸ�"<<endl;
		return 0;
	}
	for(int j = i;j<length;j++)
	{
		data[j] = data[j+1];
	}
	length --;
	return 1;
}
//�õ����Ա�ǰ����
template <typename type> int SeqList<type>::getLength() const
{
	return length;
}
//���������õ�Ԫ��
template <typename type> type SeqList<type>::getElement(int i) const
{
	if(i<0||i>=length)
	{
		cout<<"��ַ���Ϸ�"<<endl;
		return NULL;
	}
	return data[i];
}

//����Ԫ�صõ�����
template <typename type> int SeqList<type>::locateElement(type item) const
{
	for(int i = 0;i<this->getLength();i++)
	{
		if(data[i]==item)
		{
			return i;
		}
	}
	return -1;
}

//�ж��Ƿ�Ϊ��
template <typename type> bool SeqList<type>::isEmpty() const
{
	if(length == 0)
	{
		return true;
	}
	return false;
}
//������Ա�
template <typename type> void SeqList<type>::clearList()
{
	length = 0;
}

#endif // SEQLIST_H
