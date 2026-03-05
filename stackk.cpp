#include <iostream>
using namespace std;

int main() {
    int stack[100], n, choice, top = -1, value;

    
    cout << "Enter the size of stack: ";
    cin >> n;

    
    cout << "Enter " << n << " elements to fill the stack initially:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        if (top < n - 1) {
            stack[++top] = value;
        }
    }

    
    cout << "Initial Stack: ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;

    
    while (true) {
        cout << "Choice Card" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display All" << endl;
        cout << "5. Exit" << endl;
        
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting " << endl;
            break; 
        }

        switch (choice) {
            case 1: 
                if (top >= n - 1) {
                    cout << "Stack Overflow! Cannot add more." << endl;
                } else {
                    cout << "Enter value to push: ";
                    cin >> value;
                    stack[++top] = value;
                    cout << "Pushed: " << value << endl;
                }
                break;

            case 2: 
                if (top < 0) {
                    cout << "Stack Underflow" << endl;
                } else {
                    cout << "Popped element: " << stack[top--] << endl;
                }
                break;

            case 3: 
                if (top < 0) {
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Top element is: " << stack[top] << endl;
                }
                break;

            case 4: 
                if (top < 0) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Current Stack: ";
                    for (int i = top; i >= 0; i--) {
                        cout << stack[i] << " ";
                    }
                    cout << endl;
                }
                break;

            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
