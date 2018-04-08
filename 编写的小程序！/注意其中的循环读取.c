#include<stdio.h>
main ()
{
	int i;
	while(scanf("%d",&i)&&i!=-1)
	{
		if(i%3==0)
		printf("%d ",i);
	}
	printf("-1\n");
	return 0;
} 
