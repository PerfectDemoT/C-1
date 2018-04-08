#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
int **Create2(int n,int m);
main()
{

	int i,j,n,m;
	scanf("%d %d",&n,&m);
	int**num;
	num=Create2(n,m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
		scanf("%d",&num[i][j]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
		num[i][j]=-10*num[i][j];
	}
	
	for(i=0;i<n;i++){
		printf("%d",num[i][0]);
		for(j=1;j<m;j++)
		printf(" %d",num[i][j]);
		printf("\n");
		
	}

	free(num);
	num=NULL; 
	
 }
 
int **Create2(int n,int m)
 {
 	int **s,i;
 	s=malloc(sizeof(int *) *n);//也可以之前加上强制类型转化s=(int **)malloc(sizeof(int *) *m); 
 	for(i=0;i<n;i++)
 	s[i]=malloc(sizeof(int)*m);//这里也一样 
 	return s;
 }
