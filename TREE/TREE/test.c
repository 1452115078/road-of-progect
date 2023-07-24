#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
void Treetest1()
{
	int array[] = { 27,15,19,18,28,34,65,49,25,37 };
	int sz = sizeof(array) / sizeof(array[0]);
	Heap hp;
	HeapCreate(&hp, array, sz);
	HeapPush(&hp, 100);
	HeapPop(&hp);
	printf("%d\n", HeapTop(&hp));
	HeapDestory(&hp);
}
void Heapsort(int* a, int sz)
{
	////1、升序建大堆
	//for (int i = (sz - 1 - 1) / 2; i >= 0; i--)
	//{
	//	Adjustdown(a, sz, i);
	//}
	////2、头尾交换，调整
	//for (int i = 0; i < sz; i++)
	//{
	//	swap(&a[0], &a[sz - 1 - i]);
	//	Adjustdown(a, sz - 1 - i, 0);
	//}
	//2、降序建小堆
	for (int i = 1; i < sz; i++)
	{
		Adjustup(a, i);
	}
	//2、头尾交换，调整
	/*for (int i = 0; i < sz; i++)
	{
		swap(&a[0], &a[sz - 1 - i]);
		Adjustdown(a, sz - 1 - i, 0);
	}*/
}
void Treetest2()
{
	int array[] = { 27,15,19,18,28,34,65,49,25,37 };
	int sz = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	Heapsort(array, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
int main()
{
	//Treetest1();
	Treetest2();
	return 0;
}