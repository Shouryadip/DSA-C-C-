#include<iostream>
using namespace std;
#define MAX_SIZE 10
class Queue{
private:
	int front,rear;
	int arr[MAX_SIZE];
public:
	Queue(){
		front=rear=-1;
	}
	bool isEmpty(){
		return (front ==-1||front>rear);
	}
	bool isFull(){
		return (rear==MAX_SIZE-1);
	}
	void enqueue(int data){
		if(isFull()){
			cout<<"The Queue is full"<<endl;
			return;
		}
		if(front==-1){
			front=0;
		}
		else{
			arr[++rear]=data;
			cout<<data<<"Enqueue in queue"<<endl;
		}
	}
	void dequeue(){
		if(isEmpty()){
			cout<<"queue is empty,can't dequeue"<<endl;
			return;
		}
		else{
			cout<<arr[front++]<<"dequeue from the queue<<endl;";
		}
	}
	void peek(){
		if(isEmpty()){
			cout<<"Queue is Empty,Can't peek"<<endl;			
		}
		else{
			cout<<arr[front]<<endl;
		}
	}
	void display(){
		if(isEmpty()){
			cout<<"Queue is empty"<<endl;
			return;
		}
		else{
		cout<<"Queue Elements:";
		for(int i=front;i<=rear;++i){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	}
};
int main(){
	Queue Q1;
		int choice,value;
		do{
			cout<<"1.Enqueue"<<endl;
			cout<<"2.Dequeue"<<endl;
			cout<<"3.peek"<<endl;
			cout<<"4.display"<<endl;
			cout<<"Enter your choice"<<endl;
			cin>>choice;			
			switch(choice){
				case 1:
					cout<<"Enter value to enqueue"<<endl;
					cin>>value;
					Q1.enqueue(value);
					break;
				case 2:
					Q1.dequeue();
					break;
				case 3:
					Q1.peek();
					break;
				case 4:
					Q1.display();
					break;
				case 5:
					cout<<"Exiting"<<endl;
					break;
				}
			}
			while(choice!=5);
			return 0;
}
