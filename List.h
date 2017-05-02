#pragma once
#include<iostream>
using namespace std;

struct AA
{
	int _a;
	int _b;

	AA(int a = 0,int b = 0)
		:_a(a)
		, _b(b)
	{
	}
};


//链表节点
template<class T>    //这里没有必要写template<class T，class ref，class ptr>了，因为链表节点不要这么东西  
struct ListNode
{
	ListNode<T>* _next;   //这里记住和之前说的，有模板类的地方就一定要想到写那个类，我开始的时候没有写这个
	ListNode<T>* _prev;
	T _data;
public:
	ListNode(T data = 0)
		:_next(NULL)
		, _prev(NULL)
		, _data(data)
	{}
};

//迭代器iterator
template<class T,class Ref,class Ptr>
//template<class T>
class __iterator
{
	typedef ListNode<T> Node;
	typedef __iterator<T, Ref, Ptr> Self;
public:
	__iterator(Node* p)
		:_ptr(p)
	{}
public:
	bool operator!=(Node* p)
	{
		return *this != p;
	}
	T operator*()
	{
		return this->_ptr->_data;
	}
	Self& operator++()
	{
		_ptr = _ptr->_next;
		return *this;
	}
	Self operator++(int)    //这里我如果用的是引用的话，就是返回值如果是引用的话，就是有警报错误，说我返回的是局部变量
				//，然后把返回值改了之后就好了


				//一会拿来和老师的比较一下
	{
		//Node* p = _ptr;
		_ptr = _ptr->_next;
		return __iterator(_ptr->_prev);
	}

	Self& operator--()
	{
		_ptr = _ptr->_prev;
		return *this;
	}

	Self operator--(int)    //这里我如果用的是引用的话，就是返回值如果是引用的话，就是有警报错误，说我返回的是局部变量
		//，然后把返回值改了之后就好了


		//一会拿来和老师的比较一下
	{
		//Node* p = _ptr;
		_ptr = _ptr->_prev;
		return __iterator(_ptr->_next);
	}
	T* operator->()
	{
		return &(_ptr->_data);
	}


public:
	Node* _ptr;
};


//输出运算符的重载要写在类的外面
//template<class T>
//ostream& operator<<(ostream& stream, Iterator<T> i)
//{
//	stream << i->_ptr->_data;
//	return stream;
//}


//链表
template<class T>
class List
{
	
	typedef ListNode<T> Node;
	
public:
	typedef __iterator<T, T&, T*> Iterator;   //这里我们深入理解模板是什么东西，模板之前一直脑子里面有一个想法就是，模板会
			//自动根据你的使用推演出来一些类型啥的，但是，我在写的时候更多的发现模板显示的调用的机会会比较多一点
			//就比如这个地方，我们是显式的调用模板了，而且很多时候，写只要是模板类的地方，




	typedef __iterator<T,const T&,const T*> ConstIterator;  //我还是不懂
			//





	List()
		:_head(GetNode(0))
	{
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List()
	{
		this->Clear();
		delete _head;    //析构函数这里还是存在一点问题的，就是当那个const修饰的时候无法析构，然后还有一个就是也
				//可能是析构结构体的时候出现了问题
	}

public:
	Node* GetNode(T data)
	{
		return new ListNode<T>(data);    //这里注意，我开始的时候没有加上<T>的时候，编译通不过，这就是因为ListNode在定义的时候
				//就定义成了一个模板类，所以在出现ListNode的时候，就出现<T>，他们是一个整体
				//同时应该注意的是我们在使用其他的模板类的时候也应该注意合适的地方加上<T>
	}

	void PushBack(T data)
	{
		Node* tmp = GetNode(data);
		Node* next = _head;
		Node* prev = _head->_prev;
		tmp->_next = next;
		tmp->_prev = prev;
		next->_prev = tmp;
		prev->_next = tmp;
		/*tmp->_next = _head;
		tmp->_prev = _head->_prev;*/
	}

	void PopBack()
	{
		if (_head != _head->_next)   //这里写错了，一开始的时候写成了while，我说怎么不对呢
		{
			Node* next = _head;
			Node* prev = _head->_prev->_prev;
			delete _head->_prev;
			next->_prev = prev;
			prev->_next = next;
		}

	}

	Iterator Find(T data)
	{
		Iterator it = Iterator(_head->_next);
		while (*it != data)
		{
			++it;
		}
		return it;
	}

	void Clear()
	{
		/*Iterator it = Iterator(_head->_next);
		Iterator head(_head);
		while (it != head)
		{

		}*/
		Node *del = _head->_next;
		Node *cur = _head->_next;
		while (cur != _head)
		{
			del = cur;
			cur = cur->_next;
			delete del;
		}
		_head->_next = _head;
		_head->_prev = _head;
	}

	void Show()
	{
		Node* it = _head->_next;
		while (it != _head)
		{
			cout << it->_data << " ";
			it = it->_next;
		}
		cout << endl;
	}

	Iterator Begin()   //我这里一开始返回的是一个Node*的一个指针，但是在外面使用的时候感觉是不符合要求的，因为我的Iterator是
				//一个类型，所以我们这返回的应该是一个Iterator类型的一个对象
	{
		return Iterator(_head->_next);   //这里的方式很巧妙，构造了一个Iterator的对象
	}

	ConstIterator Begin() const
	{
		return ConstIterator(_head->_next);
	}

	Iterator End()
	{
		return Iterator(_head);
	}

	Iterator End() const
	{
		return Iterator(_head);
	}



protected:
	Node* _head;
};



