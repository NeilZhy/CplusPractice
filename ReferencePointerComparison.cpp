
#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
	int i = 15;
	int *j1 = &i;
	int &j2 = i;
	cout << "i = " << i << endl;
	cout << "j1 = " << *j1 << endl;
	cout << "j2 = " << j2 << endl;
	system("pause");
	return 0;
}