#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAME_LEN 40
#define MAX_PARTS 100

struct part{
	int number;
	char name[NAME_LEN+1];
	int on_hand;
	float price;
} inventory[MAX_PARTS]={0,"",0,0};


int num_part=0;//初始化个数。

void creat();
int find_part(int number);
int insert();
//输入商品信息。 
int update();
//更新。 
void print();
//输出。 
int del(); 
//接下来这个函数用于文件处理储存. 
void save(); //储存。
void input(); //开始时输入文件原有数据。 
 
//先设计主函数 。 
main()
{
	int code,i;
	
	 void (*meanu_select[6])(void)={
 creat, 
 insert,
 update,
 del,
 print,
 exit
 };
 //尝试用指向函数的指针数组来编写指令选择模块。
 //用指向函数的指针) 
  input();
	while(1){
	printf("请输入您的选择:");
	printf("\n\n\t************************LIST*************************\n");
	printf("\t*                   1:创建一个100条空记录的         *\n");
	printf("\t*                   2:输入商品记录                  *\n");
	printf("\t*                   3:更新商品记录                  *\n");
	printf("\t*                   4:删除商品记录                  *\n");
	printf("\t*                   5:输出全部商品记录              *\n");
	printf("\t*                   6:退出程序                      *\n");
	printf("\t*****************************************************\n");
		scanf("%d",&code);
		while(getchar()!='\n')
		;
		if(code==1){
			FILE* fp;
			struct part zero={0,"",0,0.0};
			
				if((fp=fopen("commodity.dat","rb+"))==NULL)
		{
			printf("Can't open the file\n");
			return;
		}
			rewind(fp);
			for(i=0;i<100;i++)
			fwrite(&zero,sizeof(struct part),1,fp);
			
			for(i=0;i<num_part;i++){
				strcpy(inventory[i].name,zero.name);
				inventory[i].number=zero.number;
				inventory[i].on_hand=zero.on_hand;	
				inventory[i].price=zero.price;
			}
			
			num_part=0;
			printf("100条空记录创建完毕\n");
		}
		else if(code==6){
		printf("程序运行结束，再见。\n");
			exit(0);
		}
		else

				
			meanu_select[code-1]();
			
	}
		
		printf("\n");
	
}
 
 
int find_part(int number)//find_part函数设计.
{
	int i;
	for(i=0;i<num_part;i++){
		if(inventory[i].number==number)
		{ 
			return i;
			} 
	} 
	return -1;
  }  
 
int insert()//insert 函数设计.
 {
 	while(1){
	int part_number;
	if(num_part==MAX_PARTS){
		printf("Database is full;can't add more parts.\n");
		return;
	}
	printf("输入商品信息[ID为-1代表输入结束]:\n商品ID:");
	scanf("%d",&part_number);
	if(part_number==-1)
	break;
	else{
	if(find_part(part_number)>=0){
		printf("该商品信息已存在。\n");
}
	else{
	inventory[num_part].number=part_number;
	getchar(); 
	printf("商品名:") ;
	gets(inventory[num_part].name);
	printf("数量:");
	scanf("%d",&inventory[num_part].on_hand);
	printf("价格:");
	scanf("%f",&inventory[num_part].price);
	save();
	num_part++;
}
}
}
	printf("商品信息输入结束\n");
	print();
  } 
  

int update()//设计函数update. 
{	
	while(1){
	int i,number,change1,change2;
	char str[100],ch;
	FILE* fp;
	struct part news={0,"",0};
	
	printf("请输入待更新商品(ID)[ID为-1代表结束更新]: ");
	scanf("%d",&number);
	if(number==-1)
	return -1;
	i=find_part(number);
	if(i>=0){
		printf("原商品信息如下:\n");
		
			printf("记录号(商品ID)\t商品名                  "
	"数量\t价格\n");
		printf("%7d       \t%-25s%d\t%.2f\n", inventory[i].number,
		inventory[i].name,inventory[i].on_hand,inventory[i].price);
		
		printf("请输入更新信息[如不更新请直接按回车]:\n");
		printf("商品名:");
		getchar();
		gets(str);
		if(str[0]!='\0')
		strcpy(inventory[i].name,str);
		
		printf("数量:");
		gets(str);
		if(atoi(str)!=0){
			change1=atoi(str);
			inventory[i].on_hand=change1;
		}
		printf("价格:");
		gets(str);
		if(atof(str)!=0.0){
			change2=atof(str);
			inventory[i].price=change2;
	}
		//接下来更新文件。 
		if((fp=fopen("commodity.dat","rb+"))==NULL)
		{
			printf("Can't open the file\n");
			return;
		}
		strcpy(news.name,inventory[i].name);
		news.number=inventory[i].number ;
		news.on_hand=inventory[i].on_hand;
		news.price=inventory[i].price;
		
		fseek(fp,i*sizeof(struct part),SEEK_SET);
		if(fwrite(&news,sizeof(struct part),1,fp)!=1)
		printf("File write error\n");
		rewind(fp);
		fclose(fp);
	}
	else
	printf("对不起记录号为%d的商品不存在，无法更新\n",i);
}
	printf("更新工作结束\n");
}


void print()//设计函数printf. 
{
	int i;
	printf("记录号(商品ID)\t商品名                  "
	"数量\t价格\n");
	for(i=0;i<num_part;i++){
		printf("%7d       \t%-25s%d\t%.2f\n", inventory[i].number,
		inventory[i].name,inventory[i].on_hand,inventory[i].price);
	}
	
	 
 }
 

int del()//删除函数。 
{
	while(1){
	int i,number,j;
	char ch ;
	printf("请输入待删除商品ID[记录号为-1代表结束删除]:");
	scanf("%d",&number);
	if(number==-1)
	return -1;
	i=find_part(number);//寻找删除信息的位置。 
	
	printf("该商品信息如下:");
		printf("记录号(商品ID)\t商品名                  "
	"数量\t价格\n");
		printf("%7d       \t%-25s%11d\t%.2f\n", inventory[i].number,
		inventory[i].name,inventory[i].on_hand,inventory[i].price);
	

	FILE*fp;
	if((fp=fopen("commodity.dat","wb"))==NULL)
		{
			printf("Can't open the file\n");
			return;
		}
	
	if(i>=0){
		printf("是否确实删除(确认按Y，取消按N)?\n");
		getchar();
	scanf("%c",&ch);
	if(ch=='Y'){
	printf("您选择删除记录号为10的商品\n");
		
			num_part-=1;
			for(;i<num_part;i++){
				strcpy(inventory[i].name,inventory[i+1].name);
				inventory[i].number=inventory[i+1].number;
				inventory[i].on_hand=inventory[i+1].on_hand;	
				inventory[i].price=inventory[i+1].price;
			}
			
		rewind(fp);
		for(i=0;i<num_part;i++){//将数组中更新的信息写入文件中。 
			if(fwrite(&inventory[i],sizeof(struct part),1,fp)!=1)
			printf("File write error\n");
	}
	print();
	}
		else{
	printf("您选择不删除记录为%d的商品\n",number);
	print();
	}
}
	else
		printf("对不起，记录号为%d的商品不存在，无法进行删除操作\n",number);
	}
		printf("删除工作结束\n");
}
 

//设计文件储存函数
void save()
{
	FILE*fp;
	int i;
	if(num_part!=0){
	if((fp=fopen("commodity.dat","ab"))==NULL)
		{
			printf("Can't open the file\n");
			return;
		}
	if(fwrite(&inventory[num_part],sizeof(struct part),1,fp)!=1)
		printf("File write error\n");
	}
	else{
		if((fp=fopen("commodity.dat","wb"))==NULL)
		{
			printf("Can't open the file\n");
			return;
		}
	if(fwrite(&inventory[num_part],sizeof(struct part),1,fp)!=1)
		printf("File write error\n");
	}
	fclose(fp);
 } //完成储存函数。
 
 
 //接下来是用于将原有文件数据输入到作为中间介质的数组中
 void input()
 {
 	FILE*fp;
 	int size,daxiao,i;
 	if((fp=fopen("commodity.dat","rb"))==NULL)
		{
			printf("Can't open the file\n");
			return;
		}
		fseek(fp,0,SEEK_END);
		size=ftell(fp);
		daxiao=size/(sizeof(struct part));
		if(size==0)
		;
		else{
		rewind(fp);
		for(i=0;i<daxiao;i++)
		{
		fread(&inventory[i],sizeof(struct part),1,fp);
		num_part++;	
		}
	}
	fclose(fp);
  } 
 
 

