#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_capacity = 4;
	ps->_top = 0;
	ps->_a = (STDataType*)malloc(sizeof(STDataType) * ps->_capacity);
	if (ps->_a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
}
// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	//�������
	if (ps->_capacity == ps->_top)
	{
		STDataType* tmp = (STDataType*)realloc(ps->_a, sizeof(STDataType) * ps->_capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->_a = tmp;
		ps->_capacity *= 2;
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->_top--;
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->_a[ps->_top - 1];
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->_top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0;
}
// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}