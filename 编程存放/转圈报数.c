
//那本薄的C语言数330页第6题。 
//虽然编好了，不过有一堆警告，还要弄懂。 


#include<stdio.h>
struct quan{
	int num;
	struct quan* next;
};

struct quan* shengcheng(struct quan* list,int n);

main ()
{
	int n=13;
	struct quan *first,*last;
	first=malloc(sizeof(struct quan));
	first->next=NULL;
	first->num=n;
	last=first;
	for(n=12;n>=1;n--){
		first=shengcheng(first,n);
	}
	
	last->next=first;//连成一个圈。 
	
	int i;
	struct quan *q,*pre,*f=NULL;
	q=first;
	pre=NULL;
	for(i=1;i<=13;i++){
		if(i%3==0){
			pre->next=q->next;
			f=q;
			q=q->next;
			free(f);	
		}
		else
		{
			pre=q;
			q=q->next;
		}
	}

	struct quan *souxun;
	souxun=first;
	while(souxun->num!=13){
		printf("%d ",souxun->num);
		souxun=souxun->next;
	}
	
}

struct quan* shengcheng(struct quan* list,int n)
 	{
 		struct quan* new;
 		new=malloc(sizeof(struct quan));
 		if (new==NULL){
 			printf("内存分配失败\n");
 		}
 		new->next=NULL;
 		new->num=n;
 		new->next=list;
 		return new;
 	}
 	
