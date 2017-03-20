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
		*_count = 1;
	}

	String(const String& s)
		:_str(s._str)
		, _count(s._count)
	{
		//strcpy(_str,s._str);
		(*_count)++;
	}

	~String()
	{
		if (1 == *_count)
		{
			delete[] _str;
			_str = NULL;
			delete _count;
		}
		else
		{
			(*_count)--;
		}
	}

	char& operator[](int n)
	
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
	s1[1] = 'o';
	s1.Show();
	String s2(s1);
	String s3(s2);

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