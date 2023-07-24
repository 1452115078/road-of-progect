#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
#include "Queue.h"
void StackTest1()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	printf("%d\n", StackTop(&st));
	printf("%d\n", StackEmpty(&st));
	printf("%d\n", StackSize(&st));
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	printf("%d\n", StackTop(&st));
	printf("%d\n", StackEmpty(&st));
	printf("%d\n", StackSize(&st));
	StackPop(&st);
	printf("%d\n", StackEmpty(&st));


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
	printf("%d\n", QueueFront(&q));
	printf("%d\n", QueueBack(&q));
	printf("%d\n", QueueSize(&q));
	printf("%d\n", QueueEmpty(&q));
	//QueuePop(&q);
	//QueuePop(&q);
	///*printf("%d\n", QueueFront(&q));
	//printf("%d\n", QueueBack(&q));
	//printf("%d\n", QueueSize(&q));*/
	//printf("%d\n", QueueEmpty(&q));
	QueueDestroy(&q);



}
int main()
{
	//StackTest1();
	QueueTest1();
	return 0;
}