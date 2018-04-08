/************************************
* About:    ����ͼ��Prim�㷨ʵ��    *
* Author:   Xiong                   *
* Time:     16.12.15                *
*************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXNUM 100
#define MAXINT 9999

void Prim(int (*c)[MAXNUM],int,int,int);

//�����鶼���±�1��ʼ
int main()
{
	int c[MAXNUM][MAXNUM]; //ͼ���ڽӾ���
	int n, line;  //����� ·����
	int p, q, weight; //�ڽӾ����еĺ������꼰Ȩֵ
	int u;//Դ��

	printf("Please inut the number of node:");
	scanf("%d", &n);
	printf("Please input the number of line:");
	scanf("%d", &line);

	for (int i = 1; i <= n; i++) //��ʼ������
		for (int j = 1; j <= n; j++)
			c[i][j] = MAXINT;

	printf("p -> q:line��\n");
	for (int i = 1; i <= line; i++)
	{
		scanf("%d %d %d", &p, &q, &weight);
		c[p][q] = weight;
		c[q][p] = weight;
	}

	for (int i = 1; i <= n; i++) //��ӡ�ڽӾ���
	{
		for (int j = 1; j <= n; j++)
			printf("%8d", c[i][j]);
		printf("\n");
	}
	printf("\n");

	printf("Please input the source vertix:");
	scanf("%d", &u);
	Prim(c, n, line, u);

	return 0;
}

//c:The graph;
//n:The number of all vertix;
//line:The number of all edges;
//u:The source vertix;
void Prim(int(*c)[MAXNUM], int n, int line, int u)
{
	int lowcost[MAXNUM];  //lowcost[i]��¼��iΪ�յ�ıߵ���СȨֵ����lowcost[i]=0ʱ��ʾ�յ�i����������
	int mst[MAXNUM]; //mst[i]��¼��Ӧlowcost[i]�����,��mst[i]=0ʱ��ʾ�յ�i����������
	int i, j, min, minid, sum = 0; //minid:��СȨֵ�ߵĽڵ�  mid:��СȨֵ  sum:��Ȩֵ

	for (i = 1; i <= n; i++) //��ʼ��
	{
		mst[i] = u;  //���е����ʼ�㶼��Դ��u
		lowcost[i] = c[u][i];  //��u��i��Ȩֵ
	}

	for (i = 2; i <= n; i++) //����ʣ�µĵ�
	{
		min = MAXINT;

		for (j = 1; j <= n; j++) //�ҵ���СȨֵ�ı�
		{
			if (lowcost[j] < min && lowcost[j] != 0)
			{
				min = lowcost[j];
				minid = j;
			}
		}
		printf("%d->%d ", mst[minid], minid);
		sum += min;

		lowcost[minid] = 0; //��¼���minid����������

		for (j = 1; j <= n; j++)//���¸��㵽���Ѿ��������ĵ���ɵļ��ϡ�����СȨֵ
		{
			if (j == u);
			else
			{
				if (c[minid][j] < lowcost[j])
				{
					lowcost[j] = c[minid][j];
					mst[j] = minid;
				}
			}
		}

	}
	printf("Sum:%d\n", sum);
}