#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
void TESTSTACK1()
{
	ST st;
	InitStack(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);



	DestoryStack(&st);
}

int main()
{
	TESTSTACK1();
	return 0;
}