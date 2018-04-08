#include<stdio.h>
#include<stdlib.h>
void shiyan(int *point_1,int *point_2);
main()
{
	int k[100]={342,345,67,1423,768},*aptr_1,*aptr_2,l,*array;
	char M[100]="Hello word!",*str_1;
	str_1=M;
	array=malloc(sizeof(int)*10);
	printf(M);
	puts(M);
	printf("%s\n",str_1);
	printf("%s\n",&*str_1);
	for(;*str_1;str_1++)
	printf("%c",*str_1); 
	printf("\n");
	aptr_1=&k[1];
	aptr_2=&k[4];
	printf("%d\n",aptr_2-aptr_1);
	int a,c,b,*point_1,*point_2,i;
	scanf("%d %d %d",&a,&b,&c);
	point_1=&a;
	point_2=&b;
	printf("%d %d\n",*point_1,*point_2);
	if(a<b){
		shiyan(point_1,point_2);
	}
	printf("%d %d\n",*point_1,*point_2);
	printf("%d %d\n",a,b);
	if(a>b){
		i=*point_1;
		*point_1=*point_2;
		*point_2=i;
	}
	printf("%d %d\n",*point_1,*point_2);
	printf("%d %d",a,b);
}

void shiyan(int *point_1,int *point_2)
{
	int i;
	i=*point_1;
	*point_1=*point_2;
	*point_2=i;
}
