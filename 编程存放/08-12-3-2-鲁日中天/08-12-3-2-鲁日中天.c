#include<stdio.h>
#include<string.h> 
#define START 0//��ʼ��
#define p1 1//���ڱ����пո�֮ǰ�������ַ��� 
#define p2 2//�жϱ����ĵ�һ���ַ��Ƿ�ϸ� �� 
#define p3 3//�ж��ַ���֮����'='����';'���ж�';'֮����û���쳣�ַ�. 
#define p4 4//�ж�'='֮����ַ������ж��Ƿ�Υ�档 
#define END 5//������ 
main ()
{
	int i=1,state=0,zhishi=1;
	char temp,str[100],ch;
	//�Ƚ����ַ������롣
	printf("Please input a string:");
	gets(str);
	ch==str[0];
	while(ch){
		switch(state){
			case START:state=1;
					break;
					
			case p1:while(ch!=' '&&ch!='\0'){
					ch=str[i];
					i++;	
				}
				if(ch=='\0'){
					zhishi=0;
					state=END;
				}
				else {
				  i++;
				  ch=str[i];
				  while(ch==' '){
				  	i++;
				  ch=str[i];
				  }
				  state=p2;
			}
				  break;
				  
			case p2:if(!(ch=='_'||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))){
						state=END;
						zhishi=0; 
						break;
			}
					else {
						i++;
						ch=str[i];
						state=p3;
						break;
					}
					
			case p3:while(ch!='='||ch!=';'){
						if(!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')||ch=='_')){
							state=END;
							zhishi=0;
							break;
						}
						else {
						i++;
						ch=str[i];
						
						while(ch==' '){
				  	i++;
				  ch=str[i];
				  }
				  if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')||ch=='_'){
				  			state=END;
							zhishi=0;
							break;
				  }
						
						if(ch==';') {
							i++;
							ch=str[i];
							if(str[i]!='\0')
							zhishi=0;
							state=END;
							break;
						}
						if(ch=='='){
							i++;
							ch=str[i];
							while(ch==' '){
				  	i++;
				  ch=str[i];
				  }
							if(ch==';') {
							zhishi=0;
							state=END;
							i++;
							ch=str[i];
							break;
						}
						else{
						state=p4;
						break;
					}
						} 
					}
				}
					state=p4;
					break;
					
			case p4:while(ch!=';'){
				while(ch==' '){
				  	i++;
				  ch=str[i];
				  }
				if(!(ch<='9'&&ch>='0')){
					state=END;
					zhishi=0;
					break;
				}
				else {
						i++;
						ch=str[i];
					}
					while(ch==' '){
				  	i++;
				  ch=str[i];
				  }
			}
			
				i++;
				ch=str[i];
				if(str[i]!='\0')
				zhishi=0;		
				state=END;
			break;
			case END:ch='\0';
					break;			
			
	}
}
	if(zhishi==0)
	printf("The result is:NO.\n");
	else 
	printf("The result is:YES.\n");
}
