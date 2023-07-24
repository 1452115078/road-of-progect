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

// �ѵĹ���
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
	//��������µ���
	//for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	//{
	//	Adjustdown(hp->_a, n, i);//
	//}
	////��������ϵ���
	for (int i = 1; i < n; i++)
	{
		Adjustup(hp->_a, i);
	}
}
// �ѵ�����
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}
// �ѵĲ���
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
	//���ϵ���
	int parent = ((hp->_size - 1) - 1) / 2;
	for (int i = (hp->_size - 1 - 1) / 2; i >= 0; i--)
	{
		Adjustdown(hp->_a, hp->_size, i);
	}
}
// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	//1�������Ѷ������һ������
	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	//2������
	for (int i = (hp->_size - 1 - 1) / 2; i >= 0; i--)
	{
		Adjustdown(hp->_a, hp->_size, i);
	}
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->_a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->_size;
}
// �ѵ��п�
bool HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0;
}