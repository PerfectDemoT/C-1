#include<stdio.h>
int lunnian(int y);
int yuefen(int m,int k); 
int gainianpanduan(int y);
void shuchu(int m,int xingqinian,int k);
main()
{
	int i,j,m,y,date,xingqinian,xingqiri,k,d=0,t=0,x=0;
	scanf("%d %d",&y,&m);
	k=gainianpanduan(y);
	xingqinian=(lunnian(y)+yuefen(m,k))%7+1; 
	printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");
	for(i=1;i<=xingqinian;i++){
		printf("\t");
	}
	shuchu(m,xingqinian,k);
	system("pause");
	return 0;
 
}
int lunnian(int y)
{
	int day,n,i,lunniannum;
	for(i=1;i<y;i++){
		if((i%4==0&&i%100!=0)||i%400==0)
		lunniannum++;
	}
	day=365*(y-lunniannum-1)+366*lunniannum;
	return day;
}
int yuefen(int m,int k)
{
	int i,day=0;
	for(i=1;i<m;i++){
	if(i==1||i==3||i==5||i==7||i==8||i==10)
    day+=31;
    else if(i==4||i==6||i==9||i==11)
    day+=30;
    else if(i==2&&k==0)
    day+=28;
    else if(i==2&&k==1)
    day+=29;
	}
	return day;
}
int gainianpanduan(int y)
{
	int k=0;
	if((y%4==0&&y%100!=0)||y%400==0)
	k=1;
	return k;
}
void shuchu(int m,int xingqinian,int k)
{
	int t=0,d=0,x=0,j;
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    for(j=1;j<=31;j++){
    	t++;
    	printf("%d\t",j);
    	if(t==(7-xingqinian)){
		printf("\n");
    	x=1;
    }
        	if(x==1)
    	d++;
    	if((d-1)%7==0&&x==1&&d!=1)
    	printf("\n");
	} 
    else if(m==4||m==6||m==9||m==11)
        for(j=1;j<=30;j++){
    	t++;
    	printf("%d\t",j);
    	if(t==(7-xingqinian)){
    	printf("\n");
    	x=1;
    }
    	if(x==1)
    	d++;
    	if((d-1)%7==0&&x==1&&d!=1)
    	printf("\n");
	} 
    else if(m==2&&k==0)
        for(j=1;j<=28;j++){
    	t++;
    	printf("%d\t",j);
    	if(t==(7-xingqinian)){
    	printf("\n");
    	x=1;
    }
        	if(x==1)
    	d++;
    	if((d-1)%7==0&&x==1&&d!=1)
    	printf("\n");
	} 
    else if(m==2&&k==1)
        for(j=1;j<=29;j++){
    	t++;
    	printf("%d\t",j);
    	if(t==(7-xingqinian)){
    	printf("\n");	
    	x=1;
    }
        	if(x==1)
    	d++;
    	if((d-1)%7==0&&x==1&&d!=1)
    	printf("\n");
	} 
	printf("\n"); 
}
