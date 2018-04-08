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
	getchar();
	scanf("%d",&p);
	for(i=p-1;i<10;i++){
		shuzu[i]=shuzu[i+1];
	}
	for(i=0;i<9;i++){
		printf("%d  ",shuzu[i]);
	}
}
