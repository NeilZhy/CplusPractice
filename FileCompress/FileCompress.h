#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"Heap.h"
#include"Heap.h"
#include<algorithm> 
#include<iostream>
#include<string>
using namespace std;

struct CharInfo
{
	unsigned  char _ch;  

	//改动
	//为了扩大其范围，int型能处理的范围已经不能满足，所以定义Long Long型予以表示    






	long long _count;
	string _code;
	CharInfo()    //这里写构造函数是为了后面那个非法值准备的


		//改动
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
	void CompressCount(char* filename)
	{









		//这里的二进制读取是一会需要注意的问题
		FILE* out = fopen(filename,"rb");
		int ch = fgetc(out);
		//char ch = fgetc(out);
		//int arrlen = 0;
		while (ch != EOF)   //ch!=EOF  改动
		{
			_info[(unsigned char)ch]._count++;
			//arrlen++;
			ch = fgetc(out);
		}
		//fclose(out);   //这里需要把这个注释掉，因为下面生成Huffmancode的时候还需要在读一遍源文件
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

		//生成Huffmancode之后，下一步就是再读一遍源文件，然后把文件写入到一个新的文件中来
		fseek(out, 0, SEEK_SET);   //这一句的作用是把文件指针调整到最前面，然后重新读取一遍源文件

		//这里封装一个函数吧，把那个文件生成一个新的文件
		NewFile(out,filename);
		fclose(out);

	}

	void UnCompress(char* filename,string name)
	{
		
		string aaa = filename;
		//首先这里我们应该有一个Huffman树，这里需要重新生成一个Huffman树
		CharInfo invalid;
		//下面的这个还是有一个bug
		HuffmanTree<CharInfo> FileTree(_info, 256, invalid);  
		HuffmanNode<Node>* root = FileTree.Getroot();
		HuffmanNode<Node>* cur = root;
		//这里我们不需要Huffman编码了，因为我下面要做的事情就是，
					//每次从压缩文件中读取一个数字，读0往左走，读1往右走
		//首先读出一个字符，然后把这个字符转换成code，这里我们还需要准备的工作就是，需要把后缀给去掉，我这里就不去了
		//就直接生成一个新的文件了
		//这里我们没有直接把字符转化成code的函数，所以我们这里可以用之前的与或的形式来写
		long long max = (root->_w)._count;
		int num = 0;
		FILE* out = fopen(aaa.c_str(), "rb");
		FILE* in = fopen(name.c_str(), "wb");
		char ch = fgetc(out);
		unsigned char n = 1;
		n <<= 7;
		//while (!feof(out))    //这里一开始的使用是这个样子的while(ch != EOF)，但是它是一个死循环





		//这里是我参考着改动的部分
		while ((unsigned char)ch != EOF)  
		{     //因为我这里定义的ch是无符号整型的，所以这里EOF返回的是-1，所以不管怎么样，我的ch永远不会等于EOF，所以死循环
			for (int i = 0; i < 8;i++)
			{
				if ((((unsigned char)ch << i) & n) != 0)   //这里&运算的时候不正确1000 0000 & 1 0100 0000结果是1 0000 0000
				{
					cur = cur->_right;
				}
				else
				{
					cur = cur->_left;
				}
				if ((cur->_left == NULL) && (cur->_right == NULL))   //判断
				{
					//fwrite(&(cur->_w)._ch, sizeof((cur->_w)._ch),1, in);
					fputc((cur->_w)._ch,in);
					num++;
					if (num > max)    //这里的一个if的判断是为了让我们的字符数少于一开始的数字大小，这个max是头结点中的
								//那个权重的值，就是出现的字符的总次数
					{

						fclose(out);
						fclose(in);
						return;
					}
					cur = root;
				}
			}
			ch = fgetc(out);
			num++;
		}
		feof(in);
		fclose(out);
		fclose(in);
	}

	void NewFile(FILE* out,char* filename)    //这里我们想要做的工作就是，做一个while循环，每次给一个字符，初始化为0000 0000
		//（这里用字节 表示这个字符），然后我们想每次从源文件中读取一个字符的时候，获取其相应的code，然后
		//然后通过与或运算和左移操作把这个结果每八位放置到一个文件中去
	{
		//char ch = fgetc(out);
		int ch = fgetc(out);
		string newfile = filename;   //这种方式是不可取的string newfile = filename + "huffman";因为这里离的filename
						//不是一个string类型的，不支持加
		newfile += "huffman";
		FILE* In = fopen(newfile.c_str(),"wb");  //这里是什么意思，并不懂 呀，呀呀  
		char chIn = 0;
		int count = 0;
		

		while (!feof(out))
		/*while (ch != EOF)*/    //每次从源文件中读取一个字符，然后获取它的code
		{
			string& code = _info[(unsigned char)ch]._code;
			//string code = _info[(unsigned char)ch]._code;
			int size = code.size();
			//这里可以做一个for循环，每次读取八次，读取完毕八次之后写入一次
			/*for (int i = 0; i < 8; i++)   //这里做for循环的方式不好，因为还需要考虑没有八个的时候再次读取，这里我们使用
								//cout
			{
				chIn << 1;
				if (code[i] == '1')
				{
					chIn &= 1;
				}
			}*/
			for (int i = 0; i < size; i++)
			{
				chIn <<= 1;
				count++;
				if (code[i] == '1')
				{
					chIn |= 1;
				}
				if (count == 8)
				{
					//fwrite(&chIn,sizeof(chIn),1,In);
					fputc(chIn,In);
					count = 0;
					chIn = 0;
				}
			}
			ch = fgetc(out);
		}
		chIn <<= (8-count);
		//fwrite(&chIn,sizeof(chIn),1, In);
		fputc(chIn,In);
		fclose(In);
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
			//leaf->_w._code = code;  //这里我们不应该把code存放在树里面，因为我们现在只是把code生成了，但是还没有把文件转成
			//哈夫曼编码的形式进行存储，接下来我们需要再次读取源文件，然后还需要索引一遍code，这个时候索引的时候不能
			//在树里面遍历，而是应该直接从数组里面进行读取，所以这里应该把code存放在数组里面
			_info[(unsigned char)(leaf->_w)._ch]._code = code;   //这样操作之后我们就把那个code放在了数组里面了
		}
	}

	void CreatHuffmanCode1(HuffmanNode<Node>* root,string code = "")   //这里传入一个默认的参数，就是在根的时候，
						//把一开始赋值为""，然后下面往左的时候加上0，往右的时候加上1
	{
		//string code = "";
		if (NULL == root)
		{
			return;
		}
		CreatHuffmanCode1(root->_left,code+'0');
		CreatHuffmanCode1(root->_right,code+'1');
		if ((NULL == root->_left) && (NULL == root->_right))
		{
			_info[(unsigned char)(root->_w)._ch]._code = code;
		}
	}

	


private:
	CharInfo _info[256];
};
