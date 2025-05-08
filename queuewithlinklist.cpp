#include <iostream>
// Node class for linked list
class Node {
public:
    int data;
    Node* next;
	Node* NULLptr;
    Node(int value) {
        data = value;
        next = NULLptr;
    }
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;
	Node* NULLptr;
public:
    Queue() {
        front = rear = NULLptr;
    }

    // Function to enqueue an element
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == NULLptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to dequeue an element
    void dequeue() {
        if (front == NULLptr) {
            std::cout << "Queue is empty.\n";
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == NULLptr) {
                rear = NULLptr;
            }
        }
    }

    // Function to display the front element of the queue
    void frontElement() {
        if (front == NULLptr) {
            std::cout << "Queue is empty.\n";
        } else {
            std::cout << "Front element: " << front->data << "\n";
        }
    }

    // Function to display the queue
    void display() {
        if (front == NULLptr) {
            std::cout << "Queue is empty.\n";
        } else {
            Node* temp = front;
            while (temp != NULLptr) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << "\n";
        }
    }
};

int main() {
    Queue myQueue;

    // Enqueue elements
    int n, value , choice;
    
    do{
    	std::cout<<"\t :Queue Menu:"<<std::endl;
    	std::cout<<"\t 1.Enqueue:"<<std::endl;
    	std::cout<<"\t 2.Dequeue:"<<std::endl;
    	std::cout<<"\t 3.Display:"<<std::endl;
    	std::cout<<"\t 4.Front element:"<<std::endl;
    	std::cout<<"\t 5.Exiting from the pogramn: "<<std::endl;
    	std::cout <<"\t Enter your choice: ";
    	std::cin >> choice;
    	
    	switch (choice) {
    	case 1:
    		std::cout << "Enter the number of elements to enqueue: ";
    		std::cin >> n;
			std::cout << "Enter " << n << " elements:\n";
    		for (int i = 0; i < n; ++i) {
        	std::cin >> value;
        	myQueue.enqueue(value);
    		}
    		break;
        case 2:
        	// Dequeue elements
   			int m;
   			std::cout << "Enter the number of elements to dequeue: ";
    		std::cin >> m;
			std::cout << "Dequeuing " << m << " elements:\n";
    		for (int i = 0; i < m; ++i){
        	myQueue.dequeue();
        	}
        	break;        
        case 3:
        	// Display the queue
   			 std::cout << "Queue elements: ";
    		myQueue.display();
    		break;    		
    	case 4:
    		// Front element
   			std::cout<<"The front elements is: ";
    		myQueue.frontElement();
    		break;    	
    	case 5:
    		std::cout << "Exiting program." <<std::endl;
            break;            
        default:
        	std::cout << "Invalid choice. Please enter a valid option." <<std::endl;
        	break;
   	}
    }while(choice != 5);
	return 0;
}
