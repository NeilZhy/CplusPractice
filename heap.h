#pragma once

#include<iostream>
#include<vector>
using namespace std;

template<class T>   //利用仿函数
struct Less
{
	bool operator()(const T& left,const T& right)
	{
		return left < right;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T& left, const T& right)
	{
		return left > right;
	}
};

template<class T,class Container = Greater<int>>  //这里的Heap应该是一个完全二叉树，特点就是，左边的一定有，叶子节点出现在最后两层
class Heap
{
public:
	Heap(T* arr, size_t size)   //这个地方我们在函数里面不能使用size_t size = sizeof(arr) / sizeof(arr[0]); 
	{								//因为这里离传递过来数组的时候，数组名会降级为指针，这样所测得的结果就是4
		for (size_t i = 0; i < size; i++)
		{
			_hp.push_back(arr[i]);
		}

		//建堆
		for (int i = (size-2) / 2; i>=0;i--)   //找到倒数第一个非叶子节点，下标从0开始，所以这里结束是0
		{
			AdjustDown(i);
		}
	}

	void PushBack(int data)   //首先现在vector里面加入一个数据，然后调用AdjustUp进行向上调整
	{
		_hp.push_back(data);
		int child = _hp.size() - 1;
		AdjustUp(child);
	}

	void PopFront()   //这个是删除一个数据，可以先和最后一个数据进行交换后，然后删除最后一个节点，然后在进行调整
	{
		int size = _hp.size() - 1;
		swap(_hp[0],_hp[size]);
		_hp.pop_back();
		AdjustDown(0);
	}

	void HeapSort(int size)
	{
		for (int i = size - 1; i > 0; i--)
		{
			swap(_hp[0],_hp[i]);
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
	void TopK(int n,int size)    //实现找最大的五个数据，这个时候，我们建立的就是一个有五个数据的小堆，所以这里我们应该做的就是
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
				swap(_hp[i],_hp[0]);
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
		size_t child = root * 2 + 1;    //这里默认的应该是左子树
		size_t size = _hp.size() - 1;
		if (((child + 1)<size) && (_hp[child] < _hp[child + 1]))//child标记的是大的那一个,加上 前面的那一个判断,这里有一个
						//&&的使用，我们应该把那个判断size放在前面，因为如果把后面的那个放在前面的话，就不能起到判断的作用

		{
			child = child + 1;
		}
		while (child < size)   
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

	void AdjustUp(int child)   
	{
		int root = (child - 1) / 2;
		while (root > 0)   //当0的时候没有办法判断，所以下面单独写一个进行判断
		{
			if (_hp[child] > _hp[root])
			{
				swap(_hp[root], _hp[child]);
			}
			child = root;
			root = (child - 1) / 2;
		}
		if (_hp[child] > _hp[0])
		{
			swap(_hp[root], _hp[child]);
		}
		
	}


private:
	vector<int> _hp;
	Container _con;   //利用仿函数
};