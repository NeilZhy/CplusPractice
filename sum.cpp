#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<windows.h>
using namespace std;

int add(int a, int b)
{
	int c;
	c = a + b;
	return c;
}

int main()
{
	int x, y, sum;
	cout << "enter two num"<<'\n';
	cin >> x;
	cin >> y;
	sum = add(x,y);
	cout << "Tish sum is "<<sum<<'\n';
	system("pause");
	return 0;

}