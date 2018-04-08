#include<stdio.h>
#include<math.h>
main()
{
	int q,w,e,r,t,y,u,i,o,p;
	float xyi,yyi,xsan,ysan,xba,yba,xjiu,yjiu,xshi,yshi,xzong,yzong,x1,x2,x3,x4,x5,y1,y2,y3,y4,y5;
	float zongjuli,min=999999999;
	printf("请依次输入坐标横纵坐标，中间用空格隔开\n");
	scanf("%f %f %f %f %f %f %f %f %f %f",&xyi,&yyi,&xsan,&ysan,&xba,&yba,&xjiu,&yjiu,&xshi,&yshi);
	for(q=1;q<=5;q++){
		if(q==1){
			x1=xyi;
			y1=yyi;
			} 
			else if(q==2){
			x1=xsan;
			y1=ysan;
		}
			else if(q==3){
			x1=xba;
			y1=yba;
		}
			else if(q==4){
			x1=xjiu;
			y1=yjiu;
		}
			else if(q==5){
			x1=xshi;
			y1=yshi;
		}
			for(w=1;w<=5;w++){
					if(w==1&&q!=1){
			x2=xyi;
			y2=yyi;
			} 
			else if(w==2&&q!=2){
			x2=xsan;
			y2=ysan;
		}
			else if(w==3&&q!=3){
			x2=xba;
			y2=yba;
		}
			else if(w==4&&q!=4){
			x2=xjiu;
			y2=yjiu;
		}
			else if(w==5&&q!=5){
			x2=xshi;
			y2=yshi;
		}
			for(e=1;e<=5;e++){
						if(e==1&&q!=1&&w!=1){
			x3=xyi;
			y3=yyi;
			} 
			else if(e==2&&q!=2&&w!=2){
			x3=xsan;
			y3=ysan;
		}
			else if(e==3&&q!=3&&w!=3){
			x3=xba;
			y3=yba;
		}
			else if(e==4&&q!=4&&w!=4){
			x3=xjiu;
			y3=yjiu;
		}
			else if(e==5&&q!=5&&w!=5){
			x3=xshi;
			y3=yshi;
		}
			for(r=1;r<=5;r++){
					if(r==1&&q!=1&&w!=1&&e!=1){
			x4=xyi;
			y4=yyi;
			} 
			else if(r==2&&q!=2&&w!=2&&e!=2){
			x4=xsan;
			y4=ysan;
		}
			else if(r==3&&q!=3&&w!=3&&e!=3){
			x4=xba;
			y4=yba;
		}
			else if(r==4&&q!=4&&w!=4&&e!=4){
			x4=xjiu;
			y4=yjiu;
		}
			else if(r==5&&q!=5&&w!=5&&e!=5){
			x4=xshi;
			y4=yshi;
		}
			for(t=1;t<=5;t++){
						if(t==1&&q!=1&&w!=1&&e!=1&&r!=1){
			x5=xyi;
			y5=yyi;
			} 
			else if(t==2&&q!=2&&w!=2&&e!=2&&r!=2){
			x5=xsan;
			y5=ysan;
		}
			else if(t==3&&q!=3&&w!=3&&e!=3&&r!=3){
			x5=xba;
			y5=yba;
		}
			else if(t==4&&q!=4&&w!=4&&e!=4&&r!=4){
			x5=xjiu;
			y5=yjiu;
		}
			else if(t==5&&q!=5&&w!=5&&e!=5&&r!=5){
			x5=xshi;
			y5=yshi;
		}
		zongjuli=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))+sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3))+sqrt((x3-x4)*(x3-x4)+(y3-y4)*(y3-y4))+sqrt((x4-x5)*(x4-x5)+(y4-y5)*(y4-y5));
		if(zongjuli<min){
		min=zongjuli;
		y=q;
		u=w;
		i=e;
		o=r;
		p=t;
		
		}
			}
			}
			}
			}
	}
	printf("%d %d %d %d %d\n",y,u,i,o,p);
	printf("%f\n",min); 
 } 

