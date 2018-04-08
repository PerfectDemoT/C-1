#include<stdio.h>
int i=0;
int weishu(int n);
main()
{
	int n;
	scanf("%d",&n);
	printf("%d",weishu(n));
	return 0; 
 } 
 int weishu(int n)
 {
 	i=i+1;
 	if(n/10>0)
 	return weishu(n/10);
 	else
 	return i;
 }
