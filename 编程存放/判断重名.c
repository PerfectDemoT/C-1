#include<stdio.h>
main()
{
	char a[50]={"0"},i,j,k,b[50][8]={{"Alice"},{"Bob"},{"Lucky"},{"Kitty"},{"Tim"},{"Lucy"},{"Jim"},{"Helena"}};
	printf("input the names  ");
	gets(a); 
	for(i=1;i<=8;i++)
	{
	if(a[50]==b[50][i])
	printf("���ظ�\n");
	else 
	printf("����\n");
	}
	return 0;
}
