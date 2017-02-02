#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	void* pc;
	int i = 456;
	char c = 'a';
	pc = &i;
	cout << *(int*)pc<<endl;
	pc = &c;
	cout << *(char*)pc << endl;
	system("pause");
	return 0;
}