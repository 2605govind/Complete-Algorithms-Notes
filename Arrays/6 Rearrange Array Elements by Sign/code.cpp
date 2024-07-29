#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int i = 0, j = 1;

        for(auto x : nums) {
            if(x < 0) {
                ans[j] = x;
                j += 2;
            }else {
                ans[i] = x;
                i += 2;
            }  
        }

        return ans;
    }
};

int main() {
    Solution s;
    std::vector<int> arr = {1, -2, 3, -4, 5, -6};
    std::vector<int> result = s.rearrangeArray(arr);
    
    for (int num : result) {
        std::cout << num << " ";
    }
    
    return 0;
}