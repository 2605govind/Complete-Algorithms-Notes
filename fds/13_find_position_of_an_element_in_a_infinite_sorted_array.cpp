// Problem 13 Find position of an element in a infinite sorted array
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchElementInInfiniteSortedArray(vector<int> &nums, int key) {
        // Declare low and high
        int low = 0;
        int high = 1;

        // Find high for given key, we know key is always bound with low and high index 
        while(key > nums[high]) {
            // key is not present smaller value of low index so we modify low with high
            low = high;
            // Every time we increas high multiply by 2 
            high = high * 2;
        }

        // Here we find low and high and key is always present in between
        
        // Using binary search
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == key) {
                return mid;
            }else if(nums[mid] > key) {
                high = mid - 1;
            }else {
                low  = mid + 1;
            }
        }

        // If key in not present in infinite sorted array
        return -1;
    }
};

int main(){
    // Infinite array :- we don't know size of array and nums is denoted infinite array
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14}; 
    int key = 3;

    Solution s;
    cout<<s.searchElementInInfiniteSortedArray(nums, key);
}
