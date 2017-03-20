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
		*_count = 1;           //�������ü���
	}

	String(const String& s)   //����ǿ������캯�����򲻸������¿��ٿռ��ˣ����ʱ��������ָ��ͬһ���ڴ�ռ�
		:_str(s._str)
		, _count(s._count)
	{
		//strcpy(_str,s._str);
		(*_count)++;     //û����һ������ָ������ռ��ʱ�򣬾͸�������һ����ֹ���������ʱ�����������
	}

	~String()
	{
		if (1 == *_count)          //��Ϊ�������ָ����Ŷͬһ���ڴ�ռ䣬����ֻ�е�_count��1��ʱ�򣬲�������������ע���
			                       //������ռ�����ü�����count�ռ䶼��������
		{
			delete[] _str;
			_str = NULL;
			delete _count;
			_count = NULL;
		}
		else                    //�������һ�������ʱ�����count����1����ʹ����һ
		{
			(*_count)--;
		}
	}

	char& operator[](int n)     //����������Ҫ�ı�һ����������ݣ�Ȼ����Ϊ�п��ܶ������ָ��ͬһ���ռ䣬
		                         //���Ҹı�����һ�������ʱ��,���������Ķ��󶼸ı䣬���������뵱���������ʱ�����Ǹ�������󿪱�һ���µĿռ�
	
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