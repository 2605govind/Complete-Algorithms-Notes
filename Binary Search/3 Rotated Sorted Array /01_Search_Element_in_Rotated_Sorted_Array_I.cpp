#include<iostream>
#include<vector>
using namespace std;


int findElementInRotateSortedArray(vector<int> &nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    int mid;

    while(start <= end) {
        mid = end + (start - end) / 2;

        if(nums[mid] == target) {
            return mid;
        }

        // move so that first find which part is sorted
        // left part is sorted 
        if(nums[mid] >= nums[start]) {
            // left side
            if(nums[mid] >= target && nums[start] <= target) {
                end = mid - 1;
            }else {
                start = mid + 1;
            }

        // right part is sorted    
        }else {
            // move right side
            if(nums[mid] <= target && nums[end] >= target) {
                start = mid + 1;
            }else {
                end = mid - 1;
            }
        }
    }

    return -1;
}


int main() {
    vector<int> nums = {7,8,9,1,2,3,4,5,6};
    int target = 9;

    cout<<findElementInRotateSortedArray(nums, target);
}