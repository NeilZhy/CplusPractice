#include<iostream>
using namespace std;
#include"AutoPtr.h"

void F1()
{
	int* p = new int(10);
	AutoPtr<int> ptr(p);   //这里我用Autoptr去管理我这个指针，当发生异常程序跳转的时候，出了作用域，就会自动的执行我们的
				//析构函数，然后把动态开辟的空间释放掉
		//这里调用的是构造函数

	//功能一：解引用显示内容，我们想让我们自己的智能指针想原生指针一样，使用*p就能得到指针所指向的内容，我们可以重载*
	cout << *p << endl;
	cout << *ptr << endl;
	*p = 20;
	*ptr = 30;
	cout << *p << endl; 

	//功能二：我们一般在使用指针的时候会使用->的形式进行一些操作，当然这一班是针对指向结构体的指针，指向结构体的一个成员变量的时候
	
	AutoPtr<AA> pA(new AA);
	pA->_a = 100;
	cout << pA->_a;
	cout << endl;

	//功能三：我们还需要使用拷贝构造函数，但是这里的拷贝构造函数是值拷贝的形式，所以在最后释放的时候会出现两次释放，
	//导致程序崩溃，所以这里我们需要重写他




	//这里有一个错误，不知道为什么编译通不过
	AutoPtr<int> p1(ptr);   //这里应该是用一个对象去初始化另外一个对象，所以括号里面的内容应该是ptr，ptr是一个对象
					//这里调用的应该是一个拷贝构造函数
	


	//我们上面的int* p是原生指针的使用形式，我们这里也可以使用原生指针的使用形式，可以进行如下的操作
	AutoPtr<int> pp(new int(10));
	char* p0 = new char[0x7fffffff];   //这里就出现了 一个异常，然后程序跳转，下面的程序不在执行，因为我们这里开辟的数组的空间太大
				//但是，虽然程序跳转了 ，但是刚刚new了一个新的空间，我们因为这里的异常，没有delete掉，所以这个程序还是有问题的
					//这个时候，智能指针应运而生
	cout << "delete p" << endl;
	cout << "delete[]" << endl;
	delete p;
	delete[] p0;
}

void F2()
{
	try       //正常使用下面的代码程序，下面的代码有什么问题的话，会被catch捕获到
	{
		F1();
	}
	catch (const exception e)   //捕获到了try里面的代码，然后进行下面的操作
	{
		cout << e.what()<< endl;
		//throw;   //他可以进行操作，可以不操作，直接扔出去
	}
}

int main()
{
	F2();
	/*try
	{
		F2();
	}
	catch (const exception e)
	{
		cout << e.what() << endl;
	}*/
	return 0;
}