#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int str[100][100];
	int i;
	int m = 0, n = 0;
	scanf("%d", &i);
	while (i)
	{
		if (i == '\n')
		{
			str[m][n] = '\n';
			m++;
		}
		else
		{
			str[m][n] = i;
			n++;
		}
		scanf("%d", &i);
	}
}