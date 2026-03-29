#include<iostream>
using namespace std;

#define SIZE 100
int queue[SIZE];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value) {
    if(rear == SIZE - 1) {
        cout << "Queue Overflow\n";
    } else {
        if(front == -1) front = 0;
        rear++;
        queue[rear] = value;
        cout << "Inserted: " << value << endl;
    }
}

// Dequeue
void dequeue() {
    if(front == -1 || front > rear) {
        cout << "Queue Underflow\n";
    } else {
        cout << "Deleted: " << queue[front] << endl;
        front++;
        if(front > rear) front = rear = -1; // Queue becomes empty
    }
}

// Display
void display() {
    if(front == -1) {
        cout << "Queue is Empty\n";
    } else {
        cout << "Queue Elements: ";
        for(int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

// Count Elements
int countElements() {
    if(front == -1) return 0;
    return rear - front + 1;
}

// Main Menu
int main() {
    int choice, value;
    do {
        cout << "\n1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Count Elements\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
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
                cout << "Number of elements: " << countElements() << endl;
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 5);

    return 0;
}
