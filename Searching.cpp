#include <iostream>
#include <algorithm> // Required for sort()
#include <vector>

using namespace std;

// Linear Search: Checks every element one by one
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Binary Search: Repeatedly divides the search interval in half
int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents potential overflow

        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, target, choice;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> data(n);
    cout << "Enter " << n << " integers: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "\nEnter the number to search for: ";
    cin >> target;

    cout << "\nChoose search method:\n1. Linear Search\n2. Binary Search (Will sort array first)\nChoice: ";
    cin >> choice;

    int index = -1;

    if (choice == 1) {
        index = linearSearch(data, target);
    } 
    else if (choice == 2) {
        // Binary Search MUST have a sorted array
        sort(data.begin(), data.end());
        cout << "\nSorted array for Binary Search: ";
        for (int x : data) cout << x << " ";
        cout << endl;
        
        index = binarySearch(data, target);
    } 
    else {
        cout << "Invalid choice." << endl;
        return 1;
    }

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
