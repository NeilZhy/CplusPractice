#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;

struct role
{
	size_t value;
	int flag;   //1代表的是龙   2代表的是骑士
	role()
		:value(0)
		, flag(0)
	{}
};

bool myfunction(role i, role j) { return (i.value<j.value); }

int main()
{
	vector<role> rolearr;
	int n = 0;
	int m = 0;
	cin >> n >> m;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		role Loong;
		cin >> Loong.value;
		Loong.flag = 1;
		rolearr.push_back(Loong);
	}
	for (i = 0; i < m; i++)
	{
		role Loong;
		cin >> Loong.value;
		Loong.flag = 2;
		rolearr.push_back(Loong);
	}

	sort(rolearr.begin(), rolearr.end(), myfunction);
	vector<role>::iterator it = rolearr.begin();
	vector<role>::iterator it2 = rolearr.begin();
	int num = 0;
	while (it != rolearr.end())
	{
		if (it->flag == 1)
		{
			it2 = it;
			while (it2 != rolearr.end())
			{
				if (it2->flag == 2)
				{
					num += it2->value;
					break;
				}
				it2++;
			}
			if (it2 == rolearr.end())

			{
				cout << "-1";
				return 0;
			}
		}
		it++;
	}
	cout << num;
	return 0;


}




















//struct role
//{
//	size_t zhi;
//	int flag;  //1是龙，2是勇士
//};
//
//bool myfunction(role i, role j) { return (i.zhi<j.zhi); }
//
//int main()
//{
//	size_t nlong = 0;
//	size_t nyongshi = 0;
//	vector<role> vctrole;
//	cin >> nlong >> nyongshi;
//	size_t i = 0;
//	size_t zhizhi = 0;
//	for (i = 0; i < nlong; i++)
//	{
//		cin >> zhizhi;
//		role m;
//		m.flag = 1;
//		m.zhi = zhizhi;
//		vctrole.push_back(m);
//	}
//	for (i = 0; i < nyongshi; i++)
//	{
//		cin >> zhizhi;
//		role n;
//		n.flag = 2;
//		n.zhi = zhizhi;
//		vctrole.push_back(n);
//	}
//
//	int num = 0;
//
//	sort(vctrole.begin(), vctrole.end(), myfunction);
//	vector<role>::iterator it = vctrole.begin();
//	vector<role>::iterator it2 = vctrole.begin();
//	while (it != vctrole.end())
//	{
//		if (it->flag == 1)
//		{
//			it2 = it;
//			while (it2 != vctrole.end())
//			{
//				if (it2->flag == 2)
//				{
//					num += it2->zhi;
//					break;
//				}
//				else
//				{
//					it2++;
//				}
//			}
//			if (it2 == vctrole.end())
//			{
//				num = -1;
//				cout << num;
//				return 0;
//			}
//		}
//		it++;
//
//	}
//	cout << num;
//	return 0;
//
//}

//int main()
//{
//	double len = 0;
//	double gv = 0;
//	double pv = 0;
//	double time = 0;
//	double t = 0;
//	cin >> len >> gv >> pv >> time;
//	double tg = len / gv;
//	double pg = len / pv;
//	double n = 0;
//	if (tg > pg)
//	{
//		t = tg;
//	}
//	else
//	{
//		t = pg;
//	}
//	int iz = time / t;
//	int i = 1;
//	double tn = 0;
//	double leng = 0;
//	double lenp = 0;
//	double clen = 0;
//	int m = 0;
//	while (i <= iz)
//	{
//		tn = t*i;
//		leng = tn*gv;
//		lenp = tn*pv;
//		clen = leng - lenp;
//		if (clen < 0)
//		{
//			clen = -clen;
//		}
//		m = clen/len;
//		if (m % 2 != 0)
//		{
//			n++;
//		}
//		i++;
//	}
//	cout << n;
//	return 0;
//
//}



//#include<iostream>
//using namespace std;
//
////独立的小易，正确答案，
////int main()
////{
////	int x, f, d,p;
////	cin >> x >> f >> d >> p;
////	int day = d / x;
////	if (day <= f)
////	{
////		cout << day;
////		return 0;
////	}
////	else
////	{
////		cout << f + (d - f*x) / (p + x);
////	}
////	return 0;
////}
//
//
////逆序排列
////int main()
////{
////	int arr[2*10*10*10*10*10];
////	int n = 0;
////	cin >> n;
////	int i = 0;
////	for (; i < n; i++)
////	{
////		cin >> arr[i];
////	}
////	
////	for (i = n-1; i>-1; i -= 2)
////	{
////		cout << arr[i]<<" ";
////	}
////	if (n % 2)
////	{
////		i = 1;
////	}
////	else
////	{
////		i = 0;
////	}
////	for (; i < n-2; i += 2)
////	{
////		cout << arr[i]<<" ";
////	}
////
////	cout << arr[i];
////	return 0;
////	
////}
//
//
//
////#include<vector>
////#include<list>
////int main()
////{
////	long long n = 0;
////	long long i = 0;
////	long long m = 0;
////	list<long long> arr;
////	list<long long> brr;
////	cin >> n;
////	
////	for (i = 0; i < n; i++)
////	{
////		cin >> m;
////		brr.push_back(m);
////		brr.reverse();
////	}
////	list<long long>::iterator it = brr.begin();
////	list<long long>::iterator end = brr.end();
////	end--;
////	while (it != end)
////	{
////		cout << *it << " ";
////		it++;
////	}
////	cout << *it;
////	return 0;
////}
//
//
//
//
//
//
////独立的小易
//////int main()
//////{
//////	int x, f, d, p;
//////	int n = 0;
//////	cin >> x >> f >> d >> p;
//////	while ((x*n + (n - f)*p) < d)
//////	{
//////		n++;
//////	}
//////	if (n-- < f)
//////	{
//////		n = 0;
//////		while ((x*n) < d)
//////		{
//////			n++;
//////		}
//////	}
//////	
//////	cout << n;
//////	return 0;
//////	
//////}
////
//
//
////#include<list>
////int main()
////{
////	long long n = 0;
////	long long i = 0;
////	long long high = 0;
////	list<long long> stulist;
////	list<long long> feng;
////	cin >> n;
////	long long back = 0;
////	long long front = 0;
////	
////	for (; i < n; i++)
////	{
////		cin >> high;
////		stulist.push_back(high);
////	}
////	stulist.sort();
////	high = stulist.front();
////	stulist.pop_front();
////	feng.push_back(high);
////	while (!stulist.empty())
////	{
////		high = stulist.back();
////		stulist.pop_back();
////		back = feng.back();
////		front = feng.front();
////		if (abs(high - back) > abs(high - front))
////		{
////			feng.push_back(high);
////		}
////		else
////		{
////			feng.push_front(high);
////		}
////		high = stulist.front();
////		stulist.pop_front();
////		back = feng.back();
////		front = feng.front();
////		if (abs(high - back) > abs(high - front))
////		{
////			feng.push_back(high);
////		}
////		else
////		{
////			feng.push_front(high);
////		}
////	}
////	list<long long>::iterator it = feng.begin();
////	list<long long>::iterator it2 = feng.begin();
////	it2++;
////	high = 0;
////	while (it2 != feng.end())
////	{
////		high += abs(*it - *it2);
////		it++;
////		it2++;
////	}
////	cout << high;
////	return 0;
////}
//
////彩色砖块
//
////int main()
////{
////	char arr[51];
////	cin >> arr;
////	char comp1 = arr[0];
////	char comp2 = 0;
////	int len = strlen(arr);
////	int i = 1;
////	for (; i < len; i++)
////	{
////		if (arr[i] != comp1)
////		{
////			comp2 = arr[i];
////			break;
////		}
////	}
////	if (comp2 == 0)
////	{
////		cout << "1";
////		return 0;
////	}
////	for (; i < len; i++)
////	{
////		if ((arr[i] != comp1) && (arr[i]) != comp2)
////		{
////			cout << "0";
////			return 0;
////		}
////	}
////	cout << "2";
////	return 0;
////
////}
//
//
////#include<algorithm>
//////等差数列
////int main()
////{
////	int arr[50];
////	int  n = 0;
////	cin >> n;
////	int i = 0;
////	for (; i < n; i++)
////	{
////		cin >> arr[i];
////	}
////	sort(arr,arr+n);
////	for (i = 0; i < n-2; i++)
////	{
////		if ((arr[i + 2] - arr[i + 1]) != (arr[i + 1] - arr[i]))
////		{
////			cout << "Impossible";
////			return 0;
////		}
////	}
////	cout << "Possible";
////	return 0;
////}
//
////01串
//
//#include<string.h>
//int main()
//{
//	char arr[51];
//	cin >> arr;
//	int len = strlen(arr);
//	int i = 1;
//	int max = 1;
//	int flag = 1;
//	for (; i < len;i++)
//	{
//		if (arr[i] != arr[i - 1])
//		{
//			flag++;
//		}
//		else
//		{
//			if (flag>max)
//			{
//				max = flag;
//			}
//			flag = 1;
//		}
//	}
//	if (flag > max)
//	{
//		max = flag;
//	}
//	cout << max;
//	return 0;
//
//}