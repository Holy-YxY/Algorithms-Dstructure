#pragma once
#include "Stack(ջ)\l_Stack.h"
/*
 *	Sequential String - ����˳��洢�ṹ
*/

class s_String
{
public:
	s_String();
	/*
	 *���¼��������Ĺ��ܣ����ȡC++ʵ�֣�����C++������Խ��б���
	 *	1.void StrAssign(&T, chars);	//����һ��ֵ�����ַ�������chars�Ĵ�T
	 *	2.StrCopy(&T, S);	//��S���Ƶô�T
	*/
	s_String(const char* chars);	//���ع��캯��������ͬ��1
	//s_String(const s_String & s);	//���Ĭ�Ͽ������캯������ͬ��2�����ǽ��е���ǳ����,��������ʱ����ڴ�й©
	s_String(const s_String & s);	//��д�������캯��Ϊ���
	void operator=(const s_String& s);	//����ͬ�ϣ�����C++11���Խ�����չ
	char operator[](int i);	//��ȡ���ĵ�i��Ԫ��
	bool StrEmpty();	//���Ƿ�Ϊ�մ����մ� = ""����Ϊ�շ���true������false
	int StrCompare(const s_String& S);	//��ǰ�� >��=��< ��S���򷵻��� >��=��< 0
	int StrLength();	//����Ԫ�ظ���
	void ClearString();	//����ǰ�����
	void Concat(s_String S1);	//��S1�����ڵ�ǰ���ĺ��沢����Ϊ��ǰ��
	/*
	 * ����:�������ַ����ϲ��ҷ��أ�����C++11���ԡ�
	 * ע:��������ֵʱ����һ�ο������캯�������û����дΪ����������ͷ�ͬһ�ڴ棬����ڴ�й©��
	 *    ��Ҳ��������д�������캯��Ϊ�������һ��ԭ��
	 */
	s_String operator+(const s_String& S1);
	s_String SubString(int pos, int len);	//���ص�ǰ����pos���ַ��𳤶�len���ִ�
	/*
	 * ����:�����Ӵ�T�ڵ�ǰ����pos���ַ�֮���һ�γ��ֵ�λ��.�������ڣ��򷵻�ֵΪ0
	 * ��������:����ģʽƥ���㷨
	 *		1.BFƥ���㷨
	 *		2.KMPƥ���㷨
	*/
	int Index(s_String T, int pos);	//�˴�ΪKMP�㷨��ʵ��
	l_Stack<int> Index(s_String T);	//����Ϊ�����Ӵ�T�ڵ�ǰ�������в��ص��Ӵ���һ�γ��ֵ�λ�ã�ΪReplace������ʵ���ṩ����
	void Replace(s_String T, s_String V);	//��V�滻��ǰ����������T��ȵĲ��ص����Ӵ�
	void StrInsert(int pos, s_String T);	//��ǰ���ĵ�pos���ַ�֮ǰ���봮T
	void StrDelet(int pos, int len);	//ɾ����ǰ����pos���ַ��𳤶�Ϊlen���Ӵ�
	~s_String();	//���ٴ�
private:
	char* ch;
	int length = 0;
};

s_String::s_String()
{
	ch = NULL;
}

s_String::s_String(const s_String & s)
{
	length = s.length;
	ch = new char[s.length + 1];
	for (int i = 0; i <= s.length; i++)
	{
		ch[i] = s.ch[i];
	}
}

void s_String::operator=(const s_String & s)
{
	length = s.length;
	if (ch != NULL)
	{
		delete[] ch;
		ch = NULL;
	}
	ch = new char[s.length + 1];
	for (int i = 0; i <= s.length; i++)
	{
		ch[i] = s.ch[i];
	}
}

inline char s_String::operator[](const int i)
{
	if (i > length)
		return ch[i];
	else
		return ch[i - 1];
}

s_String::s_String(const char* chars)
{
	const char* ptr = chars;
	while (*ptr != '\0')
	{
		length++;
		ptr++;
	}
	ch = new char[length + 1];
	for (int i = 0; i <= length; i++, chars++)
	{
		ch[i] = *chars;
	}
}

inline bool s_String::StrEmpty()
{
	return !length && ch;
}

inline int s_String::StrCompare(const s_String & S)
{
	return length - S.length;
}

inline int s_String::StrLength()
{
	return length;
}

inline void s_String::ClearString()
{
	if (ch != NULL)
	{
		delete[] ch;
		ch = NULL;
	}
	ch = new char[1];
	ch[0] = '\0';
	length = 0;
}

void s_String::Concat(s_String S1)
{
	char* _ch = new char[length];
	for (int i = 0; i < length; i++)
	{
		_ch[i] = ch[i];
	}
	delete[] ch;
	ch = NULL;
	ch = new char[length + S1.length + 1];
	for (int i = 0; i < length + S1.length + 1; i++)
	{
		if (i < length)
			ch[i] = _ch[i];
		else
			ch[i] = S1.ch[i - length];
	}
	length += S1.length;
	delete[] _ch;
	_ch = NULL;
}

s_String s_String::operator+(const s_String & S1)
{
	s_String _str;
	_str.length = length + S1.length;
	_str.ch = new char[_str.length + 1];
	for (int i = 0; i < _str.length + 1; i++)
	{
		if (i < length)
			_str.ch[i] = ch[i];
		else
			_str.ch[i] = S1.ch[i - length];
	}
	return _str;
}

s_String s_String::SubString(int pos, int len)
{
	if (pos > length || pos < 1 || len > length - pos)
		return "";
	s_String _str;
	_str.ch = new char[len + 1];
	_str.length = len;
	int i;
	for (i = 0; i < len; i++)
	{
		_str.ch[i] = ch[pos + i - 1];
	}
	_str.ch[i] = '\0';
	return _str;
}

int s_String::Index(s_String T, int pos)
{
	//��ģʽ��T��next��������ֵ����������nextval
	int i = 0, j = -1;
	int* nextval = new int[T.length];
	nextval[0] = -1;
	while (i < T.length - 1)
	{
		if (j == -1 || T.ch[i] == T.ch[j])
		{
			++i;
			++j;
			if (T.ch[i] != T.ch[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
	//����ģʽ��T��nextval������T�ڵ�ǰ���е�pos���ַ�֮���λ��
	//����T�ǿգ�1 <= pos <= this.length
	if (T.length == 0 || pos < 1 || pos > this->length)
		return 0;
	int s, t;
	s = pos;
	t = 0;
	while (s < length && t < T.length)
	{
		if (t == -1 || ch[s] == T.ch[t])		//��Ӧ��ȼ����ȽϺ����ַ�
		{
			++s;
			++t;
		}
		else
			t = nextval[t];		//ģʽ������
	}
	delete[] nextval;
	nextval = NULL;
	if (t == T.length)		//ƥ��ɹ�
	{
		return s - T.length + 1;
	}
	else
		return 0;
}

l_Stack<int> s_String::Index(s_String T)
{
	//��ȡ�±�����鶯̬���󣬵���֮ǰʵ�ֵ���ʽ�洢�ṹ��ջ
	l_Stack<int> _arr;
	int pos = 1;
	while (pos < this->length)
	{
		_arr.Push(Index(T, pos));
		if (_arr.GetTop() == 0)
			break;
		pos = _arr.GetTop() + T.length - 1;
	}
	return _arr;
}

void s_String::Replace(s_String T, s_String V)
{
	l_Stack<int> _arr(Index(T));
	while (_arr.StackLength())
	{
		int pos = _arr.Pop();
		StrDelet(pos, T.length);
		StrInsert(pos, V);
	}
}

void s_String::StrInsert(int pos, s_String T)
{
	if (pos > 0 && pos <= length)
	{
		s_String _str;
		_str.length = length + T.length;
		_str.ch = new char[_str.length + 1];
		int i = -1;
		while (++i < _str.length)
		{
			if (pos == 1)
			{
				if (i < T.length)
					_str.ch[i] = T.ch[i];
				else
					_str.ch[i] = ch[i - T.length];
			}
			else
			{
				if (i < pos - 1 || i > pos + T.length - 2)
					_str.ch[i] = ch[i > (pos + T.length - 2) ? i - T.length : i % (pos - 1)];
				else
					_str.ch[i] = T.ch[i - pos + 1];
			}
		}
		_str.ch[i] = '\0';
		*this = _str;
	}
}

void s_String::StrDelet(int pos, int len)
{
	if (pos >= 1 && pos < length && len <= length - pos)
	{
		s_String _str;
		_str.length = length - len;
		_str.ch = new char[length - len + 1];
		int i = -1;
		while (++i < length)
		{
			if (i < pos)
				_str.ch[i] = ch[i];
			else if (i > pos + len - 2)
				_str.ch[i - len] = ch[i];
		}
		_str.ch[i - len] = '\0';
		*this = _str;
	}
}

s_String::~s_String()
{
	delete[] ch;
	ch = NULL;
}