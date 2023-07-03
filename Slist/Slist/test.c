#define _CRT_SECURE_NO_WARNINGS
#include "Slist.h"
void TestSlist1()
{
	SListNode* st = NULL;
	SListPushBack(&st, 1);
	SListPushBack(&st, 2);
	SListPushBack(&st, 3);
	SListPushBack(&st, 4);
	SListPrint(st);
	//SListNode* pos = SListFind(st, 2);
	//SListInsertAfter(pos, 5);
	//SListInsertAfter(pos, 6);
	//SListPrint(st);
	//SListEraseAfter(pos);
	//SListEraseAfter(pos);
	//SListPrint(st);

	/*if (pos == NULL)
	{
		printf("no\n");
	}
	else
	{
		printf("%d", pos->data);
	}*/
	//SListPopBack(&st);
	//SListPopBack(&st);
	//SListPopBack(&st);
	//SListPopBack(&st);
	////SListPopBack(&st);
	//SListPrint(st);

	SListDestroy(st);
}
void TestSlist2()
{
	SListNode* st = NULL;
	SListPushFront(&st, 1);
	SListPushFront(&st, 2);
	SListPushFront(&st, 3);
	SListPushFront(&st, 4);
	SListPrint(st);
	SListPopFront(&st);
	SListPopFront(&st);
	SListPopFront(&st);
	SListPopFront(&st);
	SListPopFront(&st);
	SListPrint(st);

	SListDestroy(st);
}
int main()
{
	TestSlist1();
	//TestSlist2();
	return 0;
}