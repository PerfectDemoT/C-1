#include<stdio.h>
#include<stdlib.h>
struct lianbiao{
	int num;
	struct lianbiao* next;
};

void shifang(struct lianbiao *head);

main ()
{
	int n,i=0;
	struct lianbiao *p=NULL,*first=NULL;
	printf("please input a list (end by -1):");
	for(;;){
	scanf("%d",&n);
	if(n!=-1){
		first=malloc(sizeof(struct lianbiao));
		if(first==NULL){
			printf("内存分配失败\n");
		}
		else{
			i++;
		first->num=n;
		first->next=p;
		p=first;
	}
	}
	else 
	break;	
}//创建链表；	


if(i!=2){
	struct lianbiao *head,*prep,*tail,*temp;
		tail=NULL;
		//开始排序。		
			tail=NULL;
			head=first;
		while(head->next!=tail){
			prep=head;
			p=head->next;
			while(p->next!=tail){
				if(p->num>p->next->num){
					temp=p->next;
					prep->next=p->next;
					p->next=p->next->next;
					prep->next->next=p;
					p=temp;
				}
				//节点后移。
				p=p->next;
				prep=prep->next; 
			}
			tail=p;
		}
		
		
	//之前会出现第一个节点未排序的情况，现在进行插入，（虽然应该会让时间复杂度增加,
	//不过还未找到更好的方法解决这个问题。）
	//另外链表只有两个数的时候 会有问题，所以单独提出来讨论了。 
		struct lianbiao *now,*pre,*zhiqian=NULL;
		struct lianbiao* zhongjian,*prev;
		int m;
		now=first;
		first=first->next;
		now->next=NULL;
		 m=now->num;
	prev=NULL,now=NULL;
		for(now=first,prev=NULL;
			now->num<m&&now->next!=NULL;
			prev=now,now=now->next)
			;
		if(now->next==NULL){
		now=malloc(sizeof(struct lianbiao));
		now->next=NULL;
		now->num=m;
		prev->next->next=now;
	}
		else if(prev==NULL)
		{
		prev=malloc(sizeof(struct lianbiao));
		prev->num=m;
		prev->next=first; 
		first=prev;
	}
		else
		{	
			zhongjian=malloc(sizeof(struct lianbiao));
			zhongjian->num=m;
			prev->next=zhongjian;
			zhongjian->next=now;
		}
	//有序插入模块结束。
		
}
	else{
	if(first->num>first->next->num){
		first->next->next=first;
		first=first->next;
		first->next->next=NULL;
	}
	}
////排序完毕。
	
	

//输出
		p=first;
		printf("The new list is:");
		while(p){
			printf("%d ",p->num);
			p=p->next;
		} 
		
		
		
//接下来释放节点。
		struct lianbiao *head2=first,*last=first; 
	while(last){
		last=last->next;
	}		
	shifang(head2);
		free(last);	 			
 } 
 
 
 
 void shifang(struct lianbiao *head)
{
	struct lianbiao *r=head->next;
	if(r!=NULL){
		shifang(r);
		free(head);
	}	
}

