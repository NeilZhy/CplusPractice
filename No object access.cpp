#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class A
{
public:
	void Show()
	{
		printf("%p",this);          //当我们外面的指针指向NULL的时候，这里打印的结果是0，我们知道了这里是通过this指针来调用函数的
		//cout << "Show()  " << endl;
		//cout << _a << endl;    如果加上这一句程序就会出错，因为这里我们访问了对象的内存空间，所以编译不过
	}
protected:
	int _a;

};

int main()
{
	A a;
	A* p = NULL;   
	p->Show();    //无对象调用函数，这里实际上是传递一个地址，这里我们没有访问对象的空间，所以这里不会出错
	return 0;
}