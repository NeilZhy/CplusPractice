#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class SeqList
{
public:
	SeqList()
		:_p(NULL)
		, _size(0)
		, _capacity(0)
	{
	}

	void PushBack(T data);
	/*{
		CheckCapacity();
		_p[_size] = data;
		
		_size++;
	}*/

	void CheckCapacity();
	/*{
		if (_capacity <= _size)
		{
			_p = (T*)realloc(_p, (_size + 3)*sizeof(T));
			_capacity += 3;
		}
	}*/

	void Show();
	/*{
		for (int i = 0; i < _size; i++)
		{
			cout << _p[i];
		}
		cout << endl;
	}*/

protected:
	T* _p;
	int _size;
	int _capacity;
};

template<typename T>
void SeqList<T>::CheckCapacity()
{
	//����ʹ��realloc���ԣ���Ϊ����������string���͵�ʱ�����￪�ٵ���һ��������Ҫ���������ڹ��캯��֮���
	/*if (_capacity <= _size)
	{
		_p = (T*)realloc(_p, (_size + 3)*sizeof(T));
		_capacity += 3;
	}*/

	//������new���пռ�Ŀ���
	if (_capacity <= _size)
	{
		T* temp = new T[_size + 3];  //�����µĿռ�
		_capacity += 3;
		memcpy(temp, _p, _size*sizeof(T));   //���ֽڿ���
		delete[] _p;     //ԭ���Ŀռ��ͷŵ�
		_p = temp;   //_pָ���µĿռ�

	}
}

template<typename T>
void SeqList<T>::PushBack(T data)
{
	CheckCapacity();
	_p[_size] = data;

	_size++; 
}


template<typename T>
void SeqList<T>::Show()
{  
	for (int i = 0; i < _size; i++)
	{
		cout << _p[i]<<"  ";
	}
	cout << endl;
}


void Test1()
{
	SeqList<int> a;
	a.PushBack(1);
	a.PushBack(2);
	a.PushBack(3);
	a.PushBack(4);
	a.PushBack(5);
	a.Show();
}
//
void Test2()
{
	SeqList<string> s;
	s.PushBack("hello");
	s.PushBack("world!");
	s.Show();
}


int main()
{
	
	Test1();
	Test2();
	//cout << "hello" << endl;

	return 0;
}