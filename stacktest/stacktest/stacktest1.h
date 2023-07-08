#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//����ʵ�ֶ���
typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

typedef struct {
	Queue q1;
	Queue q2;
} MyStack;
// ��ʼ������
void QueueInit(Queue* q);
// ��β�����
void QueuePush(Queue* q, QDataType data);
// ��ͷ������
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool QueueEmpty(Queue* q);
// ���ٶ���
void QueueDestroy(Queue* q);


MyStack* myStackCreate();
void myStackPush(MyStack* obj, int x);
int myStackPop(MyStack* obj);
bool myStackEmpty(MyStack* obj);
int myStackTop(MyStack* obj);
void myStackFree(MyStack* obj);
