#define _CRT_SECURE_NO_WARNINGS 1
//带有默认值参数的函数

#include<iostream>
#include<windows.h>
using namespace std;

void init(int x = 5,int y = 10)
{
	cout << "x: " << x << "  " << "y:  " << y << endl;
}

int main()
{
	init(100,50);
	init(25);
	init();
	system("pause");
	return 0;
}