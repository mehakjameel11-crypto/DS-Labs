#include <iostream>
using namespace std;

// Inventory class
class Inventory {
public:
    int serialNum;
    int manufactYear;
    int lotNum;

    // Constructor to initialize
    Inventory(int s = 0, int y = 0, int l = 0) {
        serialNum = s;
        manufactYear = y;
        lotNum = l;
    }

    // Display part info
    void display() {
        cout << "Serial Number: " << serialNum << ", Manufacturing Year: " << manufactYear << ", Lot Number: " << lotNum << endl;
    }
};

// Node class for stack
class Node {
public:
    Inventory part;
    Node* next;

    Node(Inventory p) {
        part = p;
        next = nullptr;
    }
};

// Stack class
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push a part
    void push(int s, int y, int l) {
        Inventory p(s, y, l);
        Node* node = new Node(p);
        node->next = top;
        top = node;
        cout << "Part added to inventory.\n";
    }

    // Pop a part
    void pop() {
        if (top == nullptr) {
            cout << "Inventory is empty. No part to remove.\n";
            return;
        }
        cout << "Part removed:\n";
        top->part.display();
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Display remaining parts
    void displayAll() {
        if (top == nullptr) {
            cout << "No parts left in inventory.\n";
            return;
        }
        cout << "\nParts remaining in inventory:\n";
        Node* temp = top;
        while (temp != nullptr) {
            temp->part.display();
            temp = temp->next;
        }
    }
};

int main() {
    Stack inventoryStack;
    int choice;

    while (true) {
        cout << "\nInventory Menu:\n";
        cout << "1. Add part to inventory\n";
        cout << "2. Take part from inventory\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int s, y, l;
            cout << "Enter Serial Number: ";
            cin >> s;
            cout << "Enter Manufacturing Year: ";
            cin >> y;
            cout << "Enter Lot Number: ";
            cin >> l;
            inventoryStack.push(s, y, l);
        }
        else if (choice == 2) {
            inventoryStack.pop();
        }
        else if (choice == 3) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    inventoryStack.displayAll();
    return 0;
}
