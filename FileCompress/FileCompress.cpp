#include"HuffmanTree.h"
#include<iostream>
using namespace std;
#include"FileCompress.h"

int main()
{
	int arr[] = {1,5,6,7,2,3,9,5,4};
	int n = sizeof(arr) / sizeof(arr[0]);
	//HuffmanTree<int> hfmtree(arr, n,2);
	Filecompress file;
	file.CompressCount("aa.txt");
	return 0;
}