#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"

// 初始化栈
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = (Stack*)malloc(sizeof(Stack) * 4);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	ps->top = 0;
	ps->capicity = 4;
}
// 入栈
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->top == ps->capicity)
	{
		Stack* tmp = (Stack*)realloc(ps->a, sizeof(Stack) * ps->capicity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capicity *= 2;
	}
	ps->a[ps->top] = data;
	ps->top++;
}
// 出栈
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}
bool StackEmpty(Stack* ps);
// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}
// 销毁栈
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capicity = ps->top = 0;
}