#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;


class String
{
public:
	String(char *s)
		:_str(new char[strlen(s) + 1])     //这里我在一开始写的时候的代码是:_str(s)，然后下面没有实用strcpy这个函数
		                                    //这样做的一个结果就是，我们在析构函数的时候，把静态区中的字符串给释放了，这是错误的
	{
		strcpy(_str,s);
		cout << "构造函数" << endl;
	}

	String(String &s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str,s._str);
		cout << "拷贝构造函数" << endl;
	}

	/*String(String s)
		:_str(new char[strlen(s._str) + 1])
	{
		
		cout << "拷贝构造函数" << endl;
	}*/

	String()
		:_str(new char[1]) 
	{
		cout << "参数为空的构造函数" << endl;
		*_str = '\0';                      //这里_str是一个指针，我们不能把一个结束字符直接给这个指针变量
		                                   //一开始的时候我的代码是str = '\0's
	}

	~String()
	{
		cout << "析构函数" << endl;
		delete[] _str;
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
	cout << s3 << endl;
	String s4(s1);
	cout << s4 << endl;

	return 0;
	
}