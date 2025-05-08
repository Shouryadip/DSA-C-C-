#include<iostream>
using namespace std;
class Node{
	public:
		Node *prev;
		int data;
		Node *next;
		Node(int d){
			prev=NULL;
			data=d;
			next=NULL;
		}
};
class DLL{
	Node *head;
	public:
		DLL(){
			head=NULL;
		}
		void insertAtBeggining(int value){
			Node *newNode=new Node(value);
			if(!head){
				newNode->next=head;
				head=newNode;
				return;
			}
			head->prev=newNode;
			newNode->next=head;
			head=newNode;
			return;
		} 
		void insertAtEnd(int value){
			Node *newNode=new Node(value);
			if(!head){
				newNode->next=head;
				head=newNode;
				return;
			}
			Node *temp=head;
			while(temp->next){
				temp=temp->next;
			}
				temp->next=newNode;
				newNode->prev=temp;
				return;
		}
		void display(){
			if(!head){
				cout<<"Empty Linkedlist\n";
				return;
			}
			Node *temp=head;
			while(temp->next){
				cout<<temp->data<<"->";
				temp=temp->next;
			}
			cout<<temp->data<<"\n";
			return;
		}
		void delBeg(){
			if(!head){
				cout<<"List Empty\n";
				return;
			}
			if(!head->next){
				delete head;
				head=NULL;
				return;
			}
			Node *temp=head;
			head=head->next;
			temp->next=NULL;
			head->prev=NULL;
			cout<<"Deleted:"<<temp->data<<endl;
			delete temp;
			return;
		}
		void delEnd(){
			if(!head){
				cout<<"Empty List\n";
				return;
			}
			if(!head->next){
				delete head;
				head=NULL;
				return;
			}
			Node *temp=head;
			while(temp->next->next){
				temp=temp->next;
			}
			Node *temp2=temp->next;
			temp2->prev=NULL;
			temp->next=NULL;
			cout<<"Deleted"<<temp2->data<<endl;
			delete temp2;
			return;
		}
};
