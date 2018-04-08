#include<stdio.h>
void fanxiang(int *p_1,int n); 
main()
{
int n,*p_1;
scanf("%d",&n);
int i,j,t,a[n];
for(i=0;i<n;i++)
scanf("%d",&a[i]);
p_1=a;
fanxiang(p_1,n);
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n"); 
for(i=0;i<n-1;i++){
	for(j=0;j<n-i-1;j++){
		if(a[j]>a[j+1]){
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
	}
}

for(i=0;i<n;i++)
printf("%d ",a[i]);
}

void fanxiang(int *p_1,int n)
{
	int temp,*i,*j,m,*p_2;
	m=(n-1)/2;
	i=p_1;
	j=p_1+n-1;
	for(;i<=p_1+m;i++,j--){
		temp=*i;
		*j=*i;
		*j=temp;
	}
}
