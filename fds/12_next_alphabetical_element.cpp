// Pattern 10: Next alphabetical element
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:    
    // Method for finding next alphabet
    char findNextAlphabeticalEle(vector<char> &nums, char key) {
        int n = nums.size();
        // Using binary search 
        int low = 0, high = n-1, mid;

        // Initially store '#' for not found
        char res = '#';

        while(low <= high) {
            // If interger index is large then variable can go out of bound so we use this 
            mid = low + (high - low) / 2;

            // If key is nums[mid] then move to right side of next alphabet 
            if(key == nums[mid]) {
                low = mid + 1;

            // Move right side
            }else if(key > nums[mid]) {
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
    vector<char> nums = {'a', 'c', 'f', 'g'};

    Solution s;
    char key = 'a';
    cout<<s.findNextAlphabeticalEle(nums, key);
}