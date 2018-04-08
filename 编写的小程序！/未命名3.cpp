/* 计算最小的钞票组合进行付款 */ 
#include<stdio.h>
int main()
{
   int pay_count,bill100,bill50,bill20,bill10,bill5,bill1,q,w,e,r,t;
   printf("please putin the pay_count\n");
   scanf("%d",&pay_count);
   bill100=pay_count/100;
   r=pay_count-bill100*100;
   bill50=r/50;
   t=r-bill50*50;
   bill20=t/20;
   q=t-bill20*20;
   bill10=q/10;
   w=q-bill10*10;
   bill5=w/5;
   e=w-bill5*5;
   bill1=e/1;
   printf("%d,%d,%d,%d,%d,%d\n",bill100,bill50,bill20,bill10,bill5,bill1);
   return 0;
}
