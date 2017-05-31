#include<iostream>
using namespace std;
#include"AVLTree.h"

void TestAVLTree()
{
	/*int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };*/
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int len = sizeof(arr) / sizeof(arr[0]);
	AVLTree<int> tree;
	for (int i = 0; i < len; i++)
	{
		tree.Insert(arr[i]);
	}

	//这组数据还没有测试过，回去测试吧





	//tree.Insert(5);
	//tree.Insert(8);
	//tree.Insert(1);
	//tree.Insert(7);
	//tree.Insert(9);
	//tree.Insert(-5);
	///*tree.Insert(2);
	//tree.Insert(3);
	//tree.Insert(4);*/
	//tree.Insert(-4);
	tree.IsBanlance();


}


int main()
{
	TestAVLTree();
	return 0;
}