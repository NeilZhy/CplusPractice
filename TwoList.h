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
	ListNode* Find(DataType data);    //����ע���һ��������ǣ�����ֵ����д��Node*��Ȼ���ߵ�������һ���ģ�����������д����
	                                  //����ʵ�ֵ�ʱ����ΪNode���������涨��ģ�����ֵ��������
	void Insert(Node* pos,DataType data); //��������pos��ǰ�����һ������
	void Del();                     //ȫ��ɾ�����൱���������� 
	void Erase(Node* pos);					//���ɾ��
	void Reverse();                //��������

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
	cout << "˳��" << endl;
	while (cur)
	{
		cout << cur->_data << " ";
		tail = cur;                   //Ϊ���������������ӡ��ѭ��������tailָ��ľ������һ���ڵ�
		cur = cur->_next;
	}
	
	cout << endl;
	cout << "����" << endl;
	while (tail)                   //�����ӡ
	{
		cout << tail->_data << " ";
		tail = tail->_prev;
	}
	cout << endl;

}

DataType List:: PopBack()
{
	if (NULL == _head)               //�޽ڵ�
	{
		return 0;
	}
	else if (NULL == _head->_next)   //ֻ��һ���ڵ�
	{
		int num = _head->_data;
		delete _head;
		_head =_tail = NULL;
		return num;
	}
	else                        //����ڵ�
	{
		Node* cur = _head;
		while (cur->_next->_next)
		{
			cur = cur->_next;
		}
		int num = cur->_next->_data;
		delete cur->_next;
		cur->_next = NULL;
		_tail = cur;     //����֮ǰû�иı�_tail��ָ�򣬵�������ĳ������
		return num;
	}
}

//ǰ�壬��������������нڵ㣬����һ���ڵ�
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
	assert(NULL != pos);    //����ָ���ʱ���ʹ�ö���
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
	if (_head == pos)      //ɾ������ͷ���
	{
		PopFront();
		//return;
	}
	else if (_tail == pos)  //ɾ������β�ڵ�
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

//��һ������swap��������ֵ
//void List:: Reverse()
//{
//	Node* head = _head;
//	Node* tail = _tail;
//	//��������ż����,����ͬʱָ��ͷ��������Ϊ��
//	while ((head != tail) && (head != tail) && (head->_prev != tail))   //��һ���ж������Ƿ�Ϊ�գ���һ���ж�����������������������ж�ż�����������
//	{
//		swap(head->_data,tail->_data);
//		head = head->_next;
//		tail = tail->_prev;
//	}
//}

//����������ָ��
void List::Reverse()
{
	Node* prev1 = _head;    //һ��ʼ���ſ����ĸ�ָ�룬һ��ָ��ǰ��һ��ָ���Ȼ������̫�鷳��
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