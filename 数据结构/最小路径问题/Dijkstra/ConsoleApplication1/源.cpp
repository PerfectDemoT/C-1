/************************************
* About:    有向图的Dijkstra算法实现*
* Author:   Xiong                   *
* Time:     16.12.7                 *
*************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXNUM 100
#define MAXINT 9999

void Dijkstra(int, int, int*, int*, int (*c)[MAXNUM]);
void SearchPath(int*, int, int);

//各数组都从下标1开始
int main()
{
	int dist[MAXNUM];  //当前点到源点的最短路径
	int prev[MAXNUM];  //记录当前点的前一个结点
	int c[MAXNUM][MAXNUM]; //图的邻接矩阵
	int n, line;  //结点数 路径数
	int p, q, len; //邻接矩阵中的横纵坐标及长度

	printf("Please inut the number of node:");
	scanf("%d", &n);
	printf("Please input the number of line:");
	scanf("%d", &line);

	for (int i = 1; i <= n; i++) //初始化数组
		for (int j = 1; j <= n; j++)
			c[i][j] = MAXINT;

	for (int i = 1; i <= n; i++)
		dist[i] = MAXINT;

	printf("p -> q:line：\n");
	for (int i = 1; i <= line; i++)
	{
		scanf("%d %d %d", &p, &q, &len);
		c[p][q] = len;
	}

	for (int i = 1; i <= n; i++) //打印邻接矩阵
	{
		for (int j = 1; j <= n; j++)
			printf("%8d", c[i][j]);
		printf("\n");
	}
	printf("\n");

	Dijkstra(n, 1, dist, prev, c);
	printf("源点到最后一个顶点的最短路径长度：%d\n", dist[n]);
    printf("源点到最后一个顶点的路径为:");
	SearchPath(prev, 1, n);
	return 0;
}

//n - n nodes
//v - the source node
//dist[] - the distance from the ith node to the source node
//prev[] - the previous of the ith node
//c[][] - every two node's distance
void Dijkstra(int n, int v, int *dist, int *prev, int c[][MAXNUM])
{
	bool s[MAXNUM];   //判断是否已存入S集合中
	for (int i = 1; i <= n; i++)
	{
		dist[i] = c[v][i];   //将源点与各个点之间的距离存入dist
		s[i] = 0;   //初始化
		if (dist[i] == MAXINT)
			prev[i] = 0;
		else
			prev[i] = v;
	}
	dist[v] = 0;  //源点v到v的距离为0
	s[v] = 1;  //将源点放入S中

	//在没有放入S的结点i中，取dist[i]min,放入结点S中
	//从第二个结点开始，第一个是源点
	for (int i = 2; i <= n; i++)
	{
		int temp = MAXINT;  //用来比较大小存入dist中
		int u = v;

		//找出dist中的最小值
		for (int j = 1; j <= n; j++)  
			if (!s[j] && dist[j] < temp) //没有放入S中且小于之前的值
			{
				u = j;
				temp = dist[j];
			}
		s[u] = 1;  //代表最小的点已经存入S集合中

		for (int j = 1; j <= n;j++)
			if (!s[j] && c[u][j] < MAXINT)
			{
				int newdist = dist[u] + c[u][j];
				if (newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
	}
}

//find the path from source v to u
void SearchPath(int *prev, int v, int u)
{
	int que[MAXNUM];  //保存从v到u的经过的点
	int t = 1;
	que[t] = u;
	while (prev[u] != 0) 
	{
		t++;
		que[t] = prev[u];
		u = prev[u];
	}
	for (; t > 1; t--)
		printf("%d->", que[t]);
	printf("%d", que[1]);

}

