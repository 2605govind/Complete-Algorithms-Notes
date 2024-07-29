#include<iostream>
#include<vector>
using namespace std;

bool isPresentInDublicateRotateSortedArray(vector<int> &nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    int mid;

    while(start <= end) {
        mid = end + (start - end) / 2;

        if(nums[mid] == target) {
            return true;
        }

        // if start mid and end will be same then srink the search space
        if(nums[start] == nums[mid] && nums[mid] == nums[end]) {
            start += 1;
            end -= 1;
            continue;
        }


        // move the right search space
        if(nums[mid] <= nums[end]) {
            // move right side
            if(nums[mid] <= target && target <= nums[end]) {
                start = mid + 1;
            }else {
                end = mid - 1;
            }
        }else {
            if(nums[mid] >= target && nums[start] <= target) {
                end = mid - 1;
            }else {
                start = mid + 1;
            }
        }
    }

    return false;
}

int main() {
    vector<int> nums = {3,3,1,3,3,3,3};
    int target = 1;

    if(isPresentInDublicateRotateSortedArray(nums, target)) {
        cout<<target<<" is present \n";
    }else {
        cout<<target<<" is not present \n";
    }
}