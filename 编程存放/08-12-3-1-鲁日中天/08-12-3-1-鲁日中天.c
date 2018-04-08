#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

#define START 0//开始 
#define p1 1//遍历加判断 
#define p2 2//用于去掉双杠注释。 
#define p3 3//用于去掉有星号注释. 
#define END 4//结束。 
void copyfiledeletezhushi(void);
main()
{
	copyfiledeletezhushi();	
}

//接下来进行函数设计。 
void copyfiledeletezhushi(void)
{
	FILE*in,*out;
	int state=0;
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
	switch(state){
		case START: state=p1;
					break;
				
		case p1:if('/'==ch1){
					ch2=ch1;
					ch1=fgetc(in);
					if('/'==ch1)//双杠注释处理。
					state=p2;
					else if('*'==ch1)//单斜杠加星号情况处理。
					state=p3;
					else
						fputc(ch2,out); 
					} 
					else {
					fputc(ch1,out);//写入目标文件。 
					ch1=fgetc(in);	
					}
				break;
				
		case p2:fseek(in,-2,1);
				fgets(str,sizeof(str),in);//直接用数组储存注释，不输入到文件中。 
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

