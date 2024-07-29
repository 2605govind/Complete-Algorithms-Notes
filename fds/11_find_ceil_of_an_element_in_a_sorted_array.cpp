// Pattern 10: Find ceil on an element in a sorted array
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:    
    // Method for finding ceil of an element
    int findCeilValue(vector<int> &nums, int target) {
        int n = nums.size();
        // Using binary search 
        int low = 0, high = n-1, mid;

        // Store ceil value
        int res = -1;

        // Iterate based on mid
        while(low <= high) {
            // If interger value is large then variable can go out of bound so we use this 
            mid = low + (high - low) / 2;

            // If target is nums[mid]
            if(target == nums[mid]) {
                return nums[mid];

            // Move right side
            }else if(target > nums[mid]) {
                low = mid + 1;

            // Move left side
            }else {
                res = nums[mid];
                high = mid - 1;
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums = {2,3,4,8,10,10,12,19};

    Solution s;
    cout<<s.findCeilValue(nums, 5);
}