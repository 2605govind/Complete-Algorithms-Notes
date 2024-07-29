#include<iostream>
using namespace std;

// Iterative Binary Search
int binarySearchIterative(int arr[], int target, int n) {
    int low = 0;                // Starting index of the array
    int high = n - 1;           // Ending index of the array
    int mid;                    // Variable to store the middle index

    while (low <= high) {       // Continue searching while low index is less than or equal to high index
        mid = low + (high - low) / 2;   // Calculate the middle index to divide the array into two halves

        if (arr[mid] == target) {       // If the middle element is equal to the target
            return mid;                 // Target found, return the index of the target
        } else if (arr[mid] < target) { // If the middle element is less than the target
            low = mid + 1;              // Discard the left half of the array by setting low to mid + 1
        } else {                        // If the middle element is greater than the target
            high = mid - 1;             // Discard the right half of the array by setting high to mid - 1
        }
    }

    return -1;   // Target not found, return -1
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int target, int low, int high, int n) {
    if (low > high) {           // Base case: If low index exceeds high index, target is not found
        return -1;
    }

    int mid = low + (high - low) / 2;   // Calculate the middle index to divide the array into two halves

    if (arr[mid] == target) {           // If the middle element is equal to the target
        return mid;                     // Target found, return the index of the target
    } else if (arr[mid] < target) {     // If the middle element is less than the target
        return binarySearchRecursive(arr, target, mid + 1, high, n);   // Recursively search in the right half
    } else {                            // If the middle element is greater than the target
        return binarySearchRecursive(arr, target, low, mid - 1, n);    // Recursively search in the left half
    }
}

int main() {
    int array[] = {3, 4, 6, 7, 9, 12, 16, 17};   // Sorted array for binary search
    int size = sizeof(array) / sizeof(array[0]);   // Calculate the size of the array
    int target = 16;                            // Element to be searched

    // Perform iterative binary search
    int index = binarySearchIterative(array, target, size);

    // Display the result of iterative binary search
    if (index == -1) {
        cout << target << " is not found!\n";
    } else {
        cout << target << " is found at index " << index << "\n";
    }

    return 0;
}
