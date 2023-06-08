#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDatatype;
typedef struct SeqList
{
	SLDatatype* a;
	int sz;//�ִ�����
	int capicity;//����
}SL;

void SLInit(SL* pc);//��ʼ��
void SLDestory(SL* pc);
void SLPrint(SL* pc);//��ӡ

void SLPushback(SL* pc, SLDatatype x);//β��
void SLPopback(SL* pc);//βɾ

void SLPushfront(SL* pc, SLDatatype x);//ͷ��
void SLPopfront(SL* pc);//ͷɾ

void SLInsert(SL* pc, int pos, SLDatatype x);//����λ�ò���
void SLErase(SL* pc, int pos);//����λ�ò���



