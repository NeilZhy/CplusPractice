#pragma once

template<class T,size_t N = 100>   //������ģ�����
class staticStack
{
public:
	staticStack()  //��̬ջ
		:_size(0)
	{
	}
	void PushBack(T data)  //��ջ
	{
		_a[_size] = data;
		_size++;
	}

	void PopBack()   //��ջ
	{
		_size--;
	}

	T Top()   //ȡջ��Ԫ��
	{
		if (0 == _size)
		{
			cout << "ջΪ��" << endl;
			return (T)0;
		}
		return _a[_size-1];
	}

	void Show()   //��ӡջ
	{
		size_t i = 0;
		for (; i < _size;i++)
		{
			cout << _a[i] << " ";
		}
		cout << endl;
	}


protected:
	T _a[N];
	size_t _size;
};

//staticStack<int,20> i;   //������ʹ�÷�����ģ�������ʱ����Բ��ü����Ǹ�����,�����ǿ��Բ���д���Ǹ�20

template<class T>   //��̬ջ
class Stack
{
public:
	Stack()   //������ʽ�洢�ṹʵ�ֶ�̬ջ
		:_size(0)
		,_capacity(5)
	{
		_s = new T[_capacity];   //
	}

	~Stack()
	{
		delete[] _s;
	}

	void CheckCapacity()    //��̬����
	{
		if (_size >= _capacity)
		{
			_capacity = _capacity + _capacity/2;  //����һ��ʼ��ʱ��Ҳ�Ǵ���ģ����ǣ��ҿ�ʼд���ǣ�3/2��*capacity�����Ǵ�Сû�иı�
			T* tmp = new T[_capacity];
			memcpy(tmp,_s,_capacity*sizeof(T));   //��������д��ʱ������˴��󣬾����Ǹ���û��д*sizeof(),����Ӧ��ע���ǰ��ֽڿ���
			delete _s;
			_s = tmp;
		}
	}

	void Push(T data)   //��ջ
	{
		CheckCapacity();
		_s[_size] = data;
		_size++;
	}

	T Top()   //ȡջ��Ԫ��
	{
		if (0 == _size)
		{
			cout << "ջΪ��" << endl;
			return T();   //ע�����ע�����ע������
		}
		return _s[_size - 1];
	}

	void Pop()   //��ջ
	{
		_size--;
	}

	void Show()   //��ӡջ
	{
		size_t i = 0;
		for (; i < _size; i++)
		{
			cout << _s[i] << " ";
		}
		cout << endl;
	}


protected:
	T* _s;    //һ������ָ�룬ָ��һ��ջ�ṹ
	size_t _size;   //��ǰջ�Ĵ�С
	size_t _capacity;  //��ǰջ��������
};

template<size_t M = 5,size_t N = 5>
class Maze
{
public:
	Maze(int maze[M][N])   //���캯������ʼ���Թ�
	{
		int i = 0, j = 0;
		for (i; i < M;i++)   //�������д�ϳ�ֵ����Ϊ�뿴����һ��
		{
			for (j = 0; j < N;j++)  //���������д�ϳ�ֵ�Ļ������ĵ�һ��ѭ��������j�Ѿ������4��������һ��ѭ��ֱ�Ӿʹ���
			{
				_maze[i][j] = maze[i][j];
			}
		}
	}
	void Show()   //��ӡ�Թ�
	{
		int i = 0, j = 0;
		for (i; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				cout<<_maze[i][j]<<" ";
			}
			cout << endl;
		}
		cout << endl;
	}

	struct entry   //����һ���ṹ�壬��������Թ��������ֵ��±�
	{
		entry()
		:_line(1)  //��ʼֵ���Թ������
		,_cow(0)
		{
		}
		int _line;
		int _cow;
	};

	void GetPath()   //�Թ����
	{
		Stack<entry> s;
		entry next;
		while (CheckAssess(next,s))
		{
			if (N - 1 == next._line)   //����鵽�Ѿ����˱߽�֮�󣬾ͱ�ʾ�Ѿ��߳�����
			{
				_maze[next._line][next._cow] = 2;
				return;
			}
		}
	}

	bool CheckAssess(entry& next, Stack<entry>& s)   //���·��
	{
		//�������
		if (0 == _maze[(next._line) - 1][next._cow])
		{
			_maze[next._line][next._cow] = 2;
			s.Push(next);
			(next._line)--;
			
			return true;
		}
		//����ұ�
		if (0 == _maze[next._line][(next._cow) + 1])
		{
			_maze[next._line][next._cow] = 2;
			s.Push(next);
			(next._cow)++;
			return true;
		}

		//�������
		if (0 == _maze[(next._line) + 1][next._cow])
		{
			_maze[next._line][next._cow] = 2;
			s.Push(next);
			(next._line)++;
			return true;
		}

		//����ұ�
		if (0 == _maze[next._line][(next._cow) - 1])
		{
			_maze[next._line][next._cow] = 2;
			s.Push(next);
			(next._cow)--;
			return true;
		}
		s.Pop();
		next = s.Top();
		
	}

protected:
	int _maze[M][N];  //�Թ�������Ԫ����һ����ά����
};

