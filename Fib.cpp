#include<iostream>
using namespace std;


//�ǵݹ�ʵ��
//ʱ�临�Ӷ�  O(n)
//�ռ临�Ӷ�  O(1)
void fib1(int n)
{
	int first = 1;
	int sceond = 1;
	int fib = 1;
	int i = 0;
	for (i = 1; i <= n - 2; i++)
	{
		fib = first + sceond;
		first = sceond;
		sceond = fib;
	}
	cout << fib << endl;

}

//�����鱣��  --- �ǵݹ�ʵ��
//ʱ�临�Ӷ�  O(n)
//�ռ临�Ӷ�  O(n)
void fibarr(int n)
{
	int* arr = new int[n];
	arr[0] = arr[1] = 1;
	for (int i = 2; i < n;i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	for (int i = 0; i < n;i++)
	{
		cout << arr[i] << "  ";
	}
}

//�ݹ�ʵ��
//ʱ�临�Ӷ�  O(2^n)
//�ռ临�Ӷ�  O(n)
int fib2(int n)
{
	//int fib;
	if ((n != 2)&&(1 != n))
	{
		return fib2(n-2) + fib2(n-1);	
	}
	
	else
	{
		return 1;
	}
}


//�ݹ�ʵ���Ż�
//�ռ临�Ӷ�  O(n)
//ʱ�临�Ӷ�  O(n)
long long Fibonacci(int n,int first = 1, int second = 1)
{
	if (n == 3)
	{
		return first + second;
	}

	return Fibonacci(n - 1,second, first + second);
};

void Testfib2()
{
	cout << fib2(1) << endl;
	cout << fib2(2) << endl;
	cout << fib2(3) << endl;
	cout << fib2(4) << endl;
	cout << fib2(5) << endl;
	cout << fib2(6) << endl;
	cout << fib2(7) << endl;
}

int main()
{
	
	fib1(40);
	///*Testfib2();
	//fibarr(7);
	//cout << endl;
	cout<<Fibonacci(40);
	return 0;
}
