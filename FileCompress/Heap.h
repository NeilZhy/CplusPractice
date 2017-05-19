#pragma once
#include"HuffmanTree.h"
#include<iostream>
#include<vector>
using namespace std;


template<class T>   //���÷º���,�������ǲ���������д�Ǹ��ȽϵĴ�С����_w�Ƚ��ˣ����ǻ���FileCompress��ȥ����һ��operator<
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






//�����ر�ע���һ����ǣ������ڳ���ģ��ĵط�һ��Ҫ�����ǲ�����Ҫ����ģ�����

template<class T, class Container = Less<T>>  //�����HeapӦ����һ����ȫ���������ص���ǣ���ߵ�һ���У�Ҷ�ӽڵ�������������
											//�ҰѱȽϵ�λ��һ�����������Ƕ��Ǵ��ڻ��߶���С���ˣ�����������ͳһ������
					//��˼����˵����������ϵ����Ǵ��ںţ������µ�����С�ںţ��ҿ��԰�С�ں�����ıȽϵ����ݵ�ǰ��λ�ø���
				//һ�£�����ԭ����С�ھͱ���˴�����
class Heap
{
public:
	Heap()
	{}
	Heap(T* arr, size_t size)   //����ط������ں������治��ʹ��size_t size = sizeof(arr) / sizeof(arr[0]); 
	{								//��Ϊ�����봫�ݹ��������ʱ���������ή��Ϊָ�룬��������õĽ������4
		//_hp.reserve(size);   ����ʹ��reserve�������ǣ�ֱ�Ӹı�hp�е�capacity������ֱ�Ӹı�hp�е������Ĵ�С��Ҳ����˵
		//�������ֱ��ʹ����һ��Ļ�������ֱ�ӿ�����һ���ռ䣬����ռ�Ĵ�С�ոպù��洢size���ֽڣ��������ĺô����ǣ�
		//����Ҫ��pushback��ʱ��һ�δθ��ݴ�С���ٿռ���
		//����һ��������resize�������ֱ�Ӹı�size������ֱ�Ӹı䵱ǰ�洢����ռ�Ĵ�С��
		for (size_t i = 0; i < size; i++)
		{
			_hp.push_back(arr[i]);
		}

		//����
		for (int i = (size - 2) / 2; i >= 0; i--)   //�ҵ�������һ����Ҷ�ӽڵ㣬�±��0��ʼ���������������0
		{
			AdjustDown(i);
		}
	}



	void PushBack(T data)   //��������vector�������һ�����ݣ�Ȼ�����AdjustUp�������ϵ���
	{
		_hp.push_back(data);
		int child = _hp.size() - 1;
		AdjustUp(child);
	}

	void PopFront()   //�����ɾ��һ�����ݣ������Ⱥ����һ�����ݽ��н�����Ȼ��ɾ�����һ���ڵ㣬Ȼ���ڽ��е���
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
			size_t child = root * 2 + 1;    //����Ĭ�ϵ�Ӧ����������
			size_t msize = i - 1;
			if (((child + 1)<msize) && (_hp[child] < _hp[child + 1]))//child��ǵ��Ǵ����һ��,���� ǰ�����һ���ж�,������һ��
				//&&��ʹ�ã�����Ӧ�ð��Ǹ��ж�size����ǰ�棬��Ϊ����Ѻ�����Ǹ�����ǰ��Ļ����Ͳ������жϵ�����

			{
				child = child + 1;
			}
			while (child < msize)
				//��Ϊ�˷�ֹ���ǵ�������±�Խ��,������һ��ʼ�õ���if�������Ļ�����ֻ�ܵ���һ�Ρ���������Ҫ�����
				//ÿһ��������Ӧ����һ���ѣ���������Ӧ����ѭ��������Ӧ����if
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

	//����ʵ�ֵĺܻ���
	void TopK(int n, int size)    //ʵ��������������ݣ����ʱ�����ǽ����ľ���һ����������ݵ�С�ѣ�������������Ӧ�����ľ���
	{
		//�Ȱ�������ݽ�����һ��С��
		for (int i = (n - 2) / 2; i >= 0; i--)   //�ҵ�������һ����Ҷ�ӽڵ㣬�±��0��ʼ���������������0
		{
			int child = i * 2 + 1;    //����Ĭ�ϵ�Ӧ����������
			int m = n - 1;
			if (((child + 1)<m) && (_hp[child] > _hp[child + 1]))//child��ǵ��Ǵ����һ��,���� ǰ�����һ���ж�,������һ��
				//&&��ʹ�ã�����Ӧ�ð��Ǹ��ж�size����ǰ�棬��Ϊ����Ѻ�����Ǹ�����ǰ��Ļ����Ͳ������жϵ�����

			{
				child = child + 1;
				while (child < m)
					//��Ϊ�˷�ֹ���ǵ�������±�Խ��,������һ��ʼ�õ���if�������Ļ�����ֻ�ܵ���һ�Ρ���������Ҫ�����
					//ÿһ��������Ӧ����һ���ѣ���������Ӧ����ѭ��������Ӧ����if
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
				//�������ǾͿ�����ᵽ�˷º����ĺô��ˣ���Ϊ��ԭ�������µ����ǽ�����ѵģ��������������õ������µ�����
				//����С�ѵģ����������������
				//�������Ȳ��޸��ˣ��Լ����ڷº����������ر�����
				size_t root = 0;
				size_t child = root * 2 + 1;    //����Ĭ�ϵ�Ӧ����������
				size_t m = n - 1;
				if (((child + 1)<m) && (_hp[child] > _hp[child + 1]))//child��ǵ��Ǵ����һ��,���� ǰ�����һ���ж�,������һ��
					//&&��ʹ�ã�����Ӧ�ð��Ǹ��ж�size����ǰ�棬��Ϊ����Ѻ�����Ǹ�����ǰ��Ļ����Ͳ������жϵ�����

				{
					child = child + 1;
					while (child < m)
						//��Ϊ�˷�ֹ���ǵ�������±�Խ��,������һ��ʼ�õ���if�������Ļ�����ֻ�ܵ���һ�Ρ���������Ҫ�����
						//ÿһ��������Ӧ����һ���ѣ���������Ӧ����ѭ��������Ӧ����if
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
	void AdjustDown(int root)   //�����ｨ��һ�����
	{  

		//������Ҫ�ر�ע����ǣ����ڶ������ʱ��template<class T, class Container = Less<T>> ���Ѿ�ȷ��Container��T����
				//���ˣ��������ﲻ��Ҫ�ټ���ģ����
		Container _com;
		int child = root * 2 + 1;    //����Ĭ�ϵ�Ӧ����������


		int size = _hp.size() - 1;      //�����ǵ�vector����û��һ�����ݵ�ʱ�����ǵ�_hp.size()��0
					//��ȥ1֮���Ǻܴ��һ�����ݣ��ͻᵼ����������ݳ����������ﻻ��int

		//�����ڽ�����ʱ���ǵ�����һ��forѭ���ģ���������ֻ�迼��ÿ���ڲ������ǶѾͺ���
		//if (((child + 1)<size) && _com(_hp[child + 1],_hp[child]))//child��ǵ��Ǵ����һ��,���� ǰ�����һ���ж�,������һ��
		//				//&&��ʹ�ã�����Ӧ�ð��Ǹ��ж�size����ǰ�棬��Ϊ����Ѻ�����Ǹ�����ǰ��Ļ����Ͳ������жϵ�����

		//{
		//	child = child + 1;
		while (child <= size)
			//��Ϊ�˷�ֹ���ǵ�������±�Խ��,������һ��ʼ�õ���if�������Ļ�����ֻ�ܵ���һ�Ρ���������Ҫ�����
			//ÿһ��������Ӧ����һ���ѣ���������Ӧ����ѭ��������Ӧ����if
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
		while (root > 0)   //��0��ʱ��û�а취�жϣ��������浥��дһ�������ж�
		{





			//���ﲢû�е����Ǹ�operator�����������
			if (_com(_hp[child],_hp[root]))
			{
				swap(_hp[root], _hp[child]);   //��������ֱ������oprator<()
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
	//Container _con;   //���÷º���
};