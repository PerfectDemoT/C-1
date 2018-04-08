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


int num_part=0;//��ʼ��������

void creat();
int find_part(int number);
int insert();
//������Ʒ��Ϣ�� 
int update();
//���¡� 
void print();
//����� 
int del(); 
//������������������ļ�������. 
void save(); //���档
void input(); //��ʼʱ�����ļ�ԭ�����ݡ� 
 
//����������� �� 
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
 //������ָ������ָ����������дָ��ѡ��ģ�顣
 //��ָ������ָ��) 
  input();
	while(1){
	printf("����������ѡ��:");
	printf("\n\n\t************************LIST*************************\n");
	printf("\t*                   1:����һ��100���ռ�¼��         *\n");
	printf("\t*                   2:������Ʒ��¼                  *\n");
	printf("\t*                   3:������Ʒ��¼                  *\n");
	printf("\t*                   4:ɾ����Ʒ��¼                  *\n");
	printf("\t*                   5:���ȫ����Ʒ��¼              *\n");
	printf("\t*                   6:�˳�����                      *\n");
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
			printf("100���ռ�¼�������\n");
		}
		else if(code==6){
		printf("�������н������ټ���\n");
			exit(0);
		}
		else

				
			meanu_select[code-1]();
			
	}
		
		printf("\n");
	
}
 
 
int find_part(int number)//find_part�������.
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
 
int insert()//insert �������.
 {
 	while(1){
	int part_number;
	if(num_part==MAX_PARTS){
		printf("Database is full;can't add more parts.\n");
		return;
	}
	printf("������Ʒ��Ϣ[IDΪ-1�����������]:\n��ƷID:");
	scanf("%d",&part_number);
	if(part_number==-1)
	break;
	else{
	if(find_part(part_number)>=0){
		printf("����Ʒ��Ϣ�Ѵ��ڡ�\n");
}
	else{
	inventory[num_part].number=part_number;
	getchar(); 
	printf("��Ʒ��:") ;
	gets(inventory[num_part].name);
	printf("����:");
	scanf("%d",&inventory[num_part].on_hand);
	printf("�۸�:");
	scanf("%f",&inventory[num_part].price);
	save();
	num_part++;
}
}
}
	printf("��Ʒ��Ϣ�������\n");
	print();
  } 
  

int update()//��ƺ���update. 
{	
	while(1){
	int i,number,change1,change2;
	char str[100],ch;
	FILE* fp;
	struct part news={0,"",0};
	
	printf("�������������Ʒ(ID)[IDΪ-1�����������]: ");
	scanf("%d",&number);
	if(number==-1)
	return -1;
	i=find_part(number);
	if(i>=0){
		printf("ԭ��Ʒ��Ϣ����:\n");
		
			printf("��¼��(��ƷID)\t��Ʒ��                  "
	"����\t�۸�\n");
		printf("%7d       \t%-25s%d\t%.2f\n", inventory[i].number,
		inventory[i].name,inventory[i].on_hand,inventory[i].price);
		
		printf("�����������Ϣ[�粻������ֱ�Ӱ��س�]:\n");
		printf("��Ʒ��:");
		getchar();
		gets(str);
		if(str[0]!='\0')
		strcpy(inventory[i].name,str);
		
		printf("����:");
		gets(str);
		if(atoi(str)!=0){
			change1=atoi(str);
			inventory[i].on_hand=change1;
		}
		printf("�۸�:");
		gets(str);
		if(atof(str)!=0.0){
			change2=atof(str);
			inventory[i].price=change2;
	}
		//�����������ļ��� 
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
	printf("�Բ����¼��Ϊ%d����Ʒ�����ڣ��޷�����\n",i);
}
	printf("���¹�������\n");
}


void print()//��ƺ���printf. 
{
	int i;
	printf("��¼��(��ƷID)\t��Ʒ��                  "
	"����\t�۸�\n");
	for(i=0;i<num_part;i++){
		printf("%7d       \t%-25s%d\t%.2f\n", inventory[i].number,
		inventory[i].name,inventory[i].on_hand,inventory[i].price);
	}
	
	 
 }
 

int del()//ɾ�������� 
{
	while(1){
	int i,number,j;
	char ch ;
	printf("�������ɾ����ƷID[��¼��Ϊ-1�������ɾ��]:");
	scanf("%d",&number);
	if(number==-1)
	return -1;
	i=find_part(number);//Ѱ��ɾ����Ϣ��λ�á� 
	
	printf("����Ʒ��Ϣ����:");
		printf("��¼��(��ƷID)\t��Ʒ��                  "
	"����\t�۸�\n");
		printf("%7d       \t%-25s%11d\t%.2f\n", inventory[i].number,
		inventory[i].name,inventory[i].on_hand,inventory[i].price);
	

	FILE*fp;
	if((fp=fopen("commodity.dat","wb"))==NULL)
		{
			printf("Can't open the file\n");
			return;
		}
	
	if(i>=0){
		printf("�Ƿ�ȷʵɾ��(ȷ�ϰ�Y��ȡ����N)?\n");
		getchar();
	scanf("%c",&ch);
	if(ch=='Y'){
	printf("��ѡ��ɾ����¼��Ϊ10����Ʒ\n");
		
			num_part-=1;
			for(;i<num_part;i++){
				strcpy(inventory[i].name,inventory[i+1].name);
				inventory[i].number=inventory[i+1].number;
				inventory[i].on_hand=inventory[i+1].on_hand;	
				inventory[i].price=inventory[i+1].price;
			}
			
		rewind(fp);
		for(i=0;i<num_part;i++){//�������и��µ���Ϣд���ļ��С� 
			if(fwrite(&inventory[i],sizeof(struct part),1,fp)!=1)
			printf("File write error\n");
	}
	print();
	}
		else{
	printf("��ѡ��ɾ����¼Ϊ%d����Ʒ\n",number);
	print();
	}
}
	else
		printf("�Բ��𣬼�¼��Ϊ%d����Ʒ�����ڣ��޷�����ɾ������\n",number);
	}
		printf("ɾ����������\n");
}
 

//����ļ����溯��
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
 } //��ɴ��溯����
 
 
 //�����������ڽ�ԭ���ļ��������뵽��Ϊ�м���ʵ�������
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
 
 

