#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct queue
{
	char* DataPtr;
	int front;
	int rear;
	int maxsize;
}QUEUE,*QUEUEPTR;

void InitQueue(QUEUEPTR Q,int max); //创建队列
void PrintQueue(QUEUEPTR Q);  //打印队列
bool FullQueue(QUEUEPTR Q);  //判断队列是否溢满
bool EmptyQueue(QUEUEPTR Q);  //判断队列是否为空
void InsertQueue(QUEUEPTR Q, char data);  //从尾部插入队列
void AddQueue(QUEUEPTR Q, int size); //增加队列的长度
void DestroyQueue(QUEUEPTR Q);  //销毁队列

int main()
{
	QUEUEPTR Q;
	int maxsize,size;
	char data;

	printf("Please input the size of this circle queue:");
	scanf("%d", &maxsize);
	while (getchar() != '\n');
	
	Q = (QUEUEPTR)malloc(sizeof(QUEUE));
	if (Q == NULL)
		printf("Error!\n");
	else
	{
		InitQueue(Q,maxsize);
		printf("Please input the num you want add:");
		scanf("%c", &data);
		for (int j = 0; j < maxsize;j++)
		{
			InsertQueue(Q, data);
			scanf("%c", &data);
		}

		PrintQueue(Q);
	    printf("Please input the size you want add in this queue:");
		scanf("%d", &size);

		AddQueue(Q, size);
		printf("Please input the num you want add:");
		getchar();
		for (int i = 0; i < size; i++)
		{
			scanf("%c", &data);
			InsertQueue(Q, data);
		}
		PrintQueue(Q);

		DestroyQueue(Q);
	}
	return 0;
}

void InitQueue(QUEUEPTR Q,int max)
{
	Q->maxsize = max+1;
	Q->front = 0;
	Q->rear = Q->front;
	Q->DataPtr = (char*)malloc(sizeof(char));
}

void PrintQueue(QUEUEPTR Q)
{
	if (EmptyQueue(Q))
		printf("Error!\n");
	else
	{
		for (int i = Q->front; i != Q->rear; i++)
		{
			if (i > Q->maxsize)
				i = i%Q->maxsize;
			printf("%c ", Q->DataPtr[i]);
		}
		printf("\n");
	}

}

bool FullQueue(QUEUEPTR Q)
{
	if ((Q->rear + 1) % Q->maxsize == Q->front)
		return true;
	else
		return false;
}

bool EmptyQueue(QUEUEPTR Q)
{
	if (Q->front == Q->rear)
		return true;
	else
		return false;
}

void InsertQueue(QUEUEPTR Q, char data)
{
	if (FullQueue(Q))
		printf("Error!\n");
	else
	{
		Q->DataPtr[Q->rear] = data;
		Q->rear = (Q->rear + 1) % Q->maxsize;
	}
}

void AddQueue(QUEUEPTR Q, int size)
{
	Q->maxsize = Q->maxsize + size;
}

void DestroyQueue(QUEUEPTR Q)
{
	Q->DataPtr = NULL;
	Q->front = 0;
	Q->rear = 0;
}
