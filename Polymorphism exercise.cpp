#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//
//class A
//{
//public:
//	 virtual ~A()
//	{
//		cout << "~A()" << endl;
//	}
//	void ShowA();
//public:
//	int _a;
//
//};
//
//class B :public A
//{
//public:
//	void ShowA();         //�γ������أ���Ϊ���ǣ���д���������Ǹ�����virtual������ֵ....����û��virtual
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//public:
//	int _b;
//};
//
//void A::ShowA()
//{
//	cout << "ShowA" << endl;
//}
//
//void B::ShowA()
//{
//	cout << "ShowB" << endl;
//}
//
//int main()
//{
//	///*A a;
//	//B b;*/
//	///*a.ShowA();
//	//b.ShowA();*/
//	//A* pa = new(A);
//	////B* pb = new(B);     //��������ַ�ʽ�Ļ���û������ģ����ȵ���A��������������pb�е�A�����ͷŵ���Ȼ�����B��������
//	//						//��B�����ͷŵ�
//	//A* pb = new(B);         //����������Ϊû���γɶ�̬���������ָ����ָ�����ָ�룬��ֻ�ͷ��˸���Ķ���
//	//						//����û���ͷ�����Ķ�����������Ӧ�������������ĸ����������virtual���������γɶ�̬
//
//	//delete pa;
//	//delete pb;
//
//	return 0;
//}



class Base1
{
public:
	virtual void fun1();
	virtual void fun2();
public:
	int _b1;
};

class Base2
{
public:
	virtual void fun1();
public:
	int _b2;
};



class Deriv :public Base1,public Base2
{
public:
	void fun1();
	void fun2();
public:
	int _d;
};



void Base1::fun1()
{
	cout << "Base1fun1" << endl;
}
void Base1::fun2()
{
	cout << "Base1fun2" << endl;
}

void Base2::fun1()
{
	cout << "Base2fun1" << endl;
}

void Deriv::fun1()
{
	cout << "Derivfun1" << endl;
}

void Deriv::fun2()
{
	cout << "Derivfun2" << endl;
}

typedef  int(*V_FUNC)();      //������һ������ָ��

//void ShowPoint(int *s)
//{
//	while ((*s) != 0)           //����е����һ��λ�÷�����һ��0����Ϊ�����ı�ʶ����������ѭ�������ı�ʶ��*s ��= 0
//	{
//		printf("%p\n", s);
//		V_FUNC f = (V_FUNC)*s;      //���ﴫ�����ĵ�ַʱһ�����麯���ĵ�ַ��Ȼ��������õ�����һ����������
//		//��������Ҫ���������ã��õ�������������ĺ���ָ��
//
//		f();                       //�����������
//		s++;
//	}
//}

typedef int(*V_FUNC)();  //������һ������ָ��

void PrintTable(int* vTable)
{
	printf("vTable : 0x%p\n", vTable);
	for (size_t i = 0; vTable[i] != 0; i++)
	{
		V_FUNC f = (V_FUNC)vTable[i];      //����ǿת��V_FUNC������������������V_FUNC
		f();
	}
	cout << endl;
}

int main()
{
	Base1 bb1;
	Deriv dd1;
	PrintTable((int*)(*((int*)&dd1)));      //�����ڵ��õ�ʱ������ȡ��bb1�ĵ�ַ����Ϊbb1�д�ŵ������ָ�뻹��������һЩ����
											//��Ϊ������ȡ��bb1�����ָ�룬���������ǣ�(int*)&bb1)�����½����þ͵õ�
											//�����ָ������ݣ��������������ʵ��һ�����飬�����з��õ����麯���ĵ�ַ
											//�����ڰ����ǿת��int*�������Ļ�����ÿ�ξ͵õ�һ���麯���ĵ�ַ��
	cout<<sizeof(dd1)<<endl;     //����˵������Ľ��Ӧ���������ģ����ȷ�����һ��Base1�Ķ���������һ�����ָ�룬
								//ָ��һ���������з�����Base1��fun1�ĺ���ָ�룬Ȼ�������Deriv��fun1�ĺ���ָ��
								//���ŷ�����Base1�ĳ�Ա��������֮���ǰ˸��ֽ�
								//Ȼ�������һ��Base2��һ������������һ�����ָ�루ָ��һ���������з�����Base2��fun1��
								//��һ��Base2�ĳ�Ա����������֮�������ǰ˸��ֽ�
								//������Deriv�ĳ�Ա���������������20���ֽڣ��Ͳ��ԵĽ�����
	return 0;

}