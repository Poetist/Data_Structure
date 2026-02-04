#include <iostream>
using namespace std;

int main() {
    int arr[5],choice, i, sum, max, min;
    cout<<"enter the element of an array";
    for (i = 0; i < 5; i++) {
        cin >> arr[i];
    }

   {
        cout << "Choice Card" << endl;
        cout << "1. Display Array" << endl;
        cout << "2. Replace an element" << endl;
        cout << "3. Sum of an Element" << endl;
        cout << "4. Find Maximum Number" << endl;
        cout << "5. Find Minimum Number" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                cout << "Array elements: ";
                for (i = 0; i < 5; i++) cout << arr[i] << " ";
                cout << endl;
                break;
                
            case 2: 
                arr[2]=8;
                for(i=0;i<5;i++)
                cout<<arr[i];
                break;

            case 3:
                sum = 0;
                for (i = 0; i < 5; i++) sum += arr[i];
                cout << "Sum of elements: " << sum << endl;
                break;

            case 4:
                max = arr[0];
                for (i = 1; i < 5; i++) {
                    if (arr[i] > max) max = arr[i];
                }
                cout << "Maximum element: " << max << endl;
                break;

            case 5: 
                min = arr[0];
                for (i = 1; i < 5; i++) {
                    if (arr[i] < min) min = arr[i];
                }
                cout << "Minimum element: " << min << endl;
                break;


            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } 

    return 0;
}
