#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;//���������ʾ��
	int size;//Ԫ�ظ���
	int capicity;//����
}Hp;

void HeapInit(Hp* php);//��ʼ��
void HeapDestory(Hp* php);//����
void HeapPush(Hp* php, HPDataType x);//����
void HeapPrint(Hp* php);//��ӡ
void HeapPop(Hp* php);//�Ѷ�ɾ��
HPDataType HeapTop(Hp* php);//�Ѷ�Ԫ��
int HeapSize(Hp* php);//�Ѹ���
bool HeapEmpty(Hp* php);//����

