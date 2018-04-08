#include<stdio.h>
#include<string.h>
main()
{
	char a[100][100],b[100];
	int i,j,n,zhishi=0;
	printf("请输入已有姓名个数: ");
	scanf("%d",&n); 
	printf("\n请设定已有姓名\n"); 
	for(i=0;i<=n;i++){
	gets(a[i]);
	}
	printf("\n请设定要检测的姓名\n");
	gets(b);
	for(i=0;i<=n;i++){
		if(strcmp(a[i],b)==0){
			printf("\n有重复,");
			zhishi=1;
			break;
		}
	}
	if(zhishi==0)
	printf("\n用户名可用\n");
	else
	printf("用户名已被使用\n");
	system("pause"); 
 } 
