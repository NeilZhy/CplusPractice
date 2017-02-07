
#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
	int i = 10;
	int &j = i;
	i = 30;
	cout << "i = " << i << " j = " << j << endl;
	j = 80;
	cout << "i = " << i << " j = " << j << endl;
	system("pause");
	return 0;
}