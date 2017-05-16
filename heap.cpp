#include"heap.h"

void TestHeap()
{
	int arr[] = { 1, 5, 3, 8, 4, 6, 9, 5 };
	size_t size = sizeof(arr) / sizeof(arr[0]);   //这里注意的一个点就是，要除以sizeof(arr[0])
	Heap<int> hp(arr, size);
	hp.PushBack(10);
	hp.PopFront();
	hp.PopFront();
}

int main()
{
	TestHeap();
	return 0;
}