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

	bool Insert(K key)
	{
		//�����ڵ�Ϊ�յ�ʱ��
		if (NULL == _root)
		{
			_root = new Node(key);
			_root->_clor = BLACK;
			return true;
		}
		//�� ���ڵ㲻Ϊ�յ�ʱ��ʹ����ͨ �Ĳ��뷨�ͺ�
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
					break;  //��һ���ڵ����֮������Ӧ��ֹͣwhile
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

		//���������е���
		cur = insert;
		parent = cur->_parent;
		///*Node* pparent = parent->_parent;*/  //���ﲻ�ܰ�pp���嵽�����Ϊ�����p�պ��Ǹ��ڵ����һ��
		
		while (parent && parent->_clor == RED)  //��p���ڣ���pΪ���ʱ��
		{
			if (_root == parent)   //�������Ǳ�֤��parent�Ƿ���ڣ���������û�б�֤pp�Ƿ������壬���p�Ǹ���ֱ�Ӱ�p�ú�
				//����ÿ��·�϶�����һ����ɫ�ڵ㣬�Ը���·������ĺ�ɫ�ڵ�ĸ�������Ӱ�죬��Ҳ��������Щ�����ı���ɫ��
				//�ı���ڵ�Ϊ��ɫ�ĵ�����һ����
			{
				_root->_clor = BLACK;
				break;
			}
			Node* pparent = parent->_parent;  //
			//��ʼһ���жϣ������е�˫���ĸĳɵ���������
			if (pparent->_left == parent && parent->_right == cur)
			{
				RotaL(parent);
				//�����Ǳ���󵥺��ҵ�֮��Ҫ��������
				cur = parent;
				parent = parent->_parent;
			}

			if (pparent->_right == parent && parent->_left == cur)
			{
				RotaR(parent);
				//�����Ǳ���󵥺��ҵ�֮��Ҫ��������
				cur = parent;
				parent = parent->_parent;
			}

			//��ʱ�Ѿ������ֻ�е����������
			//��������������һ������ж����ж����󵥻����ҵ�
			if (parent->_left == cur)  //��
			{
				//�����һ���ж��������Ƿ����
				//����uncle�����ں�uncle����δ�ڵĴ����߼���һ����










				Node* uncle = pparent->_right;
				if (uncle)  //uncle����
				{
					//uncle����ʱ�ж�uncle��ɫ
					if (uncle->_clor == RED)
					{
						//������ɫ
						pparent->_clor = RED;
						parent->_clor = BLACK;
						uncle->_clor = BLACK;
						//�ı��ϵ��������һ��ѭ��
						cur = pparent;
						parent = cur->_parent;
						_root->_clor = BLACK;  //ֻҪ������ɫ�Ķ��ĵط��ҾͰѸ��ڵ��clor�ĳɺ�ɫ�������ͽ������һ�Ѹ��ڵ�ĳ��˺�ɫ��������
						continue;  //���������continue��uncle�������˺�ɫ����ô������ж�uncle�Ƿ�Ϊ���ֽ�ȥ��
						//pparent = parent->_parent;   //�����pp����д��������Ϊp�����Ǹ��ڵ�������Ǹ�NULL����ôpp
														//��������û������ģ��������е�ʱ��ܿ��ܾͻ�ҵ�
					}
					if (uncle->_clor == BLACK)
					{
						RotaR(pparent);
						parent->_clor = BLACK;
						pparent->_clor = RED;
						_root->_clor = BLACK;  //ֻҪ������ɫ�Ķ��ĵط��ҾͰѸ��ڵ��clor�ĳɺ�ɫ�������ͽ������һ�Ѹ��ڵ�ĳ��˺�ɫ��������
						break;
					}
				}
				else   //uncle������
				{
					RotaR(pparent);
					parent->_clor = BLACK;
					pparent->_clor = RED;
					_root->_clor = BLACK;  //ֻҪ������ɫ�Ķ��ĵط��ҾͰѸ��ڵ��clor�ĳɺ�ɫ�������ͽ������һ�Ѹ��ڵ�ĳ��˺�ɫ��������
					break;
				}
			}


			if (parent->_right == cur) //�ҵ�
			{
				Node* uncle = pparent->_left;
				if (uncle)  //uncle����
				{
					//uncle����ʱ�ж�uncle��ɫ
					if (uncle->_clor == RED)
					{
						//������ɫ
						pparent->_clor = RED;
						parent->_clor = BLACK;
						uncle->_clor = BLACK;
						_root->_clor = BLACK;  //ֻҪ������ɫ�Ķ��ĵط��ҾͰѸ��ڵ��clor�ĳɺ�ɫ�������ͽ������һ�Ѹ��ڵ�ĳ��˺�ɫ��������
						//�ı��ϵ��������һ��ѭ��
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
						_root->_clor = BLACK;  //ֻҪ������ɫ�Ķ��ĵط��ҾͰѸ��ڵ��clor�ĳɺ�ɫ�������ͽ������һ�Ѹ��ڵ�ĳ��˺�ɫ��������
						break;
					}
				}
				else   //uncle������
				{
					RotaL(pparent);
					parent->_clor = BLACK;
					pparent->_clor = RED;
					_root->_clor = BLACK;  //ֻҪ������ɫ�Ķ��ĵط��ҾͰѸ��ڵ��clor�ĳɺ�ɫ�������ͽ������һ�Ѹ��ڵ�ĳ��˺�ɫ��������
					break;
				}
			}

		}
		return true;
	}


private:
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
	}


private:
	Node* _root;
};

