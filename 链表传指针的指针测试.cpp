#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<vector>

using namespace std;

struct node{
	int data ;
	struct node* next= NULL ;
};

int insertList(node **header , node **last); //���뺯�� ,��ָ���ָ�� 
void printList(node *header) ; 




main(){
	struct node *header=NULL , *last=NULL ;
	header=(struct node*)malloc(sizeof(struct node)) ;
	last = header ;
	
	while(insertList(&header , &last)){ //��ָ���ָ�� 
	}
	printList(header) ;
}
	 
	 


int insertList(node **header , node **last){
	
	struct node* ptr ;
	int data ;
	
	printf("�������λ�õ�ϵ��\n") ;
	
	cin>>data ;
	
	if(data!=0){
		ptr=(struct node*)malloc(sizeof(struct node)) ;
		ptr->data=data ;
		ptr->next = NULL ;
		(*last)->next = ptr ;
		(*last) = ptr ;	
		return 1 ;
	}
	else{
		return 0 ;
	}
}
  
void printList(node *header){
	struct node *ptr ;
	ptr = header->next ;
	
	while(ptr){
		cout<<ptr->data<<endl ;
		ptr = ptr->next ;
	}

}


