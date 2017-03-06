#include<iostream>
#include<windows.h>
using namespace std;
 
class Coord
{
private:
	int x;
	int y;
public:
	Coord(int a = 0, int b = 0)
	{
		x = a;
		y = b;
	}
	int gecx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
};

int main()
{
	int i, j;
	Coord coord(5,6);
	i = coord.gecx();
	j = coord.gety();
	cout << " x = " << i << endl;
	cout << " y = " << j << endl;

	system("pause");
	return 0;
}