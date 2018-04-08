#include<stdio.h>
#include<stdlib.h>
struct BTNode{
	int data;
	struct BTNode * lchild;
	struct BTNode * rchild; 
};
typedef struct BTNode BiNode;

int creatBitree(BiNode **T);//创建二叉树 
void preorderBitree(BiNode* T);//先遍历二叉树 
void MiddleorderBitree(BiNode* T);//中序遍历二叉树
void postorderBitree(BiNode* T);//后续遍历二叉树
int Treedeep(BiNode* T);//二叉树深度
int Leafcount(BiNode* T);//叶节点个数 
main ()
{
	BiNode*T;
	int depth=0,leafcount=0;
	printf("请输入第一个节点的值，-1表示没有叶节点\n");
	creatBitree(&T);
	
	printf("先序遍历二叉树\n");
	preorderBitree(T);
	printf("\n");
	
	printf("中序遍历二叉树\n");
	MiddleorderBitree(T);
	printf("\n");
	
	printf("后序遍历二叉树\n");
	postorderBitree(T);
	printf("\n");
	
	depth=Treedeep(T);
	printf("树的深度为%d\n",depth);
	
	leafcount=Leafcount(T);
	printf("叶子的节点个数为%d\n",leafcount);
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
			printf("内存分配失败\n");
			return 0;
		}
		else{
			(*T)->data=ch;
			printf("请输入%d的左节点\n",ch);
			creatBitree(&((*T)->lchild));
			printf("请输入%d的右节点\n",ch);
			creatBitree(&((*T)->rchild));
		}
	}
	return 1;
}

void preorderBitree(BiNode* T)//先序遍历二叉树 
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


void MiddleorderBitree(BiNode* T)//中序遍历二叉树
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


void postorderBitree(BiNode* T)//后续遍历二叉树
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
 
 
int Treedeep(BiNode* T)//二叉树深度 
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
 
 int Leafcount(BiNode* T)//叶节点个数
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
