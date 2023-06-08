#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDatatype;
typedef struct SeqList
{
	SLDatatype* a;
	int sz;//现存数量
	int capicity;//容量
}SL;

void SLInit(SL* pc);//初始化
void SLDestory(SL* pc);
void SLPrint(SL* pc);//打印

void SLPushback(SL* pc, SLDatatype x);//尾插
void SLPopback(SL* pc);//尾删

void SLPushfront(SL* pc, SLDatatype x);//头插
void SLPopfront(SL* pc);//头删

void SLInsert(SL* pc, int pos, SLDatatype x);//任意位置插入
void SLErase(SL* pc, int pos);//任意位置插入



