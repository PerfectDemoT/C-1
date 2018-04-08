#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct BiTNode
{
	int data;
	struct BiTNode *lChild, *rChild;    //左右子树域
}BiTNode, *BiTree;

void CreateBiTree(BiTree *);
void InOrderBiTree(BiTree);
void ChangeBiTree(BiTree);
int LeafCount(BiTree,int *);
void Swap(BiTree *, BiTree *);
int Isomorphic(BiTree, BiTree);  //判断两个二叉树是否同构

int main()
{
	BiTree T;
	T = NULL;
	int num = 0;
	CreateBiTree(&T);   //创建二叉树
	InOrderBiTree(T);  //中序遍历二叉树
	printf("\n");
	ChangeBiTree(T);   //所有结点的左、右子树相互交换
	InOrderBiTree(T);  //中序遍历二叉树
	printf("\n");
	printf("The num of leaf node's number is :%d\n",LeafCount(T,&num));  //统计二叉树叶子结点的个数
	return 0;
}

void CreateBiTree(BiTree *T)
{
	int ch;
	//printf("Please input the data in BiTree(end up with -1):\n");
	scanf("%d", &ch);
	getchar();
	if (ch == -1)
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
			printf("ERROR!\n");
		else
		{
			(*T)->data = ch;
			printf("input the %d's left node:\n", ch);
			CreateBiTree(&((*T)->lChild));
			printf("input the %d's right node:\n", ch);
			CreateBiTree(&((*T)->rChild));
		}
	}
}

void InOrderBiTree(BiTree T)
{
	if (T == NULL)
		return;
	InOrderBiTree(T->lChild);
	printf("%d ", T->data);
	InOrderBiTree(T->rChild);
}

void ChangeBiTree(BiTree T)
{
	if (T)
	{
		ChangeBiTree(T->lChild);
		ChangeBiTree(T->rChild);
		Swap(&T->lChild, &T->rChild);
	}
}

int LeafCount(BiTree T, int *num)
{
	if (T)
	{
		if (T->lChild == NULL && T->rChild == NULL)
			(*num)++;
		LeafCount(T->lChild, num);
		LeafCount(T->rChild, num);
	}
	return *num;
}

void Swap(BiTree *A, BiTree *B)
{
	BiTree temp;
	temp = *A;
	*A = *B;
	*B = temp;
}

int Isomorphic(BiTree R1, BiTree R2)
{
	if ((R1 == NULL) && (R2 == NULL)) //both empty
		return 1;

	if (((R1 == NULL) && (R2 != NULL)) || ((R1 != NULL) && (R2 == NULL)))//one of them is empty
		return 0;

	if (R1->data != R2->data) //roots are different
		return 0;

	if ((R1->lChild == NULL) && (R2->lChild == NULL))//both have no left subtree
		return Isomorphic(R1->rChild, R2->rChild);

	if (((R1->lChild != NULL) && (R2->lChild != NULL)) && (R1->lChild->data == R2->lChild->data)) //no need to swap the left and the right
		return (Isomorphic(R1->rChild, R2->rChild) && Isomorphic(R1->lChild, R2->lChild));
	else //need to swap the left and the right
		return (Isomorphic(R1->lChild, R2->rChild) && Isomorphic(R1->rChild, R2->lChild));
}

