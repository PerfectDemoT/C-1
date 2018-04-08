#include<stdio.h>
main ()
{
	int i,num1=0,num2;
	printf("请输入要分解的素数\n");
	scanf("%d",&num2);
	printf("%d=",num2);
	for(i=2;i<=num2;i++)
	{
		if(num2%i==0){
		num2=num2/i;
	printf("%d*",i);
		num1++;
		}
	}
	printf("\b \b");
	printf("\n");
	printf("%d",num1);
}
