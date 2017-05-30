#include<iostream>
using namespace std;

template<class K>
struct AVLNode
{
	AVLNode* _parent;
	AVLNode* _left;
	AVLNode* _right;
	K _k;
	int _bf;
	AVLNode(K key)
	{
		_parent = NULL;
		_right = NULL;
		_left = NULL;
		_k = key;
		_bf = 0;
	}
};

template<class K>
class AVLTree
{
	typedef AVLNode<K> Node;
public:
	AVLTree()
		:_root(NULL)
	{}

	bool Insert(K key)
	{
		//首先使用搜索二叉树的 方式把一个节点插进去
		Node* insert = new Node(key);
		if (NULL == _root)
		{
			_root = insert;
			return true;
		}
		Node* cur = _root;
		Node* parent = cur;

		while (cur)
		{
			if (key > cur->_k)
			{
				if (cur->_right == NULL)
				{
					cur->_right = insert;
					insert->_parent = cur;
					break;  //当一个节点插入之后我们应该停止while
				}

				cur = cur->_right;
				parent = cur;

			}
			else if (key < cur->_k)
			{
				if (cur->_left == NULL)
				{
					cur->_left = insert;
					insert->_parent = cur;
					break;
				}

				cur = cur->_left;
				parent = cur;
			}
			else
			{
				return false;
			}


			
		}
		cur = insert;
		while (parent)  //这里需要一直往上调整吗 ,我认为不需要继续往往上调整了
		{
			//首先更新当前的，右++，左--
			if (parent->_left == cur)
			{
				parent->_bf--;
				
			}
			if (parent->_right == cur)
			{
				parent->_bf++;
				
			}
			
			

			//旋转
			if (parent->_bf == 2 && parent->_right->_bf == 1)
			{
				//右单
				RotaR(parent);

			}
			if (parent->_bf == -2 && parent->_right->_bf == -1)
			{
				//左单
				RotaL(parent);
			}
			if (parent->_bf == 2 && parent->_right->_bf == -1)
			{
				//左双
				RotaR(parent->_right);
				RotaL(parent);
			}
			if (parent->_bf == -2 && parent->_left->_bf == 1)
			{
				//右双
				RotaR(parent->_left);
				RotaL(parent);
			}
			cur = parent;
			parent = parent->_parent;
		}
		return true;
	}

private:
	void RotaL(Node* parent)   //左单
	{
		Node* pprent = parent->_parent;
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_right = subLR;
		subLR->_parent = parent;
		subL->_right = parent;
		parent->_parent = subL;
		if (pprent->_left == parent)
		{
			pprent->_left = subL;
			subL->_parent = pprent;
		}
		if (pprent->_right == parent)
		{
			pprent->_right = subL;
			subL->_parent = pprent;
		}
		//如果是根节点
		if (pprent == _root)
		{
			_root = subL;
		}

		//调整平衡因子，这里把平衡因子都调整为0
		subL->_bf = 0;
		parent->_bf = 0;
	}

	void RotaR(Node* parent)   //左单
	{
		Node* pprent = parent->_parent;
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_left = subRL;
		subRL->_parent = parent;
		subR->_left = parent;
		parent->_parent = subR;
		if (pprent->_right == parent)
		{
			pprent->_right = subR;
			subR->_parent = pprent;
		}
		if (pprent->_left == parent)
		{
			pprent->_left = subR;
			subR->_parent = pprent;
		}
		//如果是根节点
		if (pprent == _root)
		{
			_root = subR;
		}

		//调整平衡因子，这里把平衡因子都调整为0
		subR->_bf = 0;
		parent->_bf = 0;
	}


private:
	Node* _root;
};