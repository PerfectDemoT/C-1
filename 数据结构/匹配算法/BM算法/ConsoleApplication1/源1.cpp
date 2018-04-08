#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

void InitData(char*, char*);
int GoodValue(char*);
void BM(char*, char*);
int BadValue(char, char*,int);


int  main()
{
	char *source, *target;  //source�ַ�����target������
	source = (char*)malloc(sizeof(char)*MAX);
	target = (char*)malloc(sizeof(char)*MAX);

	InitData(source, target);  //��ʼ��

	BM(source, target);  //BM�㷨

	return 0;

}

void InitData(char* source, char* target)
{
	char ch;
	int i = 0;

	if ((!source) || (!target))
		printf("Error!\n");
	else
	{
		printf("Please input the string(end of with #):");
		while ((ch = getchar() )!= '#')  //ԭ����ҳ�ϵ���Щ���⣬�����õ��Ƕ�ά���飬��Ҳ���Ǻܶ�
		{
			source[i] = ch;
			i++;
		}
		source[i] = '\0';
		printf("Please input the string you want search(end up with #):");
		getchar();
		i = 0;
		while ((ch = getchar()) != '#')
		{
			target[i] = ch;
			i++;
		}
		target[i] = '\0';
	}
}

//����λ�� = �ú�׺��λ�� - �������е���һ�γ���λ��
//����ʱ��λ�õ�ȡֵ��"�ú�׺"�����һ���ַ�Ϊ׼�����"�ú�׺"����������û���ظ����֣���������һ�γ���λ��Ϊ -1
int GoodValue(char* target)
{
	int tarlen = strlen(target);
	char temp;
	int i = 0, value = -1;
	for (; i < tarlen; i++)
	{
		temp = target[tarlen - 1];
		if (target[i] == temp)
			value = i;
		break;
	}
	value = tarlen - 1 - value;
	return value;
}

//���Ƶ�λ�� = ���ַ���λ��-�����ʵ���һ��λ��
int BadValue(char bad, char* target,int place)  //ֱ�ӷ��غ��Ƶ�λ��
{
	int badindex = -1;
	for (int i = 0; i < strlen(target); i++)
	{
		if (bad == target[i])
		{
			badindex = strlen(target) - 1 - i;
		}
	}
	badindex = place - badindex;
	return badindex;
}

void BM(char* source, char* target)
{
	int i = 0, j = 0;
	int soulen = strlen(source);
	int tarlen = strlen(target);
	int badvalue = 0, distence = 0, goodvalue = 0;

	if (soulen<tarlen)  //�Ƚϳ���
		printf("�ַ����ĳ���С�������ʵĳ���\n");

	i = tarlen - 1; j = tarlen - 1; //��β��ʼƥ��

	while (i < soulen && j>=0)
	{
		if (source[i] == target[j])  //�ַ�ƥ��ɹ�
		{
			if (j == 0)
				printf("ƥ��ɹ���\n");
			i--; 
			j--;
		}
		else   //δƥ��ɹ�
		{
			if (j == tarlen - 1)  //���β�ַ�δƥ��ɹ���"���ַ�����"
			{
				badvalue = BadValue(source[i], target,j);
				i = i + badvalue;
			}
			else     //"�ú�׺����"
			{
				goodvalue = GoodValue(target);
				i = i + goodvalue;
			}
		}
	}
}
