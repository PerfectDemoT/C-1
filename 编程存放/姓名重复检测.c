#include<stdio.h>
#include<string.h>
main()
{
	char a[100][100],b[100];
	int i,j,n,zhishi=0;
	printf("������������������: ");
	scanf("%d",&n); 
	printf("\n���趨��������\n"); 
	for(i=0;i<=n;i++){
	gets(a[i]);
	}
	printf("\n���趨Ҫ��������\n");
	gets(b);
	for(i=0;i<=n;i++){
		if(strcmp(a[i],b)==0){
			printf("\n���ظ�,");
			zhishi=1;
			break;
		}
	}
	if(zhishi==0)
	printf("\n�û�������\n");
	else
	printf("�û����ѱ�ʹ��\n");
	system("pause"); 
 } 
