#define _CRT_SECURE_NO_WARNINGS 1 
//���������ͺ꺯���ıȽ�
#include<iostream>
#include<windows.h>
using namespace std;

//�꺯�����ܻ�õ����벻���Ľ��
//#define doub(x) x*2
//�ڽ��������õ�ʱ��������ݵĲ�����1+2�������5���������������Ҫ��6

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