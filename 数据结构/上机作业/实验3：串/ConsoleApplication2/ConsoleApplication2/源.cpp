#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

#define MAX 100

typedef struct Chunk
{
	char ch[1];
	struct Chunk* nextPtr;
}Chunk;

typedef struct
{
	Chunk *head, *tail;
	int curlen;
}LString;

void GetChunk(Chunk* C,LString* L);
void Chunkcmp(LString *str1, LString *str2);

int main()
{
	Chunk *C1, *C2;
	LString* L1 = (LString*)malloc(sizeof(LString));
	LString* L2 = (LString*)malloc(sizeof(LString));
	C1 = (Chunk*)malloc(sizeof(Chunk));
	C2 = (Chunk*)malloc(sizeof(Chunk));
	GetChunk(C1, L1);
	GetChunk(C2, L2);
	Chunkcmp(L1, L2);
	return 0;
}

void GetChunk(Chunk*c1, LString*l1)
{
	char *ch;
	Chunk *c = c1,*currentptr;
	int i = 0;

	ch = (char*)malloc(sizeof(char)*MAX);
	printf("Please input the string:");
	ch[0] = getchar();
	if (ch[0] == '\n')
		ch[0] = '\0';
	else
	{
		while (ch[i] != '\n')
		{ 
			i++;
			scanf("%c", &ch[i]);
		}
	}
	i = 0;
	l1->head = c;

	for (; ch[i]; i++)
	{
		c->ch[0] = ch[i];
	    c->nextPtr = (Chunk*)malloc(sizeof(Chunk));
		c = c->nextPtr;
	}

	l1->curlen = i;
	l1->tail = c;
	c->nextPtr = NULL;
}

void Chunkcmp(LString *str1, LString *str2)
{
	int i = 0, flag = 0;
	Chunk *c1=str1->head, *c2=str2->head;
	while (i < str1->curlen && i < str2->curlen)
	{
		if (c1->ch[0] == c2->ch[0])
		{
			c1 = c1->nextPtr;
			c2 = c2->nextPtr;
			i++;
		}
		else
		{
			flag = 1;
			if (c1->ch[0] > c2->ch[0])
				printf("string1 > string2: %d\n",c1->ch[0]-c2->ch[0]);
			else
				printf("string2 > string1: %d\n", c2->ch[0] - c1->ch[0]);
			break;
		}
	}
	if (flag == 0)
	{
		if (str1->curlen == str2->curlen)
			printf("string1 = string2\n");
		else if (str1->curlen > str2->curlen)
			printf("string1 > string2: %d\n",c1->ch[0]-c2->ch[0]);
		else
			printf("string2 > string1: %d\n",c2->ch[0]-c1->ch[0]);
	}
}