#include<stdio.h>
main()
{
	int i,j,a,b,c,d=10,e=0,f,g,h;
	scanf("%d",&a);
	c=a;
      for(b=1;c>0;b++){
	c=c/d;
      }
      for(j=0;j<(b-3);j++){
	  d*=10;
	  }
	  g=a;
      for(i=0;i<b;i++){
	  f=g%10;
	  e=e+f*d;
	  d/=10;
	  g=g/10;  
	   }
	   printf("%d\n",e);
	   if(e==a)
	   printf("ÊÇ\n");
	   else
	   printf("²»ÊÇ\n");
	   return 0; 
}
