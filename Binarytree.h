#pragma once 

#include<iostream>
using namespace std;
#include<queue>

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
	Binary(T* arry, size_t n, const T& invalid)   //����һ�����飬����ĳ��ȣ���һ���Ƿ�����
		//������������ķ�ʽ����һ��������
		//�����ڳ�Ա������ һ�㲻ʹ�õݹ飬������������дһ������������һ����
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
	void PrevShow()   //ǰ�����
	{
		_PrevShow(_root);
		cout << endl;
	}
	void InShow()  //�������
	{
		_InShow(_root);
		cout << endl;
	}
	void LowShow()  //�������
	{
		_LowShow(_root);
		cout << endl;
	}
	void LevelShow()  //�������
	{
		_LevelShow(_root);
		cout << endl;
	}
	size_t LeavNodeNum()  //Ҷ�ӽڵ�ĸ���
	{
		return _LeavNodeNum(_root);
	}
	size_t NodeNum()
	{
		return _NodeNum(_root);
	}
	size_t LevelNum(size_t n)  //ĳһ��Ľڵ�ĸ���
	{
		return _LevelNum(_root, n);
	}
	size_t Depth()  //�����
	{
		return _Depth(_root);

	}
	Node* Find(const T& num)
	{
		return _Find(_root,num);
	}


private:
	Node* _Binary(T* arry, size_t n, const T& invalid, size_t& index)   //�����index�Ǳ��������ʵĵ�ǰλ��
	{
		Node* root = NULL;   //д�ݹ��ʱ���޷Ǿ����������⣬һ���Ƿ���������һ���������⡣���ʱ��������Ҫһ����������
		//����if�����ǵķ��ؿ�����ִ�У����Ժ�ִ�У����ǵķ����������Է���if�У�Ҳ���Է���if��
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


	//�������캯����û��д  �Ǹ��Ⱥ������������Ҳû��д
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

	//T& __PrevShow(Node *root)   //�ı�ǰ�������ÿ�η���һ������
	//{
	//	if (NULL == root)
	//	{
	//		return '#';
	//	}

	//	return root->_data;
	//	_PrevShow(root->_left);
	//	_PrevShow(root->_right);
	//}

	void _PrevShow(Node *root)   //ǰ�����
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

	void _LowShow(Node* root)  //��������
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


	void _LevelShow(Node* root)  //�������
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

	size_t _LeavNodeNum(Node* root)   ////Ҷ�ӽڵ�ĸ���   �ݹ�   ����������������
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
		if ((NULL == root->_left)&&(root->_right == NULL))   //������Ϊ�յ�ʱ�򷵻�1
		{
			return 1;
		}
		else if ((NULL == root->_left) && (NULL != root->_right))  //��һ���ڵ�Ϊ�յ�ʱ�򷵻���һ���ڵ㣬�ټ����Լ���1 
		{
			return _NodeNum(root->_right) + 1;
		}
		else if ((NULL == root->_right) && (NULL != root->_left))
		{
			return _NodeNum(root->_left) + 1;
		}
		return _NodeNum(root->_left) + _NodeNum(root->_right) + 1;   //�����Ҷ���Ϊ�յ�ʱ�򣬷������Ҳ�õĽ����Ȼ���ڼ����Լ�
	}

	size_t _LevelNum(Node* root,size_t n )
	{
		//����ĳһ��ģ��Ҿ���Ҫ֪��������һ����ӽڵ����
		//  1.ָ��ΪNULL������  2. ��Ϊ�գ����n == 1 ,����1��else�������һ��Ȼ�󷵻��ּ�һ
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

	Node* _Find(Node* root, const T& num)       //�ر���Ҫ�������Ҳ�֪��Ϊʲô��
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
		Clear(root->_left);  //�����ǵ�root��һ��Ҷ�ӽڵ��ʱ����һ��ջ����������һ��rootָ��ľ������Ҷ�ӽڵ�
				//���ǽ��뵽����ݹ麯����ȥ�������������NULL��Ȼ������з��أ�Ȼ��delete���Ҷ�ӵ�root��
				//ͨ�����˼����԰���֮ǰд��һ���ü������������۸��޸���
		Clear(root->_right);   
		delete root;
		root = NULL;
	}
private:
	Node* _root;
};