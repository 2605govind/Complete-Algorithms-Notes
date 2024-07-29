#include<iostream>
#include<vector>
using namespace std;


int singleNonDuplicate(vector<int> &arr) {
    int n = arr.size();

    // edge case 
    if(n == 1) return arr[0];

    // trim down the search space for avoid the too many condition of out of bound memory access
    if(arr[0] != arr[1] ) return arr[0];
    if(arr[n-1] != arr[n-2] ) return arr[n-1];

    // after trim assign to binary serach
    int start = 1;
    int end = n - 1;
    int mid;

    while(start <= end) {
        mid = end + (start - end) / 2;

        // target the non dubplicate value
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) {
            return arr[mid];
        }

        // finding non dublicate containig part
        if((mid%2 == 1)&&arr[mid] == arr[mid-1] || (mid%2 == 0)&&arr[mid] == arr[mid+1]) {
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    } 
    return -1;
}


int main() {
    vector<int> nums = {1,1,2,2,3,3,4,5,5,6,6};

    cout<<" Single Element in a Sorted Array is "<<singleNonDuplicate(nums)<<endl;
}