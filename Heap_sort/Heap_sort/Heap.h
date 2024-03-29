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
void Adjustup(HPDataType* a, int child);//向上调整
void Adjustdown(HPDataType* a, int parent, int k);//向下调整
// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n);
// 堆的销毁
void HeapDestory(Heap* hp);
//堆的打印
void HeapPrint(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);

