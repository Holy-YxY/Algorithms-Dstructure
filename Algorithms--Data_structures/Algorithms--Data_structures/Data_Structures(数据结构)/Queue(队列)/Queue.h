#pragma once

/*
	sequential queue����ѭ������
	����:�Ƚ��ȳ�
*/

template<class T>
class Queue
{
public:
	Queue(int queueCapacity = 10);	//���캯����ʼ������Ĭ������Ϊ10
	bool isEmpty() const;			//���ܺ����жϵ�ǰ�����Ƿ�Ϊ��
	void push_Q(const T& item);		//���β����Ԫ��
	void pop_Q();					//ɾ������Ԫ��
	void traversal();				//��������
	int numel();					//��ǰ������Ԫ�ظ���
	T& Front();						//��ȡ��ǰ����Ԫ��ֵ
	T& Rear();						//��ȡ��ǰ��βԪ��ֵ
	~Queue();						//���ٶ���
private:
	T* queue;						//����ָ��
	int capacity;					//���г���
	int front;						//������Ԫ���±�
	int rear;						//����βԪ���±�
	int number;						//����Ԫ�ظ���
};

template<class T>
Queue<T>::Queue(int queueCapacity) :capacity(queueCapacity)
{
	if (capacity < 1) throw "Queue capacity must be > 0";
	queue = new T[capacity];
	front = rear = number = 0;
}

template<class T>
inline bool Queue<T>::isEmpty() const
{
	return !number;
}

template<class T>
void Queue<T>::push_Q(const T& item)
{
	if (number == capacity) throw "The queue is full";
	if (rear == capacity && front > 0)
		rear = 0;
	queue[rear++] = item;
	number++;
}

template<class T>
void Queue<T>::pop_Q()
{
	if (number == 0) throw "The queue is empty";
	if (front == capacity && rear > 0 && front >= rear)
		front = 0;
	queue[front++].~T();
	//front = (front + 1) % capacity;
	number--;
}

template<class T>
void Queue<T>::traversal()
{
	if (number == 0) throw "The queue is empty";
	int ff = front;
	int rr = rear;
	int xx = front>=rear ? capacity : rear;
	for(int i = ff; i < xx ; i++)
		std::cout << queue[i] << " ";
	if(rear <= front)
		for (int j = 0; j < rr; j++)
		{
			std::cout << queue[j] << " ";
		}
	std::cout << std::endl;
}

template<class T>
int Queue<T>::numel()
{
	//return front < rear ? rear - front : capacity - front + rear;
	return number;
}

template<class T>
inline T& Queue<T>::Front()
{
	if (number == 0) throw "The queue is empty";
	return queue[front];
}

template<class T>
inline T& Queue<T>::Rear()
{
	if (number == 0) throw "The queue is empty";
	return queue[rear-1];
}

template<class T>
Queue<T>::~Queue()
{
	delete[] queue;
	queue = 0;
}

