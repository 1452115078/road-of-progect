#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;//创建数组表示堆
	int size;//元素个数
	int capicity;//容量
}Hp;

void HeapInit(Hp* php);//初始化
void HeapDestory(Hp* php);//销毁
void HeapPush(Hp* php, HPDataType x);//插入
void HeapPrint(Hp* php);//打印
void HeapPop(Hp* php);//堆顶删除
HPDataType HeapTop(Hp* php);//堆顶元素
int HeapSize(Hp* php);//堆个数
bool HeapEmpty(Hp* php);//判满

