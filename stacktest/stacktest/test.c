#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"
#include "Queue.h"
#include "stacktest1.h"

void StackTest1()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	
	printf("%d\n", StackTop(&st));
	printf("%d\n", StackSize(&st));
	StackPop(&st);
	printf("%d\n", StackTop(&st));

	StackDestroy(&st);

}
void QueueTest1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	printf("%d\n", QueueSize(&q));
	printf("%d\n", QueueFront(&q));
	printf("%d\n", QueueBack(&q));
}
void w1()
{
	MyStack* st = myStackCreate();
	myStackPush(st, 1);
	myStackPush(st, 2);
	myStackPush(st, 3);

}
int main()
{
	//StackTest1();
	//QueueTest1();
	w1();
	return 0;
}