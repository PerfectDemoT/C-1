#include<stdio.h>
int isPrime(int n);
void printFactor(int n);
main ()
{
	int n,m,k;
	printf("请输入两个整数，先小后大，中间用空格各开。\n");
	scanf("%d %d",&n,&m);
	for(k=n;k<=m;k++){
	if(isPrime(k)==1){
		printf("%d=%d",k,k);
	}
	else{
		printFactor(k);
	}
	printf("\n");
}
}
int isPrime(int n)
{
	int i;
	for(i=2;i<=(n/2);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
void printFactor(int n)
{
	int yi=0,i,j,fenshen;
	fenshen=n;
	for(;fenshen>0;fenshen=fenshen/i){
	for(i=2;i<=fenshen;i++){
		if(isPrime(i)==1&&yi==0&&fenshen%i==0){
			printf("%d=%d",n,i);
			yi=1;
			break;
		}
		else if(isPrime(i)==1&&fenshen%i==0){
			printf("*%d",i);
			break;
		}
	}
}
}
