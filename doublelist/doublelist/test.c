#define _CRT_SECURE_NO_WARNINGS
#include "dlist.h"
void t1()
{
	ListNode* lt = ListCreate();
	ListPushBack(lt, 1);
	ListPushBack(lt, 2);
	ListPushBack(lt, 3);
	ListPushBack(lt, 4);
	ListPrint(lt);
	ListNode* pos = ListFind(lt, 3);
	ListInsert(pos, 5);
	ListPrint(lt);

	ListErase(pos);
	ListPrint(lt);

	//ListPopBack(lt);
	//ListPrint(lt);

	ListDestory(lt);
}
void t2()
{
	ListNode* lt = ListCreate();
	ListPushFront(lt, 1);
	ListPushFront(lt, 2);
	ListPushFront(lt, 3);
	ListPushFront(lt, 4);
	ListPrint(lt);
	ListPopFront(lt);
	ListPopFront(lt);
	ListPopFront(lt);
	ListPopFront(lt);
	ListPrint(lt);
	ListPopFront(lt);

	ListDestory(lt);
}
int main()
{
	t1();
	//t2();
	return 0;
}