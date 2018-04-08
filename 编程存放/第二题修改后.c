#include<stdio.h>
#include<math.h>
main()
{
	int a,b,c,d=0,i,j,k=0,l=0,p=0,s=1;
	scanf("%d %d %d",&a,&b,&c);
	for(i=a;i<=b;i++){
		k=0;
		for(j=1;j<i;j++){
			if(i%j==0)
			k+=j;
	
		}
		if(fabs(i-k)<=c&&(s==1)){
		printf("%d",i);
		s++;
		l=1;
		p=1;
		d+=1;
		}
		else if(fabs(i-k)<=c&&(s>1)){
		printf("\t%d",i);
		
		l=1;
		p=1;
		d+=1;
		}
		
	if(d==5){
	printf("\n");
	d=0;
	s=1;
}
	} 
	if(l==0)
	printf("There is no proper number in the interval.\n");
	if(p==1)
	printf("\n");

    return 0;
 } 
 
 
