#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<cmath>



bool prime(int x)
{
	int y;
	for (y = 2; y <= sqrt(x); y++)
	if (x%y == 0)
		return false;
	return true;
}


int  main()
{
	int a = 0, b = 0;
	vector<int> prm;
	prm.resize(1000);
	cin >> a >> b;
	int i = 0;
	int j = 0;
	int y = 2;
	int m = 0;
	for (i = 2; i <= b; i++)
	{
		if (prime(i))
		{
			prm[i] = i;
		}
	}
	for (i = a; i <= b;i++)
	{
		if (i == prm[i])
			cout << i<<"=" << prm[i] << endl;
		else
		{
			cout << i << "=";
			m = i;
			while (m != prm[m])
			{
				for (y = 2; y <= sqrt(m); y++)
				{
					if (m%y == 0)
					{
						m = m / y;
						cout << y << "*";
						break;
					}
				}
			}
			cout << m << endl;
			
			
		}
	}
	return 0;
}



//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//#include<vector>
//#include<cmath>
//#include<list>
//
//bool prime(int x)
//{
//	int y;
//	for (y = 2; y <= sqrt(x); y++)
//	if (x%y == 0)
//		return false;
//	return true;
//}
//
//
//int  main()
//{
//	int a = 0, b = 0;
//	vector<int> prm;
//	prm.resize(1000);
//	list<int> lis;
//	cin >> a >> b;
//	int i = 0;
//	int j = 0;
//	int y = 2;
//	int m = 0;
//	for (i = 2; i <= b; i++)
//	{
//		if (prime(i))
//		{
//			prm[i] = i;
//		}
//	}
//	for (i = a; i <= b; i++)
//	{
//		if (i == prm[i])
//			cout << i << "=" << prm[i] << endl;
//		else
//		{
//			m = i;
//			while (m != prm[m])
//			{
//				for (y = 2; y <= sqrt(m); y++)
//				{
//					if (m%y == 0)
//					{
//						m = m / y;
//						lis.push_back(y);
//						break;
//					}
//				}
//			}
//			lis.push_back(m);
//			lis.sort();
//			cout << i << "=";
//			list<int>::iterator it = lis.begin();
//			list<int>::iterator it2 = lis.end();
//			it2--;
//			while (it != it2)
//			{
//				cout << *it << "*";
//				it++;
//			}
//			cout << *it2 << endl;
//			lis.clear();
//		}
//	}
//	return 0;
//}


//int main()
//{
//	long long n = 0;
//	long long sum = 0;
//	long long i = 0;
//	cin >> n;
//	for (i = 0; i <= n; i++)
//	{
//		sum += i;
//	}
//	cout << sum;
//	return 0;
//	
//}








//#include<string>
//#include<vector>

//
//int main()
//{
//	vector<string> time = {"zero","one","two","three","four","five" ,"six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","twenty one","twenty two","twenty three"};
//	size_t h = 0;
//	size_t m = 0;
//	cin >> h >> m;
//	cout << time[h] << " ";
//	if (m == 0)
//	{
//		cout << "o'clock";
//	}
//	else if (m<=20)
//	{
//		cout << time[m];
//	}
//	else if (m < 30)
//	{
//		cout << "twenty " << time[m % 10];
//	}
//	else if (m < 40)
//	{
//		cout << "thirty " << time[m % 10];
//	}
//	else if (m < 50)
//	{
//		cout << "forty " << time[m % 10];
//	}
//	else
//	{
//		cout << "fifty " << time[m % 10];
//	}
//	return 0;
//}