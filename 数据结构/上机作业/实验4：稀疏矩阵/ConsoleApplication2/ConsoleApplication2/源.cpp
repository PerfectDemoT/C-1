#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSIZE 1000


typedef struct
{
	int i, j;  //�����ھ����е��б���б�
	int e;  //����
}Triple;

typedef struct
{
	Triple data[MAXSIZE + 1];  //��Ԫ��� data[0]����
	int mu, nu, tu;  //����������������Ԫ����
}TSMatrix;


TSMatrix* NewMatrix();  //����һ����Ԫ���ʾ��ϡ�����
void PrintMatrix(TSMatrix*);   //��ӡϡ����������Ԫ��
TSMatrix* MultMatrix(TSMatrix*, TSMatrix*);
TSMatrix* AddMatrix(TSMatrix*, TSMatrix*);

int main()
{
	TSMatrix *M,*N;
	TSMatrix *ADD, *MULT;
	M = (TSMatrix*)malloc(sizeof(TSMatrix));  //��ʼ��
	N = (TSMatrix*)malloc(sizeof(TSMatrix));  //��ʼ��
	ADD = (TSMatrix*)malloc(sizeof(TSMatrix));  //��ʼ��
	MULT = (TSMatrix*)malloc(sizeof(TSMatrix));  //��ʼ��
	int m, n;
	M = NewMatrix();
	N = NewMatrix();
	printf("***********************************************\n");
	MULT = MultMatrix(M, N);
	if (MULT == NULL)
		printf("Sorry,these two matrice can't multiply.\n");
	else
		PrintMatrix(MULT);

	printf("***********************************************\n");
	ADD = AddMatrix(M, N);
	if (ADD == NULL)
		printf("Sorry,these two matrice can't add.\n");
	else
		PrintMatrix(ADD);

	return 0;
}

TSMatrix* NewMatrix()  //����һ����Ԫ���ʾ��ϡ�����
{
	TSMatrix *M;
	int str[100][100];
	int m, n, num = 1; //��Ԫ���б��Ǵ�1��ʼ��
	M = (TSMatrix*)malloc(sizeof(TSMatrix));  //��ʼ��


	printf("Please input the matrix's row:");
	scanf("%d", &m);
	printf("Please input the matrix's rank:");
	scanf("%d", &n);
	M->mu = m;
	M->nu = n;
	M->tu = 0;

	printf("Please input a matrix:\n");
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &str[i][j]);
			if (str[i][j] != 0)
			{
				M->data[num].e = str[i][j];
				M->data[num].i = i + 1;
				M->data[num].j = j + 1;
				M->tu++; num++;
			}
		}
	return M;
}

void PrintMatrix(TSMatrix *M)
{
	printf("��Ԫ��Ϊ��\n");
	printf("row\trank\tdata\n");
	for (int i = 1; i <= M->tu; i++)
		printf("%d\t%d\t%d\n", M->data[i].i, M->data[i].j, M->data[i].e);

	int m = 1;
	printf("����Ϊ��\n");
	for (int i = 1; i <= M->mu; i++)
	{
		for (int j = 1; j <= M->nu; j++)
		{
			if (i == M->data[m].i && j == M->data[m].j)
			{
				printf("%d ", M->data[m].e);
				m++;
			}
			else
				printf("0 ");
		}
		printf("\n");
	}
}

TSMatrix* MultMatrix(TSMatrix *M, TSMatrix*T)
{
	TSMatrix *Q, *S;
	int i = 1, j = 1;
	Triple data;
	if (M->nu != T->mu)
		return Q = NULL;

	Q = (TSMatrix*)malloc(sizeof(TSMatrix));  //��ʼ��
	S = (TSMatrix*)malloc(sizeof(TSMatrix));
	Q->mu = M->mu;
	Q->nu = T->nu;
	Q->tu = 0;
	memset(Q->data, 0, sizeof(Q->data));
	memset(S->data, 0, sizeof(S->data));
	while (i <= M->tu)
	{
		for (j = 1; j <= T->tu; j++)
		{
			if (M->data[i].j == T->data[j].i)
			{
				Q->data[M->data[i].i*T->data[j].j].e = (M->data[i].e)*(T->data[j].e) + Q->data[M->data[i].i*T->data[j].j].e;
				Q->data[M->data[i].i*T->data[j].j].i = M->data[i].i;
				Q->data[M->data[i].i*T->data[j].j].j = T->data[j].j;
			}
		}
		i++;
	}

	for (int m = 1; m < (Q->mu*Q->nu); m++)
	{
		if (Q->data[m].e != 0)
		{
			if (Q->data[m].i > Q->data[m + 1].i)
			{
				data = Q->data[m];
				Q->data[m] = Q->data[m + 1];
				Q->data[m + 1] = data;
			}
		}
	}
	S->mu = Q->mu;
	S->nu = Q->nu;
	S->tu = 0;
	for (int m = 1; m <= (Q->mu*Q->nu); m++)
	{
		if (Q->data[m].e != 0)
		{
			S->tu++;
			S->data[S->tu]= Q->data[m];

		}
	}
	return S;
}

TSMatrix* AddMatrix(TSMatrix*M, TSMatrix*T)
{
	TSMatrix *Q;
	Q = (TSMatrix*)malloc(sizeof(TSMatrix));  //��ʼ��
	int i = 1, j = 1;
	if ((M->mu != T->mu)||(M->nu != T->nu))
		return Q = NULL;

	Q->mu = M->mu;  //���������ݣ�M,T,Q��ʵ��һ����
	Q->nu = M->nu;
	Q->tu = 0;

	while (i <= M->tu || j <= T->tu)
	{
		if (i > M->tu)
		{
			Q->tu++;
			Q->data[Q->tu].i = T->data[j].i;
			Q->data[Q->tu].j = T->data[j].j;
			Q->data[Q->tu].e = T->data[j].e;
	        j++;
		}
		else if (j > T->tu)
		{
			Q->tu++;
			Q->data[Q->tu].i = M->data[i].i;
			Q->data[Q->tu].j = M->data[i].j;
			Q->data[Q->tu].e = M->data[i].e;
            i++;
		}
		else
		{
			Q->tu++;
			if (M->data[i].i == T->data[j].i && M->data[i].j == T->data[j].j)  //�������ھ����е�λ����ͬ
			{
				Q->data[Q->tu].i = M->data[i].i;
				Q->data[Q->tu].j = M->data[i].j;
				Q->data[Q->tu].e = M->data[i].e + T->data[j].e;
			    j++; i++;
			}
			else if (M->data[i].i > T->data[j].i || (M->data[i].i == T->data[j].i && M->data[i].j > T->data[j].j))  //M�ĺ��������T �� ��������ȵ�M�����������T 
			{
				Q->data[Q->tu].i = T->data[j].i;
				Q->data[Q->tu].j = T->data[j].j;
				Q->data[Q->tu].e = T->data[j].e;
                j++;
			}
			else   //M�ĺ�����С��T �� ��������ȵ�M��������С��T 
			{
				Q->data[Q->tu].i = M->data[i].i;
				Q->data[Q->tu].j = M->data[i].j;
				Q->data[Q->tu].e = M->data[i].e;
                i++;
			}
		}
	}
	return Q;
}