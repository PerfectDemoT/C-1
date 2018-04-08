#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
void InitData(char*, char*);
void Horspool(char*, char*);

int main()
{
	char *source, *target;
	source = (char*)malloc(sizeof(char)*MAX);
	target = (char*)malloc(sizeof(char)*MAX);
	InitData(source, target);
	Horspool(source, target);
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

void Horspool(char*source, char*target)
{
	int tarlen, soulen;
	tarlen = strlen(target);
	soulen = strlen(source);
	int i = 0, j = 0, m = 0;  //i为匹配串的位置，j为模式串的位置

	j = tarlen - 1; //从尾开始匹配
	i = j;
	while (i < soulen && j>=0)
	{
		if (source[i] == target[j])  //字符匹配成功
		{
			if (j == 0)
				printf("success!\n");
			i--; j--;
		}
		else
		{
			for (m = 0; m < tarlen; m++)  //寻找相同的字符
			{
				if (target[m] == source[i])  //存在相同的字符
				{
					i = i - m + tarlen - 1;
					break;
				}
			}
			if (m == tarlen)  //没有相同的字符
				i = i + tarlen;
			j = tarlen - 1;

		}
	}
}