#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
	int data;
	struct ListNode *nextPtr;
};

typedef struct ListNode LISTNODE;
typedef LISTNODE* LISTNODEPTR;

LISTNODEPTR createList(int,LISTNODEPTR);
void insert(LISTNODEPTR, int);
void printList(LISTNODEPTR);
void destroyList(LISTNODEPTR);

int main()
{
	int x, m,n;
	printf("Please input the nodelist's number you want create:");
    scanf("%d", &n);
	printf("Please input the X you want find:");
	scanf("%d", &x);
	printf("Please input the number of node you want add:");
	scanf("%d", &m);

	LISTNODEPTR headPtr = NULL, selectPtr = NULL,ptr;
	headPtr = (LISTNODEPTR)malloc(sizeof(LISTNODE));
	headPtr = createList(n,headPtr);
	ptr = headPtr->nextPtr;
	while (ptr != NULL)
	{
		if (ptr->data == x)
			insert(ptr, m);
		ptr = ptr->nextPtr;
	}
	printList(headPtr->nextPtr);
	destroyList(headPtr);
	return 0;
}

LISTNODEPTR createList(int n,LISTNODEPTR headPtr)
{
	LISTNODEPTR currentPtr = NULL, lastPtr = headPtr;
	int data;
	printf("Please input the nodelist:");
	for (int i = 1; i <= n; i++)
	{
		currentPtr = (LISTNODEPTR)malloc(sizeof(LISTNODE));
		if (currentPtr != NULL)
		{
			scanf("%d", &data);
			currentPtr->data = data;
			lastPtr->nextPtr = currentPtr;
			lastPtr = currentPtr;
		}
	}
	lastPtr->nextPtr = NULL;
	return headPtr;
}

void insert(LISTNODEPTR selectPtr, int m)
{
	LISTNODEPTR currentPtr, lastPtr = selectPtr, ptr = selectPtr->nextPtr;
	int data;
	printf("Please input the nodelist you want insert:");
	for (int i = 1; i <= m; i++)
	{
		currentPtr = (LISTNODEPTR)malloc(sizeof(LISTNODE));
		if (currentPtr != NULL)
		{
			scanf("%d", &data);
			currentPtr->data = data;
			lastPtr->nextPtr = currentPtr;
			lastPtr = currentPtr;
		}
	}
	lastPtr->nextPtr = ptr;
}

void printList(LISTNODEPTR currentPtr)  //print listnode
{
	if (currentPtr == NULL)
		printf("the list is empty\n");
	else
	{
		printf("the list is:\n");
		while (currentPtr != NULL)
		{
			printf("%d-->", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		printf("NULL\n\n");
	}
}

void destroyList(LISTNODEPTR headPtr)   //detory listnode
{
	LISTNODEPTR tempPtr;
	while (headPtr != NULL)
	{
		tempPtr = headPtr;
		headPtr = headPtr->nextPtr;
		free(tempPtr);
	}
}