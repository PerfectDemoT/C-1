#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

void InitData(char*, char*);
void GetNext(char*, int*);
void KMP(char*, char*, int*);

int  main()
{
	char *source, *target;  //source字符串，target搜索词
	int next[MAX]; 
	source = (char*)malloc(sizeof(char)*MAX);
	target = (char*)malloc(sizeof(char)*MAX);
	InitData(source, target);  //初始化
	GetNext(target, next);  //获取next数组
	KMP(source, target, next);
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

void GetNext(char *p, int *next)
{
	int plen = strlen(p);
	next[0] = -1;
	int k = -1, j = 0;
	while (j < plen - 1)
	{
		if (k == -1 || p[k] == p[j])
		{
			k++;  j++;
			next[j] = k;
		}
		else
			k = next[k];
	}
}

void KMP(char*source, char*target, int*next)
{
	int i = 0, j = 0, m = 0;
	int soulen, tarlen;
	soulen = strlen(source);
	tarlen = strlen(target);

	while (i < soulen && j < tarlen )
	{
		if (source[i] == target[j])  //如果字符匹配成功
		{
			if (j == tarlen - 1)
			{
				printf("匹配成功！\n");
				m = 1;
			}

			i++; j++; 
		}
		else  //模式串向右移动的位数为：失配字符所在位置 - 失配字符对应的next 值
		{
			i = i - next[j];
			j = 0;
		}
	}
	if (i == soulen && m == 0)
		printf("匹配失败！\n");
}