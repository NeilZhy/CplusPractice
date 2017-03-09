#include<iostream>
using namespace std;

class Complex
{
public:
	Complex(double real = 0.0,double imag = 0.0);   //������������ʱ����Ը�����ֵ����Ϊ������ʱ��û�ж�����������е���
	Complex operator+(Complex &c);
	Complex& operator=(Complex &c);    //���ﺯ���ķ���ֵҲ��������Ҫ˼����һ�����⣬���ǣ�����ֵ�ɲ�����Ϊvoid�������Ŀ����������ŷӰ���
	                                   //������������ȵĻ������׳��������ˣ�����������ǵ��õ�ʱ��ʹ��c3 = c2 = c1
	                                   //ʵ��������ĵ���ʱ����д������������ӵ� c3(c2(c1))�������Ļ������û�з���ֵ�����c2��û�а취����c3��������û�а취������
	Complex& Complex::operator+=(Complex &c);
	void show();
	
private:
	double _real;
	double _imag;
};

Complex::Complex(double real,double imag):     //�ڶ���� ʱ�򲻿��Ը�����ֵ������Ҫ����һ�����εĹ��̣����ܸ���ֵ
_real(real),
_imag(imag)   
{
	cout << "constructor" << endl;
}



Complex Complex:: operator+(Complex &c)   //ע�⣬�����ⶨ�庯����ʱ��Ҫ�Ѻ����ķ���ֵ������ǰ��
                                          //����ĺ�������ʵ���ϻ���һ��thisָ�룬��Complex Complex::operator+(this,Complex &c)
										   //���this����ָ�򱾶����һ��ָ��
{
	Complex tmp;                     //���������һ�ι��캯��
	tmp._real = _real + c._real;
	tmp._imag = _imag + c._imag;
	return tmp;                      //����û��ֱ�ӷ���tmp�����Ǹ�����һ�ݣ�Ȼ����ÿ������캯�������Ƶ���һ�ݸ�������
}

Complex& Complex::operator=(Complex &c)     //����ע�ⷵ�ص�Complex��һ�����ã���Ϊ�������ǶԱ�������еĲ��������Ҳ�����֮��������󻹴���
                                              //���ڷ���ֵ��������Ķ��󣬻�����Ķ�����������⣬��������������֮����������ڵĻ�������ֵ������������һ�����ã������ľ����������
{
	if (this != &c)            //��ֹ�Լ����Լ���ֵ
	{                         
		_real = c._real;       
		_imag = c._imag;
		return *this;
	}
	return *this;
}

Complex& Complex::operator+=(Complex &c)         //+=����������غ�=�����������������
{
	_real = _real + c._real;
	_imag = _imag + c._imag;
	return *this;
}

void Complex::show()
{
	cout << _real << "+" << _imag << "i" << endl;
}

int main()
{
	Complex c0;
	Complex c1(1.1,1.1);
	Complex c2(2.2,2.2);
	Complex c3 = c1 + c2;
	Complex c4 = c3 + c0;
	c0.show();
	c1.show();
	c2.show();
	c3.show();
	c4.show();
	c4 = c0;
	c4.show();
	c0 += c1;
	c1.show();
	system("pause");
	return 0;
}