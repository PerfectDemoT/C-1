#include<stdio.h>

main()
{
	int a,b,e,d;  
	int r,c,C;
	printf("�������������Ľ״�(ע�������˹���)\n");
	printf("��ʽʾ�������Ϊ1��2��2��3���������\n��дΪ 1 2 2 3 �������м��ÿո������\n");//˵�������ʽ����� 
	scanf("%d %d %d %d",&a,&b,&e,&d);//ȷ����Ľ״��磺1*2��2*3 
	if(b==e)//�ж����Ƿ���Ͼ���������� 
	   {
	int A[a][b],B[b][d];
	int M[100][100]={0};
	printf("������þ���\n");
	for(r=0;r<a;r++)
	{
	for(c=0;c<b;c++)
	{
	scanf("%d",&A[r][c]);
	}
	}
	printf("\n");
	for(c=0;c<b;c++)
	{
	for(C=0;C<d;C++)
	{
	scanf("%d",&B[c][C]);
	}
	}
	for(r=0;r<a;r++)
	{
	for(C=0;C<d;C++)
	 {
	for(c=0;c<b;++c)
    M[r][C]+=A[r][c]*B[c][C];
	 }
	}
	printf("\n\n");
	printf("\t������\n"); 
	for(r=0;r<a;r++)
	{
		for(C=0;C<d;C++){
	printf("%5d",M[r][C]);
	printf(" ");
	}
	printf("\n");
	}
	  }
	  else
	  printf("�Բ���������ľ��󲻷��������������������������롣\n");
	system("pause");
	return 0; 
}
