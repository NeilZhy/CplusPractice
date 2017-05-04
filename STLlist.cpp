#include<iostream>
using namespace std;
#include"List.h"
#include<vector>
#include<list>


//部分内容没有写完整，明天再补充

//测试vector，顺序表
void TestVector()
{
	vector<int> Seq;    //构造函数
	vector<int>::iterator it = Seq.begin();
	cout << *it;
}

void TestList()
{
	list<int> L;   //list是一个模板类，是STL这个标准模板类库里面实现好的东西。这里我们实例化了一个链表
	L.push_back(1);   //调用成员函数，往链表里面添加了一些东西
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	L.push_back(5);
	L.push_back(6);
	list<int>::iterator it = L.begin();   //iterator是一个模板类，是一个迭代器，简单理解是用来指向L这个链表里面的一个一个
			//节点的，然后我们要对这个迭代器赋初值，就是L.begin()，是L的一个成员函数
			//iterator是list里面的一个typedef的一个类型
	//cout << *it;
	for (; it != L.end();it++)    //L是一个双向有头的循环链表，底层实现的时候，这个end就是那个头节点
	{
		cout << *it << " ";
		//*it = 10;
	}
	cout << endl;
	for (it = L.begin(); it != L.end(); it++)    //
	{
		cout << *it << " ";    //这里我们定义的时候，it是一个普通迭代器，可以执行读写操作
	}

	list<int>::const_iterator cit = L.begin();
	for (cit = L.begin(); cit != L.end(); cit++)    //
	{
		//*cit = 1;    //这里是一个const的迭代器，所以我们不能通过这样的方式去修改它的值
	}

	list<int>::reverse_iterator rit = L.rbegin();   //注意这里必须是rbegin
	for (; rit != L.rend(); rit++)    //
	{
		cout << *rit<<" ";
	}

	//补充说明，这里的链表是左臂右开的，意思就是说，我们实现的是一个双向有头的循环链表，然后那个头结点是空的

}


void TestMyList()
{
	List<int> L;
	L.PushBack(1);
	L.PushBack(2);
	L.PushBack(3);
	L.PushBack(4);
	L.Show();
	L.PopBack();
	L.Show();
	L.Insert(L.Find(1),0);
	L.Show();
	L.PushBack(5);
	L.Show();
	L.Erase(L.Find(5));
	L.Show();
	L.PopBack();
	L.Popfront();
	L.Show();
	//cout << *(L.Find(1)) << endl;
	/*L.Clear();
	L.Show();*/





	//Iterator<List<int>> it = L.Begin();   //我认为这一个是正确的使用方式
	//List<int>::Iterator it = L.Begin();     //这里我一开始使用的时候，是尝试使用Iterator<int>的类似的形式，但是这样的做法是
	//		//错误的，因为我开始的时候定义的一个类是__Iterator,但是我的Iterator是在类List中使用typedef定义的，所以它的使用
	//		//方式应该是List<int>::Iterator
	///*cout << *it << endl;
	//cout << *(++it) << endl;
	//cout << *(it++) << endl; 
	//cout << *(--it) << endl;
	//cout << *(it--) << endl;*/
	//const List<int> l1(L);   //这里我们在使用ConstIterator的时候，要首先由一个const的链表，或者一般在传参的时候，
	//	//比如写一个print链表的一个函数，需要传递的参数是一个const的对象，函数原型可以这样写void Pritnf(const List<int> l)
	//List<int>::ConstIterator it1 = l1.Begin();
	//cout <<"ConstIterator  "<<*it1 << endl;

	//List<AA> LL;
	//LL.PushBack(AA());
	//LL.PushBack(AA());
	//LL.PushBack(AA());
	//List<AA>::Iterator itAA = LL.Begin();
	//cout<<itAA->_a;

}

int main()
{

	//Show();
	//TestVector();
	///*TestList*/();
	TestMyList();
	return 0;
}