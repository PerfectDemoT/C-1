#include<stdio.h>
int hanshu(int a[],int n);
void paixu(int a[],int n);
main()
{
	
		struct book{
		char title[10];
		char author[10];
		float value;
		
}boo;

	gets(boo.title);
	gets(boo.author);
	scanf("%f",&boo.value);
	
	
	printf("\n");
	printf("%s %s %.2f",boo.title,boo.author,boo.value);
	printf("\n");
	
	
	puts(boo.title);
	puts(boo.author);
	printf("%f",boo.value);
	printf("\n");
	
	
	int n=10,a[10]={45,134,45,66666,65,657,87,3342,23,8};
	printf("%d\n",hanshu(a,n));
	paixu(a,n);
}
int hanshu(int a[],int n)
{
	int xiabiao=0,large=a[0],i;
	for(i=0;i<n;i++){
		
		if(a[i]>large){
		xiabiao=i;
		large=a[i];
	}
	}
	return xiabiao;
	}
void paixu(int a[],int n)
{
	int t,i,size=n;
	for(;size>1;size--){
		i=hanshu(a,size);
		t=a[i];
		a[i]=a[size-1];
		a[size-1]=t;
	}
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
