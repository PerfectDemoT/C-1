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


int num_part=0;//��ʼ��������


int compare_part1(const void*p,const void*q); 
int compare_part2(const void* p,const void* q);
int find_part(int number);
void insert();
void search();
void update();
void print();
void sorting_number();
void sorting_name();
//������������������ļ�������. 
void save(); //���档
void input(); //��ʼʱ�����ļ�ԭ�����ݡ�
void renew();//����update�����ݸ��¡� 
 
//����������� �� 
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
 //������ָ������ָ����������дָ��ѡ��ģ�顣(�Ǳ����C��������ʹ�õ���
 //switch��䣬��֮ǰ����ż����ָ��̶����default�������������֣�����
 //����ָ������ָ��)
 //�������Լ��������#include<stdlib.h>ͷ�ļ��е�qsort������������qsort�������ͼ�
 //���ϵ�314ҳ�� 
	
	
		printf("\n\n\t********************STUDENT LIST*********************\n");
	printf("\t*                   1:intput record                 *\n");
	printf("\t*                   2:search record                 *\n");
	printf("\t*                   3:update record                 *\n");
	printf("\t*                   4:print record                  *\n");
	printf("\t*                   5:sorting_number                *\n");
	printf("\t*                   6:sorting_name                  *\n");
	printf("\t*                   7:quit                          *\n");
	printf("\t*****************************************************\n");

	input();//���ļ����������롣 
	while(1){
		printf("Enter operation code: ");
		scanf("%d",&code);
		while(getchar()!='\n')
		;
	meanu_select[code-1]();
		printf("\n");
	}
}
 
 
int find_part(int number)//find_part�������.
{
	int i;
	for(i=0;i<num_part;i++){
		if(inventory[i].number==number)
			return i;
	} 
	return -1;
  }  
 
 void insert()//insert �������.
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
  
  
void search()//���seacher����. 
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


void update()//��ƺ���update. 
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


void print()//��ƺ���printf. 
{
	int i;
	printf("Part number\tPart name                  "
	"Quantity on hand\n");
	for(i=0;i<num_part;i++){
		printf("%7d         \t%-25s%11d\n", inventory[i].number,
		inventory[i].name,inventory[i].on_hand);
	}
	
	 
 }
 
 
 sorting_number()//��Ʊ���������� 
 {
 	qsort(inventory,num_part,sizeof(struct part),compare_part1);
	printf("����ɱ������\n");
  } 
  
  sorting_name()//���������������
  {
  		qsort(inventory,num_part,sizeof(struct part),compare_part2);
  		printf("�������������\n"); 
   } 
 
 
 compare_part1(const void* p,const void* q)//��number�������� 
 {
 	if(((struct part*)p)->number<((struct part*)q)->number)
 	
 		return -1;
 	else if(((struct part*)p)->number==((struct part*)q)->number)
 		return 0;
		 else 
		 return 1;
	 
 }
 
 
  compare_part2(const void* p,const void* q)//��name��������
 {
 	return strcmp(((struct part*)p)->name,
	 				((struct part*)q)->name);
  } 


//����ļ����溯��
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
 } //��ɴ��溯����
 
 
 //�����������ڽ�ԭ���ļ��������뵽Ԥ��������
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
 
 
 //����������Ҫһ���޸ĵĺ������޸��ļ����������֧��update()����.
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
