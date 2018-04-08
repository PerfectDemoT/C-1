#include<stdio.h>
main()
{
	int i,shuzu[10]={0},j,p;
	for(i=0;i<10;i++){
		scanf("%d",&shuzu[i]);
	}
	for(i=0;i<10;i++){
		printf("%d  ",shuzu[i]);
	}
	scanf("%d",&p);
	for(j=8;j>p;j--){
		shuzu[j+1]=shuzu[j];
		if(j==p){
			shuzu[j]=p;
		}
	}
		for(i=0;i<10;i++){
		printf("%d  ",shuzu[i]);
	}
	
}
