#include<iostream>
using namespace std;
#include"List.h"
#include<vector>
#include<list>


//��������û��д�����������ٲ���

//����vector��˳���
void TestVector()
{
	vector<int> Seq;    //���캯��
	vector<int>::iterator it = Seq.begin();
	cout << *it;
}

void TestList()
{
	list<int> L;   //list��һ��ģ���࣬��STL�����׼ģ���������ʵ�ֺõĶ�������������ʵ������һ������
	L.push_back(1);   //���ó�Ա���������������������һЩ����
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	L.push_back(5);
	L.push_back(6);
	list<int>::iterator it = L.begin();   //iterator��һ��ģ���࣬��һ���������������������ָ��L������������һ��һ��
			//�ڵ�ģ�Ȼ������Ҫ���������������ֵ������L.begin()����L��һ����Ա����
			//iterator��list�����һ��typedef��һ������
	//cout << *it;
	for (; it != L.end();it++)    //L��һ��˫����ͷ��ѭ�������ײ�ʵ�ֵ�ʱ�����end�����Ǹ�ͷ�ڵ�
	{
		cout << *it << " ";
		//*it = 10;
	}
	cout << endl;
	for (it = L.begin(); it != L.end(); it++)    //
	{
		cout << *it << " ";    //�������Ƕ����ʱ��it��һ����ͨ������������ִ�ж�д����
	}

	list<int>::const_iterator cit = L.begin();
	for (cit = L.begin(); cit != L.end(); cit++)    //
	{
		//*cit = 1;    //������һ��const�ĵ��������������ǲ���ͨ�������ķ�ʽȥ�޸�����ֵ
	}

	list<int>::reverse_iterator rit = L.rbegin();   //ע�����������rbegin
	for (; rit != L.rend(); rit++)    //
	{
		cout << *rit<<" ";
	}

	//����˵�������������������ҿ��ģ���˼����˵������ʵ�ֵ���һ��˫����ͷ��ѭ������Ȼ���Ǹ�ͷ����ǿյ�

}


void TestMyList()
{
	List<int> L;
	L.PushBack(1);
	L.PushBack(2);
	L.PushBack(3);
	L.PushBack(4);
	L.Show();
	L.PopBack();
	L.Show();
	L.Insert(L.Find(1),0);
	L.Show();
	L.PushBack(5);
	L.Show();
	L.Erase(L.Find(5));
	L.Show();
	L.PopBack();
	L.Popfront();
	L.Show();
	//cout << *(L.Find(1)) << endl;
	/*L.Clear();
	L.Show();*/





	//Iterator<List<int>> it = L.Begin();   //����Ϊ��һ������ȷ��ʹ�÷�ʽ
	//List<int>::Iterator it = L.Begin();     //������һ��ʼʹ�õ�ʱ���ǳ���ʹ��Iterator<int>�����Ƶ���ʽ������������������
	//		//����ģ���Ϊ�ҿ�ʼ��ʱ�����һ������__Iterator,�����ҵ�Iterator������List��ʹ��typedef����ģ���������ʹ��
	//		//��ʽӦ����List<int>::Iterator
	///*cout << *it << endl;
	//cout << *(++it) << endl;
	//cout << *(it++) << endl; 
	//cout << *(--it) << endl;
	//cout << *(it--) << endl;*/
	//const List<int> l1(L);   //����������ʹ��ConstIterator��ʱ��Ҫ������һ��const����������һ���ڴ��ε�ʱ��
	//	//����дһ��print�����һ����������Ҫ���ݵĲ�����һ��const�Ķ��󣬺���ԭ�Ϳ�������дvoid Pritnf(const List<int> l)
	//List<int>::ConstIterator it1 = l1.Begin();
	//cout <<"ConstIterator  "<<*it1 << endl;

	//List<AA> LL;
	//LL.PushBack(AA());
	//LL.PushBack(AA());
	//LL.PushBack(AA());
	//List<AA>::Iterator itAA = LL.Begin();
	//cout<<itAA->_a;

}

int main()
{

	//Show();
	//TestVector();
	///*TestList*/();
	TestMyList();
	return 0;
}