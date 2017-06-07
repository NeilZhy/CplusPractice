#pragma once
#include<iostream>
using namespace std;
#include"Heap.h"
#include<string>

//����һ��HuffmanNode
template<class T>
struct HuffmanNode
{
	HuffmanNode* _parent;
	HuffmanNode* _left;   //������
	HuffmanNode* _right;   //������
	T _w;                 //Ȩֵ

	HuffmanNode(T w)
		:_left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _w(w)
	{}
};

template<class T>
class HuffmanTree
{
	typedef HuffmanNode<T> Node;
public:
	struct NodeCompare
	{
		bool operator()(Node *left, Node *right)
		{
			return left->_w < right->_w;         //����������Ҫ����operator<()
		}
	};

	HuffmanTree(T* a, int n, T& invalid = T())    //�������һ��Ĭ�ϵĲ���T()����Ϊ���������ֻ����һ��������һ��intֵ
		//��ô���������T()�����intֵ����һ���������
	{
		//��������������������Ҫȡ��С���������ݣ����ʱ��϶�����������ķ�ʽ��������ÿ�ζ���Ҫ����һ����
		//̫�������������������Ǵ���һ���ѣ�ÿ��ȡ������ĶѶ���Ԫ�أ�����ֱ�Ӱ�֮ǰд���Ǹ���ͷ�ļ��ù���ʹ�þͺ�
		//Heap<Node*> minHeap(a,n);   //����һ��С���ѣ���Ϊ����ÿ����Ҫȡ������С������Ԫ�أ���������������heap�л���Ҫдtop
		//						//�����С���ѵ�ʱ�����ǿ����ȹ���һ���յĶѣ�Ȼ�����push�������������ֱ��ʹ��
		//				//���캯��һ����λ
		Heap<Node*, NodeCompare> minHeap;    //�����Ļ������ǾͰѸ����ڵ��ָ������˶�����
		for (int i = 0; i < n;i++)
		{
			if (a[i]._count != invalid._count)
			//��������if�ж�һ���ǲ���Ҫ�ģ�����Ϊ�˴���һ������������ʱ��ֻ�ѳ��ֵ��ַ����������ͺ���
			minHeap.PushBack(new Node(a[i]));    //����ÿ��PushBack��ʱ�򶼻����һ�����򣬵�������������ǰ���֮ǰд���Ƶ�
							//������������Ӧ��дpush������
		}
		//�����ڵ���Pushback��ʱ�������⣬��������û�н���һ�����ӵĲ���


		Node* left = NULL;
		Node* right = NULL;
		Node* root = NULL;
		while (minHeap.Size()>1)     //������Ҫ��һ��ѭ���Ľ�����־�����Զ�������дһ��size���������ǵõ�������Ԫ�صĶ���
		{
			left = minHeap.Top();    //�õ���С������Ȩ�صĽڵ�
			minHeap.PopFront();
			right = minHeap.Top();
			minHeap.PopFront();


			//root = new Node(left->_count + right->_count);      //�����Ҿ���Ҫ�����ҵ��ļ�ѹ��������Ҫ������дԴ���룬�����
			//										//��Ҫ����_count
			//					//�����ҵ�����Ǵ�Ĳ�Ӧ��ʹ��root = new Node(left->_count + right->_count);�����_count
			//����Ӧ��ʹ��ԭ����_w����Ϊ����huffmantree��ʹ�õ���һ���ڵ㣬��������Ӧ��������charinfo�е�operator+
			root = new Node(left->_w + right->_w);
			root->_left = left;
			left->_parent = root;
			root->_right = right;
			right->_parent = root;
			minHeap.PushBack(root);
		}
		_node = minHeap.Top();
	}

	Node* Getroot()
	{
		return _node;
	}
private:
	Node* _node;
};