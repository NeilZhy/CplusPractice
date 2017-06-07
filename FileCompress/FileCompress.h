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

	//�Ķ�
	//Ϊ�������䷶Χ��int���ܴ���ķ�Χ�Ѿ��������㣬���Զ���Long Long�����Ա�ʾ    






	long long _count;
	string _code;
	CharInfo()    //����д���캯����Ϊ�˺����Ǹ��Ƿ�ֵ׼����


		//�Ķ�
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
	void CompressCount(char* filename)
	{









		//����Ķ����ƶ�ȡ��һ����Ҫע�������
		FILE* out = fopen(filename,"rb");
		int ch = fgetc(out);
		//char ch = fgetc(out);
		//int arrlen = 0;
		while (ch != EOF)   //ch!=EOF  �Ķ�
		{
			_info[(unsigned char)ch]._count++;
			//arrlen++;
			ch = fgetc(out);
		}
		//fclose(out);   //������Ҫ�����ע�͵�����Ϊ��������Huffmancode��ʱ����Ҫ�ڶ�һ��Դ�ļ�
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

		//����Huffmancode֮����һ�������ٶ�һ��Դ�ļ���Ȼ����ļ�д�뵽һ���µ��ļ�����
		fseek(out, 0, SEEK_SET);   //��һ��������ǰ��ļ�ָ���������ǰ�棬Ȼ�����¶�ȡһ��Դ�ļ�

		//�����װһ�������ɣ����Ǹ��ļ�����һ���µ��ļ�
		NewFile(out,filename);
		fclose(out);

	}

	void UnCompress(char* filename,string name)
	{
		
		string aaa = filename;
		//������������Ӧ����һ��Huffman����������Ҫ��������һ��Huffman��
		CharInfo invalid;
		//��������������һ��bug
		HuffmanTree<CharInfo> FileTree(_info, 256, invalid);  
		HuffmanNode<Node>* root = FileTree.Getroot();
		HuffmanNode<Node>* cur = root;
		//�������ǲ���ҪHuffman�����ˣ���Ϊ������Ҫ����������ǣ�
					//ÿ�δ�ѹ���ļ��ж�ȡһ�����֣���0�����ߣ���1������
		//���ȶ���һ���ַ���Ȼ�������ַ�ת����code���������ǻ���Ҫ׼���Ĺ������ǣ���Ҫ�Ѻ�׺��ȥ����������Ͳ�ȥ��
		//��ֱ������һ���µ��ļ���
		//��������û��ֱ�Ӱ��ַ�ת����code�ĺ����������������������֮ǰ��������ʽ��д
		long long max = (root->_w)._count;
		int num = 0;
		FILE* out = fopen(aaa.c_str(), "rb");
		FILE* in = fopen(name.c_str(), "wb");
		char ch = fgetc(out);
		unsigned char n = 1;
		n <<= 7;
		//while (!feof(out))    //����һ��ʼ��ʹ����������ӵ�while(ch != EOF)����������һ����ѭ��





		//�������Ҳο��ŸĶ��Ĳ���
		while ((unsigned char)ch != EOF)  
		{     //��Ϊ�����ﶨ���ch���޷������͵ģ���������EOF���ص���-1�����Բ�����ô�����ҵ�ch��Զ�������EOF��������ѭ��
			for (int i = 0; i < 8;i++)
			{
				if ((((unsigned char)ch << i) & n) != 0)   //����&�����ʱ����ȷ1000 0000 & 1 0100 0000�����1 0000 0000
				{
					cur = cur->_right;
				}
				else
				{
					cur = cur->_left;
				}
				if ((cur->_left == NULL) && (cur->_right == NULL))   //�ж�
				{
					//fwrite(&(cur->_w)._ch, sizeof((cur->_w)._ch),1, in);
					fputc((cur->_w)._ch,in);
					num++;
					if (num > max)    //�����һ��if���ж���Ϊ�������ǵ��ַ�������һ��ʼ�����ִ�С�����max��ͷ����е�
								//�Ǹ�Ȩ�ص�ֵ�����ǳ��ֵ��ַ����ܴ���
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

	void NewFile(FILE* out,char* filename)    //����������Ҫ���Ĺ������ǣ���һ��whileѭ����ÿ�θ�һ���ַ�����ʼ��Ϊ0000 0000
		//���������ֽ� ��ʾ����ַ�����Ȼ��������ÿ�δ�Դ�ļ��ж�ȡһ���ַ���ʱ�򣬻�ȡ����Ӧ��code��Ȼ��
		//Ȼ��ͨ�������������Ʋ�����������ÿ��λ���õ�һ���ļ���ȥ
	{
		//char ch = fgetc(out);
		int ch = fgetc(out);
		string newfile = filename;   //���ַ�ʽ�ǲ���ȡ��string newfile = filename + "huffman";��Ϊ�������filename
						//����һ��string���͵ģ���֧�ּ�
		newfile += "huffman";
		FILE* In = fopen(newfile.c_str(),"wb");  //������ʲô��˼�������� ѽ��ѽѽ  
		char chIn = 0;
		int count = 0;
		

		while (!feof(out))
		/*while (ch != EOF)*/    //ÿ�δ�Դ�ļ��ж�ȡһ���ַ���Ȼ���ȡ����code
		{
			string& code = _info[(unsigned char)ch]._code;
			//string code = _info[(unsigned char)ch]._code;
			int size = code.size();
			//���������һ��forѭ����ÿ�ζ�ȡ�˴Σ���ȡ��ϰ˴�֮��д��һ��
			/*for (int i = 0; i < 8; i++)   //������forѭ���ķ�ʽ���ã���Ϊ����Ҫ����û�а˸���ʱ���ٴζ�ȡ����������ʹ��
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
			//leaf->_w._code = code;  //�������ǲ�Ӧ�ð�code����������棬��Ϊ��������ֻ�ǰ�code�����ˣ����ǻ�û�а��ļ�ת��
			//�������������ʽ���д洢��������������Ҫ�ٴζ�ȡԴ�ļ���Ȼ����Ҫ����һ��code�����ʱ��������ʱ����
			//�����������������Ӧ��ֱ�Ӵ�����������ж�ȡ����������Ӧ�ð�code�������������
			_info[(unsigned char)(leaf->_w)._ch]._code = code;   //��������֮�����ǾͰ��Ǹ�code����������������
		}
	}

	void CreatHuffmanCode1(HuffmanNode<Node>* root,string code = "")   //���ﴫ��һ��Ĭ�ϵĲ����������ڸ���ʱ��
						//��һ��ʼ��ֵΪ""��Ȼ�����������ʱ�����0�����ҵ�ʱ�����1
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
