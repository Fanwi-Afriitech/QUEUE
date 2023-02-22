

#include <iostream>

using namespace  std;

// CODE FOR QUEUE
class link1{
		
	public:
		string name;
		int age;
		double height;
		link1 *pnext;
		link1(string n,int a,double h){
			name=n;
			age=a;
			height=h;
			pnext=NULL;
			
		}
		
		void displays(){
			cout<<"{"<<name<<","<<age<<","<<height<<"}-->";
		}
		
};

class linkedlist{
	private: 
	  link1 *pfirst;
	  link1 *plast;
	public:
		linkedlist(){
			pfirst=NULL;
		}
		
	int enqueue(string n,int a,double h){
		link1 *pnewlink=new link1(n,a,h);
		if(pfirst==NULL){
			pfirst=pnewlink;
			plast=pnewlink;
			return 0;
		}
		else{
			plast->pnext=pnewlink;
			plast=pnewlink;
		}
		return 0;
	
	}
	
	void displayone(){
		link1 *pcurrent =pfirst;
			pcurrent->displays();				
		
	}
	
	void dequeue(){
		pfirst=pfirst->pnext;
	}
	//question 7
	double av_height(){
		link1 *pheight=pfirst;
		double sum=0;
		int c=0;
		while(pheight!=NULL){
			sum=sum+pheight->height;
			c++;
			pheight=pheight->pnext;
		}
		return sum/c;
			
	}
	//question 8
	void atheletes(){
		link1 *page=pfirst;
		while(page!=NULL){
			if(page->age>30){
				page->displays();
			}
			page=page->pnext;
		}
	}

	
};
int main() {
	linkedlist l1;
	l1.enqueue("Fred",34,1.7);
	l1.enqueue("Sue",27,1.2);
	l1.enqueue("Joe",48,1.4);
	l1.enqueue("Zoe",30,1.3);



	
	
	// Question 5
	l1.dequeue();
	l1.dequeue();
	l1.enqueue("Tom",44,1.1);
	l1.dequeue();
	l1.enqueue("Mark",34,1.4);
	l1.enqueue("Anne",24,1.0);
	l1.displayone();
	cout<<"\n The average is "<<l1.av_height()<<endl;
	l1.atheletes();
	
	

}
