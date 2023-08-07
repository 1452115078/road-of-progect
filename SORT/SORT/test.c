#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	if (a1 == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	int* a2 = (int*)malloc(sizeof(int) * N);
	if (a2 == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	int* a3 = (int*)malloc(sizeof(int) * N);
	if (a3 == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	int* a4 = (int*)malloc(sizeof(int) * N);
	if (a4 == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	int* a5 = (int*)malloc(sizeof(int) * N);
	if (a5 == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	int* a6 = (int*)malloc(sizeof(int) * N);
	if (a6 == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	int* a7 = (int*)malloc(sizeof(int) * N);
	if (a7 == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand() + i;
		//a1[i] = i;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();
	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();
	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();
	int begin7 = clock();
	BubbleSort(a6, N);
	int end7 = clock();
	printf("InsertSort:%dms\n", end1 - begin1);
	printf("ShellSort:%dms\n", end2 - begin2);
	printf("SelectSort:%dms\n", end3 - begin3);
	printf("HeapSort:%dms\n", end4 - begin4);
	printf("QuickSort:%dms\n", end5 - begin5);
	printf("MergeSort:%dms\n", end6 - begin6);
	printf("BubbleSort:%dms\n", end7 - begin7);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}
void TestInsertSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int sz = sizeof(a) / sizeof(a[0]);
	SortPrintf(a, sz);
	InsertSort(a, sz);
	SortPrintf(a, sz);
}
void TestShellSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int sz = sizeof(a) / sizeof(a[0]);
	SortPrintf(a, sz);
	ShellSort(a, sz);
	SortPrintf(a, sz);
}
void TestSelectSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int sz = sizeof(a) / sizeof(a[0]);
	SortPrintf(a, sz);
	SelectSort(a, sz);
	SortPrintf(a, sz);
}
void TestHeapSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int sz = sizeof(a) / sizeof(a[0]);
	SortPrintf(a, sz);
	HeapSort(a, sz);
	SortPrintf(a, sz);
}
void TestBubbleSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int sz = sizeof(a) / sizeof(a[0]);
	SortPrintf(a, sz);
	BubbleSort(a, sz);
	SortPrintf(a, sz);
}
void TestQuickSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int sz = sizeof(a) / sizeof(a[0]);
	SortPrintf(a, sz);
	//QuickSort(a, 0, sz - 1);
	QuickSortNonR(a, 0, sz - 1);
	SortPrintf(a, sz);
}
int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	TestQuickSort();
	//TestOP();
	return 0;
}
