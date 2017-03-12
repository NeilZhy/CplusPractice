#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;


class String
{
public:
	String(const char *s = "")                   //一开始这里参数没有默认值的，然后我想解决不传参的时候是一种什么情况，于是我给它赋了初值
		:_str(new char[strlen(s) + 1])     //这里我在一开始写的时候的代码是:_str(s)，然后下面没有实用strcpy这个函数
		                                    //这样做的一个结果就是，我们在析构函数的时候，把静态区中的字符串给释放了，这是错误的
	{
		strcpy(_str,s);
		cout << "构造函数" << endl;
	}

	String(const String &s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str,s._str);
		cout << "拷贝构造函数" << endl;
	}

	//String()                           //我这里想把这个空的给去掉，于是想到在构造函数中去把那个参数给一个初始值，""，就是一个空
	//	:_str(new char[1]) 
	//{
	//	cout << "参数为空的构造函数" << endl;
	//	*_str = '\0';                      //这里_str是一个指针，我们不能把一个结束字符直接给这个指针变量
	//	                                   //一开始的时候我的代码是str = '\0's
	//}

	~String()
	{
		cout << "析构函数" << endl;
		if (NULL != _str)                    //这里一般有一个判断，来看看这个指针所指向的空间是否为空
		{
			delete[] _str;
		}
		
	}

	friend ostream& operator<< (ostream & stream, String &s);


private:
	char* _str;
};

ostream& operator<< (ostream & stream, String &s)
{
	stream << s._str;
	return stream;
}

int main()
{
	String s1("hello bit");
	cout << s1 << endl;
	String s2;
	cout << s2 << endl;
	String s3(s2);
	//s3 = s1;
	cout << s3 << endl;
	String s4(s1);
	cout << s4 << endl;

	return 0;
	
}
