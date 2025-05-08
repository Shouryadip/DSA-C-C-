#include <iostream>
class Node {
public:
    int data;
    Node* next;
    Node* NULLptr;
    // Constructor
    Node(int value) : data(value), next(NULLptr) {}
};

// Stack class using linked list
class Stack {
private:
    Node* top; // Pointer to the top of the stack
	Node* NULLptr;
public:
    // Constructor
    Stack(): top(NULLptr) {}

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == NULLptr;
    }

    // Function to push an element onto the stack
    void push(int value) {
        // Create a new node
        Node* newNode = new Node(value);

        // Set the new node's next pointer to the current top
        newNode->next = top;

        // Set the top pointer to the new node
        top = newNode;
    }

    // Function to pop an element from the stack
    void pop() {
        if (!isEmpty()) {
            // Save the current top node
            Node* temp = top;

            // Move the top pointer to the next node
            top = top->next;

            // Delete the old top node
            delete temp;
        } else {
            std::cout << "Stack is empty. Cannot pop." <<std::endl;
        }
    }

    // Function to get the top element of the stack
    int peek() {
        if (!isEmpty()) {
            return top->data;
        } else {
            std::cout << "Stack is empty. Cannot peek." << std::endl;
            return -1; // Assuming -1 is not a valid element in the stack
        }
    }
    
    void display(){
    	if(isEmpty()){
    		std::cout<<"Stack is empty \n";
    		return;
		}
	Node* current=top;
	std::cout<<"Stack Elements:";
	while(current!= NULLptr){
	std::cout<<current->data<<" ";
		current=current->next;
	}
	std::cout<<std::endl;
	}
};

int main() {
    Stack myStack;

    int choice, value;

    do {
        std::cout << "\t Stack Menu:" <<std::endl;
        std::cout << "\t 1. Push" <<std::endl;
        std::cout << "\t 2. Pop" <<std::endl;
        std::cout << "\t 3. Peek" <<std::endl;
        std::cout << "\t 4. Exit" <<std::endl;
        std::cout << "\t 5. Display" <<std::endl;
        std::cout << "\t Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter a value to push: ";
                std::cin >> value;
                myStack.push(value);
                break;

            case 2:
                myStack.pop();
                break;

            case 3:
                std::cout << "Top element: " << myStack.peek() <<std::endl;
                break;

            case 4:
                std::cout << "Exiting program." <<std::endl;
                break;
            case 5:
             myStack.display();
				break;
            default:
                std::cout << "Invalid choice. Please enter a valid option." <<std::endl;
        }

    } while (choice != 4);

    return 0;
}

