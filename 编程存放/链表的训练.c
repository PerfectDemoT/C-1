//���Ĳ���ģ�������⡣
//ɾ��ģ�鵱û����Ѱ������ʱҲ������쳣ֹͣ���� 

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
	printf("������Ҫ�������������(0��Ϊֹͣ��)\n");
	for(;;){
		scanf("%d",&n);
		if(n==0)
		break; 
		first=shengcheng(first,n);
	}//��������
	
	 struct lianbiao*p=NULL;
	for(p=first;p!=NULL;p=p->next){
		printf("%d ",p->value);
	}//�������� 
	
	printf("\n");
	printf("����������ҵ�����\n");
	scanf("%d",&c); 
	for(p=first;p!=NULL;p=p->next){
		if(p->value==c)
		break;
	}
		if (p!=NULL)
		printf("%d\n",p->value);
		else 
		printf("������ֲ�����\n");//������Ѱ��
		
		struct lianbiao* prev=NULL,*now=NULL;
		printf("��������Ҫɾ��������\n");
		scanf("%d",&s);
		for(now=first,prev=NULL;
			now->value!=s&&now!=NULL;
			prev=now,now=now->next)
			;
		if(now==NULL)
		printf("û���ҵ������֣��޶���\n");//û���ҵ�������ʱ�ᵼ�³���ֹͣ�쳣�� 
		else if(prev==NULL)
		{
		printf("�����һ��Ϊ�����֣�ɾ����һ��\n");
		first=first->next;
		free(now);
	}
		else
		{	
			prev->next=now->next;
			printf("�������������м䣬��ɾ��\n\n");
			free(now);
		}//����Ľڵ�������ɾ���� 
			
	
	//��Ϊ������Ƶ�ģ�飬�������е���Ϊ����ʱ�������м���롣
	struct lianbiao* zhongjian;
	prev=NULL,now=NULL;
	int k ;
		printf("��������Ҫ���������\n(��Ϊʵ��ģ�飬��ȷ��֮ǰ��������ʱ�Ѿ���ɴ�С��������)\n");
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
		printf("�����ִ����������֣��Ѳ��뵽���\n");
	//	free(prev); 
	}
		else if(prev==NULL)
		{
		prev=malloc(sizeof(struct lianbiao));
		prev->value=k;
		prev->next=first; 
		printf("������С�����������е����֣��Ѳ��뵽��һ����\n");
		first=prev;
	//	free(now);
	}
		else
		{	
			zhongjian=malloc(sizeof(struct lianbiao));
			zhongjian->value=k;
			prev->next=zhongjian;
			zhongjian->next=now;
			printf("�������������м䣬�Ѳ��롣\n");
		//	free(now);
		}
	//�������ģ�������
	
	//�˴��Բ����ģ����������� 
	struct lianbiao* temp;
	for(p=first;p!=NULL;p=p->next){
		printf("%d ",p->value);
	}//��������************��δ��������ģ���Ƿ�����********* 
 } 
 
 	struct lianbiao* shengcheng(struct lianbiao* list,int n)
 	{
 		struct lianbiao* new;
 		new=malloc(sizeof(struct lianbiao));
 		if (new==NULL){
 			printf("�ڴ����ʧ��\n");
 		}
 		new->next=NULL;
 		new->value=n;
 		new->next=list;
 		return new;
 		
 		
	 }
