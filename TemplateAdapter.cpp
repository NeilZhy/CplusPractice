#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"TemplateAdapter.h"
using namespace std;

void Test1()
{
	List<int> s;
	s.PushBack(1);
	s.PushBack(2);
	s.PopBack();
	s.PushFront(0);
	s.PopBack();
	s.PopBack();
	s.PushFront(0);
	s.PushFront(0);
	s.PopFront();
	s.PopFront();
	s.Show();

}

void StackTest()
{
	Stack<int, List<int>> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Pop();
	s.Pop();
	s.Pop();
	s.Show();
}

void QueueTest()
{
	Queue<int, List<int>> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Pop();
	s.Pop();
	s.Pop();
	s.Show();
}



int main()
{

	//Test1();
	//StackTest();
	QueueTest();
	return 0;
}