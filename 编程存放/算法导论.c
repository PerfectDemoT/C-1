//�������������Ը��� 
#include<string.h>
#include<stdio.h>
main ()
{
	char a[1000];//�ַ��ͣ����Բ���֪�������е�Ԫ�ظ�������ֱ�����롣 
	int i,j,len,jishu=0;
	gets(a);//��������� �� 
	len=strlen(a);//��ͷ�ļ��а�����strlen����ȷ�������鳤�ȡ� 
	for(i=0;i<len;i+=2){
		for(j=i+2;j<len;j+=2){
			if(a[i]>a[j])
			jishu++;
		}
	}//�����пո�ҲΪһ���ַ�������Ϊ+2�� 
	printf("%d",jishu);	
}
