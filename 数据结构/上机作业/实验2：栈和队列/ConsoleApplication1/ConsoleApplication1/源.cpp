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

void initStack(STACKPTR pStack);    //��ջ���г�ʼ���ĺ���
void pushStack(STACKPTR pStack, char data);  //��ջ�ĺ���
void popStack(STACKPTR pStack);//��ջ�ĺ���
void clearStack(STACKPTR pStack);   //���ջ�ĺ���

int main()
{
	STACKPTR stack;
	int flag = 0;
	stack = (STACKPTR)malloc(sizeof(STACK));
	char data;
	printf("Please input the data(end up with *):");
	scanf("%c", &data);

	initStack(stack);  //��ʼ��ջ
	while (data != '*' && flag < MAX_QUEUE)
	{
		pushStack(stack, data);  //��������ջ
		scanf("%c", &data);
		flag++;
	}
	printf("Now the data are:");
	while (stack->Top != stack->Bottom) //��ջ
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

void pushStack(STACKPTR pStack, char data) //����Topָ��
{
	*pStack->Top = data;
	pStack->Top++;
}

void popStack(STACKPTR pStack)   //����Topָ��
{
	pStack->Top--;
	printf("%c ", *pStack->Top);
}

void clearStack(STACKPTR pStack)  //ָ���ÿ�
{
	pStack->Bottom = NULL;
	pStack->Top = NULL;
}