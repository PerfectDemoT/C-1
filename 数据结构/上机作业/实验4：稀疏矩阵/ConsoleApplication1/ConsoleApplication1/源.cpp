#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSIZE 1000

typedef struct
{
	int i, j;  //数据在矩阵中的行标和列标
	int e;  //数据
}Triple;

typedef struct
{
	Triple data[MAXSIZE + 1];  //三元组表 data[0]不用
	int mu, nu, tu;  //行数，列数，非零元个数
}TSMatrix;


TSMatrix NewMatrix();  //建立一个三元组表示的稀疏矩阵
void PrintMatrix(TSMatrix*);   //打印稀疏矩阵的所有元素

int main()
{
	TSMatrix M;
	int m, n, flag = 1;
	while (flag)
	{
		M = NewMatrix();
		PrintMatrix(&M);
		printf("If input the other matrix?");
		scanf("%d", &flag);
	}
	return 0;
}

TSMatrix NewMatrix()  //建立一个三元组表示的稀疏矩阵
{
	TSMatrix M;
	int str[100][100];
	int m, n, num = 1; //三元表列标是从1开始的

	printf("Please input the matrix's row:");
	scanf("%d", &m);
	printf("Please input the matrix's rank:");
	scanf("%d", &n);
	M.mu = m;
	M.nu = n;
	M.tu = 0;

	printf("Please input a matrix:\n");
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &str[i][j]);
			if (str[i][j] != 0)
			{
				M.data[num].e = str[i][j];
				M.data[num].i = i+1;
				M.data[num].j = j+1;
				M.tu++; num++;
			}
		}
	return M;
}

void PrintMatrix(TSMatrix *M)
{
	printf("三元表为：\n");
	printf("row\trank\tdata\n");
	for (int i = 1; i <= M->tu; i++)
		printf("%d\t%d\t%d\n", M->data[i].i, M->data[i].j, M->data[i].e);
}
