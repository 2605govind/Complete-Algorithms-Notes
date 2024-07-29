#include<iostream>
using namespace std;

// Iterative Lower Bound
int lowerBound(int arr[], int target, int n) {
    int low = 0;                // Starting index of the array
    int high = n - 1;           // Ending index of the array
    int mid, ans = -1;          // Variable to store the middle index and lower bound

    while (low <= high) {       // Continue searching while low index is less than or equal to high index
        mid = low + (high - low) / 2;   // Calculate the middle index to divide the array into two halves

        if (arr[mid] >= target) { // If the middle element is greate than and equle to the target
            ans = mid;            // store mid for lower bound  
            high = mid - 1;       // Discard the right half of the array by setting high to mid - 1
                                  
        } else {                  // If the middle element is less than the target
            low = mid + 1;        // Discard the left half of the array by setting low to mid + 1    
        }
    }

    return ans;   // return lower bound
}

// Iterative Upper Bound
int upperBound(int arr[], int target, int n) {
    int low = 0;                // Starting index of the array
    int high = n - 1;           // Ending index of the array
    int mid, ans = -1;          // Variable to store the middle index and lower bound

    while (low <= high) {       // Continue searching while low index is less than or equal to high index
        mid = low + (high - low) / 2;   // Calculate the middle index to divide the array into two halves

        if (arr[mid] > target) { // If the middle element is greate than and equle to the target
            ans = mid;            // store mid for upper bound  
            high = mid - 1;       // Discard the right half of the array by setting high to mid - 1
                                    
        } else {                  // If the middle element is less than the target
            low = mid + 1;        // Discard the left half of the array by setting low to mid + 1    
        }
    }

    return ans;   // return upper bound
}


int main() {
    int array[] = {3, 4, 6, 7, 9, 9, 9, 12, 16, 17};   // Sorted array for binary search
    int size = sizeof(array) / sizeof(array[0]);   // Calculate the size of the array
    int target = 9;                            // Element to be find lower and upper bound

    cout<<"Lower bound is "<<lowerBound(array, target, size)<<endl;
    cout<<"Upper bound is "<<upperBound(array, target, size)<<endl;

    return 0;
}
