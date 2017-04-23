#pragma once
#include<iostream>
using namespace std;
#include<string>

//�쳣ʹ�ò���
void Fun1()
{
	cout << "Fun1()" << endl;
	throw string("Fun1 error");
}

void Fun2()
{
	cout << "Fun2" << endl;
	try			//�������ǽ�����try֮����ô�������е�try�Ͳ���ִ���ˣ�����ֱ����ת��ȥ��һ���쳣ֻ����һ��
	{
		Fun1();
	}
	catch (string e)
	{
		cout << e << endl;
	}

}


//�޸�Exception��ģ��ʵ��һ��һ��new����
//Exception����һ������ѣ�Ȼ���������׳��쳣��ʱ������׳���һ����Ķ���
class Exception
{
public:
	Exception(int errId, const char * errMsg)
		: _errId(errId)
		, _errMsg(errMsg)
	{}
	virtual void What() = 0;   //������һ�����麯��������Ǹ��࣬�����ڸ�����ָ�������ȥʵ��������Ϊ�����кܶ�����������
	/*{
		cout << "errId:" << _errId << endl;
		cout << "errMsg:" << _errMsg << endl;
	}*/
protected:
	int _errId; // ������
	string _errMsg; // ������Ϣ
};

class BadAlloc :public Exception
{
	//class Child :public Test
	//{
	//public:
	//	Child() :Test("hello")            //ָ�����û���ڶ������캯��  
	//	{
	//		printf("child\n");
	//	}
	//};
};





//�쳣��ʹ�ò��Ժ���
void test1()   
{
	try
	{
		Fun2();
		cout << "mainFun try" << endl;    //�������ִ�е�����һ��֮����ΪFun2�����������쳣�������������䲻��ִ�У�
		//���þ䲻��ִ�У�����ֱ����ת����Ӧ��catch����Fun1�����и�throw���� �Ǹ�λ�ÿ�ʼ��ת��
	}
	catch (const string e)    //������������һ��ע�͵��ˣ�ֻ�������catch��int e������˼����˵��û��catch��string���
		//һ��������ô�׳����쳣��û�б��������Ծͳ���ͻ�ҵ�
	{
		//cout << e << endl;
		cout << "catch main" << endl;
		cout << e << endl;     //��ʼû������ͷ�ļ������Դ���

	}
	catch (int e)
	{
		cout << e << endl;
	}
	catch (...)  //������ǲ�֪���쳣�����ͣ�����ʹ��...���в��񣬵������ַ�ʽ���ܵõ�����Ķ���
		//���򲶻񵽵�һ���쳣֮��������쳣�㲻�ٲ���ֱ�ӽ���
	{
		cout << "...����" << endl;
	}

	cout << "main Fun" << endl;  //���������catchִ�����һ��֮�󣬻���ת����һ�����ִ��
}

