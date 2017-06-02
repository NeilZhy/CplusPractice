#pragma once
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
		//����ʹ�������������� ��ʽ��һ���ڵ���ȥ
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
					break;  //��һ���ڵ����֮������Ӧ��ֹͣwhile
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
			//���ȸ��µ�ǰ�ģ���++����--
			if (parent->_left == cur)
			{
				parent->_bf--;

			}
			if (parent->_right == cur)
			{
				parent->_bf++;

			}



			//��ת
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
				//������������
				Node* right = parent->_right;
				RotaR(parent->_right);
				RotaL(parent);

				if (parent->_right == NULL)  
				{
					parent->_bf = -1;
				}
				//if (parent->_right->_left == NULL)//�������֮��parent�Ѿ��ı��� �����Կ���û��right
				//{
				//	parent->_right->_bf = 1;
				//}
				if (right->_left == NULL)
				{
					right->_bf = 1;
				}

			}
			if (parent->_bf == -2 && parent->_left->_bf == 1)
			{
				//������������
				Node* left = parent->_left;
				RotaL(parent->_left);
				RotaR(parent);
				if (parent->_left == NULL)
				{
					parent->_bf = 1;
				}
				//if (parent->_right->_left == NULL)//�������֮��parent�Ѿ��ı��� �����Կ���û��right
				//{
				//	parent->_right->_bf = 1;
				//}
				if (left->_right == NULL)
				{
					left->_bf = -1;
				}
			}

			if (0 == parent->_bf)  //�����ǵ�����һ�����ڵ��bfΪ��ʱ�򣬾Ͳ���Ҫ�ٵ�����
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
	/*�������ж�һ��AVLTree�ǲ��Ƿ��� ���ǵ�Ҫ��,�������ǵ��жϷ��� ��ͨ���������������������ĸ߶ȣ��Ƚϲ�࣬Ȼ��õ�
	�߶Ȳ�������бȽ�*/
	bool _IsBanlance(Node* root,int& length)
	{
		//��������
		if (NULL == root)
		{
			length = 0;
			return true;
		}

		//������
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
		//ԭ�����⴦��
		//���������У������룬�ݹ��ʱ��ÿ������һ��ݹ��ʱ�򱣴�߶ȣ��ݹ����ϵ�ʱ�����ʱ��1
		length++;
		cout << "AVL  true" << root->_k << endl;
		return true;
	}

	//bool _IsBalanceTree(Node* root)     //�ж����Ƿ�ƽ��   [*]  
	//	//�@��һ��O��n^2���㷨�����ϵ��µݹ飬Ȼ�������������ж��Ƿ�ƽ��
	//{
	//	if (root == NULL)
	//		return true;
	//	int left = Depth(root->_left);
	//	int right = Depth(root->_right);

	//	if (right - left != root->_baf)
	//	{
	//		cout << root->_key << ":���ƽ�����Ӵ��󣬽��ƽ�������ǣ�" << root->_baf << endl;
	//	}

	//	return abs(left - right) < 2 && _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);

	//}


	void RotaL(Node* parent)   //����
	{
		Node* pprent = parent->_parent;
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (NULL != subRL)    //���ʱ��subLR����ΪNULL�����ʱ������û�и��׵�
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		parent->_parent = subR;

		//����Ǹ��ڵ�
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
		
		
		//�����ڵ���ƽ�����ӵ�ʱ��
		//����ƽ�����ӣ������ƽ�����Ӷ�����Ϊ����Ϊ���� ���������£�����˫����ʱ����ܳ��ִ���
		//�������ǵ�����Ĵ��벻��Ҫ�Ķ���������������� ˫����ʱ����Ҫ�Ķ�����Ҫ�ֶ������ĵ���ƽ������
		subR->_bf = 0;
		parent->_bf = 0;
	}

	void RotaR(Node* parent)   //����
	{
		Node* pprent = parent->_parent;
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (NULL != subLR)    //���ʱ��subLR����ΪNULL�����ʱ������û�и��׵�
		{
			subLR->_parent = parent;
		}	
		subL->_right = parent;
		parent->_parent = subL;
		//��pprentΪNULL��ʱ���������������Ͳ���ͨ��
		
		//����Ǹ��ڵ�
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
	

		//����ƽ�����ӣ������ƽ�����Ӷ�����Ϊ0
		subL->_bf = 0;
		parent->_bf = 0;
	}




private:
	Node* _root;
};