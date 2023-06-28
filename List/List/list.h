#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDataType;
typedef struct SList
{
	struct SList* next;
	struct SList* prev;
	SLTDataType data;
}SList;
SList* BuySListNode(SLTDataType x);
SList* InitSList();
void SLTPrint(SList* phead);
void pushback(SList* phead, SLTDataType x);
void popback(SList* phead);
void pushfront(SList* phead, SLTDataType x);
void popfront(SList* phead);
SList* Find(SList* phead, SLTDataType x);
void SLTInsert(SList* phead, SLTDataType x);
void SLTErase(SList* phead);


