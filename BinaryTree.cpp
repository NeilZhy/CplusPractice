#include<iostream>
using namespace std;
#include"Binarytree.h"

void Test()
{
	char arry[] = { '1', '2', '3','#', '4', '#', '5', '6', '#', '#', '7','#','8','#','#','9' };
	char arr[] = { '1', '2', '3', '#', '4', '#', '5', '#', '#', '7', '#', '8', '#'};
	Binary<char> tree(arry, 16, '#');   //这里一开始编译不过，是因为我在写Binary的构造函数的时候，最后一个参数，T& indival
	//的时候，没有使用const T& indival
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