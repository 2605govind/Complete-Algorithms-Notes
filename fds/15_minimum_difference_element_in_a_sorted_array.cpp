// Pattern 15: Minimum difference element in a sorted array
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:    
    // Method for finding minimum difference element
    int minimumDifferenceElement(vector<int> &nums, int target) {
        int n = nums.size();
        // Using binary search 
        int low = 0, high = n-1, mid;

        // Iterate based on mid
        while(low <= high) {
            // If interger value is large then variable can go out of bound so we use this 
            mid = low + (high - low) / 2;

            // If target is nums[mid]
            if(target == nums[mid]) {
                return nums[mid];

            // Now, move left side
            }else if(target < nums[mid]) {
                high = mid - 1;

            // Move right side
            }else {
                low = mid + 1;
            }
        }

        // check which is smallest difference from target neighbour and return smallest one
        int first = abs(nums[high] - target);
        int second = abs(nums[low] - target);

        if(first < second) {
            return nums[high];
        }else {
            return nums[low];
        }
    }
};

int main() {
    vector<int> nums = {1,3,8,10,15,18,20};

    Solution s;
    cout<<s.minimumDifferenceElement(nums, 50);
}