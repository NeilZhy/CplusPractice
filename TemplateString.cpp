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

	SeqList(const SeqList& s)
	{
		_p = new T[s._size];
		//memcpy(s._p,_p,s._size*sizeof(T));   //������ʹ�ÿ������캯����ʱ�򣬵���memcpy��ʱ����ǳ������Ҳ����˵�������
		//									//�µĶ����ָ�룬ÿ��ָ����ͬһ���ַ�������������������ʱ�����ִ���
		for (int i = 0; i < s._size; i++)
		{
			_p[i] = s._p[i];              //ÿ�θ�ֵһ��������Ϊ������string��Ķ���
								//�����������ִ�������һ�����⣬���ǣ�����ֻ�����õ�string���������������ʱ����Ҫʹ�����ַ�ʽ
								//���ǣ�������������͵�ʱ�����Ż�����ͨ������ķ�ʽ���и�ֵ��������ȽϿ�

		}

		_size = s._size;
		_capacity = s._size;
	}

	~SeqList()
	{
		if (0 != _capacity)
		{
			delete[] _p;
			_size = 0;
			_capacity = 0;
			_p = NULL;
		}
	}

	void PushBack(T data);
	void CheckCapacity();
	void Show();

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
	s.PushBack("hellojjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj");
	s.PushBack("world!");
	s.Show();
	SeqList<string> n = s;    //
	//n = s;
	n.Show();
}


int main()
{
	
	Test1();
	Test2();

	return 0;
}