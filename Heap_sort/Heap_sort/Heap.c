#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"
void swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
void Adjustup(HPDataType* a, int child)//child = 4 
{
	int parent = 0;
	while (child > 0)
	{
		parent = (child - 1) / 2;//p = 1 p = 0
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
		}
		child = parent;//c = 1 c = 0
	}
}
void Adjustdown(HPDataType* a, int parent, int k)
{
	int child = 0;//p = 4
	while (parent * 2 + 1 < k)
	{
		child = parent * 2 + 1;//c = 9
		if ((child + 1 < k) && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
		}
		parent = child;//p = 9
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
	//数据拷贝
	hp->_capacity = hp->_size = n;
	memcpy(hp->_a, a, sizeof(HPDataType) * n);

	////建大堆 向上调整
	//for (int i = 0; i < n; ++i)
	//{
	//	Adjustup(hp->_a, i);
	//}
	//建大堆 向下调整
	for (int i = ((n - 1 - 1) / 2); i >= 0; --i)
	{
		Adjustdown(hp->_a, i, n);
	}

}
//堆的打印
void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
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
	//判断容量扩容
	if (hp->_capacity == hp->_size)
	{
		HPDataType* tmp = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * 2 * hp->_capacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		hp->_a = tmp;
		hp->_capacity *= 2;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;

	//堆调整
	//建大堆 向上调整
	/*for (int i = 0; i < hp->_size; ++i)
	{
		Adjustup(hp->_a, i);
	}*/
	//建大堆 向下调整
	for (int i = ((hp->_size - 1 - 1) / 2); i >= 0; --i)
	{
		Adjustdown(hp->_a, i, hp->_size);
	}
}
// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	//1、交换堆顶与最后一个元素
	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	//2、堆调整
	Adjustdown(hp->_a, 0, hp->_size);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0;
}