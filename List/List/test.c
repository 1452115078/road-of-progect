#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
void TESTLIST1()
{
	SList* phead = InitSList();
	pushback(phead, 1);
	pushback(phead, 2);
	pushback(phead, 3);
	pushback(phead, 4);
	pushback(phead, 5);
	SLTPrint(phead);
	SList* pos = Find(phead, 2);
	SLTInsert(pos, 6);
	SLTPrint(phead);

	/*if (pos)
		pos->data *= 10;
	else
		printf("not find\n");*/

	popback(phead);
	SLTPrint(phead);

	popback(phead);
	SLTPrint(phead);

	popback(phead);
	SLTPrint(phead);

	popback(phead);
	SLTPrint(phead);

	popback(phead);
	SLTPrint(phead);
}
void TESTLIST2()
{
	SList* phead = InitSList();
	pushfront(phead, 1);
	pushfront(phead, 2);
	pushfront(phead, 3);
	pushfront(phead, 4);
	pushfront(phead, 5);
	SLTPrint(phead);
	//SList* pos = Find(phead, 2);
	//SLTInsert(pos, 6);
	//SLTPrint(phead);
	popfront(phead);
	popfront(phead);
	popfront(phead);
	popfront(phead);
	popfront(phead);
	popfront(phead);
	SLTPrint(phead);
}
int main()
{
	//TESTLIST1();
	TESTLIST2();
	return 0;
}