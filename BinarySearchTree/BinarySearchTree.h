#include<iostream>
using namespace std;

//�ڵ�
template<class K>
struct BinarySearchNode    //ʹ�ö�����ʵ��
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

//�������������ص��ǣ�������С�������������ǵ�ֵ�������
template<class K>
class BinarySearchTree
{
	typedef BinarySearchNode<K> Node;
public:
	BinarySearchTree()
		:_root(NULL)
	{
	}
	
	bool Push(K key)   //��Ϊ�����п��������������Ѿ��������ֵ�ģ���������Ҫ�����ֵ����һ�������������������ʧ�ܵ�
				//���Ƿ���ֵ��bool
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
		//if (parent->_right == cur)   //if (parent->_right = cur)  ����һ��ʼд����
		//{
		//	parent->_right = insert;
		//}
		return true;
	}

	const Node* Find(K key)  const //������д�������� ����find��ʱ���� �޸�������Ϊ��������޸��˵Ļ�����������ܾͲ���
					//������������
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
				cout << "��ַΪ�� " << cur << "����Ϊ �� " << cur->_k << endl;
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
			else    //ע��ı����_root
			{
				if (NULL == cur->_left)   //��ǰ�ڵ��������Ϊ�գ����ڵ�ָ��ǰ�ڵ��������
				{
					if (_root == cur)   //if�ж����洦����ǵ�ǰ�ڵ� �պ�Ϊ���ڵ�����
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
				else if (NULL == cur->_right)  //��ǰ�ڵ��������Ϊ�գ����ڵ�ָ��ǰ�ڵ��������
											//�������������������˵�ǰ�ڵ������������Ϊ�յ����
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
				else   //���Ҷ���Ϊ��
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