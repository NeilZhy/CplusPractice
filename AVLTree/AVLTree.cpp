#include<iostream>
using namespace std;
#include"AVLTree.h"

void TestAVLTree()
{
	AVLTree<int> tree;
	tree.Insert(5);
	tree.Insert(8);
	tree.Insert(1);
	tree.Insert(7);
	tree.Insert(6);
	tree.Insert(0);
}


int main()
{
	TestAVLTree();
	return 0;
}