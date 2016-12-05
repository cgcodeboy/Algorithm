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
//构造函数
template <typename type> SeqList<type>::SeqList(int len):length(0),maxLength(len)
{
	data = new type[len];
}
//析构函数
template <typename type> SeqList<type>::~SeqList()
{

}
//插入操作,
template <typename type> int SeqList<type>::insertElement(type item,int i)
{
	if(length == maxLength)
	{
		cout<<"无可用空间"<<endl;
		return 0;
	}
	if(i<0||i>length)
	{
		cout<<"地址不合法"<<endl;
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
//删除操作
template <typename type> int SeqList<type>::deleteElement(int i)
{
	if(length == 0)
	{
		cout<<"无可删除元素"<<endl;
		return 0;
	}
	if(i<0||i>length)
	{
		cout<<"地址不合法"<<endl;
		return 0;
	}
	for(int j = i;j<length;j++)
	{
		data[j] = data[j+1];
	}
	length --;
	return 1;
}
//得到线性表当前长度
template <typename type> int SeqList<type>::getLength() const
{
	return length;
}
//根据索引得到元素
template <typename type> type SeqList<type>::getElement(int i) const
{
	if(i<0||i>=length)
	{
		cout<<"地址不合法"<<endl;
		return NULL;
	}
	return data[i];
}

//根据元素得到索引
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

//判断是否为空
template <typename type> bool SeqList<type>::isEmpty() const
{
	if(length == 0)
	{
		return true;
	}
	return false;
}
//清空线性表
template <typename type> void SeqList<type>::clearList()
{
	length = 0;
}

#endif // SEQLIST_H
