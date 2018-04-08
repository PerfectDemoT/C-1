#include<stdio.h>
#include<math.h>
int taile(int x);
main()
{
	int x;
	scanf("%d",&x);
	printf("%lf",taile(x));
 }
 int taile(int x) 
 {
 	int i;
 	double p,sum;
 	p=x;
 	while(fabs(p)>=(1e-6)){
 		sum=sum+p;
 		p=-p*x*x/((2*i-2)*(2*i-1));
 		i++;
	 }
	 return sum;
 }
