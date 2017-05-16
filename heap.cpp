#include"heap.h"

void TestHeap()
{
	int arr[] = { 1, 5, 3, 8, 4, 6, 9, 5 };
	size_t size = sizeof(arr) / sizeof(arr[0]);   //����ע���һ������ǣ�Ҫ����sizeof(arr[0])
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