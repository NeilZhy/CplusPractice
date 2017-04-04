#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//
//class A
//{
//public:
//	 virtual ~A()
//	{
//		cout << "~A()" << endl;
//	}
//	void ShowA();
//public:
//	int _a;
//
//};
//
//class B :public A
//{
//public:
//	void ShowA();         //形成了隐藏，因为覆盖（重写）的条件是父类有virtual，返回值....这里没有virtual
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//public:
//	int _b;
//};
//
//void A::ShowA()
//{
//	cout << "ShowA" << endl;
//}
//
//void B::ShowA()
//{
//	cout << "ShowB" << endl;
//}
//
//int main()
//{
//	///*A a;
//	//B b;*/
//	///*a.ShowA();
//	//b.ShowA();*/
//	//A* pa = new(A);
//	////B* pb = new(B);     //如果是这种方式的话是没有问题的，首先调用A的析构函数，把pb中的A对象释放掉，然后调用B析构函数
//	//						//把B对象释放掉
//	//A* pb = new(B);         //但是这里因为没有形成多态，所以这个指针是指向父类的指针，它只释放了父类的对象
//	//						//但是没有释放子类的对象，所以这里应该在析构函数的父类里面加上virtual，让他们形成多态
//
//	//delete pa;
//	//delete pb;
//
//	return 0;
//}



class Base1
{
public:
	virtual void fun1();
	virtual void fun2();
public:
	int _b1;
};

class Base2
{
public:
	virtual void fun1();
public:
	int _b2;
};



class Deriv :public Base1,public Base2
{
public:
	void fun1();
	void fun2();
public:
	int _d;
};



void Base1::fun1()
{
	cout << "Base1fun1" << endl;
}
void Base1::fun2()
{
	cout << "Base1fun2" << endl;
}

void Base2::fun1()
{
	cout << "Base2fun1" << endl;
}

void Deriv::fun1()
{
	cout << "Derivfun1" << endl;
}

void Deriv::fun2()
{
	cout << "Derivfun2" << endl;
}

typedef  int(*V_FUNC)();      //定义了一个函数指针

//void ShowPoint(int *s)
//{
//	while ((*s) != 0)           //虚表当中的最后一个位置放置了一个0，作为结束的标识，所以这里循环结束的标识是*s ！= 0
//	{
//		printf("%p\n", s);
//		V_FUNC f = (V_FUNC)*s;      //这里传过来的地址时一个个虚函数的地址，然后我们想得到的是一个个函数，
//		//所以这里要对它解引用，得到就是这个函数的函数指针
//
//		f();                       //调用这个函数
//		s++;
//	}
//}

typedef int(*V_FUNC)();  //定义了一个函数指针

void PrintTable(int* vTable)
{
	printf("vTable : 0x%p\n", vTable);
	for (size_t i = 0; vTable[i] != 0; i++)
	{
		V_FUNC f = (V_FUNC)vTable[i];      //这里强转成V_FUNC就是这个括号里面加上V_FUNC
		f();
	}
	cout << endl;
}

int main()
{
	Base1 bb1;
	Deriv dd1;
	PrintTable((int*)(*((int*)&dd1)));      //这里在调用的时候，首先取到bb1的地址，因为bb1中存放的是虚表指针还有其他的一些变量
											//因为我们想取得bb1的虚表指针，所以这里是（(int*)&bb1)，接下解引用就得到
											//虚表所指向的内容，这个内容里面其实是一个数组，数组中放置的是虚函数的地址
											//我们在把这个强转成int*，这样的话我们每次就得到一个虚函数的地址了
	cout<<sizeof(dd1)<<endl;     //按理说，这里的结果应该是这样的，首先放置了一个Base1的对象，这里有一个虚表指针，
								//指向一个虚表，虚表中放置了Base1的fun1的函数指针，然后放置了Deriv的fun1的函数指针
								//接着放置了Base1的成员变量这样之后是八个字节
								//然后放置了一个Base2的一个对象，里面是一个虚表指针（指向一个虚表，虚表中放置了Base2的fun1）
								//和一个Base2的成员变量，这样之后是又是八个字节
								//最后放置Deriv的成员变量，这样最后是20个字节，和测试的结果相符
	return 0;

}