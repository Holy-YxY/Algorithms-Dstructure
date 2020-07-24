#pragma once
#include <iostream>
/*
 *	Link List - ���Ա����ʽ�洢�ṹ
 *
*/

template<class T>
class Node 
{
public:
	T data;
	Node* next;
};

template<class T>
class l_list
{
public:
	l_list();								//���캯����ʼ��ͷ�ڵ�
	bool ListInsert(const T& item);			//�߼�ĩβ��������Ԫ��item
	bool ListInsert(int i, const T& item);	//�߼�˳��i��������Ԫ��item
	int LocateElem(const T& item);			//���ص�һ����itemԪ����ȵ���ţ������ڷ���0
	T GetElem(int i);				//��ȡi��Ԫ�ظ�ֵ,i=0�򷵻�ͷ���������Ԫ�ظ���
	T ListDelet(int i);				//ɾ����i��Ԫ�ز�������ֵ
	~l_list();						//�������Ա�
private:
	Node<T>* head;					//ͷ���
	Node<T>* rNode;					//β���
};

template<class T>
l_list<T>::l_list()
{
	head = new Node<T>;				//��ʼ��ͷ���
	head->data = 0;
	head->next = NULL;
	rNode = this->head;
}

template<class T>
bool l_list<T>::ListInsert(const T & item)
{
	Node<T> *newNode;				//�����½��
	newNode = new Node<T>;			//��ʼ���½ڵ�
	newNode->data = item;			//��ֵ
	newNode->next = NULL;			//ĩβָ���ÿ�
	this->head->data += 1;			//ͷ���������+1�������Ա�Ԫ�ظ���
	rNode->next = newNode;			//��ǰβ���ָ�������ɵĽ��
	rNode = newNode;				//�������ɽ����Ϊβ���
	return true;
}

template<class T>
bool l_list<T>::ListInsert(int i, const T & item)
{
	if (i > 0 && i <= this->head->data)
	{
		Node<T> *p, *s;
		s = new Node<T>;
		s->data = item;
		p = this->head;
		while (i - 1 >= 1)
		{
			p = p->next;
			i--;
		}
		s->next = p->next;
		p->next = s;
		this->head->data += 1;
		return true;
	}
	else
		return false;
}

template<class T>
int l_list<T>::LocateElem(const T & item)
{
	Node<T> *p;
	int i = 0;
	p = head;
	while (p->next)
	{
		p = p->next;
		i++;
		if (item == p->data)
			return i;
	}
	return 0;
}

template<class T>
T l_list<T>::GetElem(int i)
{
	try
	{
		if (i >= 0 && i <= this->head->data)
		{
			T _data;
			Node<T> *p;
			p = head;
			for (int n = 0; n < i; n++)
			{
				p = p->next;
			}
			_data = p->data;
			return _data;
		}
		else
			throw i;
	}
	catch (int& value)
	{
		std::cout << "GetElem ERROR! i -> ";
		return i;
	}
}

template<class T>
T l_list<T>::ListDelet(int i)
{
	try
	{
		T _data;
		if (i > 1 && i <= this->head->data)
		{
			Node<T> *p, *q;
			p = this->head;
			while (i - 1 >= 1)
			{
				if (!(p->next))
				{
					throw i;
					break;
				}
				p = p->next;
				i--;
			}
			if (!(p->next->next))
				rNode = p;
			q = p->next;
			_data = q->data;
			p->next = q->next;
			delete q;
			q = NULL;
			this->head->data -= 1;
			return _data;
		}
		else
		{
			throw i;
		}
	}
	catch (int& value)
	{
		std::cout << "ListDelet ERROR! i -> ";
		return i;
	}
}

template<class T>
inline l_list<T>::~l_list()
{
	delete head;
	head = NULL;
}
