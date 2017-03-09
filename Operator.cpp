#include<iostream>
using namespace std;

class Complex
{
public:
	Complex(double real = 0.0,double imag = 0.0);   //这里在声明的时候可以给赋初值，因为声明的时候没有对这个函数进行调用
	Complex operator+(Complex &c);
	Complex& operator=(Complex &c);    //这里函数的返回值也是我们需要思考的一个问题，就是，返回值可不可以为void，这个题目；来看是美欧影响的
	                                   //但是如果是连等的话就容易出现问题了，这里如果我们调用的时候使用c3 = c2 = c1
	                                   //实际上上面的调用时可以写成下面这个样子的 c3(c2(c1))，这样的话，如果没有返回值，这个c2就没有办法传给c3，这样就没有办法连等了
	Complex& Complex::operator+=(Complex &c);
	void show();
	
private:
	double _real;
	double _imag;
};

Complex::Complex(double real,double imag):     //在定义的 时候不可以给赋初值，这里要进行一个传参的过程，不能给初值
_real(real),
_imag(imag)   
{
	cout << "constructor" << endl;
}



Complex Complex:: operator+(Complex &c)   //注意，在类外定义函数的时候，要把函数的返回值放在最前面
                                          //这里的函数参数实际上还有一个this指针，即Complex Complex::operator+(this,Complex &c)
										   //这个this就是指向本对象的一个指针
{
	Complex tmp;                     //这里调用了一次构造函数
	tmp._real = _real + c._real;
	tmp._imag = _imag + c._imag;
	return tmp;                      //这里没有直接返回tmp，而是复制了一份，然后调用拷贝构造函数将复制的那一份给返回了
}

Complex& Complex::operator=(Complex &c)     //这里注意返回的Complex的一个引用，因为我这里是对本对象进行的操作，并且操作完之后，这个对象还存在
                                              //对于返回值类型是类的对象，还是类的对象的引用问题，如果函数操作完毕之后这个对象还在的话，返回值就是这个对象的一个引用，其他的就是这个对象
{
	if (this != &c)            //防止自己给自己赋值
	{                         
		_real = c._real;       
		_imag = c._imag;
		return *this;
	}
	return *this;
}

Complex& Complex::operator+=(Complex &c)         //+=运算符的重载和=的运算符的重载类似
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