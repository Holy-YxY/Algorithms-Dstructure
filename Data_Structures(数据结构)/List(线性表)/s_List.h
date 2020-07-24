#pragma once
#include <iostream>
/*
 *	Sequential List - ���Ա��˳��洢�ṹ
 *	���ԣ��߼����ڣ�����Ҳ����
*/

template<class T>
class s_List
{
public:
	s_List(int listCapacity = 10);			//���캯����ʼ�����Ա�Ĭ������Ϊ10
	void ClearList();						//���Ա��ÿ�
	bool ListEmpty() const;					//�ж����Ա��Ƿ�Ϊ��
	bool ListInsert(int i, const T& item);	//��i��λ�ò���Ԫ��item
	int ListLength();						//��ȡ���Ա�Ԫ�ظ���
	int LocateElem(const T& item);			//���ص�һ����item��ȵ�Ԫ�ص���ţ��������򷵻�0
	T GetElem(int i);						//��ȡ��i��Ԫ�ص�ֵ
	T ListDelet(int i);						//ɾ����i��Ԫ�ز�������ֵ
	T PriorElem(const T& item);				//���ص�һ����item��ȵ�Ԫ�ص�ǰ��
	T NextElem(const T& item);				//���ص�һ����item��ȵ�Ԫ�صĺ��
	~s_List();								//�������Ա�
private:
	T* s_list;								//���Ա�ָ��
	int capacity;							//���Ա���
	int length;								//���Ա�Ԫ�ظ���
};

template<class T>
s_List<T>::s_List(int listCapacity): capacity(listCapacity)
{
	try
	{
		if (capacity < 1)
			throw capacity;
		s_list = new T[capacity];
		length = 0;
	}
	catch (int& value)
	{
		std::cout << "List capacity must > 0" << std::endl;
	}
}

template<class T>
 inline void s_List<T>::ClearList()
{
	 length = 0;
}

 template<class T>
bool s_List<T>::ListEmpty() const
 {
	return length == 0 ? true : false;
 }

template<class T>
inline int s_List<T>::ListLength()
{
	return length;
}

template<class T>
inline T s_List<T>::GetElem(int i)
{
	return s_list[i-1];
}

template<class T>
int s_List<T>::LocateElem(const T & item)
{
	for (int num = 0; num < length; num++)
	{
		if (item == s_list[num])
		{
			return num + 1;
		}
	}
	return 0;
}

template<class T>
bool s_List<T>::ListInsert(int i, const T & item)
{
	if ((i > length ? 1 == i - length : i > 0) && i < capacity && length+1 <= capacity)
	{
		if (i > length)			//�����Ԫ��ΪĩβԪ��
		{
			s_list[i - 1] = item;
		}
		else					//�м����λ��
		{
			for (int len = length; len >= i; len--)
			{
				s_list[len] = s_list[len - 1];
			}
			s_list[i - 1] = item;
		}
		length += 1;
		return true;
	}
	else
		return false;
}

template<class T>
T s_List<T>::ListDelet(int i)
{
	length -= 1;
	return s_list[i-1];
}

template<class T>
T s_List<T>::PriorElem(const T & item)
{
	try
	{
		int x = LocateElem(item);
		if (x < 1)
			throw item;
		return s_list[x-2];
	}
	catch (T& value)
	{
		std::cout << "PriorElem ERROR -> ";
		return item;
	}
}

template<class T>
T s_List<T>::NextElem(const T & item)
{
	try
	{
		int x = LocateElem(item);
		if (x >= length || x <= 0)
			throw item;
		return s_list[x];
	}
	catch (T& value)
	{
		std::cout << "NextElem ERROR -> ";
		return item;
	}
}

template<class T>
inline s_List<T>::~s_List()
{
	delete[] s_list;
	s_list = NULL;
}
