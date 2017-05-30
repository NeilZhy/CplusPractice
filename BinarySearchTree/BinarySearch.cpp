#include<iostream>
using namespace std;
#include"BinarySearchTree.h"


void testBinarySeaech()
{
	BinarySearchTree<int> tree;
	tree.Push(5);
	tree.Push(4);
	tree.Push(12);
	tree.Push(9);
	tree.Push(6);
	tree.Push(8);
	tree.Push(7);
	tree.Push(3);
	tree.Push(1);
	tree.Push(45);
	tree.Push(6);
	tree.Push(0);
	tree.Push(2);
	tree.DeleteNode(0);
	tree.DeleteNode(5);
	tree.DeleteNode(12);
	tree.DeleteNode(4);
	tree.DeleteNode(9);
	tree.DeleteNode(6);
	tree.DeleteNode(8);   //删除8的时候出错了
	tree.DeleteNode(7);
	tree.DeleteNode(45);
	tree.DeleteNode(3);
	tree.DeleteNode(1);
	tree.DeleteNode(2);
	tree.DeleteNode(0);
	/*tree.Find(5);
	tree.Find(3);
	tree.Find(18);*/
	//tree.testFind();

}

int main()
{
	testBinarySeaech();
	
	
	return 0;

}