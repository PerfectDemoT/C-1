//计算数组的逆序对个数 
#include<string.h>
#include<stdio.h>
main ()
{
	char a[1000];//字符型，可以不用知道数组中的元素个数，而直接输入。 
	int i,j,len,jishu=0;
	gets(a);//输入该数组 。 
	len=strlen(a);//用头文件中包含的strlen函数确定该数组长度。 
	for(i=0;i<len;i+=2){
		for(j=i+2;j<len;j+=2){
			if(a[i]>a[j])
			jishu++;
		}
	}//由于有空格，也为一个字符，所以为+2。 
	printf("%d",jishu);	
}
