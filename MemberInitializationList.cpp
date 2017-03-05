#include<windows.h>
#include<iostream>
using namespace std;

class A
{
private:
	int x;
	int &rx;
	const double pi;
public:
	A(int x1) :x(x1), rx(x), pi(3.14)
	{}
	void print()
	{
		cout << "x= " << x << "rx=  " << rx << "pi=  " << pi << endl;
	}
};

int main()
{
	A a(10);
	a.print();
	system("pause");
	return 0;
}