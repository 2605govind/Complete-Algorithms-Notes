// Pattern 10: Find floor on an element in a sorted array
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:    
    // Method for finding floor of an element
    int findFloorValue(vector<int> &nums, int target) {
        int n = nums.size();
        // Using binary search 
        int low = 0, high = n-1, mid;

        // Store floor value
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
                res = nums[mid];
                low = mid + 1;

            // Move left side
            }else {
                high = mid - 1;
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums = {2,3,4,8,10,10,12,19};

    Solution s;
    cout<<s.findFloorValue(nums, 5);
}