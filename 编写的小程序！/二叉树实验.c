#include<stdio.h>
#include<stdlib.h>
struct BTNode{
	int data;
	struct BTNode * lchild;
	struct BTNode * rchild; 
};
typedef struct BTNode BiNode;

int creatBitree(BiNode **T);//���������� 
void preorderBitree(BiNode* T);//�ȱ��������� 
void MiddleorderBitree(BiNode* T);//�������������
void postorderBitree(BiNode* T);//��������������
int Treedeep(BiNode* T);//���������
int Leafcount(BiNode* T);//Ҷ�ڵ���� 
main ()
{
	BiNode*T;
	int depth=0,leafcount=0;
	printf("�������һ���ڵ��ֵ��-1��ʾû��Ҷ�ڵ�\n");
	creatBitree(&T);
	
	printf("�������������\n");
	preorderBitree(T);
	printf("\n");
	
	printf("�������������\n");
	MiddleorderBitree(T);
	printf("\n");
	
	printf("�������������\n");
	postorderBitree(T);
	printf("\n");
	
	depth=Treedeep(T);
	printf("�������Ϊ%d\n",depth);
	
	leafcount=Leafcount(T);
	printf("Ҷ�ӵĽڵ����Ϊ%d\n",leafcount);
 } 
 
int creatBitree(BiNode **T)
{
	int ch;
	scanf("%d",&ch);
	if(ch==-1){
		*T=NULL;
		return 0;
	}
	else{
		*T=(BiNode*)malloc(sizeof(BiNode));
		if(T==NULL){
			printf("�ڴ����ʧ��\n");
			return 0;
		}
		else{
			(*T)->data=ch;
			printf("������%d����ڵ�\n",ch);
			creatBitree(&((*T)->lchild));
			printf("������%d���ҽڵ�\n",ch);
			creatBitree(&((*T)->rchild));
		}
	}
	return 1;
}

void preorderBitree(BiNode* T)//������������� 
{
	if(T==NULL)
	{
		return;
	}
	else
	{
		printf("%d ",T->data);
		preorderBitree(T->lchild);
		preorderBitree(T->rchild);
	}
}


void MiddleorderBitree(BiNode* T)//�������������
{
	if(T==NULL)
	{
		return;
	}
	else 
	{
		MiddleorderBitree(T->lchild);
		printf("%d ",T->data);
		MiddleorderBitree(T->rchild);
	}
 }


void postorderBitree(BiNode* T)//��������������
{
		if(T==NULL)
	{
		return;
	}
	else
	{
		postorderBitree(T->lchild);
		postorderBitree(T->rchild);
		printf("%d ",T->data);
	}
	
 }
 
 
int Treedeep(BiNode* T)//��������� 
{
	int deep=0,ldeep=0,rdeep=0;
	if(T!=NULL)
	{
		ldeep=Treedeep(T->lchild);
		rdeep=Treedeep(T->rchild);
		deep=ldeep>=rdeep?ldeep++:rdeep++;
	}
	return deep;
 } 
 
 int Leafcount(BiNode* T)//Ҷ�ڵ����
 {
 	int count;
 	if(T!=NULL){
 		if((T->lchild)==NULL&&(T->rchild)==NULL){
 			count++;
		 }
		 Leafcount(T->lchild);
		 Leafcount(T->rchild);
	 }
	 return count;
 }
