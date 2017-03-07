#include<iostream>
using namespace std;

class Rectangle
{
private:
	int _length;
	int _width;
public:
	Rectangle(int len = 10, int wid = 10); //���캯��
	Rectangle(const Rectangle &p);  //�������캯��
	void disp();
};

Rectangle::Rectangle(int len, int wid)  //���캯��
{
	_length = len;
	_width = wid;
	cout << "using normal constructor" << endl;
}

Rectangle::Rectangle(const Rectangle &p)  //�������캯��
{
	_length = 2 * p._length;
	_width = 2 * p._width;
	cout << "using copy constructor" << endl;
}

void Rectangle::disp()
{
	cout << _length << " " << _width << endl;
}

void fun1(Rectangle p)
{
	p.disp();
}

Rectangle fun2()
{
	Rectangle p4(10,30);     //�����������ͨ�Ĺ��캯��
	return p4;             //���ﷵ�ص�һ��Rectangle�Ķ������ǻ�ʹ��p2 = fun2();ȥ�������ķ���ֵ�����������൱�ڸ�p2����һ���������캯��
}

int main()
{
	Rectangle p1(30, 40);  //������p1�����ù��캯��
	p1.disp();
	Rectangle p2(p1);   //���ÿ������캯����p1�����ֵȫ�����Ƹ�p2(���1)
	p2.disp();
	Rectangle p3 = p1;  //���ÿ������캯������p1��ֵ���Ƹ�p3(���1)
	p3.disp();
	fun1(p1);   //���ʱ�������p1��һ�����ã�Ȼ������Rectangle�Ŀ������캯��
	            //����Ӧ��˼����һ��������ǣ�Ϊʲô���õ���Rectangle�Ŀ������캯���������ҵ�һ���²��ǣ�ֱ�Ӵ�һ�������ʱ�򣬾���������һ���ˣ�������һ��ת��֮���
	            //���ܾͰѶ���ת���ɶ����һ�������˰�
	p1.disp();
	p2 = fun2();   //�����ķ���ֵ�Ƕ������ڵ�����������ÿ������캯��
	p2.disp();
	system("pause");
	return 0;
}
