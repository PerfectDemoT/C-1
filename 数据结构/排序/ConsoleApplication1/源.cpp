#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define NUM 12
void Swap(int*, int*);
void PrintStr(int*);
void BubbleSort(int*);
void QuickSort(int *,int);
void InsertSort(int *);
void ShellSort(int *);
void SelectSort(int *);
//堆排数组从1开始
void HeapSort(int *);
void HeapBuild(int *, int);
void HeapAdjust(int *, int, int);
//归并排序
void MergeSort(int *, int, int);
void Merge(int*, int, int, int);


int main()
{
	int str[NUM];
	for (int i = 0; i < NUM; i++)
		str[i] = rand() % 100 + 1;
	PrintStr(str);
	printf("Merge sort:");
	MergeSort(str, 0, NUM - 1);
	PrintStr(str);
	printf("\n");

	int str1[NUM];
	for (int i = 0; i < NUM; i++)
		str1[i] = rand() % 100 + 1;
	PrintStr(str1);
	printf("Insert sort:");
	InsertSort(str1);
	PrintStr(str1);
	printf("\n");

	int str2[NUM];
	for (int i = 0; i < NUM; i++)
		str2[i] = rand() % 100 + 1;
	PrintStr(str2);
	printf("Select sort:");
	SelectSort(str2);
	PrintStr(str2);
	printf("\n");

	return 0;
}

void Swap(int *aptr, int *bptr)
{
	int temp;
	temp = *aptr;
	*aptr = *bptr;
	*bptr = temp;
}

void PrintStr(int *str)
{
	for (int i = 0; i < NUM; i++)
		printf("%d ", str[i]);
	printf("\n");
}

void BubbleSort(int *str)
{
	for (int i = 0; i < NUM; i++)
		for (int j = 0; j < NUM - 1 - i; j++)
			if (str[j] > str[j + 1])
				Swap(&str[j], &str[j + 1]);
	PrintStr(str);
}

void QuickSort(int *str,int num)
{
	int i, j, aim;
	i = 0;
	j = 1;
	aim = str[0];
	if (num == 1)
		printf("%d ",*str);
	else
	{
		for (; j < num; j++)
			if (str[j] < aim)
			{
				Swap(&str[j], &str[i + 1]);
				i++;
			}
		Swap(&str[0], &str[i]);
		if(i>0)
		   QuickSort(&str[0], i);
		printf("%d ", str[i]);
		if (num - 1 - i>0)
			QuickSort(&str[i + 1], num - 1 - i);
	}

}

void InsertSort(int *str)
{
	for (int i = 1; i < NUM; i++)
	{
		if (str[i] < str[i - 1])
		{
			int j = i - 1;
			int x = str[i];
			str[i] = str[i - 1];
			while (j >= 0 && x < str[j])
			{
				str[j + 1] = str[j];
				j--;
			}
			str[j + 1] = x;
		}
	}
}

void ShellSort(int *str)
{
	int i, j, gap;
	for (gap = NUM / 2; gap > 0; gap /= 2)
		for (i = gap; i < NUM; i++)
			for (j = i - gap; j >= 0 && str[j] > str[j + gap]; j -= gap)
				Swap(&str[j], &str[j + gap]);
	PrintStr(str);
}

void SelectSort(int *str)
{
	for (int i = 0; i < NUM - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < NUM; j++)
			if (str[j] > str[k])
				k = j;
		if (k != i)
		{
			int t = str[i];
			str[i] = str[k];
			str[k] = t;
		}
	}
}

void HeapSort(int *pstr)
{
	int i;
	HeapBuild(pstr, NUM);
	for (i = NUM; i >= 1; i--)
	{
		Swap(&pstr[1], &pstr[i]);
		HeapBuild(pstr, i-1);
	}
}

void HeapBuild(int *pstr,int size)
{
	int i;
	for (i = size / 2; i >= 1; i--)
		HeapAdjust(pstr, i,size);
}

void HeapAdjust(int *str, int i,int size)
{
	int lChild = 2 * i;
	int rChild = 2 * i + 1;
	int max = i; 
	if (i <= size / 2)
	{
		if (lChild <= size && str[lChild] > str[max])
			max = lChild;
		if (rChild <= size && str[rChild] > str[max])
			max = rChild;
		if (max != i)
		{
			Swap(&str[i], &str[max]);
			HeapAdjust(str, max,size);
		}
	}
}

void MergeSort(int *str,int first,int last)
{
	int mid = 0;
	if (first < last)
	{
		mid = (first + last) / 2;
		MergeSort(str, first, mid);
		MergeSort(str, mid + 1, last);
		Merge(str, first, mid, last);
	}
}

void Merge(int *str, int first, int mid, int last)
{
	int i, index;
	int first1, first2, last1, last2;
	int *temp;
	temp = (int*)malloc(sizeof(int)*(last - first + 1));
	if (temp == NULL)
		printf("ERROR!\n");
	first1 = first;
	last1 = mid;
	first2 = mid + 1;
	last2 = last;
	index = 0;
	while ((first1 <= last1) && (first2 <= last2))
	{
		if (str[first1] < str[first2])
			temp[index++] = str[first1++];
		else
			temp[index++] = str[first2++];
	}
	while(first1 <= last1)
		temp[index++] = str[first1++];
	while(first2 <= last2)
		temp[index++] = str[first2++];
	for (i = 0; i < (last - first + 1); i++)
		str[first + i] = temp[i];
	free(temp);
}

