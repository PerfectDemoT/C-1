#include<stdio.h>
main()
{
	int n,a[1000],i,j,k,m,b[100],zhishi=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	scanf("%d",&a[i]);
}
	scanf("%d",&m);
	for(i=0;i<m;i++){
	scanf("%d",&b[i]);
}
	if(n==1){
		for(k=0;k<m;k++)
		printf("NULL\n");
			
	}
	else
	{
	for(j=0;j<m;j++){
		for(i=0;i<n;i++){
			if(a[i]==b[j]&&i==0){
			printf("%d\n",a[i+1]);
				zhishi=1;
			}
				else if(a[i]==b[j]&&i==(n-1)){
				printf("%d\n",a[i-1]);
				zhishi=1;
			}
				else if(a[i]==b[j]){
				printf("%d %d\n",a[i-1],a[i+1]);
					zhishi=1;
				}
		}
		if(zhishi==0)
		printf("NULL\n");
		zhishi=0;
	}
	
}
}
