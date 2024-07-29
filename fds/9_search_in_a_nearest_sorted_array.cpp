// Pattern 9: Search in a nearest sorted array 
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:    
    // Method for finding element in nearest sorted array
    int searchAnElement(vector<int> &nums, int target) {
        int n = nums.size();
        // Using binary search 
        int low = 0, high = n-1, mid;

        // Iterate based on mid
        while(low <= high) {
            // If interger value is large then variable can go out of bound so we use this 
            mid = low + (high - low) / 2;

            // If target is nums[mid]
            if(target == nums[mid]) {
                return mid;

            // If target is nums[mid-1] and check mid is always greater then and equle to low
            } else if(mid >= low && target == nums[mid-1]) {
                return mid-1;
            
            // If target is nums[mid+1] and check mid is always less then and equle to high
            } else if(mid <= high && target == nums[mid+1]) {
                return mid+1;

            // Now, move left side
            }else if(target < nums[mid]) {
                high = mid - 2;

            // Move right side
            }else {
                low = mid + 2;
            }
        }

        // If traget is not found
        return -1;
    }
};

int main() {
    vector<int> nums = {5, 10, 30, 20, 40};

    Solution s;
    cout<<s.searchAnElement(nums, 40);
}