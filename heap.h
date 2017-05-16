#pragma once

#include<iostream>
#include<vector>
using namespace std;

template<class T>   //���÷º���
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

template<class T,class Container = Greater<int>>  //�����HeapӦ����һ����ȫ���������ص���ǣ���ߵ�һ���У�Ҷ�ӽڵ�������������
class Heap
{
public:
	Heap(T* arr, size_t size)   //����ط������ں������治��ʹ��size_t size = sizeof(arr) / sizeof(arr[0]); 
	{								//��Ϊ�����봫�ݹ��������ʱ���������ή��Ϊָ�룬��������õĽ������4
		for (size_t i = 0; i < size; i++)
		{
			_hp.push_back(arr[i]);
		}

		//����
		for (int i = (size-2) / 2; i>=0;i--)   //�ҵ�������һ����Ҷ�ӽڵ㣬�±��0��ʼ���������������0
		{
			AdjustDown(i);
		}
	}

	void PushBack(int data)   //��������vector�������һ�����ݣ�Ȼ�����AdjustUp�������ϵ���
	{
		_hp.push_back(data);
		int child = _hp.size() - 1;
		AdjustUp(child);
	}

	void PopFront()   //�����ɾ��һ�����ݣ������Ⱥ����һ�����ݽ��н�����Ȼ��ɾ�����һ���ڵ㣬Ȼ���ڽ��е���
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
	void TopK(int n,int size)    //ʵ��������������ݣ����ʱ�����ǽ����ľ���һ����������ݵ�С�ѣ�������������Ӧ�����ľ���
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
				swap(_hp[i],_hp[0]);
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
		size_t child = root * 2 + 1;    //����Ĭ�ϵ�Ӧ����������
		size_t size = _hp.size() - 1;
		if (((child + 1)<size) && (_hp[child] < _hp[child + 1]))//child��ǵ��Ǵ����һ��,���� ǰ�����һ���ж�,������һ��
						//&&��ʹ�ã�����Ӧ�ð��Ǹ��ж�size����ǰ�棬��Ϊ����Ѻ�����Ǹ�����ǰ��Ļ����Ͳ������жϵ�����

		{
			child = child + 1;
		}
		while (child < size)   
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

	void AdjustUp(int child)   
	{
		int root = (child - 1) / 2;
		while (root > 0)   //��0��ʱ��û�а취�жϣ��������浥��дһ�������ж�
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
	Container _con;   //���÷º���
};