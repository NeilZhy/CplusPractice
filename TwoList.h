#include<iostream>
using namespace std;

typedef int DataType;

struct ListNode
{
	DataType _data;
	ListNode* _next;
	ListNode* _prev;
	ListNode(DataType data)
		:_next(NULL)
		, _prev(NULL)
		, _data(data)
	{}
};

class List
{
	typedef ListNode Node;

public:
	List()
		:_head(NULL)
		, _tail(NULL)
	{

	}
	~List()
	{}

	void Show();
	void PushBack(DataType data);
	DataType PopBack();
	void PushFront(DataType data);

private:
	Node* _head;
	Node* _tail;
};

void List:: PushBack(DataType data)
{
	if (NULL == _head)
	{
		_head = _tail = new Node(data);
	}
	else
	{
		_tail->_next = new Node(data);
		_tail->_next->_prev = _tail;
		_tail = _tail->_next;
	}
}

void List:: Show()
{
	Node* cur = _head;
	Node* tail = _head;
	cout << "顺序" << endl;
	while (cur)
	{
		cout << cur->_data << " ";
		tail = cur;                   //为了想让链表逆序打印，循环结束后，tail指向的就是最后一个节点
		cur = cur->_next;
	}
	
	cout << endl;
	cout << "逆序" << endl;
	while (tail)                   //逆序打印
	{
		cout << tail->_data << " ";
		tail = tail->_prev;
	}
	cout << endl;

}

DataType List:: PopBack()
{
	if (NULL == _head)               //无节点
	{
		return 0;
	}
	else if (NULL == _head->_next)   //只有一个节点
	{
		int num = _head->_data;
		delete _head;
		_head =_tail = NULL;
		return num;
	}
	else                        //多个节点
	{
		Node* cur = _head;
		while (cur->_next->_next)
		{
			cur = cur->_next;
		}
		int num = cur->_next->_data;
		delete cur->_next;
		cur->_next = NULL;
		return num;
	}
}

void PushFront(DataType data)
{

}

void Test()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.Show();
	cout << l.PopBack()<<endl;
}