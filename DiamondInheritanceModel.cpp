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


typedef  int(*V_FUNC)();      //������һ������ָ��

void ShowPoint(int *s)
{
	while ((*s) != 0)           //����е����һ��λ�÷�����һ��0����Ϊ�����ı�ʶ����������ѭ�������ı�ʶ��*s ��= 0
	{
		printf("%p\n", s);
		V_FUNC f = (V_FUNC)*s;      //���ﴫ�����ĵ�ַʱһ�����麯���ĵ�ַ��Ȼ��������õ�����һ����������
		//��������Ҫ���������ã��õ�������������ĺ���ָ��

		f();                       //�����������
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