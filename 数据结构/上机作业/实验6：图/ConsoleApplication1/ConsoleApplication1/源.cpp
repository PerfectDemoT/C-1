#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define VertexNum 100

typedef struct VertexNode
{
	int vertex;
	VertexNode* next;
};

typedef struct queue
{
	int* DataPtr;
	int front;
	int rear;
	int maxsize;
}QUEUE, *QUEUEPTR; 


void Create(VertexNode*,int,int); //创建邻接表
void Print(VertexNode*, int);//打印邻接表
void DFS(VertexNode*,int,int*,int); //深度优先搜索
void BFS(VertexNode*,QUEUEPTR,int,int);//广度优先搜索
void Init(QUEUEPTR,int);//初始化队列
void push(QUEUEPTR, int);//入队函数
int pop(QUEUEPTR);//出队函数

int main()
{
	VertexNode *v;
	v = (VertexNode*)malloc(sizeof(VertexNode)*VertexNum);
	int n, e; // n为结点数目，e为边数
	//int s[VertexNum];
	QUEUEPTR q;
	q = (QUEUEPTR)malloc(sizeof(QUEUE));
	//memset(s, 0, VertexNum);
	printf("Please input the number of vertex and edges:");
	scanf("%d %d", &n, &e);
	Create(v, n, e);
	Print(v, n);
	Init(q, n);
    //DFS(v,n,s,1);
	BFS(v, q, n,1);
	return 0;
}

void Create(VertexNode* v, int n,int e)
{
	int p, q;
	for (int i = 1; i <= n; i++)
	{
		v[i].vertex = i;
		v[i].next = NULL;
	}
		
	VertexNode *ptr1,*ptr2;
	printf("p->q:\n");
	for (int j = 1; j <= e; j++)
	{
		scanf("%d %d", &p, &q);

		for (ptr1 = &v[p]; ptr1->next != NULL; ) //当从循环中出来时，ptr == NULL
			ptr1 = ptr1->next;
		ptr1->next = (VertexNode*)malloc(sizeof(VertexNode));
		ptr1 = ptr1->next;
		ptr1->vertex = q;
		ptr1->next = NULL;

		for (ptr2 = &v[q]; ptr2->next != NULL; ) //当从循环中出来时，ptr == NULL
			ptr2 = ptr2->next;
		ptr2->next = (VertexNode*)malloc(sizeof(VertexNode));
		ptr2 = ptr2->next;
		ptr2->vertex = p;
		ptr2->next = NULL;
	}
}

void Print(VertexNode* v, int n)
{
	VertexNode *ptr;
	for (int i = 1; i <= n; i++)
	{
		ptr = &v[i];
		while (ptr->next != NULL)
		{
			printf("%d->",ptr->vertex);
			ptr = ptr->next;
		}
		printf("%d->NULL\n", ptr->vertex);
	}
	printf("\n\n");
}

void DFS(VertexNode *v, int n,int *s,int u) //u点为源点
{
	s[u] = 1;
	if (v[u].next->next == NULL)
		printf("%d\n", v[u].vertex);
	else
	{
		for (VertexNode *ptr = &v[u]; ptr != NULL;)
		{
			if (s[ptr->vertex] == 0)
			{
				printf("%d->", v[u].vertex);
				DFS(v, n, s, ptr->vertex);
			}
			ptr = ptr->next;
		}
	}
}

void Init(QUEUEPTR Q,int max)
{
	Q->maxsize = max;
	Q->front = 0;
	Q->rear = Q->front;
	Q->DataPtr = (int*)malloc(sizeof(char));
}

void BFS(VertexNode *v, QUEUEPTR q, int n,int u)  //u为源点
{
	int s[VertexNum];
	int m;
	VertexNode *ptr;
	memset(s, 0, sizeof(int)*VertexNum);
	push(q, u);
	printf("start BFT graph:\n");
	for (int i = 1; i <= n; i++)
	{
		m = pop(q);
		s[m] = 1;
		printf("%d ", m);
		ptr = v[m].next;
		while (ptr != NULL)
		{
			if (s[ptr->vertex] == 0)
				push(q, ptr->vertex);
			ptr = ptr->next;
		}
	}

}

void push(QUEUEPTR q, int n)
{
	q->DataPtr[q->rear] = n;
	q->rear++;
}

int pop(QUEUEPTR q)
{
	int i = q->DataPtr[q->front];
	q->front++;
	return i;
}