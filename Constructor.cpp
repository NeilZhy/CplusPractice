#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int y,int m,int d);
	void setDate(int y,int m,int d);
	void showDate();
};

Date::Date(int y, int m, int d) :year(y), month(m), day(d)
{
	cout << "Constcuting ..." << endl;
}

void Date::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

inline void Date::showDate()
{
	cout << year << "." << month << "." << day << endl;
}

//int main()
//{
//	Date date1(2017,3,2);
//	cout << "date1 :" << endl;
//	date1.showDate();
//	date1.setDate(2017,3,3);
//	cout << "date2 :" << endl;
//	date1.showDate();
//	return 0;
//}

int main()
{
	Date *pdate;
	pdate = new Date(2017,2,3);
	cout << "Date1 " << endl;
	pdate->showDate();
	pdate->setDate(2017,2,3);
	cout << "Date2 " << endl;
	pdate->showDate();
	return 0;

}