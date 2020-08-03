#pragma once
#include <iostream>
/*
	Sequential stack -- ջ��˳��洢�ṹ
	���ԣ��߼����ڣ�����Ҳ����
*/

template<class T>
class s_Stack
{
public:
	s_Stack(int stackCapacity = 10);	//���캯����ʼ��ջĬ������Ϊ10
	void ClearStack();	//��ջ���
	bool StackEmpty() const;	//���Ƿ�Ϊ��ջ
	T GetTop();	//��ȡջ��Ԫ�ز�������ֵ
	bool Push(const T& item);	//������Ԫ����ջ��
	T Pop();	//����ջ��Ԫ�ز�������ֵ
	int StackLength();	//����ջ��Ԫ�ظ���
	~s_Stack();			//������������ջ
private:
	T* s_stack;
	int top;		//ջ��ָ��
	int capacity;	//ջ�Ĵ洢����
};

template<class T>
s_Stack<T>::s_Stack(int stackCapacity): capacity(stackCapacity)
{
	try
	{
		if (capacity < 1)
			throw capacity;
		s_stack = new T[capacity];
		top = -1;
	}
	catch (int& value)
	{
		std::cout << "Stack capacity must > 0" << std::endl;
	}
}

template<class T>
inline void s_Stack<T>::ClearStack()
{
	top = -1;
}

template<class T>
inline bool s_Stack<T>::StackEmpty() const
{
	return top > -1 ? false : true;
}

template<class T>
T s_Stack<T>::GetTop()
{
	try
	{
		if (top > -1)
			return s_stack[top]; \
		else
			throw -1;
	}
	catch (int& value)
	{
		std::cout << "GetTop ERROR!";
		return NULL;
	}
}

template<class T>
bool s_Stack<T>::Push(const T & item)
{
	if (top < capacity - 1)
	{
		top++;
		s_stack[top] = item;
		return true;
	}
	else
		return false;
}

template<class T>
T s_Stack<T>::Pop()
{
	T data;
	data = s_stack[top];
	top--;
	return data;
}

template<class T>
inline int s_Stack<T>::StackLength()
{
	return top + 1;
}

template<class T>
inline s_Stack<T>::~s_Stack()
{
	delete[] s_stack;
	s_stack = NULL;
}
