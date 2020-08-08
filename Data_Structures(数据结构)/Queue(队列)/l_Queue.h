#pragma once
/*
 *	Link Queue -- ջ����ʽ�洢�ṹ
*/

template <class T>
class Node
{
public:
	T data;
	Node<T>* next;
};

template <class T>
class l_Queue
{
public:
	l_Queue();		//���캯����ʼ���ն���
	bool QueueEmpty() const;		//�����Ƿ�Ϊ��
	bool EnQueue(const T& item);	//��β������Ԫ��
	T GetHead();	//��ȡ����Ԫ��
	T DeQueue();	//ɾ������Ԫ��
	int QueueLength();	//����Ԫ�ظ���
	~l_Queue();		//�����������ٶ���
private:
	Node<T>* front;	//����ָ��
	Node<T>* rear;	//��βָ��
	int length;		//����Ԫ�ظ���
};

template<class T>
l_Queue<T>::l_Queue()
{
	Node<T>* _node = new Node<T>;
	front = rear = _node;
	_node->data = NULL;
	front->next = NULL;
	length = 0;
}

template<class T>
inline bool l_Queue<T>::QueueEmpty() const
{
	return length==0;
}

template<class T>
bool l_Queue<T>::EnQueue(const T & item)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = item;
	newNode->next = NULL;
	rear->next = newNode;
	rear = newNode;
	length += 1;
	return true;
}

template<class T>
inline T l_Queue<T>::GetHead()
{
	if (length <= 0)
	{
		std::cout << "GetHead ERROR! Queue is empty,Fault Data -> ";
	}
	else
		return front->next->data;
}

template<class T>
T l_Queue<T>::DeQueue()
{
	if (length > 0)
	{
		Node<T>* _node;
		T _data;
		_node = front->next;
		_data = _node->data;
		front->next = _node->next;
		delete _node;
		_node = NULL;
		length -= 1;
		return _data;
	}
	else
	{
		std::cout << "DeQueue ERROR! Queue is empty,Fault Data -> ";
	}
}

template<class T>
inline int l_Queue<T>::QueueLength()
{
	return length;
}

template<class T>
l_Queue<T>::~l_Queue()
{
	Node<T>* _node;
	while (front->next != rear)
	{
		_node = front->next;
		front = _node->next;
		delete _node;
		_node = NULL;
	}
	delete rear, front;
	front = rear = NULL;
}

