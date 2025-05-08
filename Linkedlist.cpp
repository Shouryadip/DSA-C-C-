#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int value){
			data=value;
			next=NULL;
		}
};
class Linkedlist{
	Node *head;
	public:
		Linkedlist(){
			head=NULL;
		}
	void insertAtBeggining(int value){
		Node *newNode=new Node(value);
		newNode->next=head;
		head=newNode;
		cout<<"Inserted"<<value<<"at the beggining\n";
	}
	void insertAtEnd(int value){
		Node *newNode=new Node(value);
		if(!head){
			newNode->next=head;
			head=newNode;
			cout<<"Inserted"<<value<<"at the end\n";
			return;
		}
		else{
			Node *temp=head;
			while(temp->next){
			temp=temp->next;
			}
			temp->next=newNode;
			cout<<"Inserted"<<value<<"at the end\n";
		}
	}
	void deletefromBeggining(){
		if(!head){
			cout<<"Empty list\n";
			return;
		}
		Node *temp=head;
		head=head->next;
		delete temp;
	}
	void deletefromEnd(){
		if(!head){
			cout<<"Empty List\n";
			return;
		}
		Node *temp=head;
		Node *p=NULL;
		while(temp->next){
			p=temp;
			temp=temp->next;
		}
		p->next=temp->next;
		delete temp;
	}
	void display(){
		if(head==NULL)
		return;
		Node *temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	void search(int value){
		if(!head){
			cout<<"List is empty\n";
			return;
		}
		Node *temp=head;
		while(temp){
			if(temp->data==value){
				cout<<"Number is found\n";
				return;
			}
			temp=temp->next;
		}
		cout<<"Number is not found\n";
		return;
	}
	void reverse(){
		Node *p=head, *q,*r=NULL;
		while(p){
			q=p;
			p=p->next;
			q->next=r;
			r=q;
		}
		head=q;
	}
};
int main(){
	Linkedlist l;
	int c,val;
	do{
		cout<<"1.insert at begin"<<endl;
		cout<<"2.insert at end"<<endl;
		cout<<"3.delete at begin"<<endl;
		cout<<"4.delete at end"<<endl;
		cout<<"5.display"<<endl;
		cout<<"6.search"<<endl;
		cout<<"7.reverse"<<endl;
		cout<<"8.exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>c;
		switch(c){
			case 1:
				cout<<"Enter value"<<endl;
				cin>>val;
				l.insertAtBeggining(val);
				break;
			case 2:
				cout<<"Enter value"<<endl;
				cin>>val;
				l.insertAtEnd(val);
				break;
			case 3:
				l.deletefromBeggining();
				break;
			case 4:
				l.deletefromEnd();
				break;
			case 5:
				cout<<"List is"<<endl;
				l.display();
				break;
			case 6:
				int num;
				cout<<"enter num to search"<<endl;
				cin>>num;
				l.search(num);
				break;
			case 7:
				l.reverse();
				cout<<"After reverse List"<<endl;
				l.display();
				break;
			case 8:
				break;
		}
	}
	while(c!=8);
	return 0;
}
