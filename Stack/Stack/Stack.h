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
	int top;//ջ��Ԫ�ص���һ�����±� ����Ϊ0
}ST;
void InitStack(ST* ps);
void DestoryStack(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
bool StackEmpty(ST* ps);
STDataType StackTop(ST* ps);
int StackSize(ST* ps);




