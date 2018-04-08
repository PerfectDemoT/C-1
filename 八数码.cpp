
/*
	姓名:鲁日中天
	学号:2016211339 

*/
/*
	程序说明：
		本程序只适合需要调用200步以内的广度搜索,大于200步的则会提示超出限制. 
*/



#include<stdio.h>

struct node //定义一个结构体 
{
    int xy[3][3]; //二维数组储存3*3个数据 
    int dir; //表示移动方向，0 1 2 3 分别代表 左 上 右 下 
};
struct node Node[201], end; //定义全局变量，是类型为之前定义的结构体 
int count = 1; 

void init() ; //初始化输入起始数组和目标和数组 
int loction(int num) ; //定位0的位置 
int sign(int num) ;//查看是否找到最终目标  
void move(int num) ; //判断移动 
void display(int num) ; //输出数组 
int search(); //搜寻调用函数 。 


int main()
{
    init(); //初始化数组 
    search(); //函数调用组合函数. 
    return 0;
}




void init()
{
    printf("输入起始节点的位置:\n");
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &Node[0].xy[i][j]);
    Node[0].dir = -1;
    printf("输入目标节点的位置:\n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &Node[200].xy[i][j]);
    Node[200].dir = -1;
}

//找出0的位置
int loction(int num)
{
    int i , j ;
    for (i = 0; i < 3 ; i++)
    	for(j = 0 ; j < 3 ; j++ )
	        if (Node[num].xy[i][j] == 0)  //
				return (3*i+j); //返回位置-1 
}


int sign(int num) //查看是否找到最终目标 
{
    int order = 1 ;
    for(int i = 0 ; i < 3 ; i++ ){
    	for(int j = 0 ; j < 3 ; j++ ){
    		if(Node[num].xy[i][j]!=Node[200].xy[i][j]){  //和最后一个目标Node[200]作比较 
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
    loc = loction(num); //找到0的位置 
    int stand = Node[num].dir;
    //dir的0 1 2 3分别代表其他数向 左 上 右 下
    if (loc / 3 != 0 && stand != 1)  //0不是第一行的,且不是之前0向下生成的. 
    {
        Node[count] = Node[num]; //初始化下一个节点 
        Node[count].xy[loc / 3][loc % 3] = Node[count].xy[loc / 3 - 1][loc % 3];
        Node[count].xy[loc / 3 - 1][loc % 3] = 0;
        Node[count].dir = 3;
        count++;
    };
    if (loc / 3 != 2 && stand != 3) //0不是最后一行的,且不是之前0向上生成的. 
    {
        Node[count] = Node[num];
        Node[count].xy[loc / 3][loc % 3] = Node[count].xy[loc / 3 + 1][loc % 3];
        Node[count].xy[loc / 3 + 1][loc % 3] = 0;
        Node[count].dir = 1;
        count++;
    }
    if (loc % 3 != 0 && stand != 0) //0不是第一行的,且不是之前0向右生成的. 
    {
        Node[count] = Node[num];
        Node[count].xy[loc / 3][loc % 3] = Node[count].xy[loc / 3][loc % 3 - 1];
        Node[count].xy[loc / 3][loc % 3 - 1] = 0;
        Node[count].dir = 2;
        count++;
    }
    if (loc % 3 != 2 && stand != 2) //0不是最后一行的,且不是之前0向左生成的. 
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
            printf("超出了上限次数\n");
            return 0;
        }
        if (sign(i))
        {
            printf("在第%d次找到了\n", i);
            display(i);
            return i;
        }
        move(i);
        i++;
    }
}


