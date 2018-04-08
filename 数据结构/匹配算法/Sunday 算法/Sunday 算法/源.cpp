#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

void InitData(char*, char*);
void Sunday(char*, char*);

int main()
{
	char *source, *target;
	source = (char*)malloc(sizeof(char)*MAX);
	target = (char*)malloc(sizeof(char)*MAX);
	InitData(source, target);
	Sunday(source, target);
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
		while ((ch = getchar()) != '#')
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

void Sunday(char* source, char* target)
{
	int i = 0, j = 0, m = 0, k = 0;
	int soulen, tarlen;
	soulen = strlen(source);
	tarlen = strlen(target);

	while (i < soulen && j < tarlen)
	{
		m = i + tarlen;  //����ȷ��m��λ��
		if (source[i] == target[j] )//�ַ�ƥ��ɹ�
		{
			if (j == tarlen-1)
				printf("ƥ��ɹ���\n");
			i++;
			j++;
		}
		else   //�ַ�ƥ�䲻�ɹ�
		{
			for (k = tarlen - 1; k >= 0; k--)  //�Ӻ�ǰ����m��Ӧ���ַ�
			{
				if (source[m] == target[k])
					break;
			}
			i = m - k;
		}
	}
}