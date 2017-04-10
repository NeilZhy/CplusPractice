#ifndef __TemplateAdapter_H__
#define __TemplateAdapter_H__

#include<iostream>
#include<string>
using namespace std;

template<typename T>
struct Node
{

	Node* _next;     //这里是一个指向自身的结构体的一个指针
	T _data;     //这里利用了模板，填充各个类型的数据
};


template<typename T>
class List
{
	typedef Node<T> ListNode;       //这里注意Node<T>   是一个新的类型
	typedef Node<T>* PNode;				//这里注意Node<T>   是一个新的类型
public:
	List()
		:_head(NULL)
		, _tail(NULL)
	{
	}

	void PushBack(T data);
	void PopBack();
	void Show();
	void PushFront(T data);
	void PopFront();
protected:
	PNode _head;
	PNode _tail;
};


template<typename T>
void List<T>::PushBack(T data)       //这里注意List<T>是一个新的类型，所以这里写的类域应该是List<T>
{
	if (NULL == _head)
	{
		_head = _tail = new(ListNode);
		_head->_data = data;
		_head->_next = NULL;
	}

	else
	{
		PNode cur = new(ListNode);
		_tail->_next = cur;
		_tail = _tail->_next;
		_tail->_next = NULL;
		_tail->_data = data;
	}
}


template<typename T>
void List<T>::Show()
{
	PNode cur = _head;
	while (cur)
	{
		cout << cur->_data << " ";
		cur = cur->_next;
	}
	cout << endl;
}

template<typename T>
void List<T>::PopBack()
{
	if (_head == NULL)
	{
		return;
	}
	else if (_head->_next == NULL)
	{
		delete(_head->_next);
		_head = _tail = NULL;
		return;
	}
	PNode cur = _head;
	while (cur->_next != _tail)
	{
		cur = cur->_next;
	}
	_tail = cur;
	_tail->_next = NULL;
	delete(cur->_next);
}


template<typename T>
void List<T>::PushFront(T data)
{
	if (_head == NULL)
	{
		PushBack(data);
	}
	else
	{
		PNode cur = new(ListNode);
		cur->_data = data;
		cur->_next = _head;
		_head = cur;
	}
}

template<typename T>
void List<T>::PopFront()
{
	if (NULL == _head)
		return;
	else if (NULL == _head->_next)
	{
		delete(_head);
		_head = _tail = NULL;
	}
	else
	{
		PNode del = _head;
		_head = _head->_next;
		delete(del);
		del = NULL;
	}
}

template<typename T, typename Container = List<T>>  //这里可以把这一条语句看成是一个抽象函数的形式，T和Container是两个参数
										//所以这里可以给这两个参数缺省值，就是赋初值
								//T可以理解成一个内置类型，如int，double等，Container可以是一个自定义的类，就是那个适配器
								//这里的适配器就是链表或者顺序表
								//这里我们在test函数中使用的时候，需要传递的是Queue<int, List<int>>这种形式，因为我们这里
							//的Container也是在模板类的基础上面定义出来的，和下面的模板的模板参数比较一下
class Stack
{
public:
	void Push(T data);
	void Pop();
	void Show();
protected:
	Container _con;
};

template<typename T, typename Container>
void Stack<T, Container>::Push(T data)                //这里的Stack<T, Container>相当于是一个类型，所以这里的类域要这样子表示
{
	_con.PushBack(data);
}

template<typename T, typename Container>
void Stack<T, Container>::Pop()
{
	_con.PopBack();
}

template<typename T, typename Container>
void Stack<T, Container>::Show()
{
	_con.Show();
}


template<typename T, typename Container>
class Queue
{
public:
	void Push(T data);
	void Pop();
	void Show();
protected:
	Container _con;

};

template<typename T, typename Container>
void Queue<T,Container>::Push(T data)
{
	_con.PushBack(data);
}

template<typename T, typename Container>
void Queue<T, Container>::Pop()
{
	_con.PopFront();
}

template<typename T, typename Container>
void Queue<T, Container>::Show()
{
	_con.Show();
}

//template <typename T>
//class SeqList
//{
//private:
//	int _size;
//	int _capacity;
//	T* _data;
//};
//template<typename T, typename Container = List<T>>    //这条语句是原始的版本，和下面的模板的参数做比较
//template <class T, template <class> class Container = SeqList > // 缺省参数，这个版本和上面的比较的话，就是修饰的类型
				//多了一个template <class>，这样的话，整个类型就变了，所以我们的参数也需要变，参数变成了一个
		//有模板的类型，所以我们这里就只需要填写顺序表，或者链表就好了
		//这里的template <class> class可以理解成一个类型，就是比如我们在写函数的时候，参数有一个类型，而这里的类型就是
					//一个模板的模板，就是说，这里的template <class>本身就是一个模板，然后又把它抽象为一个模板
				//这里我们在使用的时候，就不需要像上面一样Queue<int, List<int>>，而只需要Stack<int> s;
//class Stack
//{
//public:
//	void Push(const T& x);
//	void Pop();
//	const T & Top();
//	bool Empty();
//private:
//	Container<T > _con;
//};
//void Test()
//{
//	Stack<int > s1;
//	Stack<int, SeqList> s2;
//}



#endif