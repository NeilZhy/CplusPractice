#include<iostream>
#include<assert.h>
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
	List(const List& l)
	{
		Node* cur = l._head;
		while (cur)
		{
			this->PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	~List()
	{
		Del();
	}

	void Show();
	void PushBack(DataType data);
	DataType PopBack();
	void PushFront(DataType data);
	DataType PopFront();
	ListNode* Find(DataType data);    //这里注意的一个问题就是，返回值不能写成Node*虽然二者的意义是一样的，但是下文在写函数
	                                  //具体实现的时候，因为Node是在类里面定义的，返回值不能用它
	void Insert(Node* pos,DataType data); //这里是在pos的前面插入一个数据
	void Del();                     //全部删除，相当于析构函数 
	void Erase(Node* pos);					//随机删除
	void Reverse();                //逆置数据

private:
	Node* _head;
	Node* _tail;
};

void List:: PushBack(DataType data)
{
	if (NULL == _head)
	{
		_head = _tail = new Node(data);
		if (NULL == _head)
		{
			exit(0);
		}

	}
	else
	{
		_tail->_next = new Node(data);
		if (NULL == _tail->_next)
		{
			exit(0);
		}
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
		_tail = cur;     //这里之前没有改变_tail的指向，导致下面的程序出错
		return num;
	}
}

//前插，考虑两种情况，有节点，至少一个节点
void List:: PushFront(DataType data)
{
	if (NULL == _head)
	{
		PushBack(data);
	}
	else
	{
		Node* cur = new Node(data);
		if (NULL == cur)
		{
			exit(0);
		}
		cur->_next = _head;
		cur->_prev = NULL;
		_head->_prev = cur;
		_head = cur;
	}
}

DataType List:: PopFront()
{
	if (NULL == _head)
	{
		return 0;
	}
	else if (NULL == _head->_next)
	{
		DataType data = _head->_data;
		delete _head;
		_head = NULL;
		_tail = NULL;
		return data;
	}
	else
	{
		DataType data = _head->_data;
		Node* dele = _head;
		_head->_next->_prev = NULL;
		_head = _head->_next;
		delete dele;
		return data;
	}
}

ListNode* List::Find(DataType data)
{
	Node* cur = _head;
	while (cur)
	{
		if (data == cur->_data)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

void List:: Insert(Node* pos, DataType data)
{
	assert(NULL != pos);    //传入指针的时候就使用断言
	if (pos == _head)
	{
		PushFront(data);
	}
	else
	{
		Node* prev = pos->_prev;
		Node* next = pos;
		Node* cur = new Node(data);
		if (NULL == cur)
		{
			exit(0);
		}
		cur->_next = next;
		cur->_prev = prev;
		prev->_next = cur;
		next->_prev = cur;
	}
}

void List:: Del()
{
	Node* cur = _head;
	Node* del = cur;
	while (cur)
	{
		del = cur;
		cur = cur->_next;
		delete(del);
	}
	_head = NULL;
	_tail = NULL;
}

void List:: Erase(Node* pos)
{
	assert(NULL != pos);
	if (_head == pos)      //删除的是头结点
	{
		PopFront();
		//return;
	}
	else if (_tail == pos)  //删除的是尾节点
	{
		PopBack();
		//return;
	}
	else
	{
		Node* prev = pos->_prev;
		Node* next = pos->_next;
		prev->_next = next;
		next->_prev = prev;
		delete pos;
	}
}

//法一：运用swap交换数据值
//void List:: Reverse()
//{
//	Node* head = _head;
//	Node* tail = _tail;
//	//考虑奇数偶数个,考虑同时指向头即是链表为空
//	while ((head != tail) && (head != tail) && (head->_prev != tail))   //第一个判断链表是否为空，第一个判断奇数相遇的情况，第三种判断偶数相遇的情况
//	{
//		swap(head->_data,tail->_data);
//		head = head->_next;
//		tail = tail->_prev;
//	}
//}

//法二：交换指针
void List::Reverse()
{
	Node* prev1 = _head;    //一开始想着开辟四个指针，一个指向前，一个指向后，然后那样太麻烦了
	Node* prev2 = prev1;
	while (prev1)
	{
		prev2 = prev1;
		prev1 = prev1->_next;
		prev2->_next = prev2->_prev;
		prev2->_prev = prev1;
	}
	Node* tmp = _head;
	_head = _tail;
	_tail = tmp;
}

void Test()
{ 
	List l;
	/*
	cout << l.PopBack() << endl;
	l.Show();*/
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushFront(0);
	l.Insert(l.Find(3),-1);
	l.Show();
	l.Erase((l.Find(4)));
	l.Show();
	l.Reverse();
	l.Show();
	List l1(l);
	l1.Show();
	/*l.Del();
	l.Show();*/
	//cout << (l.Find(3))->_data;
	/*l.Show();
	cout << l.PopBack()<<endl;
	l.Show();
	cout << l.PopBack() << endl;*/
}