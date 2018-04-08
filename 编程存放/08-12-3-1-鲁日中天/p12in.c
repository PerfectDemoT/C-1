#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct list{
	int num;
	struct list *next;
};

main()
{
	//文件处理函数包括  fopen或者fclose("路径","指令").
	//这和之前的python中的差不多，最后需要关闭文件路径，方式误操作的错误访问。
	// 
	char str1[100],str2[10],ch;
	/*,sdznfdvklsf*/gets(str1);
	/FILE*f;
	int n;
	n=strlen(str1);
	printf("%d\n",n);
	if((f=fopen("filel.dat","w"))==NULL){
		printf("Can't open the file\n");
		exit(0);
	}
	fputs(str1,f);
	fprintf(f,"yjgjhg");
	
	if((f=fopen("filel.dat","r"))==NULL){
		printf("Can't open the file\n");
		exit(0);
	}
	while(!feof(f)){
		fscanf(f,"%s",str2);
	}
	 
	puts(str2);
	putchar(10);
	fclose(f);
	
}
