#define _CRT_SECURE_NO_WARNINGS
#include "Slist.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void SListDestroy(SListNode* plist)
{
	//assert(plist);
	free(plist);
	//plist->next = NULL;
	//plist->data = 0;
}
// 单链表打印
void SListPrint(SListNode* plist)
{
	//assert(plist);
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	slistnode* newnode = buyslistnode(x);
	slistnode* tail = *pplist;

	if (*pplist == null)
	{
		*pplist = newnode;
	}
	else
	{
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	SListNode* prev = *pplist;
	SListNode* tail = prev->next;
	if (tail == NULL)
	{
		free(prev);
		*pplist = NULL;
	}
	else
	{
		while (tail->next)
		{
			tail = tail->next;
		}
		while (prev->next->next)
		{
			prev = prev->next;
		}
		free(tail);
		prev->next = NULL;
	}
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	SListNode* cur = *pplist;
	if (*pplist == NULL)
	{
		*pplist = BuySListNode(x);
	}
	else
	{
		newnode->next = cur;
		*pplist = newnode;
	}
}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* cur = *pplist;
	if (cur->next == NULL)
	{
		free(cur);
		*pplist = NULL;
	}
	else
	{
		SListNode* next = cur->next;
		free(cur);
		*pplist = next;
	}
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	if (pos == NULL)
	{
		pos = BuySListNode(x);
	}
	else
	{
		SListNode* posnext = pos->next;
		SListNode* newnode = BuySListNode(x);
		newnode->next = posnext;
		pos->next = newnode;
	}
}
// 单链表删除pos位置之后的值 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	assert(pos);

	SListNode* posnext = pos->next;
	if (pos->next == NULL)
	{
		free(pos);
	}
	else
	{
		pos->next = posnext->next;
		free(posnext);
	}
	

}