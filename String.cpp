#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;


class String
{
public:
	String(const char *s = "")                   //һ��ʼ�������û��Ĭ��ֵ�ģ�Ȼ�������������ε�ʱ����һ��ʲô����������Ҹ������˳�ֵ
		:_str(new char[strlen(s) + 1])     //��������һ��ʼд��ʱ��Ĵ�����:_str(s)��Ȼ������û��ʵ��strcpy�������
		                                    //��������һ��������ǣ�����������������ʱ�򣬰Ѿ�̬���е��ַ������ͷ��ˣ����Ǵ����
	{
		strcpy(_str,s);
		cout << "���캯��" << endl;
	}

	String(const String &s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str,s._str);
		cout << "�������캯��" << endl;
	}

	//String()                           //�������������յĸ�ȥ���������뵽�ڹ��캯����ȥ���Ǹ�������һ����ʼֵ��""������һ����
	//	:_str(new char[1]) 
	//{
	//	cout << "����Ϊ�յĹ��캯��" << endl;
	//	*_str = '\0';                      //����_str��һ��ָ�룬���ǲ��ܰ�һ�������ַ�ֱ�Ӹ����ָ�����
	//	                                   //һ��ʼ��ʱ���ҵĴ�����str = '\0's
	//}

	~String()
	{
		cout << "��������" << endl;
		if (NULL != _str)                    //����һ����һ���жϣ����������ָ����ָ��Ŀռ��Ƿ�Ϊ��
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
