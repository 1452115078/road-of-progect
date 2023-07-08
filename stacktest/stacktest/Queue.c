#define _CRT_SECURE_NO_WARNINGS
//#include "Queue.h"
#include "stacktest1.h"
// ��ʼ������
void QueueInit(Queue* q)
{
	assert(q);
	q->head = q->tail = NULL;
	//q->head = NULL;
	//q->tail = NULL;
	q->size = 0;
}

// ��β�����
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
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
		q->tail = newnode;
	}
	q->size++;
}
// ��ͷ������
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	if (q->head->next == NULL)
	{
		free(q->head);
		free(q->tail);
		q->head = q->tail = NULL;
	}
	else
	{
		QNode* del = q->head;
		q->head = q->head->next;
		free(del);
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
	return q->size;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool QueueEmpty(Queue* q)
{
	assert(q);
	return q->head == NULL && q->tail == NULL;
}
// ���ٶ���
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->head;
	while (cur)
	{
		QNode* del = cur;
		cur = cur->next;

		free(del);
	}
	q->head = q->tail = NULL;
}
