#include<stdio.h>
void chongfu(int n,int a[n][n]);
main()
{
	int n;
	printf("please input the n\n");//这里只能用于求奇数阶数的魔方阵 
	scanf("%d",&n);
	int a[100][100]={0},i,j,d;
	if(n%2==0)
	n++;
	a[0][(n)/2]=1;
	chongfu(n,a);
 } 
 void chongfu(int n,int a[n][n])//用了求奇数阶层的魔方阵的特殊算法 
 {
 	int i,j,k,jishu=n*n;
 	i=0;
 	j=(n)/2;
 	for(k=2;k<=jishu;k++){
 		i-=1;
 		j+=1;
	if(i<0&&j==n){ 
	i+=2;
	j-=1;
	} 
	else{
		if(i<0)
		i=n-1;
		if(j>(n-1))
		j=0;
	}
		if(a[i][j]!=0){
		i+=2;
		j-=1;
		a[i][j]=k;	
		}
		else
		a[i][j]=k;
	
}
	for(i=0;i<n;i++){
	for(j=0;j<n;j++)
	printf("%d\t",a[i][j]);
	printf("\n");
}
 }
