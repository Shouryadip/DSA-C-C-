#include<iostream>
#define MAX_SIZE 10
using namespace std;

class Stack {
private:
    //static const int MAX_SIZE = 10;
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow, cannot push more elements." << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed to the stack." << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow, cannot pop from an empty stack." << endl;
        } else {
            cout << arr[top--] << " popped from the stack." << endl;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
        } else {
            cout << "Top element of the stack: " << arr[top] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; ++i) {
                cout << arr[i] <<" ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                stack.display();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 5);

    return 0;
}
