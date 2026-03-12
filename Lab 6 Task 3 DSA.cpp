#include<iostream>
#include<string>
using namespace std;

class Book
{
private:
    string id,name,author,isbn;
    double price;

public:
    Book(){}

    Book(string i,string n,double p,string a,string is)
    {
        id=i;
        name=n;
        price=p;
        author=a;
        isbn=is;
    }

    string getId()
    {
        return id;
    }

    void setBook(string i,string n,double p,string a,string is)
    {
        id=i;
        name=n;
        price=p;
        author=a;
        isbn=is;
    }

    void display()
    {
        cout<<"ID: "<<id<<"  Name: "<<name<<"  Price: "<<price
        <<"  Author: "<<author<<"  ISBN: "<<isbn<<endl;
    }
};

class Node
{
public:
    Book data;
    Node *next,*prev;

    Node(Book b)
    {
        data=b;
        next=prev=NULL;
    }
};

class BookList
{
private:
    Node* head;

public:
    BookList()
    {
        head=NULL;
    }

    void addBook(string id,string name,double price,string author,string isbn)
    {
        Book b(id,name,price,author,isbn);
        Node* newNode=new Node(b);

        if(head==NULL)
        {
            head=newNode;
            head->next=head;
            head->prev=head;
        }
        else
        {
            Node* tail=head->prev;

            tail->next=newNode;
            newNode->prev=tail;
            newNode->next=head;
            head->prev=newNode;
        }

        cout<<"Book added successfully\n";
    }

    void removeBook(string id)
    {
        Node* temp=head;

        if(head==NULL)
        {
            cout<<"List empty\n";
            return;
        }

        do
        {
            if(temp->data.getId()==id)
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;

                if(temp==head)
                    head=temp->next;

                delete temp;

                cout<<"Book deleted successfully\n";
                return;
            }

            temp=temp->next;
        }
        while(temp!=head);

        cout<<"Invalid book id\n";
    }

    void updateBook(string id,string name,double price,string author,string isbn)
    {
        Node* temp=head;

        do
        {
            if(temp->data.getId()==id)
            {
                temp->data.setBook(id,name,price,author,isbn);
                cout<<"Book updated successfully\n";
                return;
            }

            temp=temp->next;
        }
        while(temp!=head);

        cout<<"Book not found\n";
    }

    void printBooks()
    {
        if(head==NULL)
        {
            cout<<"No books\n";
            return;
        }

        Node* temp=head;

        do
        {
            temp->data.display();
            temp=temp->next;
        }
        while(temp!=head);
    }

    void printBook(string id)
    {
        Node* temp=head;

        do
        {
            if(temp->data.getId()==id)
            {
                temp->data.display();
                return;
            }

            temp=temp->next;
        }
        while(temp!=head);

        cout<<"Book not found\n";
    }
};

int main()
{
    BookList b;

    b.addBook("1","C++",500,"Haris","501");
    b.addBook("2","Java",600,"Mehak","312");
    b.addBook("3","Python",550,"Ahmed","322");
    b.addBook("4","DSA",700,"Usman","494");
    b.addBook("5","AI",800,"Ayesha","125");
    b.addBook("6","ML",750,"Zara","346");
    b.addBook("7","DBMS",650,"Ali","997");
    b.addBook("8","OS",680,"Sara","848");
    b.addBook("9","Networks",720,"Hamza","939");
    b.addBook("10","Security",900,"Fatima","101");

    cout<<"\nPrint one book\n";
    b.printBook("3");

    cout<<"\nDelete books\n";
    b.removeBook("7");
    b.removeBook("939");

    cout<<"\nAll books\n";
    b.printBooks();

    cout<<"\nUpdate book\n";
    b.updateBook("2","Advanced Java",312,"Mehak","2242");

    cout<<"\nUpdated book\n";
    b.printBook("2");
}
