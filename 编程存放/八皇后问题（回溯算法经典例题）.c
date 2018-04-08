#include<stdio.h>
#define queens 8
main ()
{
	int i,k,flag,not_finish=1,count=0;
	int a[queens+1];//皇后所在位置从1开始 ，数组下标i表示棋盘上的第i列，值表示第i列皇后的位置 
	//正在处理的元素下标，表示前i-1个元素已经符合要求，正在处理第i个元素。
	i=1;
	a[1]=1;//为数组的第一个元素赋值
	printf("可能的排序情况如下：\n");
	while(not_finish){
		while(not_finish&&i<=queens){//处理尚未结束且还没处理到queens个元素
			for(flag=1,k=1;flag&&k<i;k++)//判断是否有多个皇后在同一行 
				if(a[k]==a[i])
					flag=0; 
					
			for(k=1;flag&&k<i;k++)//判断是否有多个皇后在对角线上 
				if(a[i]==a[k]-(k-i)||a[i]==a[k]+(k-i))
					flag=0;
				
			if(!flag){//若存在矛盾，不满足要求，则需要重新设置第i个元素 
				if(a[i]==a[i-1]){//若a[i]的值已经过一圈追上a[i-1]的值
				 	i--;
					
					if(i>1&&a[i]==queens)
						a[i]=1;//当a[i]为queens时将a[i]的值置一 
						else if(i==1&&a[i]==queens)
							not_finish=0;//当地一个值达到queens时结束 
					else
						a[i]++;//将a[i]的值取下一个值 
					} else if(a[i]==queens)
						a[i]=1;
					else
						a[i]++;//将a[i]的值取下一个值 
				} else if(++i<=queens)
					if(a[i-1]==queens)
						a[i]=1;
					else
						a[i]=a[i-1]+1;//否则元素的值为前一个元素的下一个值 
			}
			
			
			if(not_finish){
				++count;
				printf((count-1)%3?"\t[%2d]:":"\n[%2d]:",count);
				
				for(k=1;k<=queens;k++)
				printf("%d    ",a[k]);//输出结果 
				
				if(a[queens-1]<queens)
					a[queens-1]++;//修改倒数第二位的值
				else
					a[queens-1]=1;
					
				i=queens-1; 
			}
		}
	} 
