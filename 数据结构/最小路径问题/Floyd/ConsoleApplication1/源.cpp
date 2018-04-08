/************************************
* About:    ����ͼ��Floyd�㷨ʵ��   *
* Author:   Xiong                   *
* Time:     16.12.8                 *
*************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define VertexNum 100
#define MAXINT 9999

typedef struct
{
	int edges[VertexNum][VertexNum]; //�ڽӾ���
	int n, e; //������������
}MGraph;

void Floyd(MGraph, int(*A)[VertexNum], int(*path)[VertexNum]);
void SearchPath(MGraph,int(*path)[VertexNum]);
void PrintPath(MGraph, int(*path)[VertexNum], int, int);

//���������1��ʼ
int main()
{
	MGraph g; 
	int p, q, len;
	int A[VertexNum][VertexNum]; //��¼ͨ��Floyd�㷨�����С�������
	int path[VertexNum][VertexNum]; //��¼u,v����֮�����·�������뾭���ĵ�
	//��ʼ��
	memset(A, 0, VertexNum*VertexNum);
	memset(path, 0, VertexNum*VertexNum);

	printf("Please input the number of vertex and edges:");
	scanf("%d %d", &g.n, &g.e);

	for (int i = 1; i <= g.n; i++) //��ʼ������
		for (int j = 1; j <= g.n; j++)
		{
			if (i == j)
				g.edges[i][j] = 0;
			else
				g.edges[i][j] = MAXINT;
		}
			
	printf("p -> q:line��\n");
	for (int i = 1; i <= g.e; i++)
	{
		scanf("%d %d %d", &p, &q, &len);
		g.edges[p][q] = len;
	}


	for (int i = 1; i <= g.n; i++) //��ӡ�ڽӾ���
	{
		for (int j = 1; j <= g.n; j++)
			printf("%8d", g.edges[i][j]);
		printf("\n");
	}
	printf("\n");


	Floyd(g, A, path);
	for (int i = 1; i <= g.n; i++) //��ӡ��С�������
	{
		for (int j = 1; j <= g.n; j++)
			printf("%8d", A[i][j]);
		printf("\n");
	}
	printf("\n");

	SearchPath(g,path);
	return 0;
}

void Floyd(MGraph g,int A[][VertexNum],int path[][VertexNum])
{

	int n = g.n;

	//��ʼ��
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			A[i][j] = g.edges[i][j];

	for (int k = 1; k <= n; k++)  //���Ӷ�ΪO(n~3)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (A[i][j]>A[i][k] + A[k][j])
				{
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = k;
				}
			}
	}
}

void SearchPath(MGraph g,int path[][VertexNum]) //��ӡ����������·��
{
	//��������
	for (int i = 1; i <= g.n; i++)
		for (int j = 1; j <= g.n; j++)
		{
			PrintPath(g, path, i, j);
			printf("\n");
		}
}

void PrintPath(MGraph g, int path[][VertexNum], int i, int j)
{
	if (path[i][j] == 0)
		printf("%d->%d  ", i, j);
	else
	{
		PrintPath(g, path, i, path[i][j]);
		PrintPath(g, path, path[i][j], j);
	}
}