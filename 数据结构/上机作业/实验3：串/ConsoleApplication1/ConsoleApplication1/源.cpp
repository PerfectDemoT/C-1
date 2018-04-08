#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct Chunk
{
	char ch;
	struct Chunk* nextPtr;
}Chunk;

Chunk* strcat(char*, char*);
void PrintStr(Chunk*);

int main()
{
	char *str1 = NULL, *str2 = NULL;
	Chunk *str3 = NULL;
	str1 = (char*)malloc(sizeof(char)*MAX);
	str2 = (char*)malloc(sizeof(char)*MAX);
	str3 = (Chunk*)malloc(sizeof(Chunk));
	printf("Please input str1:");
	scanf("%s", str1);
	printf("Please input str2:");
	scanf("%s", str2);
	printf("The new str is:");
	str3 = strcat(str1, str2);
	PrintStr(str3);
	return 0;
}

Chunk* strcat(char*str1, char*str2)
{
	Chunk *str,*a,*b;
	str = (Chunk*)malloc(sizeof(Chunk));
	a = str;
	int i = 0;
	for (; str1[i]; i++)
	{
		b = (Chunk*)malloc(sizeof(Chunk));
		b->ch = str1[i];
		a->nextPtr = b;
		a = a->nextPtr;
	}
	for (int j = 0; str2[j]; j++)
	{
		b = (Chunk*)malloc(sizeof(Chunk));
		b->ch = str2[j];
		a->nextPtr = b;
		a = a->nextPtr;
	}
	a->nextPtr = NULL;
	return str;
}

void PrintStr(Chunk* str)
{
	for (str = str->nextPtr; str != NULL; str = str->nextPtr)
		printf("%c", str->ch);
}

