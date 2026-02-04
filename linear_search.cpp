#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        
        if (arr[i] == target) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    int data[] = {12, 45, 7, 91, 23, 6};
    int size = sizeof(data) / sizeof(data[0]); 
    int key = 91;

    int index = linearSearch(data, size, key);

    if (index != -1) {
        cout << "Element found at index: " << index << std::endl;
    } else {
        cout << "Element not found." << std::endl;
    }

    return 0;
}
