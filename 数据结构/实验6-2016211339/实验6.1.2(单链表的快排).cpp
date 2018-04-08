#include<iostream>
#include<string.h>
#include<stdio.h> 
#include<stdlib.h>

using namespace std ;

class student{  //����һ��ѧ���� 
	private:
		int id ; //ѧ������ 
		string name ; //�������� 
		int score ; //�������� 
		
	public:
		student *next = NULL ; //����ָ����һ��ѧ��(����)
		
		void set_id(){ //��������id�ĺ��� 
			cin>>id ;
		}
		
		void set_name(){ //�������name�ĺ��� 
			cin>>name ;
		}
		
		void set_score(){ //�������÷��� 
			cin>>score ;
		}
		
		void set_id2(int id2){ //����������id�ĺ��� 
			this->id = id2 ;
		}
		
		void set_name2(string name2){ //��������name�ĺ��� 
			this->name = name2 ;
		}
		
		void set_score2(int score2){  //�������÷��� 
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
		
		student(){ //���캯�� 
			next = NULL ;
		}		
};

void set_data(student *head) ; //�����ݴ洢��������
void sort(student *head , student *last) ; //�������н��п�����������
student *GetPartion(student *head , student *last) ; //����ʱ�������м�¼��ʹ�����¼��λ 
void swap(student *head , student *last) ; //�������� 
void save(student *head , student students[10000] , int n) ; //�������е����ݴ�����������
void search(student students[10000] , int n , int key) ; //�۰����

main(){
	int n ; //����������Ҫ�����ѧ����Ŀ
	
	cout<<"��������Ҫ�����ѧ����Ŀ"<<endl ;
	cin>>n ;
	
	student *head ; //ָ������ͷ����ָ��
	student *last , *header ; //���������õ�. 
	
	student students[n] ; //���������ź����ѧ������
	head =new student() ;//��������ͷ���
	
	cout<<"����������ѧ���� ѧ�� �� ���� �� ������Ȼ��س�"<<endl ;
	for(int i = 0 ; i < n ; i++){
		set_data(head) ;
	}
	
	header = head->next ; 
	
	sort(header , NULL) ; //�������� 
	save(head , students , n) ; //���䴢���������� 
	
	
	int order = 1 ; //����ָʾ���� 
	while(1){
	 	cout<<"����������Ҫ���ҵķ���(����Ҫ�˳�ʱ����-1)"<<endl ;
	 	
	 	cin>>order ; //�������
		 if(order!= -1){
	 		search(students , n , order) ;
	 	}else{
	 		break ;
		 }
	 }
	 
	 cout<<"ллʹ�ã��ټ�"<<endl ; 
}

void set_data(student *head){ //�������ݵĺ���
	student *temp ;
	temp = new student() ; //����һ���µĽڵ�
	temp->set_id() ;
	temp->set_name() ;
	temp->set_score() ;
	
	temp->next = head->next ;
	head->next = temp ;
	temp = NULL ;
}

void swap(student *head , student *last){ //�������� 
	int id =  head->get_id() ;  //���������м��ݴ���� 
	string name = head->get_name() ;
	int score = head->get_score() ;
	
	head->set_id2(last->get_id()) ;
	head->set_name2(last->get_name()) ;
	head->set_score2(last->get_score()) ;
	
	last->set_id2(id) ;
	last->set_name2(name) ;
	last->set_score2(score) ;
	
} 

student *GetPartion(student *head , student *last){ //����ʱ�������м�¼��ʹ�����¼��λ 

	/*
	ԭ��
	 
	����ָ��p��q��������ָ�����next�����ƶ����ƶ��Ĺ����б���p֮ǰ��key��С��ѡ����key��
	p��q֮���key������ѡ����key����ô��q�ߵ�ĩβ��ʱ��������һ��֧���Ѱ�ҡ�
	*/ 
	
	int key = head->get_score() ;
	student *p = head ;
	student *q = head->next ;
	
	while(q != last){
		if(q->get_score() < key){
			p = p->next ;
			swap(p , q) ;
		}
		q = q->next ;
	}
	swap(head , p) ;
	return p ;
	 
} 

void sort(student *head , student *last) {//�������н��п�������
	if(head != last)
	{
		student *partion = GetPartion(head , last);
		sort(head , partion);
		sort(partion->next , last);
	}
	
}	

void save(student *head , student students[10000] , int n) {	//�������е����ݴ�����������

	student *p = head->next ;
	
	for(int i = 0 ; i < n ; i++){
		students[i].set_id2(p->get_id()) ;
		students[i].set_name2(p->get_name()) ;
		students[i].set_score2(p->get_score()) ;
		
		p = p->next ;
	}
}
 
void search(student students[10000] , int n , int key) {	//�۰����

	int low = 0, high = n-1 , mid ;
	
	while(low <= high){
		mid = ((low + high)/2) ;
		if(key < students[mid].get_score()){
			high = mid - 1 ;
		}
		else if(key > students[mid].get_score()){
			low = mid + 1 ;
		}
		else{ //���涼���ҵ���Ȼ������Ĵ��� 
			cout<<"λ��Ϊ  "<<mid+1<<"  " ; //��ʾ�ҵ��˸�λ�� 
			int temp1 = mid-1 , temp2 = mid + 1 ;
			if(students[temp1].get_score()==key)
				cout<<temp1+1<<"  " ;
			if(students[temp2].get_score()==key)
				cout<<temp2+1<<"  " ;
			
			cout<<endl ;
			
			cout<<"ѧ��\t����\t�÷�\t"<<endl ;
			cout<<students[mid].get_id()<<"\t"<<students[mid].get_name()<<"\t"<<students[mid].get_score()<<endl ;
			if(students[temp1].get_score()==key)
				cout<<students[temp1].get_id()<<"\t"<<students[temp1].get_name()<<"\t"<<students[temp1].get_score()<<endl ;
			if(students[temp2].get_score()==key)
				cout<<students[temp2].get_id()<<"\t"<<students[temp2].get_name()<<"\t"<<students[temp2].get_score()<<endl ;
			return ;
		}
	}
	cout<<"δ�ҵ��÷���"<<endl ; //ѭ����������û���ҵ� 
} 

