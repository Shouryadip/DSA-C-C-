#include<iostream>
using namespace std;
// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node* NULLptr;
    Node(int value) : data(value), next(NULLptr){}
};

// Linked list class
class LinkedList {
private:
    Node* head;
	Node* NULLptr;
public:
    LinkedList() : head(NULLptr) {}

    // Function to insert a node at the end of the linked list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to delete a node with a given value from the linked list
    void remove(int value) {
        Node* current = head;
        Node* previous = NULLptr;

        while (current && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (!current) {
            cout << "Element not found in the list." << endl;
            return;
        }

        if (!previous) {
            head = current->next;
        } else {
            previous->next = current->next;
        }

        delete current;
        cout << "Element " << value << " deleted from the list." << endl;
    }

    // Function to traverse and display the elements of the linked list
    void traverse() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to search for a node with a given value in the linked list
    bool search(int value) {
        Node* temp = head;
        while (temp) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

int main() {
    LinkedList linkedList;

    int choice, value;

    do {
        cout << "1. Insert\n2. Delete\n3. Traverse\n4. Search\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                linkedList.insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                linkedList.remove(value);
                break;
            case 3:
                cout << "Linked List: ";
                linkedList.traverse();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (linkedList.search(value)) {
                    cout << "Element found in the list." << endl;
                } else {
                    cout << "Element not found in the list." << endl;
                }
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 0);
    return 0;
}
