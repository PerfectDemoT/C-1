struct lianbiao *q,*tail;
		p=first;
		q=p->next;
		tail=NULL;
		if((q->num)<=(p->num)){
			p->next=p->next->next;
			q->next=p;
			tail=q;
			q=p->next;
		}
		p=first;
		while(p!=NULL){
		printf("%d ",p->num);
		p=p->next;		
	}
		//����
		
		
		
		
		
		
		
		
		
		
		
		
		p=first;
		if(p->num>p->next->num){
					temp=p->next;
					p->next=p->next->next;
					temp->next=p;
				first=temp;
				}
				
				
				
				
				
				
struct lianbiao* zhongjian,*prev,*now;
	prev=NULL,now=NULL;
		for(now=first,prev=NULL;
			now->num<m&&now!=NULL;
			prev=now,now=now->next)
			;
		if(now==NULL){
		now=malloc(sizeof(struct lianbiao));
		now->num=m;
		free(prev); 
	}
		else if(prev==NULL)
		{
		prev=malloc(sizeof(struct lianbiao));
		prev->num=m;
		prev->next=first; 
		first=prev;
		free(now);
	}
		else
		{	
			zhongjian=malloc(sizeof(struct lianbiao));
			zhongjian->value=m;
			prev->next=zhongjian;
			zhongjian->next=now;
			free(now);
		}
	//�������ģ�������				





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
		int m;
		now=first;
		first=first->next;
		now->next=NULL;
		 m=now->num;
		 pre=first;
		 while(pre){
		 	if(pre->num>=m&&zhiqian!=NULL&&zhiqian<=m){
				now->next=pre;
				zhiqian->next=now;
			 	break;
			 }
			 else if(pre->num>=m&&zhiqian==NULL){
			 	now->next=first;
			 	first=now;
			 	break;
			 }
			 zhiqian=pre;
			 pre=pre->next;
			 
		 }
		 if(pre==NULL){
		 	pre->next=now;
		 	now->next=NULL;
		 }
}
	else{
	if(first->num>first->next->num){
		first->next->next=first;
		first=first->next;
		first->next->next=NULL;
	}
	}
////������ϡ�
