#include<stdio.h>
main()
{
 int year;
 printf("请输入年份"); 
 scanf("%d",&year);
 if((year%4==0&&year%100!=0)||year%400==0)
 printf("这个年份是闰年\n");
 else
 printf("这个年份不是闰年\n"); 
return 0;	
}

