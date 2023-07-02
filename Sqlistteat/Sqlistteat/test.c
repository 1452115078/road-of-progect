#define _CRT_SECURE_NO_WARNINGS
#include "Sqlist.h"
void TestSqlist1()
{
	SeqList st;
	SeqListInit(&st);
	SeqListPushBack(&st, 1);
	SeqListPushBack(&st, 2);
	SeqListPushBack(&st, 3);
	SeqListPrint(&st);
	SeqListPopBack(&st);
	SeqListPopBack(&st);
	SeqListPopBack(&st);
	SeqListPopBack(&st);
	SeqListPrint(&st);
	//SeqListPushBack(&st, 4);
	//SeqListPrint(&st);
	//int ret = SeqListFind(&st, 41);
	//if (ret == -1)
	//{
	//	printf("no\n");
	//}
	//else
	//{
	//	printf("%d\n", ret);
	//}
	SeqListDestroy(&st);
}
void TestSqlist2()
{
	SeqList st;
	SeqListInit(&st);
	SeqListPushFront(&st, 3);
	SeqListPushFront(&st, 2);
	SeqListPushFront(&st, 1);
	//SeqListPushFront(&st, 4);
	SeqListPrint(&st);

	SeqListPopFront(&st);
	SeqListPopFront(&st);
	SeqListPrint(&st);



	SeqListDestroy(&st);
}
int main()
{
	//TestSqlist1();
	TestSqlist2();
}