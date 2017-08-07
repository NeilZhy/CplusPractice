#define _CRT_SECURE_NO_WARNINGS 1
#include"hashtable.h"

int main()
{
	HashTable<int, int> a;
	pair<int, int> p(5,6);
	pair<int, int> p1(15,7);
	pair<int, int> p2(25, 6);
	pair<int, int> p3(85, 6);
	pair<int, int> p4(75, 6);
	pair<int, int> p5(95, 6);
	pair<int, int> p6(2, 6);
	pair<int, int> p7(4, 6);
	a.Insert(p);
	a.Insert(p1);
	a.Insert(p2);
	a.Insert(p3);
	a.Insert(p4);
	a.Insert(p5);
	a.Insert(p6);
	a.Insert(p7);
	cout << a.Search(p);
	

	return 0;
}