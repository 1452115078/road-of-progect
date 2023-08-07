#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
#include "Stack.h"
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Printsort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
// 插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int begin = i;
		int tmp = a[begin];
		while (begin >= 0)
		{
			if (a[begin + 1] < a[begin])
			{
				swap(&a[begin + 1], &a[begin]);
			}
			begin--;
		}
	}
}
//希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//for (int i = 0; i < n - gap; i++)
		//{
		//	int begin = i;
		//	int tmp = a[begin + gap];
		//	while (begin >= 0)
		//	{
		//		if (tmp < a[begin])
		//		{
		//			a[begin + gap] = a[begin];
		//			//swap(&a[begin + gap], &a[begin]);
		//			begin -= gap;
		//		}
		//		else
		//		{
		//			break;
		//		}
		//	}
		//	a[begin + gap] = tmp;
		//}
		for (int j = 0; j < gap; j++)
		{
			for (int i = j; i < n - gap; i += gap)
			{
				int begin = i;
				int tmp = a[begin + gap];
				while (begin >= 0)
				{
					if (tmp < a[begin])
					{
						a[begin + gap] = a[begin];
						//swap(&a[begin + gap], &a[begin]);
						begin -= gap;
					}
					else
					{
						break;
					}
				}
				a[begin + gap] = tmp;
			}
		}
	}
}
// 选择排序
void SelectSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		int key = j;
		//找出最大最小元素
		for (int i = j; i < n; i++)
		{
			if (a[i] < a[key])
			{
				key = i;
			}
		}
		swap(&a[j], &a[key]);
	}
	
	//for (int j = 0; j < n; j++)
	//{
	//	int mini = j;
	//	int maxi = j;
	//	for (int i = j; i < n - j; i++)
	//	{
	//		if (a[i] > a[mini])
	//			mini = i;//mini = 1
	//		if (a[i] < a[maxi])
	//			maxi = i;//maxi = 0
	//	}
	//	swap(&a[j], &a[mini]);
	//	if (maxi == j)
	//		maxi = mini;
	//	swap(&a[n - 1 - j], &a[maxi]);
	//}
}
//// 堆排序
void AdjustDwon(int* a, int n, int root)
{
	//root = 3 2 1 0
	int child = 0;
	while (2 * root + 1 < n )
	{
		child = 2 * root + 1;//7 5 3 9 1
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child += 1;//6 4 2
		}
		if (a[child] > a[root])
		{
			swap(&a[child], &a[root]);
		}
		root = child;//2
	}
}
void HeapSort(int* a, int n)
{
	//升序 建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	//调整
	//1、交换2、调整
	for (int i = 0; i < n; i++)
	{
		swap(&a[0], &a[n - 1 - i]);
		AdjustDwon(a, n - i - 1, 0);
	}
	
}
// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		int flag = 0;
		for (int i = 0; i < n - 1 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(&a[i], &a[i + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
//三数取中
int getmax(int* a, int begin, int end)
{
	int left = begin;
	int right = end;
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[right] < a[left])
			return left;
		else
			return right;
	}
	else
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[right] > a[left])
			return left;
		else
			return right;
	}
}
//二路划分
//hoare版本
int partsort1(int* a, int left, int right)
{
	int begin = left, end = right;
	int mid = getmax(a, left, right);
	swap(&a[begin], &a[mid]);
	int keyi = begin;
	while (begin < end)
	{
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}
		while (begin < end && a[begin] <= a[keyi])
		{
			++begin;
		}
		swap(&a[begin], &a[end]);
	}
	swap(&a[keyi], &a[end]);
	keyi = begin;
	return keyi;
}
//挖坑法
int partsort2(int* a, int left, int right)
{
	int mid = getmax(a, left, right);
	swap(&a[left], &a[mid]);
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}
//前后指针
int partsort3(int* a, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	int key = begin;
	while (cur <= end)
	{
		if (a[cur] < a[key] && prev != cur)
		{
			prev++;
			swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	swap(&a[prev], &a[key]);
	key = prev;
	return key;
}
//三路划分
void partsort4(int* a, int left, int right,int* key,int* keyi1)
{
	int begin = left, end = right;
	int mid = getmax(a, begin, end);
	swap(&a[begin], &a[mid]);
	int keyi = a[begin];
	int cur = begin + 1;
	while (cur <= end)
	{
		if (a[cur] < keyi)
		{
			swap(&a[cur], &a[begin]);
			cur++;
			begin++;
		}
		else if (a[cur] > keyi)
		{
			swap(&a[cur], &a[end]);
			end--;
		}
		else
		{
			cur++;
		}
	}
	*key = end;
	*keyi1 = begin;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	//if ((right - left+1) < 10)
	//{
	//	InsertSort(a + left, right - left+1);//小区间优化减少迭代次数
	//}
	//else
	//{
		int key = 0;
		int keyi1 = 0;
		partsort4(a, left, right, &key,&keyi1);
		QuickSort(a, left, keyi1 - 1);
		QuickSort(a, key + 1, right);
	//}
}
void QuickSortNonr(int* a, int begin, int end)
{
	ST st;
	InitStack(&st);
	StackPush(&st, begin);
	StackPush(&st, end);
	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		int keyi = partsort1(a, left, right);
		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}
		if (left < keyi -1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi-1);
		}
		
	}
	DestoryStack(&st);
}
void _mergesort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	//使得子区间有序
	//[begin,mid] [mid+1,end]
	int mid = (begin + end) / 2;
	_mergesort(a, begin, mid, tmp);
	_mergesort(a, mid + 1, end, tmp);
	//归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	_mergesort(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}
void MergeSortNonr1(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	int rangeN = 1;
	while (rangeN < n)
	{
		for (int i = 0; i < n; i += rangeN * 2)
		{
			int begin1 = i, end1 = i + rangeN - 1;
			int begin2 = i + rangeN, end2 = i + 2 * rangeN - 1;
			//printf("[%d,%d],[%d,%d]\n", begin1, end1, begin2, end2);
			if (begin2 >= n)
			{
				break;
			}
			else if (end1 >= n)
			{
				break;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}
			printf("[%d,%d],[%d,%d]\n", begin1, end1, begin2, end2);

			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			//调整一部分拷贝一部分
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		rangeN *= 2;
	}
	free(tmp);
	tmp = NULL;
}
void MergeSortNonr2(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	int rangeN = 1;
	while (rangeN < n)
	{
		for (int i = 0; i < n; i += rangeN * 2)
		{
			int begin1 = i, end1 = i + rangeN - 1;
			int begin2 = i + rangeN, end2 = i + 2 * rangeN - 1;
			//printf("[%d,%d],[%d,%d]\n", begin1, end1, begin2, end2);
			if (end1 >= n)
			{
				//修正区间
				end1 = n - 1;
				begin2 = n;
				end2 = n - 1;
			}
			else if (begin2 >= n)
			{
				begin2 = n;
				end2 = n - 1;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}
			//printf("[%d,%d],[%d,%d]\n", begin1, end1, begin2, end2);

			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
		}
		//调整完毕全部一起拷贝
		memcpy(a, tmp, sizeof(int) * (n));
		rangeN *= 2;
	}
	
	free(tmp);
	tmp = NULL;
}