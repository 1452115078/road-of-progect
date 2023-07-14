#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"

void HeapInit(Hp* php)
{
	assert(php);
	php->a = NULL;
	php->capicity = php->size = 0;
}
void HeapDestory(Hp* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capicity = php->size = 0;
}
void swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
void Adjustup(HPDataType* a, int sz)
{
	int child = sz - 1;
	int parent = 0;//父节点
	while (child > 0)
	{
		parent = (child - 1) / 2;
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(Hp* php, HPDataType x)
{
	assert(php);
	//扩容
	if (php->capicity == php->size)
	{
		int newcapicity = php->capicity == 0 ? 4 : php->capicity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newcapicity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->a = tmp;
		php->capicity = newcapicity;
	}
	//插入数据
	php->a[php->size] = x;
	php->size++;
	//向上调整
	Adjustup(php->a, php->size);
}
void HeapPrint(Hp* php)
{
	assert(php);
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}
void Adjustdown(HPDataType* a, int n, int parent)
{
	int child = 0;
	while (parent * 2 + 1 < n)
	{
		child = parent * 2 + 1;
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
		}
		else
		{
			break;
		}
	}
}
void HeapPop(Hp* php)
{
	assert(php);
	//1、堆顶与最后一个元素进行交换并删除最后一个元素
	int tmp = php->a[0];
	php->a[0] = php->a[php->size - 1];
	php->a[php->size - 1] = tmp;
	php->size--;
	//2、向下调整
	Adjustdown(php->a, php->size, 0);
}
HPDataType HeapTop(Hp* php)
{
	assert(php);
	return php->a[0];
}
int HeapSize(Hp* php)
{
	assert(php);
	return php->size;
}
bool HeapEmpty(Hp* php)
{
	assert(php);
	return php->size == 0;
}