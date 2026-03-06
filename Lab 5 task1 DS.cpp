#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void insert(int x){
    Node* n = new Node{x,NULL,NULL};

    if(head==NULL){
        head=n;
        return;
    }

    Node* t=head;
    while(t->next!=NULL)
        t=t->next;

    t->next=n;
    n->prev=t;
}

void addAtBeginning(int x){
    Node* n = new Node{x,head,NULL};
    if(head!=NULL)
        head->prev=n;
    head=n;
}

void addAfter45(int x){
    Node* t=head;
    while(t!=NULL && t->data!=45)
        t=t->next;

    if(t!=NULL){
        Node* n=new Node{x,t->next,t};
        if(t->next!=NULL)
            t->next->prev=n;
        t->next=n;
    }
}

void deleteFromBeginning(){
    if(head==NULL) return;

    Node* t=head;
    head=head->next;

    if(head!=NULL)
        head->prev=NULL;

    delete t;
}

void deleteAfter45(){
    Node* t=head;

    while(t!=NULL && t->data!=45)
        t=t->next;

    if(t!=NULL && t->next!=NULL){
        Node* d=t->next;
        t->next=d->next;
        if(d->next!=NULL)
            d->next->prev=t;
        delete d;
    }
}

void display(){
    Node* t=head;
    while(t!=NULL){
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
}

int main(){

    insert(1);
    insert(45);
    insert(60);
    insert(12);

    display();

    addAtBeginning(100);
    display();

    addAfter45(200);
    display();

    deleteFromBeginning();
    display();

    deleteAfter45();
    display();
}
