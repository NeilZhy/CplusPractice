#pragma once
#include"Heap.h"
#include"Heap.h"

struct CharInfo
{
	char _ch;
	size_t _count;
	string _code;
	CharInfo()
		:_count(0)
	{}
};



class Filecompress
{
	typedef CharInfo Node;
public:
	Filecompress()   //构造函数，将节点数组里面的每个节点的_ch初始化，将_count初始化为0
	{
		for (int i = 0; i < 256; i++)
		{
			_info[i]._ch = i;
			_info[i]._count = 0;
		}
	}
	struct CompareChInfo
	{
		bool operator()(Node *left, Node *right)
		{
			return left->_count < right->_count;
		}
	};

	//接下来传入一个文本文件，然后统计文件中的字符的次数
	void CompressCount(const char* filename)
	{
		FILE* out = fopen(filename,"r");
		char ch = fgetc(out);
		//int arrlen = 0;
		while (ch != EOF)
		{
			_info[ch]._count++;
			//arrlen++;
			ch = fgetc(out);
		}
		fclose(out);
		//这里我只想放置出现的字符到Huffmantree中，然后老师讲的那个我理解的还是不够深入，所以就在用一个vector吧
		//Node arr[arrlen];

		/*for (int i = 0; i < 256; i++)
		{
			if (_info[i]._count != 0)
			{
				chararr.push_back(_info[i]);
			}
			
		}*/

		//我们在设计Huffmantree时候应该设置一个非法制，

		//下面的这个还是有一个bug
		HuffmanTree<CharInfo> huffmanChar(chararr,256);   //这里传入的应该是一个数组，我这里也应该写一个那个operator()
										//一个结构体，然后这个Huffmantree里面创建一个对象的时候之前写的就是一个HuffmanTree<CharInfo>，现在应该改成 一个
				//HuffmanTree<CharInfo，CompareChInfo>
	}


private:
	CharInfo _info[256];
};
