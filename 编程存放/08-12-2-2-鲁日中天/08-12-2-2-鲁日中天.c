#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
void copyfiledeletezhushi(void);
main()
{
	copyfiledeletezhushi();	
}

//���������к�����ơ� 
void copyfiledeletezhushi(void)
{
	FILE*in,*out;
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
		if('/'==ch1){
			ch2=ch1;
			ch1=fgetc(in);
			if('/'==ch1)//˫��ע�ʹ��� 
			{
				fseek(in,-2,1);
				fgets(str,sizeof(str),in);//ֱ�������鴢��ע�ͣ������뵽�ļ��С� 
				ch1=fgetc(in);

				
			}
			else if('*'==ch1)//��б�ܼ��Ǻ�������� 
			{
				ch1=fgetc(in);
				while(ch1!='*'&&!feof(in))
				{
					ch1=fgetc(in);
					if(ch1=='*'){
						ch1=fgetc(in);
						if(ch1=='/'){
						ch1=fgetc(in);
						ch2=ch1;
						break;
						
					}
				}
			}
		}
			else
			{
				fputc(ch2,out);
			}
		}
		else
		{
			fputc(ch1,out);//д��Ŀ���ļ��� 
			ch1=fgetc(in);
		}
	}
	
	fclose(in);
	fclose(out);
}
