Here are the six problems, their program statements, input and output examples, and C++ code with explanations.

### 1. Maximum Subarray Sum

**Problem Statement:**
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

**Input:**
- nums: An array of integers.

**Output:**
- The maximum sum of the contiguous subarray.

**Example:**
plaintext
Input: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6
Explanation: [4, -1, 2, 1] has the largest sum = 6.


**Code:**
cpp
#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArray(const std::vector<int>& nums) {
    int max_current = nums[0];
    int max_global = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        max_current = std::max(nums[i], max_current + nums[i]);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }

    return max_global;
}

int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "The maximum sum of the contiguous subarray is: " << maxSubArray(nums) << std::endl;
    return 0;
}


### 2. Maximum Sum of Subarray with Size at Least K

**Problem Statement:**
Given an array arr of integers and an integer k, find the maximum sum of a subarray with at least k elements.

**Input:**
- arr: An array of integers.
- k: An integer representing the minimum subarray size.

**Output:**
- The maximum sum of the subarray with at least k elements.

**Example:**
plaintext
Input: arr = [1, 2, 3, -10, 2, 3, 5, -2, 8], k = 3
Output: 13
Explanation: The subarray [2, 3, 5, -2, 8] has the maximum sum of 13 with at least 3 elements.


**Code:**
cpp
#include <iostream>
#include <vector>
#include <climits>

int maxSumWithAtLeastK(const std::vector<int>& arr, int k) {
    int n = arr.size();
    
    // Step 1: Calculate the max sum subarray ending at each position
    std::vector<int> max_ending_here(n, 0);
    max_ending_here[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        max_ending_here[i] = std::max(arr[i], max_ending_here[i - 1] + arr[i]);
    }
    
    // Step 2: Calculate the max sum subarray of size exactly k
    int sum_k = 0;
    for (int i = 0; i < k; ++i) {
        sum_k += arr[i];
    }
    
    std::vector<int> max_sum_exactly_k(n, 0);
    max_sum_exactly_k[k - 1] = sum_k;
    for (int i = k; i < n; ++i) {
        sum_k = sum_k + arr[i] - arr[i - k];
        max_sum_exactly_k[i] = sum_k;
    }
    
    // Step 3: Combine the results to get the max sum subarray with at least k elements
    int result = INT_MIN;
    for (int i = k - 1; i < n; ++i) {
        result = std::max(result, max_sum_exactly_k[i]);
        if (i >= k) {
            result = std::max(result, max_sum_exactly_k[i] + max_ending_here[i - k]);
        }
    }
    
    return result;
}

int main() {
    std::vector<int> arr = {1, 2, 3, -10, 2, 3, 5, -2, 8};
    int k = 3;
    std::cout << "The maximum sum of the subarray with at least " << k << " elements is: " << maxSumWithAtLeastK(arr, k) << std::endl;
    return 0;
}







### 3. Maximum Circular Subarray Sum  (https://www.youtube.com/watch?v=Q1TYVUEr-wY)

**Problem Statement:**
Given a circular integer array nums, find the maximum sum of a subarray. A circular array means the end of the array wraps around to the beginning.

**Input:**
- nums: A circular array of integers.

**Output:**
- The maximum sum of the subarray.

**Example:**
plaintext
Input: nums = [8, -4, 3, -5, 4]
Output: 12
Explanation: The subarray [4, 8] has the maximum sum of 12.


**Code:**
cpp
#include <iostream>
#include <vector>
#include <climits>

int kadaneAlgorithm(const std::vector<int>& arr) {
    int max_current = arr[0];
    int max_global = arr[0];
    
    for (size_t i = 1; i < arr.size(); ++i) {
        max_current = std::max(arr[i], max_current + arr[i]);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }
    
    return max_global;
}

int maxCircularSubarraySum(std::vector<int>& arr) {
    int n = arr.size();
    
    // Case 1: Get the maximum sum using standard Kadane's Algorithm
    int max_kadane = kadaneAlgorithm(arr);
    
    // Case 2: Find the maximum sum that includes corner elements
    int max_wrap = 0;
    for (int i = 0; i < n; ++i) {
        max_wrap += arr[i]; // Calculate array-sum
        arr[i] = -arr[i];   // Invert the array (change sign)
    }
    
    // max sum with corner elements will be:
    // array-sum - (-max subarray sum of inverted array)
    max_wrap = max_wrap + kadaneAlgorithm(arr);
    
    // The maximum circular sum will be maximum of two cases
    return std::max(max_kadane, max_wrap);
}

int main() {
    std::vector<int> arr = {8, -4, 3, -5, 4};
    std::cout << "The maximum circular subarray sum is: " << maxCircularSubarraySum(arr) << std::endl;
    return 0;
}


### 4. Maximum Sum of Two Non-Overlapping Subarrays

**Problem Statement:**
Given an array arr of integers and two integers L and M, find the maximum sum of two non-overlapping subarrays of lengths L and M.

**Input:**
- arr: An array of integers.
- L: Length of the first subarray.
- M: Length of the second subarray.

**Output:**
- The maximum sum of two non-overlapping subarrays of lengths L and M.

**Example:**
plaintext
Input: arr = [3, 8, 1, 3, 2, 1, 8, 9, 0], L = 3, M = 2
Output: 29
Explanation: The subarrays [8, 9] and [3, 8, 1] have the maximum sum of 29.


**Code:**
cpp
#include <iostream>
#include <vector>
#include <climits>

int maxSumTwoNoOverlap(const std::vector<int>& arr, int L, int M) {
    int n = arr.size();
    
    std::vector<int> sumL(n);
    std::vector<int> sumM(n);
    
    int sumLMax = 0, sumMMax = 0;
    int Lsum = 0, Msum = 0;
    
    // Compute L-sum and M-sum subarrays for each index
    for (int i = 0; i < n; ++i) {
        if (i < L) {
            Lsum += arr[i];
            sumL[i] = Lsum;
        } else {
            Lsum += arr[i] - arr[i - L];
            sumL[i] = Lsum;
        }
        
        if (i < M) {
            Msum += arr[i];
            sumM[i] = Msum;
        } else {
            Msum += arr[i] - arr[i - M];
            sumM[i] = Msum;
        }
    }
    
    int result = 0;
    
    // Find the maximum sum of two non-overlapping subarrays

    for (int i = L - 1; i < n - M; ++i) {

        sumLMax = std::max(sumLMax, sumL[i]);
        result = std::max(result, sumLMax + sumM[i + M]);
    }
    
    for (int i = M - 1; i < n - L; ++i) {
        sumMMax = std::max(sumMMax, sumM[i]);
        result = std::max(result, sumMMax + sumL[i + L]);
    }
    
    return result;
}

int main() {
    std::vector<int> arr = {3, 8, 1, 3, 2, 1, 8, 9, 0};
    int L = 3, M = 2;
    std::cout << "The maximum sum of two non-overlapping subarrays is: " << maxSumTwoNoOverlap(arr, L, M) << std::endl;
    return 0;
}


### 5. Maximum Sum of Non-Adjacent Elements (https://www.youtube.com/watch?v=VT4bZV24QNo)

**Problem Statement:**
Given an array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police. You cannot rob two adjacent houses.

**Input:**
- nums: An array of integers representing the amount of money in each house.

**Output:**
- The maximum amount of money you can rob without alerting the police.

**Example:**
plaintext
Input: nums = [2, 7, 9, 3, 1]
Output: 12
Explanation: Rob houses [2, 9, 1] for a maximum sum of 12.


**Code:**
cpp
#include <iostream>
#include <vector>
#include <algorithm>

int rob(const std::vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    
    int prev1 = 0, prev2 = 0;
    
    for (int num : nums) {
        int temp = prev1;
        prev1 = std::max(prev1, prev2 + num);
        prev2 = temp;
    }
    
    return prev1;
}

int main() {
    std::vector<int> nums = {2, 7, 9, 3, 1};
    std::cout << "The maximum amount of money you can rob is: " << rob(nums) << std::endl;
    return 0;
}


### 6. Maximum Sum of k-Subarrays (Maximum sum of k disjoint subarrays)

**Problem Statement:**
Given an array arr of integers, find the maximum sum of k disjoint subarrays.

**Input:**
- arr: An array of integers.
- k: The number of disjoint subarrays.

**Output:**
- The maximum sum of k disjoint subarrays.

**Example:**
plaintext
Input: arr = [1, 2, 3, 4, 5, 6, 7, 8, 9], k = 3
Output: 24
Explanation: The subarrays [7], [8], and [9] have the maximum sum of 24.


**Code:**
cpp
#include <iostream>
#include <vector>
#include <algorithm>

int maxSumOfKDisjointSubarrays(std::vector<int>& arr, int k) {
    int n = arr.size();
    
    // Base case: If k is greater than the size of the array, return the sum of all elements
    if (k > n) return std::accumulate(arr.begin(), arr.end(), 0);
    
    std::sort(arr.begin(), arr.end(), std::greater<int>());
    
    int max_sum = 0;
    for (int i = 0; i < k; ++i) {
        max_sum += arr[i];
    }
    
    return max_sum;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 3;
    std::cout << "The maximum sum of " << k << " disjoint subarrays is: " << maxSumOfKDisjointSubarrays(arr, k) << std::endl;
    return 0;
}


These examples demonstrate various applications of Kadane's Algorithm and its variations to solve different subarray sum problems.


can you provide this in .md file