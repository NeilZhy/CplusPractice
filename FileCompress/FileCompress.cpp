#include"HuffmanTree.h"
#include<iostream>
using namespace std;

int main()
{
	int arr[] = {1,5,6,7,2,3,9,5,4};
	int n = sizeof(arr) / sizeof(arr[0]);
	HuffmanTree<int> hfmtree(arr, n);
	return 0;
}