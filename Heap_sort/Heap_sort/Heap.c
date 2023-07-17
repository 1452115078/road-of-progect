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
	//���ݿ���
	hp->_capacity = hp->_size = n;
	memcpy(hp->_a, a, sizeof(HPDataType) * n);

	////����� ���ϵ���
	//for (int i = 0; i < n; ++i)
	//{
	//	Adjustup(hp->_a, i);
	//}
	//����� ���µ���
	for (int i = ((n - 1 - 1) / 2); i >= 0; --i)
	{
		Adjustdown(hp->_a, i, n);
	}

}
//�ѵĴ�ӡ
void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
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
	//�ж���������
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

	//�ѵ���
	//����� ���ϵ���
	/*for (int i = 0; i < hp->_size; ++i)
	{
		Adjustup(hp->_a, i);
	}*/
	//����� ���µ���
	for (int i = ((hp->_size - 1 - 1) / 2); i >= 0; --i)
	{
		Adjustdown(hp->_a, i, hp->_size);
	}
}
// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	assert(hp);
	//1�������Ѷ������һ��Ԫ��
	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	//2���ѵ���
	Adjustdown(hp->_a, 0, hp->_size);
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0;
}