#include<iostream>
#include<string.h>
#include<stdio.h> 
#include<stdlib.h>

using namespace std ;

class student{  //定义一个学生类 
	private:
		int id ; //学号属性 
		string name ; //姓名属性 
		int score ; //分数属性 
		
	public:
		student *next = NULL ; //用来指向下一个学生(链表)
		student *pre = NULL ; //用来指向前一个学生 
		
		void set_id(){ //链表设置id的函数 
			cin>>id ;
		}
		
		void set_name(){ //李彪设置name的函数 
			cin>>name ;
		}
		
		void set_score(){ //链表设置分数 
			cin>>score ;
		}
		
		void set_id2(int id2){ //数组中设置id的函数 
			this->id = id2 ;
		}
		
		void set_name2(string name2){ //数组设置name的函数 
			this->name = name2 ;
		}
		
		void set_score2(int score2){  //数组设置分数 
			this->score = score2 ;
		}
		
		int get_id(){
			return id ;
		}
		
		string get_name(){
			return name ;
		}
		
		int get_score(){
			return score ;
		}
		
		student(){ //构造函数 
			next = NULL ;
			pre = NULL ;
		}		
};

void set_data(student *head) ; //将数据存储入链表中
void sort(student *head , student *last) ; //在链表中进行快速排序排序
student *GetPartion(student *head , student *last) ; //快排时交换表中记录，使枢轴记录到位 
void swap(student *head , student *last) ; //交换函数 
void save(student *head , student students[10000] , int n) ; //将链表中的数据储存在数组中
void search(student students[10000] , int n , int key) ; //折半查找

main(){
	int n ; //用来保存需要输入的学生数目
	
	cout<<"请输入需要保存的学生数目"<<endl ;
	cin>>n ;
	
	if(n == 0){
		cout<<"不输入学生信息，程序退出" <<endl ;
		exit(0) ;
	}
	
	student *head ; //指向链表头结点的指针
	student *last , *header ; //快速排序用的. 
	
	student students[n] ; //用来储存排好序的学生数组
	head =new student() ;//创建链表头结点
	
	cout<<"请依次输入学生的 学号 ， 姓名 ， 分数，然后回车"<<endl ;
	for(int i = 0 ; i < n ; i++){
		set_data(head) ;
	}
	
	
	header = head->next ; 
	last = header ;
	
	
	while(last->next)
		last = last->next ; //得到最后一个节点 
		
	sort(header , last) ; //对其排序 
	
	
	save(head , students , n) ; //将其储存在数组中 

	
	
	int order = 1 ; //输入指示分数 
	while(1){
	 	cout<<"请输入你需要查找的分数(当需要退出时输入-1)"<<endl ;
	 	
	 	cin>>order ; //输入分数
		 if(order!= -1){
	 		search(students , n , order) ;
	 	}else{
	 		break ;
		 }
	 }
	 
	 cout<<"谢谢使用，再见"<<endl ; 
}

void set_data(student *head){ //设置数据的函数
	student *temp ;
	temp = new student() ; //申请一个新的节点
	temp->set_id() ;
	temp->set_name() ;
	temp->set_score() ;
	
	temp->next = head->next ;
	head->next = temp ;
	if(head->next->next){
		head->next->next->pre = temp ;
	}
	temp = NULL ;
}

void swap(student *head , student *last){ //交换函数 
	int id =  head->get_id() ;  //设置三个中间暂存变量 
	string name = head->get_name() ;
	int score = head->get_score() ;
	
	head->set_id2(last->get_id()) ;
	head->set_name2(last->get_name()) ;
	head->set_score2(last->get_score()) ;
	
	last->set_id2(id) ;
	last->set_name2(name) ;
	last->set_score2(score) ;
	
} 

student *GetPartion(student *head , student *last){ //快排时交换表中记录，使枢轴记录到位 
	
	int key = head->get_score() ;
	while(head != last){
		while(head != last && last->get_score() >= key){
			last = last->pre ;
		}
		swap(head , last) ;
		
		while(head != last && head->get_score()  <= key){
			head = head->next ;
		}
		swap(head , last) ;
	}

	 return head ;
} 

void sort(student *head , student *last) {//在链表中进行快速排序
	if(head != last)
	{
		student *partion = GetPartion(head , last);
		if(partion != head)
			sort(head , partion->pre);

		if(partion != last)
			sort(partion->next , last);

	}
	
}	

void save(student *head , student students[10000] , int n) {	//将链表中的数据储存在数组中

	student *p = head->next ;
	
	for(int i = 0 ; i < n ; i++){
		students[i].set_id2(p->get_id()) ;
		students[i].set_name2(p->get_name()) ;
		students[i].set_score2(p->get_score()) ;
		
		p = p->next ;
	}
}
 
void search(student students[10000] , int n , int key) {	//折半查找

	int low = 0, high = n-1 , mid ;
	
	while(low <= high){
		mid = ((low + high)/2) ;
		if(key < students[mid].get_score()){
			high = mid - 1 ;
		}
		else if(key > students[mid].get_score()){
			low = mid + 1 ;
		}
		else{ //下面都是找到了然后输出的代码 
			cout<<"位置为  "<<mid+1<<"  " ; //表示找到了该位置 
			int temp1 = mid-1 , temp2 = mid + 1 ;
			if(temp1<n && temp1>=0 && students[temp1].get_score()==key)
				cout<<temp1+1<<"  " ;
			if(temp2<n && temp2>=0 && students[temp2].get_score()==key)
				cout<<temp2+1<<"  " ;
			
			cout<<endl ;
			
			cout<<"学号\t姓名\t得分\t"<<endl ;
			cout<<students[mid].get_id()<<"\t"<<students[mid].get_name()<<"\t"<<students[mid].get_score()<<endl ;
			if(temp1<n && temp1>=0 && students[temp1].get_score()==key)
				cout<<students[temp1].get_id()<<"\t"<<students[temp1].get_name()<<"\t"<<students[temp1].get_score()<<endl ;
			if(temp2<n && temp2>=0 && students[temp2].get_score()==key)
				cout<<students[temp2].get_id()<<"\t"<<students[temp2].get_name()<<"\t"<<students[temp2].get_score()<<endl ;
			return ;
		}
	}
	cout<<"未找到该分数"<<endl ; //循环结束，且没有找到 
} 

