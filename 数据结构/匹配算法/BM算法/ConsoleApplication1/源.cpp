#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef int status;
#define MAXSIZE 100
#define ERROR 0
#define TRUE 1


//��ȡvalue����׺���򡱣��ƶ�����
status GetValue(int **value, char *target)
{
	int i = 0, j = 0;
	char temp;
	int tarlen = strlen(target);
	(*value) = (int *)malloc(sizeof(int) *MAXSIZE);
	if (!(*value))return ERROR;

	for (i = 0; i < MAXSIZE; i++) 
	{  //��ʼ��
		(*value)[i] = -1;    //-1�����׺��ƥ����ַ�
	}
	for (i = tarlen - 1; i >0; i--) 
	{
		temp = target[i];

		if (i <tarlen - 1)
			(*value)[i] = (*value)[i + 1];  //��һλ��ֵ��ǰһλ

		for (j = 0; j<i; j++) {
			if (target[j] == temp) {
				(*value)[i] = i - j;   //�ƶ��ľ���
			}
		}
	}
	return TRUE;
}

//��ʼ���ַ�����������
status InitData(char **source, char **target) 
{

	char ch;
	int i = 0;
	(*source) = (char *)malloc(sizeof(char) * MAXSIZE); //��ʼ��
	(*target) = (char *)malloc(sizeof(char) * MAXSIZE);
	if (!(*source) || !(*target))
		return ERROR;
	printf("�������ַ�����#����:\n");
	while ((ch = getchar()) != '#') 
	{
		(*source)[i++] = ch;
		(*source)[i] = '\0';
	}

	printf("��������������#����:\n");
	getchar();  //�س����
	i = 0;

	while ((ch = getchar()) != '#') 
	{
		(*target)[i++] = ch;
		(*target)[i] = '\0';
	}
	return TRUE;

}

//��ȡ�����ַ����ƶ�����
int BadValue(char bad, char *target) 
{
	int i = 0;
	int badindex = -1;
	for (i = 0; i < strlen(target); i++)
	{
		if (bad == target[i])
		{
			badindex = strlen(target) - 1 - i;
		}
	}
	return badindex;
}

//BM�㷨
status BM(char *source, char *target, int *value) 
{
	int i = 0, j = 0, soulen = strlen(source), tarlen = strlen(target);  //��ʼ��
	int badvalue = 0, distance = 0;
	if (soulen<tarlen)
	{  //�Ƚϳ���
		printf("�ַ����ĳ���С�������ʵĳ���\n");
		return ERROR;
	}

	i = tarlen - 1; j = tarlen - 1; //��β��ʼƥ��

	while (i < soulen)
	{
		if (source[i] == target[j]) 
		{  //�ַ�ƥ��ɹ�
			if (j == 0) 
			{
				printf("ƥ��ɹ�\n");
				return TRUE;
			}

			i--; j--;
		}
		else
		{  //δƥ��ɹ�
			if (j == tarlen - 1)
			{  //���β�ַ�δƥ��ɹ���"���ַ�����"
				badvalue = BadValue(source[i], target);
				if (badvalue == -1)
					badvalue = strlen(target);

				i = i + tarlen - 1 - j + badvalue;
				j = tarlen - 1;
			}
			else 
			{  //�к�׺,�Ƚ�"���ַ�����"��"��׺����"
				badvalue = BadValue(source[i], target);
				if (badvalue == -1)
					badvalue = strlen(target);
				distance = badvalue > value[j - 1] ? badvalue : value[j - 1];
				printf("�ƶ�����:%d\n", distance);
				j = tarlen - 1;   //����jλ��
				i = i + tarlen - 1 - j + distance;  //����i��λ��
			}
		}
	}
	printf("ƥ��ʧ��....");
	return ERROR;
}

void main() 
{
	char *source, *target;  //source�ַ�����target������
	int *value;  //�ú�׺�ʱ�

	int i = 0;
	InitData(&source, &target);  //��ʼ��

	GetValue(&value, target); //��ȡ��׺��

	BM(source, target, value);  //BM�㷨


	for (i = 0; i<strlen(target); i++)
	{
		printf("%d\n", value[i]);
	}

	if (source && target) 
	{
		printf("%s\n", source);
		printf("%s\n", target);
	}
}