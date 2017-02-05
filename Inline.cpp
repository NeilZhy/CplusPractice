#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<windows.h>

using namespace std;

inline double circle(double r)
{
	return 3.14*r*r;
}

int main()
{
	int r = 0;
	for (r = 1; r <= 3; r++)
	{
		cout << "r=" << r << "  area = " << circle(r) << endl;
	}
	system("pause");
	return 0;
}