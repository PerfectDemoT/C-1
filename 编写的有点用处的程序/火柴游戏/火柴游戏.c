#include <stdio.h>
#include <stdlib.h>

int main()
{
	int first, remain=31,p_get,c_get;
	do
	{
		printf("who first?if computer,input 0,if you,input 1:\n");
		scanf("%d", &first);
	} while (1 != first && 0 != first);

	if(1==first)
		{
		while(1)
		{
			do {
				printf("the remain is %d,you want to get ?\n ", remain);
				scanf("%d", &p_get);
			} while (p_get < 0 || p_get>2 || p_get > remain);
		remain -= p_get;
		if (remain == 0)
		{
			printf("congratulations! you win!\n"); break;
		}
		else
		{
			if (remain % 3 == 0)
				c_get = rand() % 2 + 1;
			else
				c_get = remain % 3;
			remain -= c_get;
			printf("computer gets %d,", c_get);
			if (remain == 0)
			{
				printf("computer wins......."); break;
			}
		}

	}

	}
		else
		{
			while (1)
			{
				if (remain % 3 == 0)
					c_get = rand() % 2 + 1;
				else
					c_get = remain % 3;
				remain -= c_get;
				printf("computer gets %d", c_get);
				if (remain == 0)
				{
					printf("computer wins......."); break;
				}
				do {
					printf("the remain is %d,you want to get ?\n ", remain);
					scanf("%d", &p_get);
				} while (p_get < 0 || p_get>2 || p_get > remain);
					remain -= p_get;
				if (remain == 0)
				{
					printf("congratulations! you win!\n"); break;
				}

			}
		}
	system("pause");	
	return 0;
}



