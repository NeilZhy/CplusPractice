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
		while (parent)
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

				RotaL(parent);

			}
			if (parent->_bf == -2 && parent->_left->_bf == -1)
			{

				RotaR(parent);
			}
			if (parent->_bf == 2 && parent->_right->_bf == -1)
			{
				//先右旋后左旋
				RotaR(parent->_right);
				RotaL(parent);
			}
			if (parent->_bf == -2 && parent->_left->_bf == 1)
			{
				//先左旋后右旋
				RotaL(parent->_left);
				RotaR(parent);
			}

			if (0 == parent->_bf)  //当我们的其中一个父节点的bf为的时候，就不需要再调整了
			{
				break;
			}
			cur = parent;
			parent = parent->_parent;

		}
		return true;
	}

	bool IsBanlance()
	{
		int num = 0;
		return _IsBanlance(_root,num);
	}

private:
	//我们想判断一个AVLTree是不是符合 我们的要求,这里我们的判断方法 是通过计算树（还有子树）的高度，比较差距，然后得到
	//高度差，这样进行比较
	bool _IsBanlance(Node* root,int& length)
	{
		//结束条件
		if (NULL == root)
		{
			length = 0;
			return true;
		}

		//子问题
		_IsBanlance(root->_left, length);
		int left = length;
		_IsBanlance(root->_right, length);
		int right = length;
		if (abs(left - right) > 1)
		{
			cout << "AVL  false" << root->_k << endl;
			return false;
		}	
		if (left >= right)
		{
			length = left;
		}
		else
		{
			length = right;
		}
		//原子问题处理
		//在子问题中，我们想，递归的时候每次往上一层递归的时候保存高度，递归往上的时候就随时加1
		length++;
		cout << "AVL  true" << root->_k << endl;
		return true;
	}


	void RotaL(Node* parent)   //右旋
	{
		Node* pprent = parent->_parent;
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (NULL != subRL)    //这个时候subLR可能为NULL，这个时候他是没有父亲的
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		parent->_parent = subR;
		if (pprent->_left == parent)
		{
			pprent->_left = subR;
			subR->_parent = pprent;
		}
		if (pprent->_right == parent)
		{
			pprent->_right = subR;
			subR->_parent = pprent;
		}
		//如果是根节点
		if (pprent == NULL)
		{
			_root = subR;
		}

		//调整平衡因子，这里把平衡因子都调整为0
		subR->_bf = 0;
		parent->_bf = 0;
	}

	void RotaR(Node* parent)   //右旋
	{
		Node* pprent = parent->_parent;
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (NULL != subLR)    //这个时候subLR可能为NULL，这个时候他是没有父亲的
		{
			subLR->_parent = parent;
		}	
		subL->_right = parent;
		parent->_parent = subL;
		//当pprent为NULL的时候，我们下面的这个就不能通过
		
		//如果是根节点
		if (pprent == NULL)
		{
			_root = subL;
		}
		else
		{
			if (pprent->_right == parent)
			{
				pprent->_right = subL;
				subL->_parent = pprent;
			}
			if (pprent->_left == parent)
			{
				pprent->_left = subL;
				subL->_parent = pprent;
			}
		}
	

		//调整平衡因子，这里把平衡因子都调整为0
		subL->_bf = 0;
		parent->_bf = 0;
	}




private:
	Node* _root;
};