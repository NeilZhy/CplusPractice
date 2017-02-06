#define _CRT_SECURE_NO_WARNINGS 1
//作用域标识符::，全局变量和局部变量
#include<iostream>
#include<windows.h>
using namespace std;

int avar = 10;

int main()
{
	int avar = 0;
	avar = 25;
	cout << "avar = " << avar << endl;
	system("pause");
	return 0;
}