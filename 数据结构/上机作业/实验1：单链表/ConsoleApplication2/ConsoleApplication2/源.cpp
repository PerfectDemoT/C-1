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

LISTNODEPTR createList(LISTNODEPTR);
void deleteList(LISTNODEPTR, int, int);
void printList(LISTNODEPTR);
void destroyList(LISTNODEPTR);

int main()
{
	int min, max;
	LISTNODEPTR headPtr;

	printf("Please input the min and the max:");
	scanf("%d %d", &min, &max);

	headPtr = (LISTNODEPTR)malloc(sizeof(LISTNODE));
	headPtr = createList(headPtr);
	deleteList(headPtr, min, max);
	//printList(headPtr->nextPtr);
	destroyList(headPtr);
}

LISTNODEPTR createList( LISTNODEPTR headPtr)
{
	LISTNODEPTR currentPtr = NULL, lastPtr = headPtr;
	int data,n;

	printf("Please input the length of the list:");
	scanf("%d", &n);
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

void deleteList(LISTNODEPTR headPtr,int n,int m)
{
	LISTNODEPTR Ptr1 = NULL, Ptr2 = NULL;
	int x=0;
	LISTNODEPTR lastPtr = headPtr,currentPtr = lastPtr->nextPtr;

	while (currentPtr != NULL  )
	{

		if (currentPtr->data < m)
		{
			if (currentPtr->data > n && x == 0)
			{
				Ptr1 = lastPtr;
				x = 1;
			}
			currentPtr = currentPtr->nextPtr;
			lastPtr = lastPtr->nextPtr;
		}
		else
			break;
	}

	Ptr2 = currentPtr;

		Ptr1->nextPtr = Ptr2;
		printList(headPtr->nextPtr);
}