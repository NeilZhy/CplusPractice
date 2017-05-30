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
		while (parent)  //������Ҫһֱ���ϵ����� ,����Ϊ����Ҫ���������ϵ�����
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
				//�ҵ�
				RotaR(parent);

			}
			if (parent->_bf == -2 && parent->_right->_bf == -1)
			{
				//��
				RotaL(parent);
			}
			if (parent->_bf == 2 && parent->_right->_bf == -1)
			{
				//��˫
				RotaR(parent->_right);
				RotaL(parent);
			}
			if (parent->_bf == -2 && parent->_left->_bf == 1)
			{
				//��˫
				RotaR(parent->_left);
				RotaL(parent);
			}
			cur = parent;
			parent = parent->_parent;
		}
		return true;
	}

private:
	void RotaL(Node* parent)   //��
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
		//����Ǹ��ڵ�
		if (pprent == _root)
		{
			_root = subL;
		}

		//����ƽ�����ӣ������ƽ�����Ӷ�����Ϊ0
		subL->_bf = 0;
		parent->_bf = 0;
	}

	void RotaR(Node* parent)   //��
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
		//����Ǹ��ڵ�
		if (pprent == _root)
		{
			_root = subR;
		}

		//����ƽ�����ӣ������ƽ�����Ӷ�����Ϊ0
		subR->_bf = 0;
		parent->_bf = 0;
	}


private:
	Node* _root;
};