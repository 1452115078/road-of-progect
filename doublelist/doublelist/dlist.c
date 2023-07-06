#define _CRT_SECURE_NO_WARNINGS
#include "dlist.h"
ListNode* buynode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->_next = newnode;
	newnode->_prev = newnode;
	newnode->_data = x;
	return newnode;
}
// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->_next = newnode;
	newnode->_prev = newnode;
	//newnode->_data = -1;
	return newnode;
}
// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	free(pHead);
	pHead = NULL;
}
// 双向链表打印
void ListPrint(ListNode* pHead)
{
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListNode* newnode = buynode(x);
	ListNode* cur = pHead;
	while (cur->_next != pHead)
	{
		cur = cur->_next;
	}
	cur->_next = newnode;
	newnode->_prev = cur;
	newnode->_next = pHead;
	pHead->_prev = newnode;
}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead->_next != pHead);
	ListNode* cur = pHead->_next;
	while (cur->_next != pHead)
	{
		cur = cur->_next;
	}
	cur->_prev->_next = pHead;
	pHead->_prev = cur->_prev;
	free(cur);
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	ListNode* newnode = buynode(x);
	ListNode* next = pHead->_next;
	newnode->_next = next;
	next->_prev = newnode;
	pHead->_next = newnode;
	newnode->_prev = pHead;
}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead->_next != pHead);
	ListNode* cur = pHead->_next;
	pHead->_next = cur->_next;
	cur->_next->_prev = pHead;
	free(cur);
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_data == x)
			return cur;
		cur = cur->_next;
	}
	return NULL;

}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* newnode = buynode(x);
	pos->_prev->_next = newnode;
	newnode->_prev = pos->_prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos->_next != pos);
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}