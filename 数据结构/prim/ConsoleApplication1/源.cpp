/************************************
* About:    无向图的Prim算法实现    *
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

//各数组都从下标1开始
int main()
{
	int c[MAXNUM][MAXNUM]; //图的邻接矩阵
	int n, line;  //结点数 路径数
	int p, q, weight; //邻接矩阵中的横纵坐标及权值
	int u;//源点

	printf("Please inut the number of node:");
	scanf("%d", &n);
	printf("Please input the number of line:");
	scanf("%d", &line);

	for (int i = 1; i <= n; i++) //初始化数组
		for (int j = 1; j <= n; j++)
			c[i][j] = MAXINT;

	printf("p -> q:line：\n");
	for (int i = 1; i <= line; i++)
	{
		scanf("%d %d %d", &p, &q, &weight);
		c[p][q] = weight;
		c[q][p] = weight;
	}

	for (int i = 1; i <= n; i++) //打印邻接矩阵
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
	int lowcost[MAXNUM];  //lowcost[i]记录以i为终点的边的最小权值，当lowcost[i]=0时表示终点i加入生成树
	int mst[MAXNUM]; //mst[i]记录对应lowcost[i]的起点,当mst[i]=0时表示终点i加入生成树
	int i, j, min, minid, sum = 0; //minid:最小权值边的节点  mid:最小权值  sum:总权值

	for (i = 1; i <= n; i++) //初始化
	{
		mst[i] = u;  //所有点的起始点都是源点u
		lowcost[i] = c[u][i];  //从u到i的权值
	}

	for (i = 2; i <= n; i++) //遍历剩下的点
	{
		min = MAXINT;

		for (j = 1; j <= n; j++) //找到最小权值的边
		{
			if (lowcost[j] < min && lowcost[j] != 0)
			{
				min = lowcost[j];
				minid = j;
			}
		}
		printf("%d->%d ", mst[minid], minid);
		sum += min;

		lowcost[minid] = 0; //记录结点minid加入生成树

		for (j = 1; j <= n; j++)//更新各点到“已经遍历过的点组成的集合”的最小权值
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