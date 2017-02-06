#define _CRT_SECURE_NO_WARNINGS 1

//作用域标识符::编译没有通过
#include<iostream>
#include<windows.h>
using namespace std;

int avara;

int main()
{
	int avara;
	avara = 25;
	::avara = 10;
	cout << "local avar = " << avara << endl;
	cout << "global avar = " << ::avara << endl;
	system("pause");
	return 0;
}