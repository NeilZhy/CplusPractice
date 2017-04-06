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
	//这里使用realloc不对，因为接下来开辟string类型的时候，这里开辟的是一个对象，需要调用类似于构造函数之类的
	/*if (_capacity <= _size)
	{
		_p = (T*)realloc(_p, (_size + 3)*sizeof(T));
		_capacity += 3;
	}*/

	//这里用new进行空间的开辟
	if (_capacity <= _size)
	{
		T* temp = new T[_size + 3];  //开辟新的空间
		_capacity += 3;
		memcpy(temp, _p, _size*sizeof(T));   //按字节拷贝
		delete[] _p;     //原来的空间释放掉
		_p = temp;   //_p指向新的空间

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