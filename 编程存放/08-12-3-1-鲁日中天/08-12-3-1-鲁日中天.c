#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

#define START 0//��ʼ 
#define p1 1//�������ж� 
#define p2 2//����ȥ��˫��ע�͡� 
#define p3 3//����ȥ�����Ǻ�ע��. 
#define END 4//������ 
void copyfiledeletezhushi(void);
main()
{
	copyfiledeletezhushi();	
}

//���������к�����ơ� 
void copyfiledeletezhushi(void)
{
	FILE*in,*out;
	int state=0;
	char ch1,ch2,ch_temp,str[10000];
//������ļ��� 
		if((in=fopen("p12in.c","r"))==NULL){
		printf("Can't open the file\n");
		exit(0);
	}

//�������ļ��� 
		if((out=fopen("p12out.c","w"))==NULL){
		printf("Can't open the file\n");
		exit(0);
	}
	ch1=fgetc(in);
	while(!feof(in)){//һ�����ַ�������ȡ�� 
	switch(state){
		case START: state=p1;
					break;
				
		case p1:if('/'==ch1){
					ch2=ch1;
					ch1=fgetc(in);
					if('/'==ch1)//˫��ע�ʹ���
					state=p2;
					else if('*'==ch1)//��б�ܼ��Ǻ��������
					state=p3;
					else
						fputc(ch2,out); 
					} 
					else {
					fputc(ch1,out);//д��Ŀ���ļ��� 
					ch1=fgetc(in);	
					}
				break;
				
		case p2:fseek(in,-2,1);
				fgets(str,sizeof(str),in);//ֱ�������鴢��ע�ͣ������뵽�ļ��С� 
				ch1=fgetc(in);
				state=p1;
				break;
				
		case p3:ch1=fgetc(in);
				while(ch1!='*'&&!feof(in))
				{
					ch1=fgetc(in);
					if(ch1=='*'){
						ch1=fgetc(in);
						if(ch1=='/'){
						ch1=fgetc(in);
						ch2=ch1;
						state=p1;
						break;
						
					}
				}
			}
			break;		
		
	}
	}
	state=END;
	
	fclose(in);
	fclose(out);
}

