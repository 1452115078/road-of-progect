#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;
void swap(HPDataType* a, HPDataType* b);
void Adjustdown(HPDataType* a, int sz, int parent);//���µ���
void Adjustup(HPDataType* a, int child);//���ϵ���
// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n);
// �ѵ�����
void HeapDestory(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
bool HeapEmpty(Heap* hp);

