//
//
//**p�൱��*(*p)��˼��**pָ��Ķ����ĵ�ַ������*p��ʾ 
//int **p��pָ����һ����ַ��p�ŵ���*p�ĵ�ַ�� *pָ���Ǵ��int �ĵ�ַ
// 
#include<string.h>
#include<stdio.h>
main()
{
	
	
	int a[5]={2, 4, 6, 8, 9};
    int * num[5]={&a[0],&a[1],&a[2],&a[3],&a[4]};
    int * * ptr, m;/*p��ָ��ָ���ָ��*/
    ptr=num;
    for(m=0;m<5;m++){
          printf("%d\t",**ptr);
          ptr ++;
     }
     printf("\n");
     
         ptr=num;
     for(m=0;m<5;m++){
          printf("%d\t",*ptr);
          ptr ++;
     }
     printf("\n");
     
     for(m=0;m<5;m++){
          printf("%d\t",num[m]);
     }    
     printf("\n");
     
     for(m=0;m<5;m++){
          printf("%d\t",*num[m]);
     }

	
	
	
	
	
	
	
	
	
	
	
	int i,j=0,len=0;
	char sentence[100000],**wpter,*word[10000],*spter;
	gets(sentence);
	spter=sentence;
	wpter=word;
	
	while(*spter!='\0'){
		word[j]=spter;//Ҳ������*wter= spter; 
		//�Ͼ�*wter����word�е�ֵ 
		while(*spter!=' '&&*spter!='\0'){
			spter++;
		}
		*spter='\0';
		spter++;
		len++;
		wpter++;
		j++;
		
	}
	for(i=0;i<len;i++)
	puts(word[i]);
}
