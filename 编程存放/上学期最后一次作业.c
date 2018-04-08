#include<stdio.h>
#include<string.h> 
struct infor{
	char name[100];
	int score;
};
main()
{
	int n,i,j;
	scanf("%d",&n);
	struct infor stu[n+1];
	struct infor mid;
	for(i=0;i<n;i++){
		scanf("%s",&stu[i].name);
		scanf("%d",&stu[i].score);
	}

	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(stu[j].score<stu[j+1].score){
				mid=stu[j] ;
				stu[j]=stu[j+1];
				stu[j+1]=mid;
			}
			else if (stu[j].score==stu[j+1].score){
				if('stu[j].score[0]'>'stu[j+1].score[0]'){
						mid=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=mid;
				}
			}
		}
	}
	for(i=0;i<n;i++){
		puts(stu[i].name);
		printf("%d\n\n",stu[i].score );
	}
	return 0;
	
}
