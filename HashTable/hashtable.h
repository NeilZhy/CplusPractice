#include<iostream>
using namespace std;
#include<vector>

//作为一个标记位
enum State   
{
	EMPTY,
	EXIT,
	DEL
};


//哈希节点
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
		_table.resize(10);  //预留的数租空间大小是
	}

	//插入函数
	bool Insert(const pair<K,V> node)
	{
		Capacity();
		int m = HanshFunc(node);  //HanshFunc，找到我需要插入的一个下标
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
		//if (_n / _table.capacity() >= 0.7)   //这类需要改进的一个地方 就是，我们不能使用0.7，因为除以了之后，不是一个小数
		//{
		//	printf("增容\n");
		//}
		if (_n * 10 / _table.capacity() >= 7)
		{
			printf("增容\n");
		}
	}

	int HanshFunc(const pair<K, V> node)
	{
		size_t index = node.first % _table.capacity();
		
		return index;
	}

private:
	vector<HashNode<K,V>> _table;  //这个是数组
	size_t _n;  //当前放置的数据的个数是多少
};