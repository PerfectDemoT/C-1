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
		//排序；
		
		
		
		
		
		
		
		
		
		
		
		
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
	//有序插入模块结束。				





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
////排序完毕。
