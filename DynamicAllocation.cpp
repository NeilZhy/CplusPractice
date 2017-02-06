#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
	int *p;
	p = new int;
	*p = 10;
	cout << *p;
	delete p;
	system("pause");
	return 0;
}