#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

void InitStack(ST* ps)
{
	assert(ps);
	/*ps->a = NULL;
	ps->top = 0;
	ps->capicity = 0;*/

	ps->a = (STDataType*)malloc(4 * sizeof(STDataType));
	if (ps->a == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	ps->top = 0;
	ps->capicity = 4;
}
void DestoryStack(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capicity = ps->top = 0;
}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capicity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, ps->capicity * 2 * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capicity *= 2;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}