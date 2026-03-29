#include<iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value)
{
    if((rear + 1) % SIZE == front)
    {
        cout << "Queue Overflow\n";
    }
    else
    {
        if(front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        queue[rear] = value;

        cout << "Inserted: " << value << endl;
    }
}

// Dequeue
void dequeue()
{
    if(front == -1)
    {
        cout << "Queue Underflow\n";
    }
    else
    {
        cout << "Deleted: " << queue[front] << endl;

        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

// Display
void display()
{
    if(front == -1)
    {
        cout << "Queue is Empty\n";
    }
    else
    {
        cout << "Queue Elements: ";
        int i = front;

        while(true)
        {
            cout << queue[i] << " ";

            if(i == rear)
                break;

            i = (i + 1) % SIZE;
        }

        cout << endl;
    }
}

// Main
int main()
{
    int choice, value;

    do
    {
        cout << "\n1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
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
                cout << "Exit\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 4);

    return 0;
}
