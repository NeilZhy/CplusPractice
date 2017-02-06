#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
	int *p;
	p = new int;
	if (!p)
	{
		cout << "error" << endl;
		return 1;
	}
	*p = 20;
	cout << *p;
	delete p;
	system("pause");
	return 0;
}