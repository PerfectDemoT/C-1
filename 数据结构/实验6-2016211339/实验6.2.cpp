#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std ;

class Array{
	public:
		int array[10000] ;
		int n ; //存储数字的个数 
		
		struct stack{
			int S[1000] ;
			int top; //用来表示栈顶指针 
		}; 
		
		struct stack SS; //定义一个栈
		
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
		
		Array(){ //构造函数 
			SS.top = 0 ;
			
			cout<<"请输入你需要输入的数字个数"<<endl ;
			cin>>n ;
			
			for(int i = 0 ; i < n ; i++){
				cin>>array[i] ;
			}
		}
		
		
		void swap(int head ,int last){ //交换函数 
			int temp =  array[head] ;  //设置中间暂存变量 
			array[head] = array[last] ;
			array[last] = temp ;
		}  
		
		void sort(int head , int last){
			if(last - head == 1){ //子序列只含有两个元素
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
		
		int GetPartion(int head , int last){ //快排时交换表中记录，使枢轴记录到位 
		
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
		
		void Qsort(){ //快排函数 
			int head = 0 , last = n-1 ;
			while(head<last){
				if(last - head > 2){ //当前子序列长度大于3且未排好序
					int partion = GetPartion(head , last) ;
					if(last-partion > partion-head){
						push(&SS , partion+1 , last) ; //长的序列入栈 
						last = partion - 1 ; //短的留下 
					} 
					else{
						push(&SS , head , partion-1) ;
						head = partion + 1 ; 
					}
				}
				else if(head < last && last - head < 3){ //当前子序列长度小于3且未排序
					sort(head , last) ; //进行比较排序
					head = last ; //表示序列已经排好序 
				}
				else{ //将剩下没排好序的子列出栈
					pop(&SS , &head , &last) ; //将head 以及last从栈中取出 
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
