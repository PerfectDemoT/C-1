#include<stdio.h>
#include<stdbool.h>

#define A 10
main()
{
int digit=0;
long long n;
bool digit_seen[A]={0};
printf("请输入需要检索的数字\n");
scanf("%lld",&n);
while(n>=0){
	digit=n%10;
	if(digit_seen[digit])
	break;
	digit_seen[digit]=true;
	n/=10;		
}
if(n>0)
printf("重复的数是%d\n",digit);
else
printf("没有重复的数字\n");
return 0;	
}
