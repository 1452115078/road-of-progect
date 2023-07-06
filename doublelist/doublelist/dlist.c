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
// �������������ͷ���.
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
// ˫����������
void ListDestory(ListNode* pHead)
{
	free(pHead);
	pHead = NULL;
}
// ˫�������ӡ
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
// ˫������β��
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
// ˫������βɾ
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
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	ListNode* newnode = buynode(x);
	ListNode* next = pHead->_next;
	newnode->_next = next;
	next->_prev = newnode;
	pHead->_next = newnode;
	newnode->_prev = pHead;
}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead->_next != pHead);
	ListNode* cur = pHead->_next;
	pHead->_next = cur->_next;
	cur->_next->_prev = pHead;
	free(cur);
}
// ˫���������
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
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* newnode = buynode(x);
	pos->_prev->_next = newnode;
	newnode->_prev = pos->_prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos->_next != pos);
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}