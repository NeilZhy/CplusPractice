#pragma once
#include"HuffmanTree.h"
#include<iostream>
#include<vector>
using namespace std;


template<class T>   //利用仿函数,这里我们不在这里面写那个比较的大小，让_w比较了，我们换在FileCompress中去重载一个operator<
struct Less
{
	bool operator()(const T& left, const T& right) const
	{
		return left < right;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T& left, const T& right) const
	{
		return left > right;
	}
};






//这里特别注意的一点就是，我们在出现模板的地方一定要考虑是不是需要加上模板参数

template<class T, class Container = Less<T>>  //这里的Heap应该是一个完全二叉树，特点就是，左边的一定有，叶子节点出现在最后两层
											//我把比较的位置一换，这样就是都是大于或者都是小于了，所以这样就统一起来了
					//意思就是说，如果我向上调整是大于号，我向下调整是小于号，我可以把小于号里面的比较的数据的前后位置给换
				//一下，这样原本的小于就变成了大于了
class Heap
{
public:
	Heap()
	{}
	Heap(T* arr, size_t size)   //这个地方我们在函数里面不能使用size_t size = sizeof(arr) / sizeof(arr[0]); 
	{								//因为这里离传递过来数组的时候，数组名会降级为指针，这样所测得的结果就是4
		//_hp.reserve(size);   这里使用reserve的作用是，直接改变hp中的capacity，就是直接改变hp中的容量的大小，也就是说
		//这里如果直接使用这一句的话，就是直接开辟了一个空间，这个空间的大小刚刚好够存储size字字节，这样做的好处就是，
		//不需要再pushback的时候，一次次根据大小开辟空间了
		//还有一个函数是resize，这个是直接改变size，就是直接改变当前存储的所占的大小了
		for (size_t i = 0; i < size; i++)
		{
			_hp.push_back(arr[i]);
		}

		//建堆
		for (int i = (size - 2) / 2; i >= 0; i--)   //找到倒数第一个非叶子节点，下标从0开始，所以这里结束是0
		{
			AdjustDown(i);
		}
	}



	void PushBack(T data)   //首先现在vector里面加入一个数据，然后调用AdjustUp进行向上调整
	{
		_hp.push_back(data);
		int child = _hp.size() - 1;
		AdjustUp(child);
	}

	void PopFront()   //这个是删除一个数据，可以先和最后一个数据进行交换后，然后删除最后一个节点，然后在进行调整
	{
		int size = _hp.size() - 1;
		swap(_hp[0], _hp[size]);
		_hp.pop_back();
		AdjustDown(0);
	}

	T Top()
	{
		return _hp[0];
	}

	size_t Size()
	{
		return _hp.size();
	}

	void HeapSort(int size)
	{
		for (int i = size - 1; i > 0; i--)
		{
			swap(_hp[0], _hp[i]);
			size_t root = 0;
			size_t child = root * 2 + 1;    //这里默认的应该是左子树
			size_t msize = i - 1;
			if (((child + 1)<msize) && (_hp[child] < _hp[child + 1]))//child标记的是大的那一个,加上 前面的那一个判断,这里有一个
				//&&的使用，我们应该把那个判断size放在前面，因为如果把后面的那个放在前面的话，就不能起到判断的作用

			{
				child = child + 1;
			}
			while (child < msize)
				//是为了防止我们的数组的下标越界,这里我一开始用的是if，这样的话，就只能调整一次。但是我们要求的是
				//每一个子树都应该是一个堆，所以这里应该是循环，而不应该是if
			{
				if (_hp[root] < _hp[child])
				{
					swap(_hp[root], _hp[child]);
				}
				root = child;
				child = root * 2 + 1;
			}

		}
		for (int i = 0; i < size; i++)
		{
			cout << _hp[i] << " ";
		}
		cout << endl;
	}

	//这里实现的很混乱
	void TopK(int n, int size)    //实现找最大的五个数据，这个时候，我们建立的就是一个有五个数据的小堆，所以这里我们应该做的就是
	{
		//先把五个数据建立成一个小堆
		for (int i = (n - 2) / 2; i >= 0; i--)   //找到倒数第一个非叶子节点，下标从0开始，所以这里结束是0
		{
			int child = i * 2 + 1;    //这里默认的应该是左子树
			int m = n - 1;
			if (((child + 1)<m) && (_hp[child] > _hp[child + 1]))//child标记的是大的那一个,加上 前面的那一个判断,这里有一个
				//&&的使用，我们应该把那个判断size放在前面，因为如果把后面的那个放在前面的话，就不能起到判断的作用

			{
				child = child + 1;
				while (child < m)
					//是为了防止我们的数组的下标越界,这里我一开始用的是if，这样的话，就只能调整一次。但是我们要求的是
					//每一个子树都应该是一个堆，所以这里应该是循环，而不应该是if
				{
					if (_hp[i] > _hp[child])
					{
						swap(_hp[i], _hp[child]);
					}
					i = child;
					child = i * 2 + 1;
				}
			}

		}

		for (int i = n; i < size - 1; i++)
		{
			if (_hp[i] > _hp[0])
			{
				swap(_hp[i], _hp[0]);
				//这里我们就可以体会到了仿函数的好处了，因为我原本的向下调整是建立大堆的，但是我现在想用到的向下调整是
				//建立小堆的，所以这里得做更改
				//我这里先不修改了，自己对于仿函数还不是特别的理解
				size_t root = 0;
				size_t child = root * 2 + 1;    //这里默认的应该是左子树
				size_t m = n - 1;
				if (((child + 1)<m) && (_hp[child] > _hp[child + 1]))//child标记的是大的那一个,加上 前面的那一个判断,这里有一个
					//&&的使用，我们应该把那个判断size放在前面，因为如果把后面的那个放在前面的话，就不能起到判断的作用

				{
					child = child + 1;
					while (child < m)
						//是为了防止我们的数组的下标越界,这里我一开始用的是if，这样的话，就只能调整一次。但是我们要求的是
						//每一个子树都应该是一个堆，所以这里应该是循环，而不应该是if
					{
						if (_hp[root] > _hp[child])
						{
							swap(_hp[root], _hp[child]);
						}
						root = child;
						child = root * 2 + 1;
					}
				}

			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << _hp[i] << " ";
		}
		cout << endl;
	}


private:
	void AdjustDown(int root)   //我这里建立一个大堆
	{  

		//这里需要特别注意的是，我在定义类的时候template<class T, class Container = Less<T>> ，已经确认Container是T类型
				//的了，所以这里不需要再加上模板了
		Container _com;
		int child = root * 2 + 1;    //这里默认的应该是左子树


		int size = _hp.size() - 1;      //当我们的vector里面没有一个数据的时候，我们的_hp.size()是0
					//减去1之后是很大的一个数据，就会导致下面的数据出错，所以这里换做int

		//上面在建树的时候，是调用了一个for循环的，所以我们只需考虑每个内部的树是堆就好了
		//if (((child + 1)<size) && _com(_hp[child + 1],_hp[child]))//child标记的是大的那一个,加上 前面的那一个判断,这里有一个
		//				//&&的使用，我们应该把那个判断size放在前面，因为如果把后面的那个放在前面的话，就不能起到判断的作用

		//{
		//	child = child + 1;
		while (child <= size)
			//是为了防止我们的数组的下标越界,这里我一开始用的是if，这样的话，就只能调整一次。但是我们要求的是
			//每一个子树都应该是一个堆，所以这里应该是循环，而不应该是if
		{
			if (((child + 1) <= size) && _com(_hp[child + 1], _hp[child]))
			{
				child = child + 1;
			}
			if (_com(_hp[child], _hp[root]))
			{
				swap(_hp[child], _hp[root]);
			}
			root = child;
			child = root * 2 + 1;
		}
		//}

	}

	void AdjustUp(int child)
	{
		Container _com;
		int root = (child - 1) / 2;
		while (root > 0)   //当0的时候没有办法判断，所以下面单独写一个进行判断
		{





			//这里并没有调用那个operator（）这个东西
			if (_com(_hp[child],_hp[root]))
			{
				swap(_hp[root], _hp[child]);   //这里我们直接重载oprator<()
			}
			child = root;
			root = (child - 1) / 2;
		}
		if (_com(_hp[child], _hp[root]))
		{
			swap(_hp[root], _hp[child]);
		}

	}


private:
	vector<T> _hp;
	//Container _con;   //利用仿函数
};