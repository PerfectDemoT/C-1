#include<stdio.h>
main(void)
{
int a[10],b[10],c[10]={0},i,j;
 for(i=0;i<10;i++)
  a[i]=i;    printf("\n");
for(i=0;i<10;i++)
 printf("%4d",a[i]);
 for(j=0;j<10;j++)
  b[j]=j;
 for(j=0;j<10;j++)
 printf("%4d",b[j]);printf("\n");
 for(i=0;i<10;i++)
 c[i]=a[i]+b[i];
 for(i=0;i<10;i++)
 printf("%4d",c[i]);
 return 0; 
}
