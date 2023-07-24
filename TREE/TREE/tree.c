#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
void swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
void Adjustdown(HPDataType* a, int sz, int parent)//p = 4 3 2 1 0
{
	int child = 0;
	while (2 * parent + 1 < sz)
	{
		child = 2 * parent + 1;
		if (child + 1 < sz && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[parent] > a[child])
		{
			swap(&a[parent], &a[child]);
		}
		parent = child;
	}
}
void Adjustup(HPDataType* a, int child)
{
	int parent = 0;
	while (child > 0)
	{
		parent = (child - 1) / 2;
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
		}
		child = parent;
	}
}

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (hp->_a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	hp->_capacity = hp->_size = n;
	memcpy(hp->_a, a, sizeof(HPDataType) * n);
	//建大堆向下调整
	//for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	//{
	//	Adjustdown(hp->_a, n, i);//
	//}
	////建大堆向上调整
	for (int i = 1; i < n; i++)
	{
		Adjustup(hp->_a, i);
	}
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_capacity == hp->_size)
	{
		HPDataType* tmp = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * hp->_capacity * 2);
		if (tmp == NULL)
		{
			perror("malloc fail");
			exit(-1);
		}
		hp->_a = tmp;
		hp->_capacity *= 2;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	//向上调整
	int parent = ((hp->_size - 1) - 1) / 2;
	for (int i = (hp->_size - 1 - 1) / 2; i >= 0; i--)
	{
		Adjustdown(hp->_a, hp->_size, i);
	}
}
// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	//1、交换堆顶与最后一个数据
	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	//2、调整
	for (int i = (hp->_size - 1 - 1) / 2; i >= 0; i--)
	{
		Adjustdown(hp->_a, hp->_size, i);
	}
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->_size;
}
// 堆的判空
bool HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0;
}