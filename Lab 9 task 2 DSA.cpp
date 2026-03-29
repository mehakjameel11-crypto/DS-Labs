#include<iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;


void enqueue(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->next = nullptr;

    if(front == nullptr) {   
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    cout << "Inserted: " << val << endl;
}


void dequeue() {
    if(front == nullptr) {
        cout << "Queue Underflow\n";
        return;
    }
    Node* temp = front;
    front = front->next;
    if(front == nullptr) rear = nullptr; 
    cout << "Deleted: " << temp->data << endl;
    delete temp;
}
void display() {
    if(front == nullptr) {
        cout << "Queue is Empty\n";
        return;
    }
    Node* temp = front;
    cout << "Queue Elements: ";
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main menu
int main() {
    int choice, value;
    do {
        cout << "\n1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 4);

    return 0;
}
