#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int capicity;
	int top;//栈顶元素的下一个的下标 设置为0
}ST;
void InitStack(ST* ps);
void DestoryStack(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
bool StackEmpty(ST* ps);
STDataType StackTop(ST* ps);
int StackSize(ST* ps);




