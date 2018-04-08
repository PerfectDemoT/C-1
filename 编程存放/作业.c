#include<stdio.h>
void InsertSort(int a[],int n);
main()
{
	int a[1000],i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	InsertSort(a,n);
	
}
void InsertSort(int a[],int n)
{
	int i,j=0,min=a[n-1],cunfang,m=n-1;
	for(j=0;j<n;j++){
	for(i=j;i<n;i++){
		if(min>a[i]){
			m=i;
			min=a[i];
		}
}
m=n-1;
min=a[n-1];

	cunfang=a[j];
	a[j]=a[m];
	a[m]=cunfang;
}
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
