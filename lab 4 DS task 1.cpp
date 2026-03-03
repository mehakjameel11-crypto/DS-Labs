 #include <iostream>
using namespace std;

struct Node {
    string brand;
    int units;
    int price;
    Node* next;
};

Node* head = NULL;

int main() {
    int choice;

    do {
        cout << "\n1. Add Mobile";
        cout << "\n2. Display Mobiles";
        cout << "\n3. Delete Mobile";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
 
        if (choice == 1) {
            Node* newNode = new Node();

            cout << "Brand: ";
            cin >> newNode->brand;
            cout << "Units: ";
            cin >> newNode->units;
            cout << "Price: ";
            cin >> newNode->price;

            newNode->next = head;
            head = newNode;

            cout << "Added!\n";
        }
 
        else if (choice == 2) {
            Node* temp = head;
            while (temp != NULL) {
                cout << "\nBrand: " << temp->brand;
                cout << "\nUnits: " << temp->units;
                cout << "\nPrice: " << temp->price << endl;
                temp = temp->next;
            }
        }

        else if (choice == 3) {
            string name;
            cout << "Enter brand to delete: ";
            cin >> name;

            Node *temp = head, *prev = NULL;

            while (temp != NULL && temp->brand != name) {
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

    } while (choice != 4);

    return 0;
}