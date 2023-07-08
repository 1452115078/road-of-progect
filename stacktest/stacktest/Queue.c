#define _CRT_SECURE_NO_WARNINGS
//#include "Queue.h"
#include "stacktest1.h"
// 初始化队列
void QueueInit(Queue* q)
{
	assert(q);
	q->head = q->tail = NULL;
	//q->head = NULL;
	//q->tail = NULL;
	q->size = 0;
}

// 队尾入队列
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
// 队头出队列
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
	return q->size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
bool QueueEmpty(Queue* q)
{
	assert(q);
	return q->head == NULL && q->tail == NULL;
}
// 销毁队列
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
