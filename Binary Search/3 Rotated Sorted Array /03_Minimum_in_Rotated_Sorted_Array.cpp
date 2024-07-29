#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int findMinimumInUniqueRotateSortedArray(vector<int> &nums) {
    int start = 0;
    int end = nums.size() - 1;
    int mid;
    int ans = INT_MAX;

    while(start <= end) {
        mid = end + (start - end) / 2;

        if(nums[start] <= nums[mid]) {
            ans = min(ans, nums[start]);
            start = mid + 1;
        }else {
            ans = min(ans, nums[mid]);
            end = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {5, 0, 1,2, 3, 4};

    cout<<"Smallest value is "<<findMinimumInUniqueRotateSortedArray(nums)<<endl;
}    