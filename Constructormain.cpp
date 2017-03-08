#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Date
{
private:
	int _year;
	int _month;
	int _day;
public:
	Date(int y,int m,int d);
	Date(const Date& d);
	void setDate(int y,int m,int d);
	void showDate();
};

Date::Date(int y = 2017, int m = 3, int d = 8) :_year(y), _month(m), _day(d)
{
	cout << "Constcuting ..." << endl;
}

Date::Date(const Date &d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	cout << "拷贝构造函数" << endl;    
}

void Date::setDate(int y, int m, int d)
{
	_year = y;
	_month = m;
	_day = d;
}

inline void Date::showDate()
{
	cout << _year << "." << _month << "." << _day << endl;
}

Date newSetdate(Date &d)
{
	Date tmp;                   //这里函数被调用，首先调用构造函数，并且自动赋初值，实例化了一个新的对象tmp
	return tmp;                 //这返回tmp的时候，没有直接把内容进行返回，而是返回tmp的一份拷贝，所以这里调用了拷贝构造函数
}

int main()
{
	Date date1(2017,3,7);         //首先调用构造函数
	date1.showDate();            //这里打印的结果是2.17,3,7  
	date1 = newSetdate(date1);   //这里首先调用的我的一个普通函数，大家可以先去这个普通函数中看一下
	date1.showDate();

	return 0;
}

//int main()
//{
//	Date *pdate;
//	pdate = new Date(2017,2,3);
//	cout << "Date1 " << endl;
//	pdate->showDate();
//	pdate->setDate(2017,2,3);
//	cout << "Date2 " << endl;
//	pdate->showDate();
//	return 0;
//
//}