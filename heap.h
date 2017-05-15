#pragma once

#include<iostream>
#include<vector>
using namespace std;

template<class T>  //�����HeapӦ����һ����ȫ���������ص���ǣ���ߵ�һ���У�Ҷ�ӽڵ�������������
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

	void AdjustDown(int root)   //�����ｨ��һ��С��
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


private:
	vector<int> _hp;
};