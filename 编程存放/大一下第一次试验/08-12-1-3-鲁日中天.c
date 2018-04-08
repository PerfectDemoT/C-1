#include<stdio.h>
#include<stdlib.h>
struct lianbiao{
	int num;
	struct lianbiao* next;
};

void shifang(struct lianbiao *head);

main()
{
	int n;
	struct lianbiao *p1=NULL,*first1=NULL;
	printf("please input list A(end by -1):\n");
	for(;;){
	scanf("%d",&n);
	if(n!=-1){
		first1=malloc(sizeof(struct lianbiao));
		if(first1==NULL){
			printf("内存分配失败\n");
		}
		else{
		first1->num=n;
		first1->next=p1;
		p1=first1;
	}
	}
	else 
	break;
	
}//创建链表1；

struct lianbiao *p2=NULL,*first2=NULL;
printf("please input list B(end by -1):\n");
	for(;;){
	scanf("%d",&n);
	if(n!=-1){
		first2=malloc(sizeof(struct lianbiao));
		if(first2==NULL){
			printf("内存分配失败\n");
		}
		else{
		first2->num=n;
		first2->next=p2;
		p2=first2;
	}
	}
	else 
	break;
	
}//创建链表2；	
	
//进行检测。 

		struct lianbiao *q1=first1,*q2=first2;
		int zhishi=0;
		while(q2){
			while(q1){
				if(q1->num==q2->num){
					while(q2){
					if(q1->num==q2->num){
						q1=q1->next;
						q2=q2->next;
					}
					else{
						zhishi=1;
					break;
				}
				}
					break;
			}
				q1=q1->next;
			}
			if(q1==NULL)
			break;
			else if(zhishi==1)
			break;
		}
		
		if(q2==NULL)
		printf("ListB is the sub sequence of listA.\n");
		else
		printf("ListB is not the sub sequence of listA.\n");
	
	//接下来进行节点释放，运用递归。 
	struct lianbiao *head1=first1,*head2=first2,*last1=first1,*last2=first2;
	while(last1){
		last1=last1->next;
	}
	while(last2){
		last2=last2->next;
	}
	
	shifang(head1);
	shifang(head2);
		free(last1);
		free(last2);
}

void shifang(struct lianbiao *head)
{
	struct lianbiao *r=head->next;
	if(r!=NULL){
		shifang(r);
		free(head);
	}	
}



