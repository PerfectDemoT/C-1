/************************************
* About:    ����ͼ��Dijkstra�㷨ʵ��*
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

//�����鶼���±�1��ʼ
int main()
{
	int dist[MAXNUM];  //��ǰ�㵽Դ������·��
	int prev[MAXNUM];  //��¼��ǰ���ǰһ�����
	int c[MAXNUM][MAXNUM]; //ͼ���ڽӾ���
	int n, line;  //����� ·����
	int p, q, len; //�ڽӾ����еĺ������꼰����

	printf("Please inut the number of node:");
	scanf("%d", &n);
	printf("Please input the number of line:");
	scanf("%d", &line);

	for (int i = 1; i <= n; i++) //��ʼ������
		for (int j = 1; j <= n; j++)
			c[i][j] = MAXINT;

	for (int i = 1; i <= n; i++)
		dist[i] = MAXINT;

	printf("p -> q:line��\n");
	for (int i = 1; i <= line; i++)
	{
		scanf("%d %d %d", &p, &q, &len);
		c[p][q] = len;
	}

	for (int i = 1; i <= n; i++) //��ӡ�ڽӾ���
	{
		for (int j = 1; j <= n; j++)
			printf("%8d", c[i][j]);
		printf("\n");
	}
	printf("\n");

	Dijkstra(n, 1, dist, prev, c);
	printf("Դ�㵽���һ����������·�����ȣ�%d\n", dist[n]);
    printf("Դ�㵽���һ�������·��Ϊ:");
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
	bool s[MAXNUM];   //�ж��Ƿ��Ѵ���S������
	for (int i = 1; i <= n; i++)
	{
		dist[i] = c[v][i];   //��Դ���������֮��ľ������dist
		s[i] = 0;   //��ʼ��
		if (dist[i] == MAXINT)
			prev[i] = 0;
		else
			prev[i] = v;
	}
	dist[v] = 0;  //Դ��v��v�ľ���Ϊ0
	s[v] = 1;  //��Դ�����S��

	//��û�з���S�Ľ��i�У�ȡdist[i]min,������S��
	//�ӵڶ�����㿪ʼ����һ����Դ��
	for (int i = 2; i <= n; i++)
	{
		int temp = MAXINT;  //�����Ƚϴ�С����dist��
		int u = v;

		//�ҳ�dist�е���Сֵ
		for (int j = 1; j <= n; j++)  
			if (!s[j] && dist[j] < temp) //û�з���S����С��֮ǰ��ֵ
			{
				u = j;
				temp = dist[j];
			}
		s[u] = 1;  //������С�ĵ��Ѿ�����S������

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
	int que[MAXNUM];  //�����v��u�ľ����ĵ�
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

