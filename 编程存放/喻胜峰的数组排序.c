#include<stdio.h>
int main() {
int n;
int a[1000];
int k;
int e;
int c,i;
c=0;
scanf("%d",&n);
for(int i=0;i<n;i++){
   scanf("%d",&a[i]);
   if(a[i]>a[i+1]){
   e=a[i+1];
   a[i+1]=a[i];
   a[i]=e;
   }
   }
scanf("%d",&k);
   for(i=0;i<k;i++){
   printf("%d\n",a[i]);
   }
   return 0;
}
