#include<iostream>
using namespace std;
#include"Binarytree.h"

void Test()
{
	char arry[] = { '1', '2', '3','#', '4', '#', '5', '6', '#', '#', '7','#','8','#','#','9' };
	char arr[] = { '1', '2', '3', '#', '4', '#', '5', '#', '#', '7', '#', '8', '#'};
	Binary<char> tree(arry, 16, '#');   //����һ��ʼ���벻��������Ϊ����дBinary�Ĺ��캯����ʱ�����һ��������T& indival
	//��ʱ��û��ʹ��const T& indival
	Binary<char> t(arr,13,'#');
	tree.PrevShow();
	tree.InShow();
	tree.LowShow();
	tree.LevelShow();
	cout << tree.LeavNodeNum() << endl;
	cout << tree.NodeNum() << endl;
	cout << tree.LevelNum(1) << endl;
	cout << tree.LevelNum(3) << endl;
	cout << tree.Depth() << endl;
	cout << t.Depth() << endl;
	cout << t.LeavNodeNum() << endl;
	cout << t.LevelNum(4) << endl;
	cout << (t.Find('3'))->_data << endl;
	cout << (t.Find('1'))->_data << endl;
	cout << (t.Find('2'))->_data << endl;
}


int main()
{
	Test();
	return 0;
}