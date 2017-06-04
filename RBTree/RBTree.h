#pragma once
#include<iostream>
using namespace std;

enum Clor
{
	RED,
	BLACK
};

template<class K>
struct RBNode
{
	RBNode* _left;
	RBNode* _right;
	RBNode* _parent;
	K _key;
	Clor _clor;
	RBNode(K key)
		:_left(NULL)
		,_right(NULL)
		,_parent(NULL)
		, _key(key)
		, _clor(RED)
	{}
};

template<class K>
class RBTree
{
	typedef RBNode<K> Node;
public:
	RBTree()
		:_root(NULL)
	{
	}

	bool IsBanlance()
	{
		if (_root->_clor == RED)   //判断根节点是否为黑
		{
			return false;
		}
		//求最左的黑色的个数，作为一个比较的基本值
		int blcNum = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_clor == BLACK)
			{
				blcNum++;
			}
			cur = cur->_left;
		}
		int num = 0;   //作为每次递归的比较值
		return _IsBanlance(_root,blcNum,num);
	}

	bool Insert(K key)
	{
		//当根节点为空的时候
		if (NULL == _root)
		{
			_root = new Node(key);
			_root->_clor = BLACK;
			return true;
		}
		//当 根节点不为空的时候，使用普通 的插入法就好
		Node* insert = new Node(key);
		Node* cur = _root;
		Node* parent = cur;

		while (cur)
		{
			if (key > cur->_key)
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
			else if (key < cur->_key)
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

		//接下来进行调整
		cur = insert;
		parent = cur->_parent;
		///*Node* pparent = parent->_parent;*/  //这里不能把pp定义到这里，因为，如果p刚好是根节点的上一个
		
		while (parent && parent->_clor == RED)  //当p存在，且p为红的时候
		{
			if (_root == parent)   //这里我们保证了parent是否存在，但是我们没有保证pp是否有意义，如果p是根，直接把p置黑
				//这样每条路上都多了一个黑色节点，对各个路径上面的黑色节点的个数并不影响，这也是下面那些遇到改变颜色就
				//改变根节点为黑色的道理是一样的
			{
				_root->_clor = BLACK;
				break;
			}
			Node* pparent = parent->_parent;  //
			//开始一层判断，把所有的双旋的改成单旋的情形
			if (pparent->_left == parent && parent->_right == cur)
			{
				RotaL(parent);
				//把他们变成左单和右单之后要调整父子
				cur = parent;
				parent = parent->_parent;
			}

			if (pparent->_right == parent && parent->_left == cur)
			{
				RotaR(parent);
				//把他们变成左单和右单之后要调整父子
				cur = parent;
				parent = parent->_parent;
			}

			//此时已经变成了只有单旋的情况了
			//单旋中最外面是一个大的判断是判断是左单还是右单
			if (parent->_left == cur)  //左单
			{
				//下面的一层判断是叔叔是否存在
				//这里uncle不存在和uncle存在未黑的处理逻辑是一样的










				Node* uncle = pparent->_right;
				if (uncle)  //uncle存在
				{
					//uncle存在时判断uncle颜色
					if (uncle->_clor == RED)
					{
						//调整颜色
						pparent->_clor = RED;
						parent->_clor = BLACK;
						uncle->_clor = BLACK;
						//改变关系，进行下一次循环
						cur = pparent;
						parent = cur->_parent;
						_root->_clor = BLACK;  //只要我有颜色改动的地方我就把根节点的clor改成黑色，这样就结果了万一把根节点改成了红色的问题了
						continue;  //这里如果不continue，uncle被换成了黑色，那么下面的判断uncle是否为黑又进去了
						//pparent = parent->_parent;   //这里的pp不能写在这里因为p可能是根节点上面的那个NULL，那么pp
														//根本就是没有意义的，而且运行的时候很可能就会挂掉
					}
					if (uncle->_clor == BLACK)
					{
						RotaR(pparent);
						parent->_clor = BLACK;
						pparent->_clor = RED;
						_root->_clor = BLACK;  //只要我有颜色改动的地方我就把根节点的clor改成黑色，这样就结果了万一把根节点改成了红色的问题了
						break;
					}
				}
				else   //uncle不存在
				{
					RotaR(pparent);
					parent->_clor = BLACK;
					pparent->_clor = RED;
					_root->_clor = BLACK;  //只要我有颜色改动的地方我就把根节点的clor改成黑色，这样就结果了万一把根节点改成了红色的问题了
					break;
				}
			}


			if (parent->_right == cur) //右单
			{
				Node* uncle = pparent->_left;
				if (uncle)  //uncle存在
				{
					//uncle存在时判断uncle颜色
					if (uncle->_clor == RED)
					{
						//调整颜色
						pparent->_clor = RED;
						parent->_clor = BLACK;
						uncle->_clor = BLACK;
						_root->_clor = BLACK;  //只要我有颜色改动的地方我就把根节点的clor改成黑色，这样就结果了万一把根节点改成了红色的问题了
						//改变关系，进行下一次循环
						cur = pparent;
						parent = cur->_parent;
						continue;
						//pparent = parent->_parent;
					}
					if (uncle->_clor == BLACK)
					{
						RotaL(pparent);
						parent->_clor = BLACK;
						pparent->_clor = RED;
						_root->_clor = BLACK;  //只要我有颜色改动的地方我就把根节点的clor改成黑色，这样就结果了万一把根节点改成了红色的问题了
						break;
					}
				}
				else   //uncle不存在
				{
					RotaL(pparent);
					parent->_clor = BLACK;
					pparent->_clor = RED;
					_root->_clor = BLACK;  //只要我有颜色改动的地方我就把根节点的clor改成黑色，这样就结果了万一把根节点改成了红色的问题了
					break;
				}
			}

		}
		return true;
	}


private:
	bool _IsBanlance(Node* root,int blcNum, int num)  //这里我们不用引用的原因是，每次我们在栈帧里面返回之后还想保留原来的值
	{
		if (root == NULL)   //递归到最后一层的时候返回
		{
			if (num != blcNum)   //这里到根节点之后，就需要判断所得到的这个数据的大小是否和传入的比较值相等
			{
				cout << "错误" << endl;
				return false;
			}
			/*cout << "根节点，此路正确而 " << root->_parent->_key << endl;*///这里root已经为空了，所以我们不能打印key
			cout << "正确" << endl;
			return true;
		}
		if (root->_clor == RED)   //这里因为传入的一个指针，他一开始肯定不是红色的，而根节点一定 是红的，所以它的父亲一定
						//存在，所以这里我们可以通果判断它的父亲和他的颜色色进行比较
		{
			if (root->_parent->_clor == RED)
			{
				return false;
			}
		}

		if (root->_clor == BLACK)
		{
			num++;
		}

		return _IsBanlance(root->_left, blcNum, num) && _IsBanlance(root->_right,blcNum,num);

	}
	void RotaL(Node* parent)   //左旋
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

		//如果是根节点
		if (pprent == NULL)
		{
			_root = subR;
			subR->_parent = NULL;
		}
		else
		{
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
		}
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
			subL->_parent = NULL;
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
	}


private:
	Node* _root;
};

