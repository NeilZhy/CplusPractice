#include<iostream>
using namespace std;
#include"AVLTree.h"
#include"RBTree.h"

void TestAVLTree()
{
	/*int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };*/
	/*int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };*/
	int arr[] = {8,5,15,16,10,12,2};   //这组数据，在我们插入的时候就会出现问题，因为我们在左旋 右旋的时候，直接 把平衡因子
								//置为了0，但是实际中，当程序执行到插入12之后，8的平衡因子不应该是0，这里可以画图看出来
								//这里只是存在了隐患，但是，当我们插入2之后就出现问题了，因为8的平衡因子是0，所以插入2
								//之后，8的平衡因子本应该是-2，但是现在变成了-1，不需要调节
	int len = sizeof(arr) / sizeof(arr[0]);
	AVLTree<int> tree;
	for (int i = 0; i < len; i++)
	{
		tree.Insert(arr[i]);
	}

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

void TestRBTree()
{
	RBTree<int> tree;
	tree.Insert(16);
	tree.Insert(8);
	tree.Insert(32);
	tree.Insert(4);
	tree.Insert(2);
	tree.Insert(3);
	tree.IsBanlance();
}


int main()
{
	/*TestAVLTree();*/
	TestRBTree();
	return 0;
}