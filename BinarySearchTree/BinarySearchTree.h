#include<iostream>
using namespace std;

//节点
template<class K>
struct BinarySearchNode    //使用二叉链实现
{
	BinarySearchNode(K key)
	{
		_k = key;
		_left = NULL;
		_right = NULL;
	}
	BinarySearchNode* _left;
	BinarySearchNode* _right;
	K _k;
};

//搜索二叉树的特点是，左子树小，右子树大，他们的值互不相等
template<class K>
class BinarySearchTree
{
	typedef BinarySearchNode<K> Node;
public:
	BinarySearchTree()
		:_root(NULL)
	{
	}
	
	bool Push(K key)   //因为这里有可能是搜索树中已经有了这个值的，但是我们要求的是值不能一样，所以这里如果插入失败的
				//就是返回值是bool
	{
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
				}
				cur = cur->_right;
			}
			else if (key < cur->_k)
			{
				if (cur->_left == NULL)
				{
					cur->_left = insert;
				}
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		//if (parent->_left == cur)
		//{
		//	parent->_left = insert;
		//}
		//if (parent->_right == cur)   //if (parent->_right = cur)  这里一开始写错了
		//{
		//	parent->_right = insert;
		//}
		return true;
	}

	const Node* Find(K key)  const //有这种写法吗，这里 我们find的时候不能 修改它，因为如果我们修改了的话，这个树可能就不是
					//搜索二叉树了
	{
		Node* cur = _root;
		while (cur)
		{
			if (key < cur->_k)
			{
				cur = cur->_left;
			}
			else if (key > cur->_k)
			{
				cur = cur->_left;
			}
			else
			{
				cout << "地址为： " << cur << "数据为 ： " << cur->_k << endl;
				return cur;
			}
		}
		return NULL;
	}

	 /*void testFind()
	 {
		 Find(5)->_k = 0;
	 }*/

	void DeleteNode(K key)
	{
		Node* cur = _root;
		Node* parent = cur;
		while (cur)
		{
			if (key < cur->_k)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (key>cur->_k)
			{
				parent = cur;
				cur = cur->_right;
			}
			else    //注意改变的是_root
			{
				if (NULL == cur->_left)   //当前节点的左子树为空，父节点指向当前节点的右子树
				{
					if (_root == cur)   //if判断里面处理的是当前节点 刚好为根节点的情况
					{
						_root = cur->_right;
						delete cur;
						break;
					}
					if (parent->_left == cur)
					{
						parent->_left = cur->_right;
					}
					if (parent->_right == cur)
					{
						parent->_right = cur->_right;
					}
					delete cur;
					break;
				}
				else if (NULL == cur->_right)  //当前节点的右子树为空，父节点指向当前节点的左子树
											//上面的两种情况还包括了当前节点的左右子树都为空的情况
				{
					if (_root == cur)
					{
						_root = cur->_left;
						delete cur;
						break;
					}
					if (parent->_left == cur)
					{
						parent->_left = cur->_left;
					}
					if (parent->_right == cur)
					{
						parent->_right = cur->_left;
					}
					delete cur;
					break;
				}
				else   //左右都不为空
				{
					Node* prev = cur;
					Node* del = cur->_right;
					
					while (del)
					{
						if (NULL == del->_left)
						{
							swap(cur->_k, del->_k);
							cur = del;
							del = cur->_right;
							continue;
						}
						prev = del;
						del = del->_left;
					}
					if (prev->_left == cur)
					{
						prev->_left = NULL;
					}
					if (prev->_right == cur)
					{
						prev->_right = NULL;
					}
					delete cur;
					break;
				}

			}
		}
	}



private:
	Node* _root;
};