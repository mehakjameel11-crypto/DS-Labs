#include <iostream>
using namespace std;
 
class Book {
public:
    string title;
    double price;
    string edition;
    int pages;
 
    Book(string t = "", double p = 0.0, string e = "", int pg = 0) {
        title = t;
        price = p;
        edition = e;
        pages = pg;
    }
 
    void display() {
        cout << "Title: " << title
             << ", Price: $" << price
             << ", Edition: " << edition
             << ", Pages: " << pages << endl;
    }
};
 
class Node {
public:
    Book book;
    Node* next;

    Node(Book b) {
        book = b;
        next = nullptr;
    }
};
 
class Stack {
private:
    Node* top;   

public:
    Stack() {
        top = nullptr;
    }
 
    void push(Book b) {
        Node* newNode = new Node(b);
        newNode->next = top;
        top = newNode;
        cout << "Pushed book: " << b.title << endl;
    }
 
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty! Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        cout << "Popped book: " << top->book.title << endl;
        top = top->next;
        delete temp;
    }
 
    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty! Nothing to peek." << endl;
            return;
        }
        cout << "Top book is: " << top->book.title << endl;
    }
 
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        cout << "\nBooks in stack:\n";
        while (temp != nullptr) {
            temp->book.display();
            temp = temp->next;
        }
    }
};

int main() {
    Stack stack;
 
    stack.push(Book("Java Basics", 350, "2nd", 200));
    stack.push(Book("Data Structures", 500, "1st", 250));
    stack.push(Book("Algorithms", 600, "3rd", 500));
    stack.push(Book("Python Concepts", 400, "1st", 300));
    stack.push(Book("Database Systems", 550, "2nd", 100));
 
    stack.peek();
    stack.pop();
    stack.pop();
    stack.display();

    return 0;
}
