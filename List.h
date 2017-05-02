#pragma once
#include<iostream>
using namespace std;

//void Show()
//{
//	cout << "hello" << endl;
//}


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
	List()
		:_head(GetNode(0))
	{
		_head->_next = _head;
		_head->_prev = _head;
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
		return Iterator(_head->_next);
	}
protected:
	Node* _head;
};



