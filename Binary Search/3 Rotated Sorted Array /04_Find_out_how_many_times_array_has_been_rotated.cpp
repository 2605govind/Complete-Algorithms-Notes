#include <bits/stdc++.h>
using namespace std;


int findKRotation(vector<int> &arr){
    int start = 0;
    int end = arr.size() - 1;
    int mid;
    int ans = INT_MAX, index = -1;

    while(start <= end) {
        mid = end + (start - end)/2;

        if(arr[start] <= arr[end]) {
            if(ans > arr[start]) {
                ans = arr[start];
                index = start;
                break;
            }
        }

        if(arr[start] <= arr[mid]) {
            if(ans > arr[start]) {
                ans = arr[start];
                index = start;
            }
            start = mid + 1;
        }else {
            if(ans > arr[mid]) {
                ans = arr[mid];
                index = mid;
            }
            end = mid - 1;
        }
    }    

    return index;
}

int main() {
    vector<int> nums = {5, 0, 1,2, 3, 4};

    cout<<findKRotation(nums)<<" numbers of time array is rotated\n";
}