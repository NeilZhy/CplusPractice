#define _CRT_SECURE_NO_WARNINGS 1 
//内联函数和宏函数的比较
#include<iostream>
#include<windows.h>
using namespace std;

//宏函数可能会得到意想不到的结果
//#define doub(x) x*2
//在接下来调用的时候，如果传递的参数是1+2，结果是5而不是我们下你给要的6

inline int doub(int x)
{
	return x * 2;
}

int main()
{
	int i = 0;
	for (i = 1; i <= 3; i++)
	{
		cout << "i =" << i << "doubled is  " << doub(i) << endl;
	}
	cout << "doub(1+2) is " << doub(1 + 2) << endl;
	system("pause");
	return 0;
}