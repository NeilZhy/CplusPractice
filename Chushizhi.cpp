#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
	int *p;
	p = new int(99);
	if (!p)
	{
		cout << "error";
		return 1;
	}
	cout << *p << endl;
	delete p;
	system("pause");
	return 0;
}