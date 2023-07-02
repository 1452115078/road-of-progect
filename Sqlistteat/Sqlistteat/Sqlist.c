#define _CRT_SECURE_NO_WARNINGS
#include "Sqlist.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = (SLDateType*)malloc(sizeof(SLDateType) * 3);
	if (ps->a == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 3;
}
void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void checkcapicity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		SLDateType* tmp = (SLDateType*)realloc(ps->a, ps->capacity * 2 * sizeof(SLDateType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	//assert(ps);
	////检查容量
	//checkcapicity(ps);
	//ps->a[ps->size] = x;
	//ps->size++;
	SeqListInsert(ps, ps->size, x);
}
void SeqListPopBack(SeqList* ps)
{
	/*assert(ps);
	assert(ps->size > 0);
	ps->size--;*/
	SeqListErase(ps, ps->size);
}
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	/*assert(ps);
	checkcapicity(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		ps->a[ps->size - i] = ps->a[ps->size - 1 - i];
	}
	ps->a[0] = x;
	ps->size++;*/
	SeqListInsert(ps, 0, x);
}
void SeqListPopFront(SeqList* ps)
{
	/*assert(ps);
	assert(ps->size > 0);
	int i = 0;
	for (i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;*/
	SeqListErase(ps, 0);
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return ps->a[i];
		}
	}
	return -1;
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	assert(ps);
	checkcapicity(ps);
	int i = 0;
	int size = ps->size;
	for (i = pos; i < ps->size; i++)
	{
		ps->a[size] = ps->a[size - 1];
		size--;
	}
	ps->a[pos] = x;
	ps->size++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(ps->size > 0);
	int i = 0;
	for (i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}