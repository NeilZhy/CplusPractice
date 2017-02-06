#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<windows.h>
using namespace std;

struct person
{
	char name[20];
	int age;
};

int main()
{
	person *p;
	p = new person;
	strcpy(p->name,"Wang Fun");
	p->age = 23;
	cout << p->name << " " << endl << p->age << endl;
	delete p;
	system("pause");
	return 0;
}