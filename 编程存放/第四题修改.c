#include<stdio.h>
int hanshu(int b[],int n);
void InsertSort(int b[],int n,int a[][1000]);
main()
{
      int i,j,n,r,c,average,sum=0,k;
      scanf("%d",&n);
      int a[n][n],b[n],f[n];
      for(r=0;r<n;r++){
        for(c=0;c<n;c++){
           scanf("%d",&a[r][c]);                 
           }
           }       
        printf("\n");
      for(r=0;r<n;r++){
        for(c=0;c<n;c++){
        sum+=a[r][c];
        }          
        
        b[r]=sum;
		sum=0;     
      } 
      for(i=0;i<n;i++){
      f[i]=b[i];
                       }
       InsertSort(b,n,a);
       for(i=0;i<n;i++)
       {
       for(j=0;j<n;j++){
      printf("%d",a[i][j]);
      if(j!=n-1)
		printf(" ");
                        }
    printf("\n");
                       }
}



int hanshu(int b[],int n)
{
    int xiabiao=0,large=b[0],i;
    for(i=0;i<n;i++){
         
        if(b[i]>large){
        xiabiao=i;
        large=b[i];
    }
    }
    return xiabiao;
    }
void InsertSort(int b[],int n,int a[][1000])
{
    int t,i,size=n,temp,j;
    for(;size>1;size--){
        i=hanshu(b,size);
        t=b[i];
        b[i]=b[size-1];
        b[size-1]=t;
    
    for(j=0;j<n;j++){
    	temp=a[i][j];
    	a[size-1][j]=a[i][j];
    	a[i][j]=temp;
    }
	}
    
}
