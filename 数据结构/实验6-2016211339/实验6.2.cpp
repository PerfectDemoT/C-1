#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std ;

class Array{
	public:
		int array[10000] ;
		int n ; //�洢���ֵĸ��� 
		
		struct stack{
			int S[1000] ;
			int top; //������ʾջ��ָ�� 
		}; 
		
		struct stack SS; //����һ��ջ
		
		void push(struct stack *SS , int head , int last){
			SS->S[SS->top] = head ;
			SS->top++ ;
			
			SS->S[SS->top] = last ;
			SS->top++ ;
			
		} 
		
		void pop(struct stack *SS , int *head , int *last){
			SS->top-- ;
			*last = SS->S[SS->top] ; 
			
			SS->top-- ;
			*head = SS->S[SS->top] ;
			
			
		}
		
		Array(){ //���캯�� 
			SS.top = 0 ;
			
			cout<<"����������Ҫ��������ָ���"<<endl ;
			cin>>n ;
			
			for(int i = 0 ; i < n ; i++){
				cin>>array[i] ;
			}
		}
		
		
		void swap(int head ,int last){ //�������� 
			int temp =  array[head] ;  //�����м��ݴ���� 
			array[head] = array[last] ;
			array[last] = temp ;
		}  
		
		void sort(int head , int last){
			if(last - head == 1){ //������ֻ��������Ԫ��
				if(array[head] > array[last])
					swap(head , last) ;
			}
			else{
				if(array[head] > array[head+1])
					swap(head , head+1) ;
				if(array[head+1] > array[last])
					swap(head+1 , last) ;
				if(array[head] > array[head+1])
					swap(head , head+1) ;
			}
		}
		
		int GetPartion(int head , int last){ //����ʱ�������м�¼��ʹ�����¼��λ 
		
			int key = array[head] ;
			while(head < last){
				while(head < last && array[last] >= key){
					last-- ;
				}
				swap(head , last) ;
				
				while(head < last && array[head] <= key){
					head++ ;
				}
				swap(head , last) ;
			}
		
			 return head ;
		}
		
		void Qsort(){ //���ź��� 
			int head = 0 , last = n-1 ;
			while(head<last){
				if(last - head > 2){ //��ǰ�����г��ȴ���3��δ�ź���
					int partion = GetPartion(head , last) ;
					if(last-partion > partion-head){
						push(&SS , partion+1 , last) ; //����������ջ 
						last = partion - 1 ; //�̵����� 
					} 
					else{
						push(&SS , head , partion-1) ;
						head = partion + 1 ; 
					}
				}
				else if(head < last && last - head < 3){ //��ǰ�����г���С��3��δ����
					sort(head , last) ; //���бȽ�����
					head = last ; //��ʾ�����Ѿ��ź��� 
				}
				else{ //��ʣ��û�ź�������г�ջ
					pop(&SS , &head , &last) ; //��head �Լ�last��ջ��ȡ�� 
				}
			}
			
			Qsort2(0 , n-1) ;
		}
		
		void Qsort2(int head , int last){
			
			if(head < last)
			{
				int partion = GetPartion(head , last);
					Qsort2(head , partion-1);
					Qsort2(partion+1 , last);
		
			}
		}
		
		void output(){
			for(int i = 0 ; i < n ; i++){
				cout<<array[i]<<"\t" ;
			}
				
		}
	
}; 


main(){
	Array test ;
	test.Qsort() ;
	test.output() ;
} 
