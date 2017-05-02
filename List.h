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


//����ڵ�
template<class T>    //����û�б�Ҫдtemplate<class T��class ref��class ptr>�ˣ���Ϊ����ڵ㲻Ҫ��ô����  
struct ListNode
{
	ListNode<T>* _next;   //�����ס��֮ǰ˵�ģ���ģ����ĵط���һ��Ҫ�뵽д�Ǹ��࣬�ҿ�ʼ��ʱ��û��д���
	ListNode<T>* _prev;
	T _data;
public:
	ListNode(T data = 0)
		:_next(NULL)
		, _prev(NULL)
		, _data(data)
	{}
};

//������iterator
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
	Self operator++(int)    //����������õ������õĻ������Ƿ���ֵ��������õĻ��������о�������˵�ҷ��ص��Ǿֲ�����
				//��Ȼ��ѷ���ֵ����֮��ͺ���


				//һ����������ʦ�ıȽ�һ��
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

	Self operator--(int)    //����������õ������õĻ������Ƿ���ֵ��������õĻ��������о�������˵�ҷ��ص��Ǿֲ�����
		//��Ȼ��ѷ���ֵ����֮��ͺ���


		//һ����������ʦ�ıȽ�һ��
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


//��������������Ҫд���������
//template<class T>
//ostream& operator<<(ostream& stream, Iterator<T> i)
//{
//	stream << i->_ptr->_data;
//	return stream;
//}


//����
template<class T>
class List
{
	
	typedef ListNode<T> Node;
	
public:
	typedef __iterator<T, T&, T*> Iterator;   //���������������ģ����ʲô������ģ��֮ǰһֱ����������һ���뷨���ǣ�ģ���
			//�Զ��������ʹ�����ݳ���һЩ����ɶ�ģ����ǣ�����д��ʱ�����ķ���ģ����ʾ�ĵ��õĻ����Ƚ϶�һ��
			//�ͱ�������ط�����������ʽ�ĵ���ģ���ˣ����Һܶ�ʱ��дֻҪ��ģ����ĵط���




	typedef __iterator<T,const T&,const T*> ConstIterator;  //�һ��ǲ���
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
		delete _head;    //�����������ﻹ�Ǵ���һ������ģ����ǵ��Ǹ�const���ε�ʱ���޷�������Ȼ����һ������Ҳ
				//�����������ṹ���ʱ�����������
	}

public:
	Node* GetNode(T data)
	{
		return new ListNode<T>(data);    //����ע�⣬�ҿ�ʼ��ʱ��û�м���<T>��ʱ�򣬱���ͨ�������������ΪListNode�ڶ����ʱ��
				//�Ͷ������һ��ģ���࣬�����ڳ���ListNode��ʱ�򣬾ͳ���<T>��������һ������
				//ͬʱӦ��ע�����������ʹ��������ģ�����ʱ��ҲӦ��ע����ʵĵط�����<T>
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
		if (_head != _head->_next)   //����д���ˣ�һ��ʼ��ʱ��д����while����˵��ô������
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

	Iterator Begin()   //������һ��ʼ���ص���һ��Node*��һ��ָ�룬����������ʹ�õ�ʱ��о��ǲ�����Ҫ��ģ���Ϊ�ҵ�Iterator��
				//һ�����ͣ����������ⷵ�ص�Ӧ����һ��Iterator���͵�һ������
	{
		return Iterator(_head->_next);   //����ķ�ʽ�����������һ��Iterator�Ķ���
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



