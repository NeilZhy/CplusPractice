#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class A
{
public:
	virtual void Fun1();
public:
	int _a;
};

class B:virtual public A
{
public:
	virtual void Fun1();
public:
	int _b;
};

class C :virtual public A
{
public:
	virtual void Fun1();
public:
	int _c;
};

class D:public B,public C
{
public:
	void Fun1();
public:
	int _d;
};

void A::Fun1()
{
	cout << "A Fun1" << endl;
}

void B::Fun1()
{
	cout << "B Fun1" << endl;
}

void C::Fun1()
{
	cout << "C Fun1" << endl;
}

void D::Fun1()
{
	cout << "D Fun1" << endl;
}


typedef  int(*V_FUNC)();      //定义了一个函数指针

void ShowPoint(int *s)
{
	while ((*s) != 0)           //虚表当中的最后一个位置放置了一个0，作为结束的标识，所以这里循环结束的标识是*s ！= 0
	{
		printf("%p\n", s);
		V_FUNC f = (V_FUNC)*s;      //这里传过来的地址时一个个虚函数的地址，然后我们想得到的是一个个函数，
		//所以这里要对它解引用，得到就是这个函数的函数指针

		f();                       //调用这个函数
		s++;
	}
}

int main()
{
	D d;
	ShowPoint((int*)(*((int*)&d)));
	cout << sizeof(d)<<endl;
	return 0;
}