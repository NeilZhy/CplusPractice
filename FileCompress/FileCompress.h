#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"Heap.h"
#include"Heap.h"
#include<algorithm> 

struct CharInfo
{
	char _ch;
	size_t _count;
	string _code;
	CharInfo()    //这里写构造函数是为了后面那个非法值准备的
		:_count(0)
	{}
	CharInfo operator+(CharInfo& l)
	{
		CharInfo ch;
		ch._count = _count + l._count;
		return ch;                           //这里我一直疑惑的一个点就是，我们非法值的_ch是啥捏，不过貌似不需要了
				//因为我们 评判非法值的标准是根据_count，而不是根据_ch
	}

	bool operator<(CharInfo& l)
	{
		return _count < l._count;
	}
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

		//我们在设计Huffmantree时候应该设置一个非法值，这里我们可以把非法值穿进去，然后每次直接从这个数组中获取信息放在
		//huffmantree中了
		CharInfo invalid;
		//下面的这个还是有一个bug
		HuffmanTree<CharInfo> FileTree(_info, 256, invalid);   //这里传入的应该是一个数组，我这里也应该写一个那个operator()
										//一个结构体，然后这个Huffmantree里面创建一个对象的时候之前写的就是一个HuffmanTree<CharInfo>，现在应该改成 一个
				//HuffmanTree<CharInfo，CompareChInfo>
		CreatHuffmanCode(FileTree.Getroot());
	}

	void CreatHuffmanCode(HuffmanNode<Node>* root)
	{
		if (NULL == root)
		{
			return;
		}
		CreatHuffmanCode(root->_left);
		CreatHuffmanCode(root->_right);
		if ((NULL == root->_left) && (NULL == root->_right))
		{
			HuffmanNode<Node>* leaf = root;
			HuffmanNode<Node>* parent = root->_parent;
			string code;
			while (parent)
			{
				if (root == parent->_left)
				{
					code.push_back('0');
				}
				if (root == parent->_right)
				{
					code.push_back('1');
				}
				root = parent;
				parent = root->_parent;
			}
			reverse(code.begin(),code.end());
			leaf->_w._code = code;
		}
	}
private:
	CharInfo _info[256];
};
