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
	cout << "�������캯��" << endl;    
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
	Date tmp;                   //���ﺯ�������ã����ȵ��ù��캯���������Զ�����ֵ��ʵ������һ���µĶ���tmp
	return tmp;                 //�ⷵ��tmp��ʱ��û��ֱ�Ӱ����ݽ��з��أ����Ƿ���tmp��һ�ݿ�����������������˿������캯��
}

int main()
{
	Date date1(2017,3,7);         //���ȵ��ù��캯��
	date1.showDate();            //�����ӡ�Ľ����2.17,3,7  
	date1 = newSetdate(date1);   //�������ȵ��õ��ҵ�һ����ͨ��������ҿ�����ȥ�����ͨ�����п�һ��
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