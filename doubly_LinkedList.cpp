#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) head->prev = newNode;
    head = newNode;
    cout << "Inserted " << value << " at beginning.\n";
}

void insertEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "Inserted " << value << " at end.\n";
}

void deleteBeginning() {
    if (head == NULL) { cout << "List is empty\n"; return; }
    Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    delete temp;
    cout << "Deleted from beginning\n";
}

void deleteEnd() {
    if (head == NULL) { cout << "List is empty\n"; return; }
    Node* temp = head;
    if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        while (temp->next != NULL) temp = temp->next;
        temp->prev->next = NULL;
        delete temp;
    }
    cout << "Deleted from end\n";
}

void displayForward() {
    if (head == NULL) { cout << "List is empty\n"; return; }
    Node* temp = head;
    cout << "Current List: ";
    while (temp != NULL) {
        cout << temp->data << (temp->next ? " <-> " : "");
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

int main() {
    int choice, value;
    bool running = true;

    while (running) {
        cout << "\n--- Doubly Linked List Menu ---" << endl;
        cout << "1. Insert Beginning "<<endl;
		cout<<  "2.Insert End" << endl;
        cout << "3. Delete Beginning  "<<endl;
		cout<<" 4. Delete End" << endl;
        cout << "5. Display List "<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Value: "; cin >> value;
                insertBeginning(value);
                displayForward(); 
                break;
            case 2:
                cout << "Value: "; cin >> value;
                insertEnd(value);
                displayForward();
                break;
            case 3:
                deleteBeginning();
                displayForward();
                break;
            case 4:
                deleteEnd();
                displayForward();
                break;
            case 5:
                displayForward();
                break;
           
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
