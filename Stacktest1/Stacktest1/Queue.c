#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"
// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->size = 0;
	q->head = q->tail = NULL;
}
// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = data;
	newnode->next = NULL;
	if (q->tail == NULL)
	{
		q->head = q->tail = newnode;
	}
	else
	{
		q->tail->next = newnode;
		q->tail = q->tail->next;
	}
	q->size++;

}
// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	if (q->head != q->tail)
	{
		QNode* del = q->head;
		free(del);

		q->head = q->head->next;
	}
	else
	{
		free(q->head);
	}
	q->size--;
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->head->data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->tail->data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->size;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->size == 0;
}
// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->head)
	{
		QNode* del = q->head;
		q->head = q->head->next;
		free(del);
		del = NULL;
	}
	q->size = 0;
}