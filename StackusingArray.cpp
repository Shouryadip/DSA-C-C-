#include<iostream>
#include<stdlib.h>
#define max_size 6
using namespace std;
class Stack{
	private:
		int size;
		int a[max_size];
		int top;
	public:
		Stack(){
			top=-1;
		}
		bool isEmpty(){
			if(top==-1){
				return true;
			}
			else{
				return false;
			}
		}
		bool isFull(){
			if(top==max_size-1){
				return true;
			}
			else{
				return false;
			}
		}
		void push(int n){
			if(isFull()){
				cout<<"Stack is overflow"<<endl;
			}
			else{
				a[top+1]=n;
				top++;
			}
		}
		void pop(){
			if(isEmpty()){
				cout<<"Stack is underflow"<<endl;
			}
			else{
				top=top-1;
				cout<<"popped "<<a[top-1]<<endl;
			}
		}
		int peek(){
		/*	if(isEmpty()){
				cout<<"Stack is Empty"<<endl;
				return a[top];
			}
			else{
				return -1;
			}*/
			;
		}
		void display(){
			for(int i=peek();i>=0;i--){
				cout<<a[i]<<endl;	
		}
		}
};
int main(){
	Stack c;
	cout<<"MENU"<<endl;
	cout<<"1.push"<<endl;
	cout<<"2.pop"<<endl;
	cout<<"3.peek"<<endl;
	cout<<"4.display"<<endl;
	cout<<"5.Exit"<<endl;
int ch;
	do{
		cout<<"Enter Choice"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				int x;
				cout<<"Enter the elemets to push"<<endl;	
				cin >> x;
				c.push(x);
				break;
			case 2:
				c.pop();
				break;
			case 3:
				cout<<"Top element:"<<c.peek()<<endl;
				break;
			case 4:
				cout<<"The stack is"<<endl;
				c.display();
				break;
			case 5:
				exit(0);
		}
	}
	while(ch!=5);
	return 0;
}
