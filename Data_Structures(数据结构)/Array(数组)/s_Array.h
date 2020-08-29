#pragma once
#include <initializer_list>	//����ʵ�ֿɱ�κ���
/*
 *	Sequential Array - �����˳��洢�ṹ
*/

template<class T>
class s_Array
{
public:
	s_Array(const int N, std::initializer_list<int> boundn);	//���ع��캯��Ϊ�ɱ�ι��캯������ʼ������
	bool Value(T& elem, std::initializer_list<int> indexn);		//��������ָ��λ��Ԫ�ظ�ֵ��elem
	bool Assign(const T& elem, std::initializer_list<int> indexn);	//����ָ��λ��Ԫ�ظ�ֵΪelem
	~s_Array();	//����������������
protected:
	/*
	 *	nά�����ӳ����Ϊ LOC(J1, J2, ������, Jn) = LOC(0,0,������,0) + ��Ci*Ji(1 -> n)
	 *	Cn = L,Ci-1 = Bi*Ci, 1 < i <= n
	*/
	auto map_C(int i);	//��C�ĵݹ麯��
private:
	T *base;		//�����׵�ַ
	int n;			//ά��
	int *bounds;	//��ά����	
};

template<class T>
s_Array<T>::s_Array(const int N, std::initializer_list<int> boundn) :n(N)
{
	auto ptr = boundn.begin();
	if ((int)boundn.size() == N)
	{
		bounds = new int[N];
		int capacity = 1;
		int i = 0;
		for (ptr; ptr != boundn.end(); ptr++, i++)
		{
			try
			{
				if (*ptr > 0)
				{
					bounds[i] = *ptr;
					capacity *= *ptr;
				}
				else
					throw *ptr;
			}
			catch (int& value)
			{
				std::cout << "��" << i + 1 << "ά�ȳ��ȱ������0 ,��ǰΪ -> " << *ptr << std::endl;
				exit(0);
			}
		}
		base = new T[capacity * sizeof(T)];
	}
}

template<class T>
bool s_Array<T>::Value(T & elem, std::initializer_list<int> indexn)
{
	auto ptr = indexn.begin();
	if ((int)indexn.size() == n)
	{
		int _sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (*ptr > bounds[i - 1] || *ptr < 0)
				return false;
			_sum += map_C(i) * (*ptr);
			ptr++;
		}
		auto loc = base + _sum;
		elem = *loc;
		return true;
	}
}

template<class T>
bool s_Array<T>::Assign(const T & elem, std::initializer_list<int> indexn)
{
	auto ptr = indexn.begin();
	if ((int)indexn.size() == n)
	{
		int _sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (*ptr >= bounds[i - 1] || *ptr < 0)
				return false;
			_sum += map_C(i) * (*ptr);
			ptr++;
		}
		auto loc = base + _sum;
		*loc = elem;
		return true;
	}
}

template<class T>
auto s_Array<T>::map_C(int i)
{
	if (i == 1)
	{
		return  bounds[i] * (int)sizeof(T);
	}
	else if (i == n)
	{
		return (int)sizeof(T);
	}
	else
	{
		return map_C(i - 1) / bounds[i];
	}
}

template<class T>
inline s_Array<T>::~s_Array()
{
	delete[] base;
	base = NULL;
	delete[] bounds;
	bounds = NULL;
}

