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
	char *source, *target;  //source字符串，target搜索词
	source = (char*)malloc(sizeof(char)*MAX);
	target = (char*)malloc(sizeof(char)*MAX);

	InitData(source, target);  //初始化

	BM(source, target);  //BM算法

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
		while ((ch = getchar() )!= '#')  //原来网页上的有些问题，好像用的是二维数组，我也不是很懂
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

//后移位数 = 好后缀的位置 - 搜索词中的上一次出现位置
//计算时，位置的取值以"好后缀"的最后一个字符为准。如果"好后缀"在搜索词中没有重复出现，则它的上一次出现位置为 -1
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

//后移的位置 = 坏字符的位置-搜索词的上一次位置
int BadValue(char bad, char* target,int place)  //直接返回后移的位置
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

	if (soulen<tarlen)  //比较长度
		printf("字符串的长度小于搜索词的长度\n");

	i = tarlen - 1; j = tarlen - 1; //从尾开始匹配

	while (i < soulen && j>=0)
	{
		if (source[i] == target[j])  //字符匹配成功
		{
			if (j == 0)
				printf("匹配成功！\n");
			i--; 
			j--;
		}
		else   //未匹配成功
		{
			if (j == tarlen - 1)  //如果尾字符未匹配成功，"坏字符规则"
			{
				badvalue = BadValue(source[i], target,j);
				i = i + badvalue;
			}
			else     //"好后缀规则"
			{
				goodvalue = GoodValue(target);
				i = i + goodvalue;
			}
		}
	}
}
