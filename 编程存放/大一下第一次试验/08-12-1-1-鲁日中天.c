#include<stdio.h>
#include<stdlib.h>
struct lianbiao{
	int num;
	struct lianbiao* next;
};

main()
{
	int n;
	struct lianbiao *p=NULL,*first=NULL;
	printf("please input the series of integers:");
	for(;;){
	scanf("%d",&n);
	if(n!=-1){
		first=malloc(sizeof(struct lianbiao));
		if(first==NULL){
			printf("内存分配失败\n");
		}
		else{
		first->num=n;
		first->next=p;
		p=first;
	}
	}
	else 
	break;
	
}//创建链表；

	int max,min,all=0;
	p=first;
	max=p->num;
	min=p->num;
	while(p){
		all+=p->num;
		if(min>=p->num){
			min=p->num;
		}
		if(max<=p->num){
			max=p->num;
		}
		p=p->next;
	}//一个循环求最大最小和总和。	
	printf("The maximum,minmum and the total are:%d %d %d",max,min,all);
 } 
