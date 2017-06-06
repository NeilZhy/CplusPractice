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
	//Filecompress f;
	file.CompressCount("aa.txt");
	file.UnCompress("aa.txthuffman", "bb.txt");
	/*f.CompressCount("t.pang");
	f.UnCompress("t.panghuffman", "2.pang");*/
	return 0;
}