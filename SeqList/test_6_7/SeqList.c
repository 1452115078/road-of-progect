#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"
void checkcapicity(SL* pc)
{
	assert(pc);
	if (pc->sz == pc->capicity)
	{
		int newcapicity = pc->capicity == 0 ? 4 : pc->capicity * 2;
		SLDatatype* tmp = (SLDatatype*)realloc(pc->a, newcapicity * sizeof(SLDatatype));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		pc->a = tmp;
		pc->capicity = newcapicity;
	}
}
void SLInit(SL* pc)
{
	pc->a = NULL;
	pc->sz = pc->capicity = 0;
}
void SLDestory(SL* pc)
{
	pc->a = pc->capicity = 0;
	free(pc->a);
	pc->a = NULL;
}
void SLPrint(SL* pc)
{
	assert(pc);
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%d ", pc->a[i]);
	}
	printf("\n");
}
void SLPushback(SL* pc, SLDatatype x)
{
	checkcapicity(pc);
	pc->a[pc->sz] = x;
	pc->sz++;
}
void SLPopback(SL* pc)
{
	assert(pc->sz > 0);
	pc->sz--;
}
void SLPushfront(SL* pc, SLDatatype x)
{
	assert(pc);
	checkcapicity(pc);
	int begin = pc->sz - 1;
	while (begin >= 0)
	{
		pc->a[begin + 1] = pc->a[begin];
		begin--;
	}
	pc->a[begin + 1] = x;
	pc->sz++;
}
void SLPopfront(SL* pc)
{
	assert(pc->sz > 0);
	assert(pc);
	int begin = 0;
	while (begin < pc->sz)
	{
		pc->a[begin] = pc->a[begin + 1];
		begin++;
	}
	pc->sz--;
}
void SLInsert(SL* pc, int pos, SLDatatype x)
{
	assert(pc);
	assert(pos >= 0);
	assert(pos <= pc->sz);
	int begin = pc->sz;
	while (begin > pos + 1)
	{
		pc->a[begin] = pc->a[begin - 1];
		begin--;
	}
	pc->a[begin] = x;
	pc->sz++;
}
void SLErase(SL* pc, int pos)
{
	assert(pc);
	assert(pos >= 0);
	assert(pos < pc->sz);
	while (pos < pc->sz - 1)
	{
		pc->a[pos] = pc->a[pos + 1];
		pos++;
	}
	pc->sz--;
}