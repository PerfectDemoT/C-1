#include<stdio.h>
void move(int n,char a,char b,char c);
main()
{
	int n;
	scanf("%d",&n);
	move(n,'a','b','c');
 } 
 void move(int n,char a,char b,char c)
 {
 	if(n==1){
 		printf("%d:%c->%c\n",n,a,c); 
	 }
	 else{
	 	move(n-1,a,c,b);
		 printf("%d:%c->%c\n",n,a,c);
		 move(n-1,b,a,c);
	 }
 }
