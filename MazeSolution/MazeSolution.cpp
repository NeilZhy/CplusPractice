#include<iostream>
using namespace std;

#include"Maze.h"


void TestSStack()
{
	staticStack<int> s;
	s.PushBack(1);
	s.PushBack(2);
	s.PushBack(3);
	s.PushBack(4);
	s.Show();
	s.PopBack();
	s.Show();
	cout << s.Top() << endl;
}

void TestStack()
{
	Stack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);
	s.Push(6);
	s.Show();
	s.Pop();
	s.Show();
}

void TestMaze()
{
	int maze[5][5] = { { 1, 1, 1, 1, 1 }, { 0, 0, 1, 1, 1 }, { 1, 0, 0, 0, 1 }, { 1, 0, 1, 1, 1 }, {1,0,1,1,1} };
	Maze<> m(maze);
	m.Show();
	m.GetPath();
	m.Show();
}


	

int main()
{
	//TestSStack();
	//TestStack();
	TestMaze();
	return 0;
}