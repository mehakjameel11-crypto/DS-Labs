#include<iostream>
#include<string>
using namespace std;

struct Node
{
    string name;
    Node* next;
};

Node* head = NULL;

// Add Employee
void addEmployee(string name)
{
    Node* newNode = new Node();
    newNode->name = name;

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

    cout<<"Employee added successfully\n";
}

// Delete Employee
void deleteEmployee(string name)
{
    if(head == NULL)
    {
        cout<<"List empty\n";
        return;
    }

    Node *curr = head, *prev = NULL;

    if(curr->name == name)
    {
        Node* temp = head;

        while(temp->next != head)
        {
            temp = temp->next;
        }

        if(temp == head)
            head = NULL;
        else
        {
            temp->next = head->next;
            head = head->next;
        }

        delete curr;
        cout<<"Employee deleted successfully\n";
        return;
    }

    prev = curr;
    curr = curr->next;

    while(curr != head)
    {
        if(curr->name == name)
        {
            prev->next = curr->next;
            delete curr;
            cout<<"Employee deleted successfully\n";
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    cout<<"Employee not found\n";
}

// Search Employee
void searchEmployee(string name)
{
    if(head == NULL)
    {
        cout<<"List empty\n";
        return;
    }

    Node* temp = head;

    do
    {
        if(temp->name == name)
        {
            cout<<"Employee found successfully\n";
            return;
        }

        temp = temp->next;
    }
    while(temp != head);

    cout<<"Employee not found\n";
}

// Update Employee
void updateEmployee(string oldName, string newName)
{
    if(head == NULL)
    {
        cout<<"List empty\n";
        return;
    }

    Node* temp = head;

    do
    {
        if(temp->name == oldName)
        {
            temp->name = newName;
            cout<<"Employee updated successfully\n";
            return;
        }

        temp = temp->next;
    }
    while(temp != head);

    cout<<"Employee not found\n";
}

// Display Employees
void display()
{
    if(head == NULL)
    {
        cout<<"No employees\n";
        return;
    }

    Node* temp = head;

    cout<<"Employee List:\n";

    do
    {
        cout<<temp->name<<" -> ";
        temp = temp->next;
    }
    while(temp != head);

    cout<<"(Back to Head)\n";
}

int main()
{
    int choice;
    string name, newName;

    do
    {
cout<<"1. Add Employee\n";
cout<<"2. Delete Employee\n";
cout<<"3. Search Employee\n";
cout<<"4. Update Employee\n";
cout<<"5. Display\n";
cout<<"6. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice)
        {
    case 1:
                cout<<"Enter name: ";
                cin>>name;
                addEmployee(name);
                break;

    case 2:
                cout<<"Enter name to delete: ";
                cin>>name;
                deleteEmployee(name);
                break;

    case 3:
                cout<<"Enter name to search: ";
                cin>>name;
                searchEmployee(name);
                break;

    case 4:
                cout<<"Enter old name: ";
                cin>>name;
                cout<<"Enter new name: ";
                cin>>newName;
                updateEmployee(name,newName);
                break;

    case 5:
                display();
                break;

        }

    }while(choice != 6);

    return 0;
}
