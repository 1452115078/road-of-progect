#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
void SLTPrint(SList* phead)
{
	assert(phead);
	SList* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
SList* BuySListNode(SLTDataType x)
{
	SList* node = (SList*)malloc(sizeof(SList));
	if (node == NULL)
	{
		perror("malloc failed\n");
		exit(-1);
	}
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}
SList* InitSList()
{
	SList* phead = BuySListNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void pushback(SList* phead, SLTDataType x)
{
	/*assert(phead);
	SList* newnode = BuySListNode(x);
	SList* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;*/
	SLTInsert(phead->prev, x);
}
void popback(SList* phead)
{
	/*assert(phead);
	assert(phead->next != phead);
	SList* tail = phead->prev;
	SList* prev = tail->prev;
	prev->next = phead;
	phead->prev = prev;
	free(tail);*/
	SLTErase(phead->prev);
}
void pushfront(SList* phead, SLTDataType x)
{
	/*assert(phead);
	SList* newnode = BuySListNode(x);
	SList* cur = phead->next;
	newnode->next = cur;
	cur->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;*/
	SLTInsert(phead, x);
}
void popfront(SList* phead)
{
	/*assert(phead);
	assert(phead->next != phead);
	SList* first = phead->next;
	SList* second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);*/
	SLTErase(phead->next);
}
SList* Find(SList* phead, SLTDataType x)
{
	assert(phead);
	SList* cur = phead->next;
	while (cur != phead)
	{
		if (x == cur->data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void SLTInsert(SList* pos, SLTDataType x)
{
	assert(pos);
	SList* newnode = BuySListNode(x);
	SList* posnext = pos->next;
	newnode->next = posnext;
	posnext->prev = newnode;
	pos->next = newnode;
	newnode->prev = pos;
}
void SLTErase(SList* pos)
{
	assert(pos);
	assert(pos->next != pos);
	SList* posprev = pos->prev;
	SList* posnext = pos->next;
	free(pos);
	posprev->next = posnext;
	posnext->prev = posprev;

}