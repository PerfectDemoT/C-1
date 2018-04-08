#include<stdio.h>
int main (void)
{
	int i,j,x;
	scanf("%d",&x);
	i=5*x+1;
	for(j=0;j<4;j++)
	{
		if(i%4==0)
		i=5*(i/4)+1;
	}
	printf("%d",i);
	return 0;
}
