#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part{
	int number;
	char name[NAME_LEN+1];
	int on_hand;
} inventory[MAX_PARTS];


int num_part=0;//初始化个数。


int compare_part1(const void*p,const void*q); 
int compare_part2(const void* p,const void* q);
int find_part(int number);
void insert();
void search();
void update();
void print();
void sorting_number();
void sorting_name();
//接下来这个函数用于文件处理储存. 
void save(); //储存。
void input(); //开始时输入文件原有数据。
void renew();//用于update的数据更新。 
 
//先设计主函数 。 
main()
{
	int code;
	
	 void (*meanu_select[7])(void)={
 insert,
 search,
 update,
 print,
 sorting_number,
 sorting_name,
 exit
 };
 //尝试用指向函数的指针数组来编写指令选择模块。(那本厚的C语言书中使用的是
 //switch语句，而之前会有偶数个指令固定输出default后的语句的情况出现，所以
 //改用指向函数的指针)
 //本程序还自己另外加了#include<stdlib.h>头文件中的qsort函数用于排序。qsort函数解释见
 //书上的314页。 
	
	
		printf("\n\n\t********************STUDENT LIST*********************\n");
	printf("\t*                   1:intput record                 *\n");
	printf("\t*                   2:search record                 *\n");
	printf("\t*                   3:update record                 *\n");
	printf("\t*                   4:print record                  *\n");
	printf("\t*                   5:sorting_number                *\n");
	printf("\t*                   6:sorting_name                  *\n");
	printf("\t*                   7:quit                          *\n");
	printf("\t*****************************************************\n");

	input();//将文件中数据输入。 
	while(1){
		printf("Enter operation code: ");
		scanf("%d",&code);
		while(getchar()!='\n')
		;
	meanu_select[code-1]();
		printf("\n");
	}
}
 
 
int find_part(int number)//find_part函数设计.
{
	int i;
	for(i=0;i<num_part;i++){
		if(inventory[i].number==number)
			return i;
	} 
	return -1;
  }  
 
 void insert()//insert 函数设计.
 {
	int part_number;
	if(num_part==MAX_PARTS){
		printf("Database is full;can't add more parts.\n");
		return;
	}
	printf("Enter part number : ");
	scanf("%d",&part_number);
	if(find_part(part_number)>=0){
		printf("Part already exists.\n");
		return;
}
	inventory[num_part].number=part_number;
	getchar(); 
	printf("Enter part name : ");
	gets(inventory[num_part].name);
	printf("Enter quantity on hand : ");
	scanf("%d",&inventory[num_part].on_hand);
	save();
	num_part++;
	
  } 
  
  
void search()//设计seacher函数. 
{
	int i,number;
	
	printf("Enter part number : ");
	scanf("%d",&number);
	i=find_part(number);
	if(i>=0){
		printf("Part name is : %s\n",inventory[i].name);
		printf("Quantity on hand : %d",inventory[i].on_hand);
	}
	else 
	printf("Part not found.\n ");
}


void update()//设计函数update. 
{
	int i,number,change;
	printf("Enter part number : ");
	scanf("%d",&number);
	i=find_part(number);
	if(i>=0){
		printf("Enter change in quantity on hand : ");
		scanf("%d",&change);
		inventory[i].on_hand+=change;
		
	}
	else
	printf("Part not found\n");
}


void print()//设计函数printf. 
{
	int i;
	printf("Part number\tPart name                  "
	"Quantity on hand\n");
	for(i=0;i<num_part;i++){
		printf("%7d         \t%-25s%11d\n", inventory[i].number,
		inventory[i].name,inventory[i].on_hand);
	}
	
	 
 }
 
 
 sorting_number()//设计编号排序函数。 
 {
 	qsort(inventory,num_part,sizeof(struct part),compare_part1);
	printf("已完成编号排序。\n");
  } 
  
  sorting_name()//设计名字排序函数。
  {
  		qsort(inventory,num_part,sizeof(struct part),compare_part2);
  		printf("已完成名字排序。\n"); 
   } 
 
 
 compare_part1(const void* p,const void* q)//对number进行排序。 
 {
 	if(((struct part*)p)->number<((struct part*)q)->number)
 	
 		return -1;
 	else if(((struct part*)p)->number==((struct part*)q)->number)
 		return 0;
		 else 
		 return 1;
	 
 }
 
 
  compare_part2(const void* p,const void* q)//对name进行排序。
 {
 	return strcmp(((struct part*)p)->name,
	 				((struct part*)q)->name);
  } 


//设计文件储存函数
void save()
{
	FILE*fp;
	int i;
	if((fp=fopen("filel.dat","ab"))==NULL)
		{
			printf("Can't open the file\n");
			return;
		}
	if(fwrite(&inventory[num_part],sizeof(struct part),1,fp)!=1)
		printf("File write error\n");
		fputs("\n",fp);
	fclose(fp);
 } //完成储存函数。
 
 
 //接下来是用于将原有文件数据输入到预订数组中
 void input()
 {
 	FILE*fp;
 	if((fp=fopen("filel.dat","rb"))==NULL)
		{
			printf("Can't open the file\n");
			return;
		}
		while(!feof(fp))
		{
		if(fread(&inventory[num_part],sizeof(struct part),1,fp)!=1)
		printf("File write error\n");
		num_part++;	
		}
  } 
 
 
 //接下来还需要一个修改的函数来修改文件里的数据来支持update()函数.
//void renew()
//{
//	FILE* fp;
//	if((fp=fopen("filel.dat","wb"))==NULL)
//		{
//			printf("Can't open the file\n");
//			return;
//		}
//		fseek(fp,)
	
//} 
