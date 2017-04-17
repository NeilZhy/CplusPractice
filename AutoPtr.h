#pragma once

//鉴于主函数中的异常处理导致的程序跳转，有可能有的动态开辟的空间不能及时的释放掉，还有就是调用函数的时候，因为一些逻辑处理
//导致程序的其他跳转，在一些动态开辟的空间没有释放的时候，本函数就结束掉了，这导致内存泄漏，所以我们想要使用下面的只能指针

//我们在主函数中就可以使用一个对象去管理我们的指针
template<typename T>
class AutoPtr
{
public:
	AutoPtr(T* p)   
		:_ptr(p)
	{}
	AutoPtr(AutoPtr<T>& p)   //这里我们不使用深拷贝，原因是我们在使用指针的时候，两个指针指向同一个空间的时候是可以同时
				//对这个空间进行改变的，就是一个指针指向的内容改变了之后，我们的另一个指针指向的这个空间也改变了
					//所以这里只能使用浅拷贝，我们想要使用的是引用计数进行浅拷贝，当计数的结果为0的时候，我们才释放一次
					//但是历史的做法是没有使用引用计数，而是使用的管理权转移，即是只有一个指针维护这个空间
					//一开始的时候，这里的拷贝拷贝构造函数写错了，我写成了AutoPtr(const T& p) 
	{
		_ptr = p._ptr;
		p._ptr = NULL;
	}
	~AutoPtr()
	{
		cout << "delete _ptr" << endl;
		delete _ptr;
	}
	T& operator*()      //这里返回值是一个引用，因为如果返回值是一个T的话，这里返回的实际上是一个临时对象，虽然我们能够通过
					//cout<<的形式去访问他，但是我们不能通过*p的形式去改变它，所以我们这里返回值是一个引用
	{
		return *_ptr;
	}

	T* operator->()    //相当于p.operator()->->_a;这里还有一个问题就是，如果我们开辟的是一个int的变量的话，这里->的重载就是多余的
	{
		return _ptr;
	}

protected:
	T* _ptr;
};

//防止拷贝，强制它不能拷贝
template<typename T>
class ScopdePtr
{
protected:
	ScopdePtr()
	{}
	ScopdePtr(ScopdePtr<T>& p);  //这里我们使用的是值定义不声明，甚至让这个函数的属性是protected或者是private
protected:
	T* _ptr;

};

class AA
{
public:
	int _a;
	int _b;
};