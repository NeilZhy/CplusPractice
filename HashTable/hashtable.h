#include<iostream>
using namespace std;
#include<vector>

//��Ϊһ�����λ
enum State   
{
	EMPTY,
	EXIT,
	DEL
};


//��ϣ�ڵ�
template<class K,class V>
struct HashNode
{
	pair<K, V> _kv;
	State _state;
	HashNode()
		:_state(EMPTY)
	{
	}
};

template<class K,class V>
ostream& operator<<(ostream &out, HashNode<K,V> node)
{
	out << " "<< " " << node._state;
	return out;
}


template<class K,class V>
class HashTable
{
	//friend ostream& operator<<(ostream &out, HashNode<K, V> node);
public:
	HashTable()
		:_n(0)
	{
		_table.resize(10);  //Ԥ��������ռ��С��
	}

	//���뺯��
	bool Insert(const pair<K,V> node)
	{
		Capacity();
		int m = HanshFunc(node);  //HanshFunc���ҵ�����Ҫ�����һ���±�
		size_t index = m;
		size_t i = 0;
		while (_table[index]._state == EXIT)
		{
			index = m;
			i++;
			index = m + i*i;
			while (index >= _table.capacity())
			{
				index = index - _table.capacity();

			}
		}
		_table[index]._kv = node;
		_table[index]._state = EXIT;
		_n++;
		return true;
	}

	int Search(const pair<K, V> node)
	{
		size_t m = HanshFunc(node);
		size_t index = m;
		size_t i = 0;
		while (_table[index]._kv.first != node.first)
		{
			if (_table[index]._state == EMPTY)
			{
				return -1;
			}
			index = m;
			i++;
			index = m + i*i;
			while (index >= _table.capacity())
			{
				index = index - _table.capacity();

			}
		}
		return index;
	}

private:
	void Capacity()
	{
		//if (_n / _table.capacity() >= 0.7)   //������Ҫ�Ľ���һ���ط� ���ǣ����ǲ���ʹ��0.7����Ϊ������֮�󣬲���һ��С��
		//{
		//	printf("����\n");
		//}
		if (_n * 10 / _table.capacity() >= 7)
		{
			printf("����\n");
		}
	}

	int HanshFunc(const pair<K, V> node)
	{
		size_t index = node.first % _table.capacity();
		
		return index;
	}

private:
	vector<HashNode<K,V>> _table;  //���������
	size_t _n;  //��ǰ���õ����ݵĸ����Ƕ���
};