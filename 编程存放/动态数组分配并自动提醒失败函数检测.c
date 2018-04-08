//这是那本厚的C语言书上的练习。
//323页。
//用来分配动态数组的函数，当内存非配失败时，会自动结束程序。 

#include<stdio.h>
#include<stdlib.h>
int* mg_malloc(int n);//函数
main ()
{
	int n;
	int* p;
	printf("请输入n的值。\n");//输入要分配的存储空间数目。 
	scanf("%d",&n);
	p=mg_malloc(n);//p指针来储存分配成功时返回的指针。 
	int i;
	//下面是用来检验空间是否真正被分配(因为分配成功没有什么提示。) 
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	for(i=0;i<n;i++){
		printf("%d",p[i]);
	} 
}

int* mg_malloc(int n)//这是函数。 
{
	int* p=NULL;
	p=malloc(n*sizeof(int));
	if(p==NULL){
	printf("内存分配失败\n");
	exit(0);//失败时结束程序。 
}
	else
	return p;
}



