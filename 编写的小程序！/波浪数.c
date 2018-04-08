#include<stdio.h>
int isWaveNum(int num);
main()
{
	int n;
	scanf("%d",&n);
	if(isWaveNum(n)==1)
		printf("YES\n");
		else
		printf("NO\n");
	
 }
 int isWaveNum(int num)
 {
 	int d=10,geshu=0,jishu,oushu,jishuzancun,oushuzancun,zhizhen=0;
 	if(0<=num&&100>num)
 	return 1;
 	else{
 	while(num>0){
	 geshu++;
	 if(geshu==1){
	 	jishu=num%10;
	 }
	 if(geshu==2){
	 	oushu=num%10;
	 }
	 if(geshu%2==1){
	 	jishuzancun=jishu;
	 	jishu=num%10;
	 }
	 else{
	 	oushuzancun=oushu;
	 	oushu=num%10;
	 }
	  num/=10;
	  if((jishu!=oushu)&&(oushu==oushuzancun)&&(jishu==jishuzancun)){
	  	zhizhen=1;
	  }
	  else{ 
	  return 0;
	  break;
}
}
}
	  if(zhizhen=1)
	  return 1;	
	 
  } 
