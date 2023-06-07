#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"
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
	}
	pc->a[pc->sz] = x;
	pc->sz++;
}
void SLPopback(SL* pc)
{
	assert(pc->sz > 0);
	pc->sz--;
}