#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class A
{
public:
	void Show()
	{
		cout << "Show()" << endl;
		//cout << _a << endl;    ���������һ�����ͻ������Ϊ�������Ƿ����˶�����ڴ�ռ䣬���Ա��벻��
	}
protected:
	int _a;

};

int main()
{
	A* p = NULL;   
	p->Show();    //�޶�����ú���������ʵ�����Ǵ���һ����ַ����������û�з��ʶ���Ŀռ䣬�������ﲻ�����
	return 0;
}