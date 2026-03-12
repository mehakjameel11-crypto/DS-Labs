#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class CircularList
{
private:
    Node* head;

public:
    CircularList()
    {
        head = NULL;
    }
 
    void InsertBefore(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;

        if(head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* temp = head;

            while(temp->next != head)
            {
                temp = temp->next;
            }

            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }
 
    void InsertAfter(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;

        if(head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* temp = head;

            while(temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }
 
    void Delete(int value)
    {
        if(head == NULL)
        {
            cout<<"List is empty\n";
            return;
        }

        Node *curr = head, *prev = NULL;
 
        if(curr->data == value)
        {
            Node* temp = head;

            while(temp->next != head)
            {
                temp = temp->next;
            }

            if(temp == head)
            {
                head = NULL;
            }
            else
            {
                temp->next = head->next;
                head = head->next;
            }

            delete curr;
            return;
        }

        prev = curr;
        curr = curr->next;

        while(curr != head)
        {
            if(curr->data == value)
            {
                prev->next = curr->next;
                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next;
        }

        cout<<"Node not found\n";
    }
 
    void Display()
    {
        if(head == NULL)
        {
            cout<<"List empty\n";
            return;
        }

        Node* temp = head;

        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        while(temp != head);

        cout<<endl;
    }
};

int main()
{
    CircularList obj;

    obj.InsertBefore(30);
    obj.InsertBefore(6);

    obj.InsertAfter(10);
    obj.InsertAfter(50);

    cout<<"Circular Linked List:\n";
    obj.Display();

    obj.Delete(6);

    cout<<"After Deletion:\n";
    obj.Display();

    return 0;
}
