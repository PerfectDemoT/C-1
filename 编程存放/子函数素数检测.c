#include<stdio.h>
int sushu(int m);
main()
{
	int n;
	scanf("%d",&n);
	if(sushu(n)==1)
	printf("������������\n");
	else
	printf("�����ֲ�������\n");
	return 0;
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
