#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSIZE 1000

typedef struct
{
	int i, j;  //�����ھ����е��б���б�
	int e;  //����
}Triple;

typedef struct
{
	Triple data[MAXSIZE + 1];  //��Ԫ��� data[0]����
	int mu, nu, tu;  //����������������Ԫ����
}TSMatrix;


TSMatrix NewMatrix();  //����һ����Ԫ���ʾ��ϡ�����
void PrintMatrix(TSMatrix*);   //��ӡϡ����������Ԫ��

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

TSMatrix NewMatrix()  //����һ����Ԫ���ʾ��ϡ�����
{
	TSMatrix M;
	int str[100][100];
	int m, n, num = 1; //��Ԫ���б��Ǵ�1��ʼ��

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
	printf("��Ԫ��Ϊ��\n");
	printf("row\trank\tdata\n");
	for (int i = 1; i <= M->tu; i++)
		printf("%d\t%d\t%d\n", M->data[i].i, M->data[i].j, M->data[i].e);
}
