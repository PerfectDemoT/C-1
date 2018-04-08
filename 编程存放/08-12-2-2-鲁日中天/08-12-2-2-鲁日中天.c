#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
void copyfiledeletezhushi(void);
main()
{
	copyfiledeletezhushi();	
}

//接下来进行函数设计。 
void copyfiledeletezhushi(void)
{
	FILE*in,*out;
	char ch1,ch2,ch_temp,str[10000];
//打开输出文件。 
		if((in=fopen("p12in.c","r"))==NULL){
		printf("Can't open the file\n");
		exit(0);
	}

//打开输入文件。 
		if((out=fopen("p12out.c","w"))==NULL){
		printf("Can't open the file\n");
		exit(0);
	}
	ch1=fgetc(in);
	while(!feof(in)){//一个个字符读入提取。 
		if('/'==ch1){
			ch2=ch1;
			ch1=fgetc(in);
			if('/'==ch1)//双杠注释处理。 
			{
				fseek(in,-2,1);
				fgets(str,sizeof(str),in);//直接用数组储存注释，不输入到文件中。 
				ch1=fgetc(in);

				
			}
			else if('*'==ch1)//单斜杠加星号情况处理。 
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
			fputc(ch1,out);//写入目标文件。 
			ch1=fgetc(in);
		}
	}
	
	fclose(in);
	fclose(out);
}
