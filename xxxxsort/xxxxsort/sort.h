#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void Printsort(int* a, int n);
// ����ʵ�ֵĽӿ�
// ��������
void InsertSort(int* a, int n);
//ϣ������
void ShellSort(int* a, int n);
//// ѡ������
void SelectSort(int* a, int n);
//// ������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);
// ð������
void BubbleSort(int* a, int n);
void QuickSort(int* a, int left, int right);
void QuickSortNonr(int* a, int left, int right);
void MergeSort(int* a, int n);
void MergeSortNonr1(int* a, int n);
void MergeSortNonr2(int* a, int n);
