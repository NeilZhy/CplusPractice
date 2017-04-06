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
	cout << IsEqual(1.2, 1.3) << endl;  //这里发生了模板的推演，就是这里我调用了两次，两次的类型不一样，其实是生成了
										//两个函数，是编译器根据类型自动生成的在查，看汇编的时候，会发现这里的函数名是
										//IsEqual<double>,而上面的那个调用的函数名是IsEqual<int>所以这里是形成了两个函数
	cout << IsEqual<int>(1, 1.2) << endl;
	return 0;
}