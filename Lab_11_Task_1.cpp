#include <iostream>
using namespace std;

// Linear Search
int ls(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element is at index " << i << " in array" << endl;
            return i;
        }
    }
    cout << "Element is missing from array" << endl;
    return -1;
}

// Binary Search
int bs(int arr[], int n, int key) {
    int s = 0, e = n - 1, mid;
    while (s <= e) {
        mid = (s + e) / 2;
        if (arr[mid] == key) {
            cout << "The key element " << key << " is at index " << mid << endl;
            return mid;
        } else if (key < arr[mid]) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    cout << "Element is not in the array" << endl;
    return -1;
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
    cout << "Array sorted using Insertion Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 2, 3, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    int key, choice;
    cout << "Enter Key element: ";
    cin >> key;

    do {
        cout << "\nEnter Your Choice:\n"
             << "0. Exit\n"
             << "1. Linear Search\n"
             << "2. Binary Search\n"
             << "3. Insertion Sort\nChoice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ls(arr, n, key);
            break;
        case 2:
            bs(arr, n, key);
            break;
        case 3:
            insertionSort(arr, n);
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
