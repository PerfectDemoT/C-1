//最后的插入模块有问题。
//删除模块当没有搜寻到数字时也会出现异常停止问题 

#include<stdio.h>
#include<stdlib.h>

	struct lianbiao{
		int value;
		struct lianbiao* next;
	};


	struct lianbiao* shengcheng(struct lianbiao* list,int n);

main ()
{
	int n,c,s;
	struct lianbiao* first=NULL;
	printf("输入需要生成链表的数字(0作为停止符)\n");
	for(;;){
		scanf("%d",&n);
		if(n==0)
		break; 
		first=shengcheng(first,n);
	}//生成链表。
	
	 struct lianbiao*p=NULL;
	for(p=first;p!=NULL;p=p->next){
		printf("%d ",p->value);
	}//遍历链表。 
	
	printf("\n");
	printf("输入你想查找的数字\n");
	scanf("%d",&c); 
	for(p=first;p!=NULL;p=p->next){
		if(p->value==c)
		break;
	}
		if (p!=NULL)
		printf("%d\n",p->value);
		else 
		printf("这个数字不存在\n");//遍历搜寻。
		
		struct lianbiao* prev=NULL,*now=NULL;
		printf("请输入需要删除的数字\n");
		scanf("%d",&s);
		for(now=first,prev=NULL;
			now->value!=s&&now!=NULL;
			prev=now,now=now->next)
			;
		if(now==NULL)
		printf("没有找到该数字，无动作\n");//没有找到该数字时会导致程序停止异常。 
		else if(prev==NULL)
		{
		printf("链表第一个为该数字，删除第一个\n");
		first=first->next;
		free(now);
	}
		else
		{	
			prev->next=now->next;
			printf("该数字在链表中间，已删除\n\n");
			free(now);
		}//链表的节点与数据删除。 
			
	
	//此为另外设计的模块，当链表中的数为有序时，进行中间插入。
	struct lianbiao* zhongjian;
	prev=NULL,now=NULL;
	int k ;
		printf("请输入需要插入的数字\n(此为实验模块，请确保之前数字输入时已经完成从小到大排序。)\n");
		scanf("%d",&k);
		for(now=first,prev=NULL;
			now->value<k&&now->next!=NULL;
			prev=now,now=now->next)
			;
		if(now->next==NULL){
		now=malloc(sizeof(struct lianbiao));
		now->next=NULL;
		now->value=k;
		prev->next->next=now;
		printf("该数字大于所有数字，已插入到最后。\n");
	//	free(prev); 
	}
		else if(prev==NULL)
		{
		prev=malloc(sizeof(struct lianbiao));
		prev->value=k;
		prev->next=first; 
		printf("该数字小于链表中所有的数字，已插入到第一个。\n");
		first=prev;
	//	free(now);
	}
		else
		{	
			zhongjian=malloc(sizeof(struct lianbiao));
			zhongjian->value=k;
			prev->next=zhongjian;
			zhongjian->next=now;
			printf("该数字在链表中间，已插入。\n");
		//	free(now);
		}
	//有序插入模块结束。
	
	//此处对插入的模块进行输出检测 
	struct lianbiao* temp;
	for(p=first;p!=NULL;p=p->next){
		printf("%d ",p->value);
	}//遍历链表。************还未检测出插入模块是否正常********* 
 } 
 
 	struct lianbiao* shengcheng(struct lianbiao* list,int n)
 	{
 		struct lianbiao* new;
 		new=malloc(sizeof(struct lianbiao));
 		if (new==NULL){
 			printf("内存分配失败\n");
 		}
 		new->next=NULL;
 		new->value=n;
 		new->next=list;
 		return new;
 		
 		
	 }
