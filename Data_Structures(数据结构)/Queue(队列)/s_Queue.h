#pragma once
/*
 *	sequential queue����ѭ������˳��洢�ṹ
*/

template<class T>
class s_Queue
{
public:
	s_Queue(int queueCapacity = 10);//���캯����ʼ������Ĭ������Ϊ10
	bool ClearQueue();				//��ն���
	bool QueueEmpty() const;		//���ܺ����жϵ�ǰ�����Ƿ�Ϊ��
	bool EnQueue(const T& item);	//���β����Ԫ��
	T GetHead();					//��ȡ����Ԫ��
	T DeQueue();					//ɾ������Ԫ��
	int QueueLength();				//��ǰ������Ԫ�ظ���
	~s_Queue();						//���ٶ���
private:
	T* queue;						//����ָ��
	int capacity;					//���г���
	int front;						//������Ԫ���±�
	int rear;						//����βԪ���±�
};

template<class T>
s_Queue<T>::s_Queue(int queueCapacity):capacity(queueCapacity)
{
	try
	{
		if (capacity > 0)
		{
			queue = new T[capacity];
			front = 0;
			rear = 0;
		}
		else
			throw capacity;
	}
	catch (const std::exception&)
	{
		std::cout << "Queue capacity must > 0" << std::endl;
	}
}

template<class T>
inline bool s_Queue<T>::ClearQueue()
{
	rear = front;
	return true;
}

template<class T>
inline bool s_Queue<T>::QueueEmpty() const
{
	return front == rear;
}

template<class T>
bool s_Queue<T>::EnQueue(const T & item)
{
	if ((rear + 1) % capacity != front)
	{
		queue[rear] = item;
		rear = (rear + 1) % capacity;
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
inline T s_Queue<T>::GetHead()
{
	if (front == rear)
	{
		std::cout << "GetHead ERROR! Queue is empty,Fault Data -> ";
		return queue[front];
	}
	else
		return queue[front];
}

template<class T>
T s_Queue<T>::DeQueue()
{
	T _data = queue[front];
	if ((front + 1) % capacity != rear)
	{
		front = (front + 1) % capacity;
		return _data;
	}
	else
	{
		front = rear;
		return _data;
	}
}

template<class T>
inline int s_Queue<T>::QueueLength()
{
	return (rear - front + capacity) % capacity;
}

template<class T>
s_Queue<T>::~s_Queue()
{
	delete queue;
	queue = NULL;
}