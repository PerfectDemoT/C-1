#include<stdio.h>
main()
{
	int f=0,i=0,j,x;
    for(x=1;f==0;x++)
    { 
	i=5*x+1;
	if(i%4==0)
	{
			f=1;
	for(j=0;j<4;j++)
	{
		i=5*(i/4)+1;
	}
	} 
    }
	printf("%d\n",i);
	return 0;
}
