#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int data){
		this->data=data;
		next=NULL;
	}
};
class CLL{
	public:
		Node *head;
		CLL(){
			head=NULL;
		}
		void insertAtBeggining(int data){
			Node *newNode=new Node(data);
			if(!head){
				head=newNode;
				head->next=head;
			}
			else{
				Node *temp=head;
				while(temp->next!=head){
					temp=temp->next;
				}
				temp->next=newNode;
				newNode->next=head;
				head=newNode;
			}
		}
		void insertAtEnd(int data){
			Node *newNode=new Node(data);
			if(!head){
				head=newNode;
				head->next=head;
			}
			if(head->next==head){
				head->next=newNode;
				newNode->next=head;
			}
			else{
				Node *temp=head;
				while(temp->next!=head){
					temp=temp->next;
				}
				temp->next=newNode;
				newNode->next=head;
			}
		}
		void display(){
			if(!head){
				cout<<"Empty List\n";
				return;
			}
			else if(head->next==head){
				cout<<head->data<<"\n";
			}
			else{
				Node *temp=head;
				while(temp->next!=head){
					cout<<temp->data<<"->";
					temp=temp->next;
				}
				cout<<temp->data<<"->"<<head->data<<"\n";
			}
		}
};
int main(){
	CLL c;
	int ch,value;
	do{
		cout<<"1.Insert at Beggining"<<endl;
		cout<<"2.Insert at End"<<endl;
		cout<<"3.Display"<<endl;
		cout<<"Enter your Choice"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter value"<<endl;
				cin>>value;
				c.insertAtBeggining(value);
				break;
			case 2:
				cout<<"Enter the value"<<endl;
				cin>>value;
				c.insertAtEnd(value);
				break;
			case 3:
				cout<<"The List is"<<endl;
				c.display();
				break;
			case 4:
				cout<<"EXITING"<<endl;
		}
	}
	while(ch!=4);
	return 0;
}

