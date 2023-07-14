#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"
void HeapTest1()
{
	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int sz = sizeof(array) / sizeof(array[0]);

	Hp php;
	HeapInit(&php);
	for (int i = 0; i < sz; i++)
	{
		HeapPush(&php, array[i]);
	}
	HeapPrint(&php);
	//HeapPush(&php, 100);
	//HeapPrint(&php);
	/*HeapPop(&php);
	HeapPrint(&php);
	HeapPop(&php);
	HeapPrint(&php);*/
	printf("%d ", HeapTop(&php));
	HeapPop(&php);
	//HeapPrint(&php);
	printf("%d ", HeapTop(&php));
	HeapPop(&php);
	//HeapPrint(&php);
	HeapDestory(&php);
}
int main()
{
	HeapTest1();
	return 0;
}