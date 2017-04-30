#pragma once
#include<iostream>
using namespace std;
#include<string>

//异常使用测试
void Fun1()
{
	cout << "Fun1()" << endl;
	throw string("Fun1 error");
}

void Fun2()
{
	cout << "Fun2" << endl;
	try			//这里我们进行了try之后，那么主函数中的try就不在执行了，而是直接跳转出去，一个异常只捕获一次
	{
		Fun1();
	}
	catch (string e)
	{
		cout << e << endl;
	}

}


//修改Exception，模拟实现一个new函数
//Exception就是一个类而已，然后我们在抛出异常的时候就是抛出的一个类的对象
class Exception
{
public:
	Exception(int errId, const char * errMsg)
		: _errId(errId)
		, _errMsg(errMsg)
	{}
	virtual void What() = 0;   //定义了一个纯虚函数，这个是父类，我们在父类中指定义而不去实现它，因为下面有很多派生的子类
	/*{
		cout << "errId:" << _errId << endl;
		cout << "errMsg:" << _errMsg << endl;
	}*/
protected:
	int _errId; // 错误码
	string _errMsg; // 错误消息
};

class BadAlloc :public Exception
{
public:
	BadAlloc(const char* msg = "") 
		:Exception(1, "BadAlloc")
	{
		_errMsg += msg;
	}
	void What()
	{
		cout << _errId << endl;
		cout << _errMsg << endl;
	}
};

class AA
{
public:
	AA()
	{
		cout << "AA()" << endl;
	}
private:
	char p[0x7fffffff];
};

//模拟实现new函数,这里new实现成一个函数
template<class T>
T* MyNew()
{
	T* p = (T*)malloc(sizeof(T));
	if (NULL == p)
	{
		throw BadAlloc("New Fail");
	}
	//new的定位表达式
	return new(p)T;
}



//异常测试函数
void TestException()
{
	try
	{
		AA* p = MyNew<AA>();
	}
	catch (BadAlloc e)
	{
		e.What();
	}
}





//异常简单使用测试函数
void test1()   
{
	try
	{
		Fun2();
		cout << "mainFun try" << endl;    //这里程序执行到上面一步之后，因为Fun2里面遇到了异常，所以下面的语句不在执行，
		//即该句不在执行，而是直接跳转到对应的catch（在Fun1里面有个throw，从 那个位置开始跳转）
	}
	catch (const string e)    //如果我这里把这一段注释掉了，只有下面的catch（int e），意思就是说，没有catch到string类的
		//一个对象，那么抛出的异常就没有被捕获，所以就程序就会挂掉
	{
		//cout << e << endl;
		cout << "catch main" << endl;
		cout << e << endl;     //开始没有引入头文件，所以错误

	}
	catch (int e)
	{
		cout << e << endl;
	}
	catch (...)  //如果我们不知道异常的类型，可以使用...进行捕获，但是这种方式不能得到具体的对象
		//程序捕获到第一个异常之后，其余的异常便不再捕获，直接结束
	{
		cout << "...捕获" << endl;
	}

	cout << "main Fun" << endl;  //上面的所以catch执行完毕一个之后，会跳转到这一句继续执行
}

