#pragma once 
#include <iostream>

/*
 * double Link List - ���Ա��˫��ѭ������
 * 
*/

template<class T>
class Node
{
public:
	T data;
	Node* prior;
	Node* next;
};

template<class T>
class dl_List
{
public:
	dl_List();								//���캯����ʼ��ͷ���
	int ListLength() const;					//��ȡ���Ա�Ԫ�ظ���
	bool ListEmpty() const;					//�ж����Ա��Ƿ�Ϊ��
	bool ListInsert(const T& item);			//˳�����Ԫ��item
	bool ListInsert(int i, const T& item);	//��i��λ�ò���Ԫ��item
	int LocateElem(const T& item);			//���ص�һ����item���Ԫ�ص���ţ��������򷵻�0
	T GetElem(int i);						//��ȡ��i��Ԫ��ֵ
	T ListDelet(int i);						//ɾ����i��Ԫ�ز�������ֵ
	T PriorElem(const T& item);				//���ص�һ����item���Ԫ�ص�ǰ��
	T NextElem(const T& item);				//���ص�һ����item���Ԫ�صĺ��
	~dl_List();				//���������������Ա�
private:
	int length;
	Node<T>* head;			//ͷ���
	Node<T>* rNode;			//βԪ��ָ��
};

template<class T>
dl_List<T>::dl_List()
{
	head = new Node<T>;
	length = 0;			
	head->data = NULL;
	head->prior = head;
	head->next = head;
	rNode = head;
}

template<class T>
inline int dl_List<T>::ListLength() const
{
	return length;
}

template<class T>
inline bool dl_List<T>::ListEmpty() const
{
	return length == 0 ? true : false;
}

template<class T>
bool dl_List<T>::ListInsert(const T & item)
{
	Node<T> *newNode;				//�����½��
	newNode = new Node<T>;			//��ʼ���½��
	newNode->data = item;			//��ֵ
	newNode->prior = rNode;			//�½��ͷָ��ָ��ǰβ���
	newNode->next = rNode->next;	//�½��βָ��ָ��ǰβ���ĺ�̼�����
	head->prior = newNode;			//ͷ���ǰ��ָ���½�㼴��β
	rNode->next = newNode;			//��ǰβ�����ָ���½��
	rNode = newNode;				//β���Ϊ�½��
	length += 1;
	return true;
}

template<class T>
bool dl_List<T>::ListInsert(int i, const T & item)
{
	try
	{
		if (i > 0 && i <= length)
		{
			Node<T>* _node;
			Node<T>* newNode = new Node<T>;
			newNode->data = item;
			_node = head;
			while (i)
			{
				_node = _node->next;
				i--;
			}
			newNode->prior = _node->prior;
			_node->prior->next = newNode;
			_node->prior = newNode;
			newNode->next = _node;
			length += 1;
			return true;
		}
		else
			throw i;
	}
	catch (int& value)
	{
		return false;
	}
}

template<class T>
inline int dl_List<T>::LocateElem(const T & item)
{
	int _length = length;
	Node<T> *_node = this->rNode;
	while (_length && _node != head)
	{
		if (_node->data == item)
		{
			return _length;
		}
		_node = _node->prior;
		_length--;
	}
	return 0;
}

template<class T>
T dl_List<T>::GetElem(int i)
{
	try
	{
		if (i > 0 && i <= length)
		{
			Node<T>* _node = this->head;
			while (i > 0)
			{
				_node = _node->next;
				i--;
			}
			return _node->data;
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
T dl_List<T>::ListDelet(int i)
{
	try
	{
		if (i > 0 && i <= length)
		{
			Node<T>* _node = this->head;
			T _data;
			while (i > 0)
			{
				_node = _node->next;
				i--;
			}
			_data = _node->data;
			_node->prior->next = _node->next;
			_node->next->prior = _node->prior;
			rNode = _node->next;
			delete _node;
			_node = NULL;
			length -= 1;
			return _data;
		}
		else
			throw i;
	}
	catch (int& value)
	{
		std::cout << "ListDelet ERROR! i -> ";
		return i;
	}
}

template<class T>
T dl_List<T>::PriorElem(const T & item)
{
	Node<T>* _node;
	_node = this->rNode;
	while (_node->prior != head)
	{
		if (_node->data == item)
			return _node->prior->data;
		_node = _node->prior;
	}
	return head->data;
}

template<class T>
T dl_List<T>::NextElem(const T & item)
{
	Node<T>* _node;
	_node = this->head->next;
	while (_node->next != head)
	{
		if (_node->data == item)
			return _node->next->data;
		_node = _node->next;
	}
	return head->data;
}

template<class T>
dl_List<T>::~dl_List()
{
	Node<T>* _node;
	while (rNode != head)
	{
		_node = rNode;
		rNode = _node->prior;
		delete _node;
		_node = NULL;
	}
	delete head;
	head = NULL;
}
