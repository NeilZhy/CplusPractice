#include<iostream>

using namespace std;

typedef int Datatype;

struct ListNode
{
	Datatype _data;
	ListNode* _next;
	ListNode(Datatype data)
		:_next(NULL)
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
		:_head(NULL)
		, _tail(NULL)
	{
		Node* cur = l._head;
		while (cur)
		{
			this->PushBack(cur->_data);    //函数复用
			cur = cur->_next;
		}
	}

	~List()
	{
		Node* cur = _head;
		Node* del = cur;
		_head = _tail = NULL;
		while (cur)
		{
			del = cur;
			cur = cur->_next;
			delete del;
		}
	}

	List& operator=(List l);
	void Show();
	void PushBack(Datatype data);
	Datatype PopBack();
	void PushFront(Datatype data);
	Datatype PopFront();

private:
	Node* _head;
	Node* _tail;
};


void List:: Show()
{
	Node* cur = _head;
	while (cur)
	{
		cout << cur->_data << " ";
		cur = cur->_next;
	}
	cout << endl;
}

void List:: PushBack(Datatype data)
{
	if (NULL == _head)
	{
		_head = new Node(data);
		_tail = _head;
	}
	/*else if (NULL == _head->_next)    一开始为了下面popback的需要，我本来想让tail指针指向倒数第二个指针，
	                                    从而减少popback中定义一个cur指针用来循环，但是popback之后
                                         tail指针还是无法回到前一个的，所以这种方式错误	                                   
	{
		_head->_next = new Node(data);
		_tail = _head;
	}*/
	else
	{
		_tail->_next = new Node(data);
		_tail = _tail->_next;
	}
}

Datatype List::PopBack()
{
	Node* cur = _head;

	if (NULL == _head)   //指针为空
		return 0;
	else if (NULL == _head->_next)  //指针只有一个元素
	{
		int num = _head->_data;
		delete _head;
		_head = _tail = NULL;
		return num;
	}
	else
	{
		int num;
		while (cur->_next->_next)
		{
			cur = cur->_next;
		}
		_tail = cur;
		num = cur->_next->_data;
		delete cur->_next;
		cur->_next = NULL;
		return num;
	}

}

void List:: PushFront(Datatype data)
{
	if (NULL == _head)
	{
		_head = new Node(data);
		_tail = _head;
	}
	else
	{
		Node* cur = _head;
		_head = new Node(data);
		_head->_next = cur;
	}
}

Datatype List:: PopFront()
{
	if (NULL == _head)    //没有节点
	{
		return 0;
	}
	else if (NULL == _head->_next)    //只有一个节点
	{
		int num = _head->_data;        //这里和Popback中只有一个节点的处理是一样的，代码直接拿下来
		delete _head;
		_head = _tail = NULL;
		return num;
	}
	else
	{
		int num = _head->_data;
		Node*del = _head;
		_head = _head->_next;
		delete del;
		return num;
	}
}

List& List::operator=(List l)
{
	swap(_head,l._head);            //现代写法
	swap(_tail, l._tail);
	return *this;
}

void Test()
{
	List l1;
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(3);
	l1.PushBack(4);
	l1.Show();
	List l2(l1);
	l2.Show();
	List l3;
	l3.Show();
	l3 = l2;
	l3.Show();
	/*cout << l1.PopBack() << endl;
	l1.Show();
	l1.PopBack();
	l1.PopBack();
	l1.Show();
	l1.PopBack();
	l1.Show();
	l1.PushFront(9);
	l1.PushFront(8);
	l1.Show();
	cout << l1.PopFront() << endl;
	l1.Show();*/
}
