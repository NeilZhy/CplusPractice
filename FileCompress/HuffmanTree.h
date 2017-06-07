#pragma once
#include<iostream>
using namespace std;
#include"Heap.h"
#include<string>

//构造一个HuffmanNode
template<class T>
struct HuffmanNode
{
	HuffmanNode* _parent;
	HuffmanNode* _left;   //左子树
	HuffmanNode* _right;   //右子树
	T _w;                 //权值

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
			return left->_w < right->_w;         //这里我们需要重载operator<()
		}
	};

	HuffmanTree(T* a, int n, T& invalid = T())    //这里给了一个默认的参数T()是因为如果我这里只穿了一个假如是一个int值
		//那么这里可以用T()给这个int值构造一个对象出来
	{
		//创建哈夫曼树，我们需要取最小的两个数据，这个时候肯定不能用排序的方式，这样做每次都需要排序一个，
		//太过繁琐，所以这里我们创建一个堆，每次取堆里面的堆顶的元素，这里直接把之前写的那个堆头文件拿过来使用就好
		//Heap<Node*> minHeap(a,n);   //这是一个小顶堆，因为我们每次需要取其中最小的两个元素，所以这里我们在heap中还需要写top
		//						//在这个小顶堆的时候，我们可以先构造一个空的堆，然后调用push，我上面就是想直接使用
		//				//构造函数一步到位
		Heap<Node*, NodeCompare> minHeap;    //这样的话，我们就把各个节点的指针放在了堆里面
		for (int i = 0; i < n;i++)
		{
			if (a[i]._count != invalid._count)
			//下面的这个if判断一般是不需要的，但是为了创建一个哈夫曼树的时候，只把出现的字符建立起来就好了
			minHeap.PushBack(new Node(a[i]));    //这里每次PushBack的时候都会进行一次排序，但是这里的排序是按照之前写的牌的
							//所以这里我们应该写push的重载
		}
		//这里在调用Pushback的时候有问题，就是它并没有进行一个建队的操作


		Node* left = NULL;
		Node* right = NULL;
		Node* root = NULL;
		while (minHeap.Size()>1)     //这里需要做一个循环的结束标志，所以堆里面再写一个size函数，就是得到堆里面元素的多少
		{
			left = minHeap.Top();    //拿到最小的两个权重的节点
			minHeap.PopFront();
			right = minHeap.Top();
			minHeap.PopFront();


			//root = new Node(left->_count + right->_count);      //这里我就需要根据我的文件压缩的特殊要求来改写源代码，这里就
			//										//需要给成_count
			//					//这里我的理解是错的不应该使用root = new Node(left->_count + right->_count);里面的_count
			//而是应给使用原来的_w，因为我在huffmantree中使用的是一个节点，这里我们应该是重载charinfo中的operator+
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