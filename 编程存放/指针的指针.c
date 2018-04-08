//
//
//**p相当于*(*p)意思是**p指向的东西的地址可以由*p表示 
//int **p；p指的是一个地址，p放的是*p的地址， *p指的是存放int 的地址
// 
#include<string.h>
#include<stdio.h>
main()
{
	
	
	int a[5]={2, 4, 6, 8, 9};
    int * num[5]={&a[0],&a[1],&a[2],&a[3],&a[4]};
    int * * ptr, m;/*p是指向指针的指针*/
    ptr=num;
    for(m=0;m<5;m++){
          printf("%d\t",**ptr);
          ptr ++;
     }
     printf("\n");
     
         ptr=num;
     for(m=0;m<5;m++){
          printf("%d\t",*ptr);
          ptr ++;
     }
     printf("\n");
     
     for(m=0;m<5;m++){
          printf("%d\t",num[m]);
     }    
     printf("\n");
     
     for(m=0;m<5;m++){
          printf("%d\t",*num[m]);
     }

	
	
	
	
	
	
	
	
	
	
	
	int i,j=0,len=0;
	char sentence[100000],**wpter,*word[10000],*spter;
	gets(sentence);
	spter=sentence;
	wpter=word;
	
	while(*spter!='\0'){
		word[j]=spter;//也可以是*wter= spter; 
		//毕竟*wter代表word中的值 
		while(*spter!=' '&&*spter!='\0'){
			spter++;
		}
		*spter='\0';
		spter++;
		len++;
		wpter++;
		j++;
		
	}
	for(i=0;i<len;i++)
	puts(word[i]);
}
