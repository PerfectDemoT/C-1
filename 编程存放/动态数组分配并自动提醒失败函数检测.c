//�����Ǳ����C�������ϵ���ϰ��
//323ҳ��
//�������䶯̬����ĺ��������ڴ����ʧ��ʱ�����Զ��������� 

#include<stdio.h>
#include<stdlib.h>
int* mg_malloc(int n);//����
main ()
{
	int n;
	int* p;
	printf("������n��ֵ��\n");//����Ҫ����Ĵ洢�ռ���Ŀ�� 
	scanf("%d",&n);
	p=mg_malloc(n);//pָ�����������ɹ�ʱ���ص�ָ�롣 
	int i;
	//��������������ռ��Ƿ�����������(��Ϊ����ɹ�û��ʲô��ʾ��) 
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	for(i=0;i<n;i++){
		printf("%d",p[i]);
	} 
}

int* mg_malloc(int n)//���Ǻ����� 
{
	int* p=NULL;
	p=malloc(n*sizeof(int));
	if(p==NULL){
	printf("�ڴ����ʧ��\n");
	exit(0);//ʧ��ʱ�������� 
}
	else
	return p;
}



