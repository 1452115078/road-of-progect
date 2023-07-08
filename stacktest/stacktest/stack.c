#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"

// ��ʼ��ջ
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
// ��ջ
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
// ��ջ
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}
bool StackEmpty(Stack* ps);
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}
// ����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capicity = ps->top = 0;
}