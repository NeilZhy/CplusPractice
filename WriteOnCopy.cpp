#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class String
{
public:
	String(char* s = "")
		:_str(new char[strlen(s) + 1])
		, _count(new int)
	{
		strcpy(_str,s);
		*_count = 1;           //利用引用计数
	}

	String(const String& s)   //如果是拷贝构造函数，则不给它重新开辟空间了，这个时候多个对象指向同一个内存空间
		:_str(s._str)
		, _count(s._count)
	{
		//strcpy(_str,s._str);
		(*_count)++;     //没当有一个对象指向这个空间的时候，就给计数加一，防止最后析构的时候多析构几次
	}

	~String()
	{
		if (1 == *_count)          //因为多个对象指向了哦同一个内存空间，所以只有当_count是1的时候，才析构它，这里注意把
			                       //把数组空间和引用计数的count空间都给析构了
		{
			delete[] _str;
			_str = NULL;
			delete _count;
			_count = NULL;
		}
		else                    //如果析构一个对象的时候，这个count不是1，就使它减一
		{
			(*_count)--;
		}
	}

	char& operator[](int n)     //这里我们需要改变一个对象的内容，然后因为有可能多个对象指向同一个空间，
		                         //当我改变其中一个对象的时候,不想其他的对象都改变，所以这里想当这种情况的时候我们给这个对象开辟一个新的空间
	
	{
		if ((*_count) != 1)
		{
			char* ss;
			ss = _str;
			//strcpy(ss,_str);
			(*_count)--;
			_str = new char[strlen(_str) + 1];
			strcpy(_str, ss);
			_count = new int;
		}
		(*_count) = 1;
		return _str[n];
	}

	String& operator=(String& s)

	{
		_str = s._str;
		_count = s._count;
		(*_count)++;
		return *this;
	}

	void Show()
	{
		cout << _str << endl;
	}

private:
	char* _str;
	int* _count;
};

int main()
{
	String s1 = "hello";
	String s2(s1);
	s2.Show();
	String s3(s2);
	s3.Show();
	s1[1] = 'o';
	s1.Show();
	String s4;
	s4.Show();
	s4 = s3;
	s4.Show();
	

	/*s1.Show();
	String s2(s1);
	s2.Show();
	String s3(s2);
	s3[1] = 'o';
	s3.Show();
	s2[1] = 'o';*/

	//system("pause");
	return 0;
}