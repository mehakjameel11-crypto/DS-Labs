#include <iostream>
using namespace std;

struct Node {
    string name;
    int age;
    string city;
    Node* next;
};

Node* head = NULL;

int main() {
    int choice;

    do {
        cout << "\n1. Create Profile";
        cout << "\n2. View Profiles";
        cout << "\n3. Search Profile";
        cout << "\n4. Delete Profile";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
 
        if (choice == 1) {
            Node* newNode = new Node();

            cout << "Name: ";
            cin >> newNode->name;
            cout << "Age: ";
            cin >> newNode->age;
            cout << "City: ";
            cin >> newNode->city;

            newNode->next = head;
            head = newNode;

            cout << "Profile created!\n";
        }
 
        else if (choice == 2) {
            Node* temp = head;
            while (temp != NULL) {
                cout << "\nName: " << temp->name;
                cout << "\nAge: " << temp->age;
                cout << "\nCity: " << temp->city << endl;
                temp = temp->next;
            }
        }
 
        else if (choice == 3) {
            string name;
            cout << "Enter name to search: ";
            cin >> name;

            Node* temp = head;
            while (temp != NULL) {
                if (temp->name == name) {
                    cout << "Found! Age: " << temp->age
                         << " City: " << temp->city << endl;
                    break;
                }
                temp = temp->next;
            }
        }
 
        else if (choice == 4) {
            string name;
            cout << "Enter name to delete: ";
            cin >> name;

            Node *temp = head, *prev = NULL;

            while (temp != NULL && temp->name != name) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == NULL) {
                cout << "Not found\n";
            } else {
                if (prev == NULL)
                    head = temp->next;
                else
                    prev->next = temp->next;

                delete temp;
                cout << "Deleted!\n";
            }
        }

    } while (choice != 5);

    return 0;
}