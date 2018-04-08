#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000
#define MIN -1000

int Find_Max_Crossing_Subarray(int*, int, int, int);
int Find_Maximum_Subarray(int*, int, int);

int  left_sum, right_sum, cross_sum, max_left, max_right;

int main()
{
	int low, high, mid,sum;
	int A[MAX];
	printf("Please input the length of the string:");
	scanf("%d", &high);
	high--;
	low = 0;
	printf("Please input the string:\n");
	for (int j = 0; j <= high; j++)
		scanf("%d", &A[j]);
	sum = Find_Maximum_Subarray(A, low, high);
	printf("%d", sum);
	return 0;
}

int Find_Maximum_Subarray(int* A, int low, int high)
{
	int mid;
	if (low == high)
		return A[low];
	else
	{
		mid = (low + high) / 2;
		left_sum = Find_Maximum_Subarray(A, low, mid);
		right_sum = Find_Maximum_Subarray(A, mid + 1, high);
		cross_sum = Find_Max_Crossing_Subarray(A, low, mid, high);
		if (left_sum >= right_sum && left_sum >= cross_sum)
			return left_sum;
		else if (right_sum >= left_sum && right_sum >= cross_sum)
			return right_sum;
		else
			return cross_sum;
	}
}

int Find_Max_Crossing_Subarray(int *A, int low, int mid, int high)
{
	int sum = 0;
	left_sum = MIN;
	for (int i = mid; i >= low; i--)
	{
		sum = sum + A[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}
	sum = 0;
	right_sum = MIN;
	for (int i = mid + 1; i <= high; i++)
	{
		sum = sum + A[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = i;
		}
	}
	return left_sum + right_sum;
}