#pragma once 

#include<iostream>
using namespace std;
#include<queue>
#include<stack>

template<class T>
struct BinaryNode
{
	BinaryNode(T data)
	:_data(data)
	, _left(NULL)
	, _right(NULL)
	{}

	T _data;
	BinaryNode<T>* _left;
	BinaryNode<T>* _right;
};

template<class T>
class Binary
{
	typedef BinaryNode<T> Node;
public:
	Binary(T* arry, size_t n, const T& invalid)   //传递一个数组，数组的长度，和一个非法数据
		//采用先序遍历的方式创建一个二叉树
		//这里在成员函数中 一般不使用递归，所以我们这里写一个函数来创建一个树
	{
		size_t index = 0;
		_root = _Binary(arry, n, invalid, index);
	}
	Binary(const Binary& tree)
	{
		_root = CBinary(tree);
	}
	~Binary()
	{
		Clear(_root);
	}
	void PrevShow()   //前序遍历
	{
		_PrevShow(_root);  //递归实现
		cout << endl;
		NoPrevShow(_root);  //非递归实现
		cout << endl;
	}
	void InShow()  //中序遍历
	{
		_InShow(_root);
		cout << endl;
		NoInShow(_root);
		cout << endl;
	}
	void LowShow()  //后序遍历
	{
		_LowShow(_root);
		cout << endl;
		NoLowShow(_root);  //非递归后续遍历
		cout << endl;
	}
	void LevelShow()  //层序遍历
	{
		_LevelShow(_root);
		cout << endl;
	}
	size_t LeavNodeNum()  //叶子节点的个数
	{
		return _LeavNodeNum(_root);
	}
	size_t NodeNum()
	{
		return _NodeNum(_root);
	}
	size_t LevelNum(size_t n)  //某一层的节点的个数
	{
		return _LevelNum(_root, n);
	}
	size_t Depth()  //算深度
	{
		return _Depth(_root);

	}
	Node* Find(const T& num)
	{
		return _Find(_root,num);
	}


private:
	Node* _Binary(T* arry, size_t n, const T& invalid, size_t& index)   //这里的index是标记数组访问的当前位置
	{
		Node* root = NULL;   //写递归的时候无非就是两种问题，一个是返回条件，一个是子问题。这个时候我们需要一个辅助工具
		//就是if，我们的返回可以先执行，可以后执行，我们的返回条件可以放在if中，也可以放在if外
		/*if ((invalid == arry[index]) || (index == n))
		{
		index++;
		return root;
		}

		else
		{
		root = new Node(arry[index]);
		index++;
		return root;
		}

		root->_left = _Binary(arry, n, invalid,index);
		root->_right = _Binary(arry, n, invalid, index);*/
		if ((invalid != arry[index]) && (index < n))
		{
			root = new Node(arry[index]);
			//index++;
			root->_left = _Binary(arry, n, invalid, ++index);
			root->_right = _Binary(arry, n, invalid, ++index);
		}
		//index++;
		return root;
	}


	//拷贝构造函数还没有写  那个等号运算符的重载也没有写
	//Node* CBinary(const Binary& tree)
	//{
	//	Node* root = NULL;
	//	if ((invalid != arry[index]) && (index < n))
	//	{
	//		root = new Node(arry[index]);
	//		//index++;
	//		root->_left = _Binary(arry, n, invalid, ++index);
	//		root->_right = _Binary(arry, n, invalid, ++index);
	//	}
	//	//index++;
	//	return root;

	//}

	//T& __PrevShow(Node *root)   //改变前序遍历，每次返回一个数据
	//{
	//	if (NULL == root)
	//	{
	//		return '#';
	//	}

	//	return root->_data;
	//	_PrevShow(root->_left);
	//	_PrevShow(root->_right);
	//}

	void _PrevShow(Node *root)   //前序遍历
	{
		if (NULL == root)
		{
			cout << "#" << " ";
			return;
		}

		cout << root->_data << " ";
		_PrevShow(root->_left);
		_PrevShow(root->_right);
	}

	void NoPrevShow(Node *root)  //前序遍历非递归实现
	{
		stack<Node*> s;
		Node* cur = root->_left;
		if (NULL == root)     //如果为NULL返回
		{
			cout << "无节点" << endl;
			return;
		}
		else
		{
			cout << root->_data << " ";   //这里root不为NULL，先访问，然后把root仿佛栈
			s.push(root);     

			while (!s.empty())   //当栈不为空的时候
			{
				while (cur)    //先访问当前节点，如果当前节点的左不为NULL的时候就一直访问左，并且使左入栈
				{
					cout << cur->_data << " ";
					s.push(cur);
					cur = cur->_left;
				}
				//所有的左访问完毕之后，再访问右，并且使左节点出栈
				cur = s.top();
				s.pop();
				cur = cur->_right;
			}
		}
		
	}

	void _InShow(Node* root)
	{
		if (NULL == root)
		{
			cout << "#" << " ";
			return;
		}
		_InShow(root->_left);
		cout << root->_data << " ";
		_InShow(root->_right);
	}

	void NoInShow(Node* root)  //中序遍历非递归实现
	{
		Node* cur = root->_left;
		if (NULL == root)
		{
			cout << "无节点" << endl;
		}
		else
		{
			stack<Node*> s;
			s.push(root);  //先使根节点入栈
			while (!s.empty())  //当栈不为NULL
			{
				while (cur)   //先把所有的左子树入栈
				{
					s.push(cur);
					cur = cur->_left;
				}
				cur = s.top();   //取栈顶节点访问
				cout << cur->_data << " ";
				s.pop();
				cur = cur->_right;
			}
		}
	}

	void _LowShow(Node* root)  //后续遍历
	{
		if (NULL == root)
		{
			cout << "#" << " ";
			return;
		}
		_LowShow(root->_left);
		_LowShow(root->_right);
		cout << root->_data << " ";
	}

	void NoLowShow(Node* root)  //后续遍历
	{
		stack<Node*> s;
			Node* cur = NULL;                      //当前结点 
			Node*pre = NULL;                 //前一次访问的结点 
			s.push(root);
			while (!s.empty())
			{
				cur = s.top();
				if ((cur->_left == NULL&&cur->_right == NULL) ||
					(pre != NULL && (pre == cur->_left || pre == cur->_right)))
				{
					cout << cur->_data << " ";  //如果当前结点没有孩子结点或者孩子节点都已被访问过 
					s.pop();
					pre = cur;
				}
				else   //左进入之后进入右，而不能像我的一样，一直进去左然后才进入右
				{
					if (cur->_right != NULL)
						s.push(cur->_right);
					if (cur->_left != NULL)
						s.push(cur->_left);
				}
			}
		}
				//cur = s.top();    //判断放右子树
				//cur = cur->_right;
				//if (NULL == cur)   //如果右子树为NULL，打印且出栈，如果右子树不为空，又跳回到上面的逻辑，继续放节点
				//{
				//	cur = s.top();
				//	cout << cur->_data << " ";
				//	s.pop();
				//	left = 1;   //说明左子树已经被打印了
				//}
				//if (1 == left)
				//{
				//	cur = s.top();
				//	cur = cur->_right;
				//}
				//


				//if (flag == 1)
				//{
				//	cur = s.top();
				//	if (NULL == cur->_right)  //区别它的右边是否为NULL
				//	{
				//		cout << cur->_data << " ";
				//		s.pop();
				//		flag = 3;
				//		if (!s.empty())
				//		{
				//			cur = s.top();
				//			cur = cur->_right;
				//		}
				//	}
				//	else
				//	{
				//		cur = cur->_right;
				//	}
				//	
				//	
				//}
	

	void _LevelShow(Node* root)  //层序遍历
	{
		queue<Node*> q;
		Node* cur = NULL;
		/*if (root != NULL)
		{

		}*/
		q.push(root);
		while (!q.empty())
		{
			cur = q.front();
			q.pop();
			cout << cur->_data << " ";
			if (cur->_left)
			{
				q.push(cur->_left);
			}
			if (cur->_right)
			{
				q.push(cur->_right);
			}
		}

	}

	size_t _LeavNodeNum(Node* root)   ////叶子节点的个数   递归   返回条件，子问题
	{
		if ((NULL == root->_left) && (NULL == root->_right))
			return 1;
		else if (NULL == root->_left)
		{
			return _LeavNodeNum(root->_right);
		}
		else if (NULL == root->_right)
		{
			return _LeavNodeNum(root->_left);
		}
		return _LeavNodeNum(root->_left) + _LeavNodeNum(root->_right);  

	}

	size_t _NodeNum(Node* root)
	{
		if ((NULL == root->_left)&&(root->_right == NULL))   //当左右为空的时候返回1
		{
			return 1;
		}
		else if ((NULL == root->_left) && (NULL != root->_right))  //当一个节点为空的时候返回另一个节点，再加上自己的1 
		{
			return _NodeNum(root->_right) + 1;
		}
		else if ((NULL == root->_right) && (NULL != root->_left))
		{
			return _NodeNum(root->_left) + 1;
		}
		return _NodeNum(root->_left) + _NodeNum(root->_right) + 1;   //当左右都不为空的时候，返回左右测得的结果，然后在加上自己
	}

	size_t _LevelNum(Node* root,size_t n )
	{
		//想算某一层的，我就需要知道他的上一层的子节点个数
		//  1.指针为NULL，返回  2. 不为空，如果n == 1 ,返回1，else返回左加一，然后返回又加一
		if (NULL == root)
		{
			return 0;
		}
		if (1 == n)
		{
			return 1;
		}
		else
		{
			return _LevelNum(root->_left, n - 1) + _LevelNum(root->_right,n - 1);
		}
	}

	size_t _Depth(Node* root)
	{
		if (NULL == root)
		{
			return 0;
		}
		else
		{
			if ((NULL == root->_left) && (NULL == root->_right))
			{
				return 1;
			}
			int l = _Depth(root->_left);
			int r = _Depth(root->_right);
			if (l > r)
				return l + 1;
			else
				return r + 1;
		}
	}

	Node* _Find(Node* root, const T& num)       //特别重要，但是我不知道为什么了
	{
		if (NULL == root)
		{
			return NULL;
		}
		else
		{
			if (num == root->_data)
			{
				return root;
			}
			Node* ret = _Find(root->_left, num);
			if (ret)
			{
				return ret;
			}
			ret = _Find(root->_right, num);
		}
	}

	void Clear(Node* root)
	{
		if (NULL == root)
		{
			return;
		}
		Clear(root->_left);  //当我们的root是一个叶子节点的时候，有一个栈，这里面有一个root指向的就是这个叶子节点
				//我们进入到这个递归函数中去，但是这搁左是NULL，然后从左中返回，然后delete这个叶子的root，
				//通过这个思想可以把我之前写的一个好几类的情况的讨论给修改了
		Clear(root->_right);   
		delete root;
		root = NULL;
	}
private:
	Node* _root;
};