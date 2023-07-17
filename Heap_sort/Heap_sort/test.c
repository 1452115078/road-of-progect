#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"

void HeapTest1()
{
	int array[] = { 27,15,19,18,28,34,65,49,25,37 };
	int sz = sizeof(array) / sizeof(array[0]);
	Heap hp;
	HeapCreate(&hp, array, sz);
	HeapPrint(&hp);

	HeapPush(&hp, 100);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
	printf("%d ", HeapTop(&hp));

	HeapDestory(&hp);
}
void Heapsort(HPDataType* array, int sz)
{
	////建小堆 向下调整 降序结果 
	//for (int i = ((sz - 1 - 1) / 2); i >= 0; --i)
	//{
	//	Adjustdown(array, i, sz);
	//}
	//for (int i = 0; i < sz; i++)
	//{
	//	swap(&array[0], &array[sz - 1 - i]);
	//	Adjustdown(array, 0, sz - 1 - i);
	//}
	//建xiao堆 向下调整 jiang序结果
	for (int i = ((sz - 1 - 1) / 2); i >= 0; --i)
	{
		Adjustdown(array, i, sz);
	}
	for (int i = 0; i < sz; i++)
	{
		swap(&array[0], &array[sz - 1 - i]);
		Adjustdown(array, 0, sz - 1 - i);
	}
}
void HeapTest2()
{
	int array[] = { 27,15,19,18,28,34,65,49,25,37 };
	int sz = sizeof(array) / sizeof(array[0]);
	Heapsort(array, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
void HeapTest3()
{
	int array[10000];
	int sz = sizeof(array) / sizeof(array[0]);

	//造数据
	int k = 10;
	int n = 10000;
	srand(time(NULL));
	FILE* fin = fopen("data.txt", "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int val = rand() % 100000;
		fprintf(fin, "%d\n", val);
	}

	fclose(fin);
	////读取数据
	FILE* fout = fopen("data.txt", "r");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(fout, "%d", &array[i]);
	}
	array[5] = 1000000 + 1;
	array[1231] = 1000000 + 2;
	array[531] = 1000000 + 3;
	array[5121] = 1000000 + 4;
	array[115] = 1000000 + 5;
	array[2335] = 1000000 + 6;
	array[9999] = 1000000 + 7;
	array[76] = 1000000 + 8;
	array[423] = 1000000 + 9;
	array[3144] = 1000000 + 10;
	fclose(fout);
	//建小堆
	Adjustdown(array, 0, k);

	for (int i = 0; i < n; i++)
	{
		if (array[0] < array[i])
		{
			swap(&array[0], &array[i]);
			Adjustdown(array, 0, k);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
int main()
{
	//HeapTest1();
	//HeapTest2();
	HeapTest3();
	return 0;
}