#include<stdio.h>

main()
{
	int a,b,e,d;  
	int r,c,C;
	printf("请依次输入矩阵的阶次(注意矩阵相乘规则！)\n");
	printf("形式示例：如果为1×2与2×3两矩阵相乘\n则写为 1 2 2 3 ，数字中间用空格隔开。\n");//说明输入格式与规则 
	scanf("%d %d %d %d",&a,&b,&e,&d);//确定其的阶次如：1*2与2*3 
	if(b==e)//判断其是否符合矩阵相乘条件 
	   {
	int A[a][b],B[b][d];
	int M[100][100]={0};
	printf("请输入该矩阵\n");
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
	printf("\t其结果是\n"); 
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
	  printf("对不起，您输入的矩阵不符合相乘条件，请检查后再重新输入。\n");
	system("pause");
	return 0; 
}
