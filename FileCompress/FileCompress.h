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
	CharInfo()    //����д���캯����Ϊ�˺����Ǹ��Ƿ�ֵ׼����
		:_count(0)
	{}
	CharInfo operator+(CharInfo& l)
	{
		CharInfo ch;
		ch._count = _count + l._count;
		return ch;                           //������һֱ�ɻ��һ������ǣ����ǷǷ�ֵ��_ch��ɶ�󣬲���ò�Ʋ���Ҫ��
				//��Ϊ���� ���зǷ�ֵ�ı�׼�Ǹ���_count�������Ǹ���_ch
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
	Filecompress()   //���캯�������ڵ����������ÿ���ڵ��_ch��ʼ������_count��ʼ��Ϊ0
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

	//����������һ���ı��ļ���Ȼ��ͳ���ļ��е��ַ��Ĵ���
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
		//������ֻ����ó��ֵ��ַ���Huffmantree�У�Ȼ����ʦ�����Ǹ������Ļ��ǲ������룬���Ծ�����һ��vector��
		//Node arr[arrlen];

		/*for (int i = 0; i < 256; i++)
		{
			if (_info[i]._count != 0)
			{
				chararr.push_back(_info[i]);
			}
			
		}*/

		//���������Huffmantreeʱ��Ӧ������һ���Ƿ�ֵ���������ǿ��԰ѷǷ�ֵ����ȥ��Ȼ��ÿ��ֱ�Ӵ���������л�ȡ��Ϣ����
		//huffmantree����
		CharInfo invalid;
		//��������������һ��bug
		HuffmanTree<CharInfo> FileTree(_info, 256, invalid);   //���ﴫ���Ӧ����һ�����飬������ҲӦ��дһ���Ǹ�operator()
										//һ���ṹ�壬Ȼ�����Huffmantree���洴��һ�������ʱ��֮ǰд�ľ���һ��HuffmanTree<CharInfo>������Ӧ�øĳ� һ��
				//HuffmanTree<CharInfo��CompareChInfo>
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
