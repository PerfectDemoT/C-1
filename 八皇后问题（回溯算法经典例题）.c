#include<stdio.h>
#define queens 8
main ()
{
	int i,k,flag,not_finish=1,count=0;
	int a[queens+1];//�ʺ�����λ�ô�1��ʼ �������±�i��ʾ�����ϵĵ�i�У�ֵ��ʾ��i�лʺ��λ�� 
	//���ڴ����Ԫ���±꣬��ʾǰi-1��Ԫ���Ѿ�����Ҫ�����ڴ����i��Ԫ�ء�
	i=1;
	a[1]=1;//Ϊ����ĵ�һ��Ԫ�ظ�ֵ
	printf("���ܵ�����������£�\n");
	while(not_finish){
		while(not_finish&&i<=queens){//������δ�����һ�û����queens��Ԫ��
			for(flag=1,k=1;flag&&k<i;k++)//�ж��Ƿ��ж���ʺ���ͬһ�� 
				if(a[k]==a[i])
					flag=0; 
					
			for(k=1;flag&&k<i;k++)//�ж��Ƿ��ж���ʺ��ڶԽ����� 
				if(a[i]==a[k]-(k-i)||a[i]==a[k]+(k-i))
					flag=0;
				
			if(!flag){//������ì�ܣ�������Ҫ������Ҫ�������õ�i��Ԫ�� 
				if(a[i]==a[i-1]){//��a[i]��ֵ�Ѿ���һȦ׷��a[i-1]��ֵ
				 	i--;
					
					if(i>1&&a[i]==queens)
						a[i]=1;//��a[i]Ϊqueensʱ��a[i]��ֵ��һ 
						else if(i==1&&a[i]==queens)
							not_finish=0;//����һ��ֵ�ﵽqueensʱ���� 
					else
						a[i]++;//��a[i]��ֵȡ��һ��ֵ 
					} else if(a[i]==queens)
						a[i]=1;
					else
						a[i]++;//��a[i]��ֵȡ��һ��ֵ 
				} else if(++i<=queens)
					if(a[i-1]==queens)
						a[i]=1;
					else
						a[i]=a[i-1]+1;//����Ԫ�ص�ֵΪǰһ��Ԫ�ص���һ��ֵ 
			}
			
			
			if(not_finish){
				++count;
				printf((count-1)%3?"\t[%2d]:":"\n[%2d]:",count);
				
				for(k=1;k<=queens;k++)
				printf("%d    ",a[k]);//������ 
				
				if(a[queens-1]<queens)
					a[queens-1]++;//�޸ĵ����ڶ�λ��ֵ
				else
					a[queens-1]=1;
					
				i=queens-1; 
			}
		}
	} 
