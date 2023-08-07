#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void SortPrintf(int* a, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
// ��������
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int begin = i;
		int tmp = a[begin + 1];
		while (begin >= 0)
		{
			if (tmp < a[begin])
			{
				a[begin + 1] = a[begin];
				begin--;
			}
			else
				break;
		}
		a[begin + 1] = tmp;
	}
}
// ϣ������
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
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
						begin -= gap;
					}
					else
						break;
				}
				a[begin + gap] = tmp;
			}
		}
	}
}
// ѡ������
void SelectSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		int begin = j;
		for (int i = begin + 1; i < n; i++)
		{
			if (a[i] < a[begin])
			{
				swap(&a[i], &a[begin]);
			}
		}
	}
}
// ������
void AdjustDwon(int* a, int n, int root)
{
	int child = 0;
	while (root * 2 + 1 < n)
	{
		child = root * 2 + 1;//9 7
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child += 1;
		}
		if (a[child] > a[root])
		{
			swap(&a[child], &a[root]);
		}
		root = child;
	}
}
void HeapSort(int* a, int n)
{
	//���������
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	//����
	for (int i = 0; i < n; i++)
	{
		swap(&a[0], &a[n - 1 - i]);
		AdjustDwon(a, n - 1 - i, 0);
	}
}
// ð������
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = j; i < n - j - 1; i++)
		{
			if (a[i + 1] < a[i])
			{
				swap(&a[i + 1], &a[i]);
			}
		}
	}
}
//����ȡ��
int getmid(int* a, int left, int right)
{
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
	else//a[left] > a[mid]
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[right] > a[left])
			return left;
		else
			return right;
	}
}
// ��������ݹ�ʵ�� ��·����
// ��������hoare�汾
int PartSort1(int* a, int left, int right)
{
	int mid = getmid(a, left, right);
	swap(&a[left], &a[mid]);
	int key = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[key])
		{
			right--;
		}
		while (left < right && a[left] <= a[key])
		{
			left++;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[left], &a[key]);
	key = left;
	return key;
}
// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int mid = getmid(a, left, right);
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
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	
	int prev = left;
	int cur = left + 1;
	int key = left;
	while (cur <= right)
	{
		if (a[cur] < a[key])
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
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	//int keyi = PartSort1(a, left, right);
	//int keyi = PartSort2(a, left, right);
	int keyi = PartSort3(a, left, right);
	//[left,keyi-1] keyi [keyi+1,right]
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}
// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right)
{
	//ջʵ��

}
// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n)
{

}
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n)
{

}