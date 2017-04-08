#ifndef __TemplateAdapter_H__
#define __TemplateAdapter_H__


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

template<typename T, typename Container>
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



#endif