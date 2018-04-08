#include<stdio.h>
main()
{
	int num,x,m,length=0,p,d=1,i;
	scanf("%d",&num);
	x=num;
	m=num;
	while(x>0){
		x=x/10;
		length++;
	}
	i=1;
	for(i=1;i<=length;i++){
		d*=10;
	}
	while(m>0){
		p=m/(d/10);
		d=d/10;
		m=m%(p*d);
		printf("%d,",p);
	}
	
 } 
 
 
 