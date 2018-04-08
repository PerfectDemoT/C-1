#include<stdio.h>
main()
{
	int i,sum=0,temp=0,n,t;
	char dir[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %s",&t,dir);
	
	if(sum==0&&dir[0]!='S')
	temp=1;
	if(sum==20000&&dir[0]!='N')
	temp=1;
	if(dir[0]=='S'){
		sum+=t;
		if(sum>20000)
		temp=1;
	}
	else if(dir[0]=='N'){
		sum-=t;
		if(sum<0)
		temp=1;
	}
	
	}
	
	if(temp==0&&sum==0)
	printf("YES\n");
	else
	printf("NO");
}
  
