#include<iostream>
using namespace std;

class Rectangle
{
private:
	int _length;
	int _width;
public:
	Rectangle(int len = 10, int wid = 10); //构造函数
	Rectangle(const Rectangle &p);  //拷贝构造函数
	void disp();
};

Rectangle::Rectangle(int len, int wid)  //构造函数
{
	_length = len;
	_width = wid;
	cout << "using normal constructor" << endl;
}

Rectangle::Rectangle(const Rectangle &p)  //拷贝构造函数
{
	_length = 2 * p._length;
	_width = 2 * p._width;
	cout << "using copy constructor" << endl;
}

void Rectangle::disp()
{
	cout << _length << " " << _width << endl;
}

void fun1(Rectangle p)
{
	p.disp();
}

Rectangle fun2()
{
	Rectangle p4(10,30);     //这里调用了普通的构造函数
	return p4;             //这里返回的一个Rectangle的对象，我们会使用p2 = fun2();去接受他的返回值，所以这里相当于给p2用了一个拷贝构造函数
}

int main()
{
	Rectangle p1(30, 40);  //定义了p1，调用构造函数
	p1.disp();
	Rectangle p2(p1);   //调用拷贝构造函数把p1里面的值全部复制给p2(情况1)
	p2.disp();
	Rectangle p3 = p1;  //调用拷贝构造函数，把p1的值复制给p3(情况1)
	p3.disp();
	fun1(p1);   //这个时候传入的是p1的一份引用，然后会调用Rectangle的拷贝构造函数
	            //这里应该思考的一个问题就是，为什么调用的是Rectangle的拷贝构造函数，这里我的一个猜测是，直接传一个对象的时候，就像传数组名一样了，发生了一个转换之类的
	            //可能就把对象转换成对象的一个引用了吧
	p1.disp();
	p2 = fun2();   //函数的返回值是对象，属于第三种情况调用拷贝构造函数
	p2.disp();
	system("pause");
	return 0;
}
