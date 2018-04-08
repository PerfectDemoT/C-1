#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_QUEUE 100

struct Stack
{
	char* Top;
	char* Bottom;
	int stack_size;
};
typedef struct Stack STACK;
typedef STACK* STACKPTR;

void initStack(STACKPTR pStack);    //对栈进行初始化的函数
void pushStack(STACKPTR pStack, char data);  //入栈的函数
void popStack(STACKPTR pStack);//出栈的函数
void clearStack(STACKPTR pStack);   //清空栈的函数

int main()
{
	STACKPTR stack;
	int flag = 0;
	stack = (STACKPTR)malloc(sizeof(STACK));
	char data;
	printf("Please input the data(end up with *):");
	scanf("%c", &data);

	initStack(stack);  //初始化栈
	while (data != '*' && flag < MAX_QUEUE)
	{
		pushStack(stack, data);  //将数据入栈
		scanf("%c", &data);
		flag++;
	}
	printf("Now the data are:");
	while (stack->Top != stack->Bottom) //出栈
		popStack(stack);
	clearStack(stack);

	return 0;
}

void initStack(STACKPTR pStack)
{
	if (pStack != NULL)
	{
		pStack->Bottom = (char*)malloc(sizeof(char));
		pStack->Top = pStack->Bottom;
	}
	else
		printf("Error!\n");
}

void pushStack(STACKPTR pStack, char data) //上移Top指针
{
	*pStack->Top = data;
	pStack->Top++;
}

void popStack(STACKPTR pStack)   //下移Top指针
{
	pStack->Top--;
	printf("%c ", *pStack->Top);
}

void clearStack(STACKPTR pStack)  //指针置空
{
	pStack->Bottom = NULL;
	pStack->Top = NULL;
}