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
			printf("�ڴ����ʧ��\n");
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
}//��������	


if(i!=2){
	struct lianbiao *head,*prep,*tail,*temp;
		tail=NULL;
		//��ʼ����		
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
				//�ڵ���ơ�
				p=p->next;
				prep=prep->next; 
			}
			tail=p;
		}
		
		
	//֮ǰ����ֵ�һ���ڵ�δ�������������ڽ��в��룬����ȻӦ�û���ʱ�临�Ӷ�����,
	//������δ�ҵ����õķ������������⡣��
	//��������ֻ����������ʱ�� �������⣬���Ե�������������ˡ� 
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
	//�������ģ�������
		
}
	else{
	if(first->num>first->next->num){
		first->next->next=first;
		first=first->next;
		first->next->next=NULL;
	}
	}
////������ϡ�
	
	

//���
		p=first;
		printf("The new list is:");
		while(p){
			printf("%d ",p->num);
			p=p->next;
		} 
		
		
		
//�������ͷŽڵ㡣
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

