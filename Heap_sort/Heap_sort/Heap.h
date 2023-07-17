#pragma once
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;
void swap(HPDataType* a, HPDataType* b);
void Adjustup(HPDataType* a, int child);//���ϵ���
void Adjustdown(HPDataType* a, int parent, int k);//���µ���
// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n);
// �ѵ�����
void HeapDestory(Heap* hp);
//�ѵĴ�ӡ
void HeapPrint(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);

