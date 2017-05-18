#pragma once

template<class T,size_t N = 100>   //非类型模板参数
class staticStack
{
public:
	staticStack()  //静态栈
		:_size(0)
	{
	}
	void PushBack(T data)  //入栈
	{
		_a[_size] = data;
		_size++;
	}

	void PopBack()   //出栈
	{
		_size--;
	}

	T Top()   //取栈顶元素
	{
		if (0 == _size)
		{
			cout << "栈为空" << endl;
			return (T)0;
		}
		return _a[_size-1];
	}

	void Show()   //打印栈
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

//staticStack<int,20> i;   //这里在使用非类型模板参数的时候可以不用加上那个数字,即就是可以不用写上那个20

template<class T>   //动态栈
class Stack
{
public:
	Stack()   //采用链式存储结构实现动态栈
		:_size(0)
		,_capacity(5)
	{
		_s = new T[_capacity];   //
	}

	~Stack()
	{
		delete[] _s;
	}

	void CheckCapacity()    //动态增容
	{
		if (_size >= _capacity)
		{
			_capacity = _capacity + _capacity/2;  //这里一开始的时候也是错误的，就是，我开始写的是（3/2）*capacity，但是大小没有改变
			T* tmp = new T[_capacity];
			memcpy(tmp,_s,_capacity*sizeof(T));   //这里我在写的时候出现了错误，就是那个我没有写*sizeof(),这里应该注意是按字节拷贝
			delete _s;
			_s = tmp;
		}
	}

	void Push(T data)   //入栈
	{
		CheckCapacity();
		_s[_size] = data;
		_size++;
	}

	T Top()   //取栈顶元素
	{
		if (0 == _size)
		{
			cout << "栈为空" << endl;
			return T();   //注意这里，注意这里，注意这里
		}
		return _s[_size - 1];
	}

	void Pop()   //出栈
	{
		_size--;
	}

	void Show()   //打印栈
	{
		size_t i = 0;
		for (; i < _size; i++)
		{
			cout << _s[i] << " ";
		}
		cout << endl;
	}


protected:
	T* _s;    //一个链表指针，指向一个栈结构
	size_t _size;   //当前栈的大小
	size_t _capacity;  //当前栈的总容量
};

template<size_t M = 5,size_t N = 5>
class Maze
{
public:
	Maze(int maze[M][N])   //构造函数，初始化迷宫
	{
		int i = 0, j = 0;
		for (i; i < M;i++)   //这里最好写上初值，因为请看下面一行
		{
			for (j = 0; j < N;j++)  //这里如果不写上初值的话，外层的第一次循环结束后，j已经变成了4，这里下一层循环直接就错了
			{
				_maze[i][j] = maze[i][j];
			}
		}
	}
	void Show()   //打印迷宫
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

	struct entry   //定义一个结构体，用来存放迷宫里面数字的下标
	{
		entry()
		:_line(1)  //初始值是迷宫的入口
		,_cow(0)
		{
		}
		int _line;
		int _cow;
	};

	void GetPath()   //迷宫求解
	{
		Stack<entry> s;
		entry next;
		while (CheckAssess(next,s))
		{
			if (N - 1 == next._line)   //当检查到已经到了边界之后，就表示已经走出来了
			{
				_maze[next._line][next._cow] = 2;
				return;
			}
		}
	}

	bool CheckAssess(entry& next, Stack<entry>& s)   //检查路径
	{
		//检测上面
		if (0 == _maze[(next._line) - 1][next._cow])
		{
			_maze[next._line][next._cow] = 2;
			s.Push(next);
			(next._line)--;
			
			return true;
		}
		//检测右边
		if (0 == _maze[next._line][(next._cow) + 1])
		{
			_maze[next._line][next._cow] = 2;
			s.Push(next);
			(next._cow)++;
			return true;
		}

		//检测下面
		if (0 == _maze[(next._line) + 1][next._cow])
		{
			_maze[next._line][next._cow] = 2;
			s.Push(next);
			(next._line)++;
			return true;
		}

		//检测右边
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
	int _maze[M][N];  //迷宫这个类的元素是一个二维数组
};

