#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << ">> Inserted " << value << " at the beginning.\n";
}

void insertEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << ">> Inserted " << value << " at the end.\n";
}

void deleteBeginning() {
    if (head == NULL) {
        cout << "!! List is already empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << ">> Deleted the first node.\n";
}


void deleteEnd() {
    if (head == NULL) {
        cout << "!! List is already empty.\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    cout << ">> Deleted the last node.\n";
}


void search(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << ">> Found " << key << " at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << ">> " << key << " not found in the list.\n";
}


void display() {
    if (head == NULL) {
        cout << "Current List: (Empty)\n";
        return;
    }
    Node* temp = head;
    cout << "Current List: ";
    while (temp != NULL) {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value;

     {
        
        cout << "1. Insert (Start)"<<endl;
        cout << "2. Insert (End)"<<endl;   
        cout << "3. Delete (Start)"<<endl;
		cout<<  "4. Delete (End)"<<endl;
		cout<<  "5. Search"<<endl;
		cout<<  "6. Display"<<endl;
        cout << "7. Exit";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Value to insert: "; cin >> value;
                insertBeginning(value);
                display();
                break;
            case 2:
                cout << "Value to insert: "; cin >> value;
                insertEnd(value);
                display();
                break;
            case 3:
                deleteBeginning();
                display();
                break;
            case 4:
                deleteEnd();
                display();
                break;
            case 5:
                cout << "Value to search: "; cin >> value;
                search(value);
                break;
            case 6:
                display();
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } 

    return 0;
}
