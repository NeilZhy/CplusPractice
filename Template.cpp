#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class A
//{
//
//};

template <typename T>
bool IsEqual(T l, T r)
{
	return l == r;
}

template <typename T,typename T2>
bool IsEqual(T l, T2 r)
{
	return l == r;
}



int main()
{
	cout << IsEqual(1, 2) << endl;
	cout << IsEqual(1.2, 1.3) << endl;  //���﷢����ģ������ݣ����������ҵ��������Σ����ε����Ͳ�һ������ʵ��������
										//�����������Ǳ��������������Զ����ɵ��ڲ飬������ʱ�򣬻ᷢ������ĺ�������
										//IsEqual<double>,��������Ǹ����õĺ�������IsEqual<int>�����������γ�����������
	cout << IsEqual<int>(1, 1.2) << endl;
	return 0;
}