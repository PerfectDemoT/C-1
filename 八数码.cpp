
/*
	����:³������
	ѧ��:2016211339 

*/
/*
	����˵����
		������ֻ�ʺ���Ҫ����200�����ڵĹ������,����200���������ʾ��������. 
*/



#include<stdio.h>

struct node //����һ���ṹ�� 
{
    int xy[3][3]; //��ά���鴢��3*3������ 
    int dir; //��ʾ�ƶ�����0 1 2 3 �ֱ���� �� �� �� �� 
};
struct node Node[201], end; //����ȫ�ֱ�����������Ϊ֮ǰ����Ľṹ�� 
int count = 1; 

void init() ; //��ʼ��������ʼ�����Ŀ������� 
int loction(int num) ; //��λ0��λ�� 
int sign(int num) ;//�鿴�Ƿ��ҵ�����Ŀ��  
void move(int num) ; //�ж��ƶ� 
void display(int num) ; //������� 
int search(); //��Ѱ���ú��� �� 


int main()
{
    init(); //��ʼ������ 
    search(); //����������Ϻ���. 
    return 0;
}




void init()
{
    printf("������ʼ�ڵ��λ��:\n");
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &Node[0].xy[i][j]);
    Node[0].dir = -1;
    printf("����Ŀ��ڵ��λ��:\n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &Node[200].xy[i][j]);
    Node[200].dir = -1;
}

//�ҳ�0��λ��
int loction(int num)
{
    int i , j ;
    for (i = 0; i < 3 ; i++)
    	for(j = 0 ; j < 3 ; j++ )
	        if (Node[num].xy[i][j] == 0)  //
				return (3*i+j); //����λ��-1 
}


int sign(int num) //�鿴�Ƿ��ҵ�����Ŀ�� 
{
    int order = 1 ;
    for(int i = 0 ; i < 3 ; i++ ){
    	for(int j = 0 ; j < 3 ; j++ ){
    		if(Node[num].xy[i][j]!=Node[200].xy[i][j]){  //�����һ��Ŀ��Node[200]���Ƚ� 
    			order = 0 ;
    			break ;
			}
		}
	}
	return order ;
}

void move(int num)
{

    int loc;
    int up = 1, down = 1, left = 1, right = 1;
    loc = loction(num); //�ҵ�0��λ�� 
    int stand = Node[num].dir;
    //dir��0 1 2 3�ֱ������������ �� �� �� ��
    if (loc / 3 != 0 && stand != 1)  //0���ǵ�һ�е�,�Ҳ���֮ǰ0�������ɵ�. 
    {
        Node[count] = Node[num]; //��ʼ����һ���ڵ� 
        Node[count].xy[loc / 3][loc % 3] = Node[count].xy[loc / 3 - 1][loc % 3];
        Node[count].xy[loc / 3 - 1][loc % 3] = 0;
        Node[count].dir = 3;
        count++;
    };
    if (loc / 3 != 2 && stand != 3) //0�������һ�е�,�Ҳ���֮ǰ0�������ɵ�. 
    {
        Node[count] = Node[num];
        Node[count].xy[loc / 3][loc % 3] = Node[count].xy[loc / 3 + 1][loc % 3];
        Node[count].xy[loc / 3 + 1][loc % 3] = 0;
        Node[count].dir = 1;
        count++;
    }
    if (loc % 3 != 0 && stand != 0) //0���ǵ�һ�е�,�Ҳ���֮ǰ0�������ɵ�. 
    {
        Node[count] = Node[num];
        Node[count].xy[loc / 3][loc % 3] = Node[count].xy[loc / 3][loc % 3 - 1];
        Node[count].xy[loc / 3][loc % 3 - 1] = 0;
        Node[count].dir = 2;
        count++;
    }
    if (loc % 3 != 2 && stand != 2) //0�������һ�е�,�Ҳ���֮ǰ0�������ɵ�. 
    {
        Node[count] = Node[num];
        Node[count].xy[loc / 3][loc % 3] = Node[count].xy[loc / 3][loc % 3 + 1];
        Node[count].xy[loc / 3][loc % 3 + 1] = 0;
        Node[count].dir = 0;
        count++;
    }

}
void display(int num)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d ", Node[num].xy[i][j]);
        printf("\n");
    }
}

int search()
{
    int i = 0;
    while (1)
    {
        printf("\n");
        display(i);
        printf("\n");
        if (i == 100)
        {
            printf("���������޴���\n");
            return 0;
        }
        if (sign(i))
        {
            printf("�ڵ�%d���ҵ���\n", i);
            display(i);
            return i;
        }
        move(i);
        i++;
    }
}


