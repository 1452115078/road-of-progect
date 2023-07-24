#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"

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
int main()
{
	QueueTest1();
	return 0;
}