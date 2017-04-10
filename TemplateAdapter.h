#ifndef __TemplateAdapter_H__
#define __TemplateAdapter_H__

#include<iostream>
#include<string>
using namespace std;

template<typename T>
struct Node
{

	Node* _next;     //������һ��ָ�������Ľṹ���һ��ָ��
	T _data;     //����������ģ�壬���������͵�����
};


template<typename T>
class List
{
	typedef Node<T> ListNode;       //����ע��Node<T>   ��һ���µ�����
	typedef Node<T>* PNode;				//����ע��Node<T>   ��һ���µ�����
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
void List<T>::PushBack(T data)       //����ע��List<T>��һ���µ����ͣ���������д������Ӧ����List<T>
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

template<typename T, typename Container = List<T>>  //������԰���һ����俴����һ������������ʽ��T��Container����������
										//����������Ը�����������ȱʡֵ�����Ǹ���ֵ
								//T���������һ���������ͣ���int��double�ȣ�Container������һ���Զ�����࣬�����Ǹ�������
								//�����������������������˳���
								//����������test������ʹ�õ�ʱ����Ҫ���ݵ���Queue<int, List<int>>������ʽ����Ϊ��������
							//��ContainerҲ����ģ����Ļ������涨������ģ��������ģ���ģ������Ƚ�һ��
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
void Stack<T, Container>::Push(T data)                //�����Stack<T, Container>�൱����һ�����ͣ��������������Ҫ�����ӱ�ʾ
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
//template<typename T, typename Container = List<T>>    //���������ԭʼ�İ汾���������ģ��Ĳ������Ƚ�
//template <class T, template <class> class Container = SeqList > // ȱʡ����������汾������ıȽϵĻ����������ε�����
				//����һ��template <class>�������Ļ����������;ͱ��ˣ��������ǵĲ���Ҳ��Ҫ�䣬���������һ��
		//��ģ������ͣ��������������ֻ��Ҫ��д˳��������������ͺ���
		//�����template <class> class���������һ�����ͣ����Ǳ���������д������ʱ�򣬲�����һ�����ͣ�����������;���
					//һ��ģ���ģ�壬����˵�������template <class>��������һ��ģ�壬Ȼ���ְ�������Ϊһ��ģ��
				//����������ʹ�õ�ʱ�򣬾Ͳ���Ҫ������һ��Queue<int, List<int>>����ֻ��ҪStack<int> s;
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