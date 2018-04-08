#include<stdio.h>
int caixiang(int z);
int sushu(int m);
main()
{
	int n,yihao,erhao;
	printf("请输入一个数\n");
	scanf("%d",&n);
	if(sushu(n)==1)
	printf("%d=1*%d\n",n,n);
	else{
	yihao=caixiang(n);
	erhao=n/yihao;
	printf("%d=%d*%d\n",n,yihao,erhao);
}
 } 
 int sushu(int m)
 {
 	int x,yushu,l=0;
 	for(x=2;x<m;x++){
 	yushu=m%x;
 	if(yushu==0)
 	l=1;
 	}
 	return(l!=1);
 }
 int caixiang(int z)
 {
 	int x,yushu,l=0,yihao,erhao;
 	for(x=2;x<z;x++){
 	yushu=z%x;
 	if(yushu==0){
 		yihao=x;
 	    if(sushu(yihao)==1)
 	erhao=z/yihao;
	 if(sushu(erhao)==1&&sushu(yihao)==1)
	 {
	 	l=1;
	 	break;
		 }	
	 }
}
	if(l==1) 
 	 return yihao;
}
