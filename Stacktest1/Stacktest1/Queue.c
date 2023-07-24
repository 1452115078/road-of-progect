#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"
// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->size = 0;
	q->head = q->tail = NULL;
}
// 队尾入队列 
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
// 队头出队列 
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
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->head->data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->tail->data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->size == 0;
}
// 销毁队列 
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