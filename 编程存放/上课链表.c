#include<stdio.h>
#include<stdlib.h>
struct lianbiao{
	int num;
	struct lianbiao* next;
};
main ()
{
	int n;
	struct lianbiao *p=NULL,*first=NULL;
	printf("please input the number\n");
	for(;;){
	scanf("%d",&n);
	if(n!=0){
		first=malloc(sizeof(struct lianbiao));
		if(first==NULL){
			printf("�ڴ����ʧ��\n");
		}
		else{
		first->num=n;
		first->next=p;
		p=first;
	}
	}
	else 
	break;
	
}//��������	
	printf("The list has done.\n");
	
	struct lianbiao *last=NULL;
	last=first;
	while(last->next){
		last=last->next;
	}
	last->next=first;
	//������Χ��Ȧ�� 
	
	
	
	
	
	int i;
	struct lianbiao *q,*pre,*f=NULL;
	q=last;
	pre=NULL;
	for(i=1;;i++){
		if(i%4==0){
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
		if(q==q->next)
		break;
	}
	
	
	
	
	
	

	
	printf("%d ",p->num);
	
	//jianyan=first;
	//while(jianyan->next){
	//	printf("%d ",jianyan->num);
	//	jianyan=jianyan->next;
	//}//���������顣 
		
		
		
 } 
