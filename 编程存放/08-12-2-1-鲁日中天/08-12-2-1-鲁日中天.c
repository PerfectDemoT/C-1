#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main ()
{
	FILE *fp;
	int capital_num[27]={0},lowercase_num[27]={0};
	int cap_num=0,low_num=0,digit_num=0,others_num=0,line_num=0,max1=0,min1=9999,countline=0;
	char ch;
	//进行文件打开。 
	if((fp=fopen("p1.txt","r"))==NULL){
		printf("Can't open the file\n");
		exit(0);
	}
	int i,j,zhishi=1;
	//进行一个个字符读入比较统计操作。 
	while(!feof(fp)){
		ch=fgetc(fp);
		countline++;
		if('A'<=ch&&ch<='Z'){
			cap_num++;
			capital_num[ch-'A']++;
		}
			else if('a'<=ch&&ch<='z'){
				low_num++;
				lowercase_num[ch-'a']++;
			}
				else if('0'<=ch&&ch<='9'){
					digit_num++;
				}
					else if(ch!='\n'){
						others_num++;
					}
						else{
							if((countline-1)>=max1)
								max1=(countline-1);
							
							if((countline-1)<=min1)
								min1=(countline-1);				
							
								line_num++; 
								countline=0;
						}
	}
	//接下来进行输出操作。
	printf("The result is:\n");
	printf("Task1:\n");
	printf("capital:%d\n",cap_num);
	printf("lowercase:%d\n",low_num);
	printf("digit:%d\n",digit_num);
	printf("others:%d\n",others_num);
	printf("\n");
	printf("Task2:\n");
	printf("line:%d\n",line_num);
	printf("%d characters in max line\n",max1);
	printf("%d characters in min line\n",min1);
	printf("\n");
	printf("Task3:\n");
	printf("CAPITAL:\n");
	char c='A'; 
	j=0;
	for(i=0;i<26;i++){
		printf("%c:%d",c+i,capital_num[i]);
		j++;
		if(j!=0&&j%3==0){
			printf("\n");
			j=0;
		}
		else
		printf("\t");
	}
	//输出每个大写字母。
	
	printf("\n");
	printf("LOWERCASE:\n");
	c='a';
	j=0; 
	for(i=0;i<26;i++){
		printf("%c:%d",c+i,lowercase_num[i]);
		j++;
		if(j!=0&&j%3==0){
			printf("\n");
			j=0;
		}
		else
		printf("\t");
	}  
	//输出每个小写字母。 
	fclose(fp);
 } 
