#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
	
	struct student{
		int num;
		char name[100];
		char sex[100];
		int age;
		double score[3];
		double save;
		double ave;
		};
	
	typedef struct node{
		struct student data;
		struct node*next;
	}Node,*link; 

int menu_select()
{
	int i;
	printf("\n\n\t********************STUDENT LIST********************");
	printf("\t*                   1.intput record                    *\n");
	printf("\t*                   2.delete record                    *\n");
	printf("\t*                   3.list record                    *\n");
	printf("\t*                   4.search record                    *\n");
	printf("\t*                   5.save record                    *\n");			
	printf("\t*                   6.load record                    *\n");
	printf("\t*                   7.quit                    *\n");
	printf("\n\n\t****************************************************\n");


	do
	{
		printf("Enter you choice\n");
		scanf("%d",&i);
		
	}while(i<=0||i>7);
	
	return i;

}
	
	void input(link l)
	{
		int i;
		Node *p,*q;
		while(1)
		{
			p=(Node*)malloc(sizeof(Node));
			if(!p)
			{
				printf("ÄÚ´æ·ÖÅäÊ§°Ü¡£\n");
				return;
			}
			printf(" input number\n");
			scanf("%d",&p->data.num);
			if(p->data.num==0)
				break;
			for(q=l;q->next!=NULL;q=q->next)
			if(q=l)
		}
	 } 
	
main()
{
		link l;
		l=malloc(sizeof(Node));
		if(!l)
		{
			printf("\n ÄÚ´æ·ÖÅäÊ§°Ü\n");
			
		}
		l->next=NULL;
		while(1)
		{
			system("cls");
			switch(men-select())
			{
				csae 1:
					intput(l);
					break;
				case 2:
					del(l);
					break;
			
				case 3:
					list(l);
					break;
				case 4:
					search(l);
					break;
				case 5:
					save(l);
					break;
				case 6:
					load(l);
					break;
				default:
					exit(0);
					break;
						
			} 
		}
}
	
	
