#include<stdio.h>
#include<stdbool.h>

#define A 10
main()
{
int digit=0;
long long n;
bool digit_seen[A]={0};
printf("��������Ҫ����������\n");
scanf("%lld",&n);
while(n>=0){
	digit=n%10;
	if(digit_seen[digit])
	break;
	digit_seen[digit]=true;
	n/=10;		
}
if(n>0)
printf("�ظ�������%d\n",digit);
else
printf("û���ظ�������\n");
return 0;	
}
