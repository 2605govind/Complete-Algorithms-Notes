# 2-Sum Problem

## Problem
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

## Solution

```cpp
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map; // value -> index
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {}; // if no solution found
}














// Sure, let's go through each of the problems based on the 2-Sum pattern with code, explanation, examples, time complexity analysis, and real-life applications.

### Problem 1: Find two numbers in an array that multiply to a given target

#### Solution
```cpp
#include <vector>
#include <unordered_map>

std::vector<int> twoProduct(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map; // value -> index
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0 && target == 0) return {i, i}; // handle zero case separately
        if (nums[i] != 0 && target % nums[i] == 0) {
            int complement = target / nums[i];
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
        }
        map[nums[i]] = i;
    }
    return {}; // if no solution found
}
```

#### Explanation
- **Example:** For `nums = [2, 4, 1, 6, 5, 10]` and `target = 20`, the function returns `[1, 5]` because `4 * 5 = 20`.
- **Time Complexity:** O(n), where n is the number of elements in the array.
- **Space Complexity:** O(n), for storing elements in the hash map.

#### Real-life Applications
1. Finding pairs of products with a specific sales value.
2. Identifying two factors of a specific product in physics or engineering problems.
3. Determining pairs of chemical reactants that produce a certain quantity of product.
4. Matching two investment amounts to achieve a target portfolio value.
5. Matching pairs of dimensions to achieve a specific area in architectural designs.




### Problem 2: Find two numbers in an array that have a given difference

#### Solution
```cpp
#include <vector>
#include <unordered_map>

std::vector<int> twoDifference(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map; // value -> index
    for (int i = 0; i < nums.size(); ++i) {
        int complement1 = nums[i] + target;
        int complement2 = nums[i] - target;
        if (map.find(complement1) != map.end()) {
            return {map[complement1], i};
        }
        if (map.find(complement2) != map.end()) {
            return {map[complement2], i};
        }
        map[nums[i]] = i;
    }
    return {}; // if no solution found
}
```

#### Explanation
- **Example:** For `nums = [1, 5, 2, 8, 3]` and `target = 3`, the function returns `[0, 1]` because `5 - 1 = 4`.
- **Time Complexity:** O(n), where n is the number of elements in the array.
- **Space Complexity:** O(n), for storing elements in the hash map.

#### Real-life Applications
1. Finding two stock prices with a specific difference for trading strategies.
2. Matching differences in temperature readings for weather analysis.
3. Finding price differences in products for discount evaluations.
4. Identifying differences in test scores for educational assessments.
5. Determining differences in distances between two locations for logistics planning.




### Problem 3: Find indices of two numbers in an array that divide to a given target


#### Solution
```cpp
#include <vector>
#include <unordered_map>

std::vector<int> twoDivide(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map; // value -> index
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0 && target % nums[i] == 0) {
            int complement = target / nums[i];
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
        }
        map[nums[i]] = i;
    }
    return {}; // if no solution found
}
```

#### Explanation
- **Example:** For `nums = [2, 4, 8, 16]` and `target = 8`, the function returns `[0, 2]` because `8 / 2 = 4`.
- **Time Complexity:** O(n), where n is the number of elements in the array.
- **Space Complexity:** O(n), for storing elements in the hash map.

#### Real-life Applications
1. Identifying two components in a recipe that combine to form a specific quantity.
2. Finding two investment returns that multiply to a specific ROI.
3. Matching two speed readings to achieve a target speed ratio.
4. Identifying two population figures that divide to a specific population density.
5. Determining two values in physics that result in a target ratio for experiments.






### Problem 4: Find two numbers in an array whose sum is closest to a given target

#### Solution
```cpp
#include <vector>
#include <algorithm>
#include <limits.h>

std::pair<int, int> twoSumClosest(const std::vector<int>& nums, int target) {
    int n = nums.size();
    std::vector<int> sortedNums = nums;
    std::sort(sortedNums.begin(), sortedNums.end());
    int left = 0, right = n - 1;
    int closestSum = INT_MAX;
    int closestPair[2] = {0, 0};
    
    while (left < right) {
        int sum = sortedNums[left] + sortedNums[right];
        if (abs(target - sum) < abs(target - closestSum)) {
            closestSum = sum;
            closestPair[0] = sortedNums[left];
            closestPair[1] = sortedNums[right];
        }
        if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }
    return {closestPair[0], closestPair[1]};
}
```

#### Explanation
- **Example:** For `nums = [1, 3, 4, 7, 10]` and `target = 8`, the function returns `3` and `4` as their sum is closest to 8.
- **Time Complexity:** O(n log n), where n is the number of elements in the array due to sorting.
- **Space Complexity:** O(n), for storing elements in the sorted array.

#### Real-life Applications
1. Finding two financial transactions whose sum is closest to a target budget.
2. Matching two items in a shopping list whose cost is closest to a gift card value.
3. Identifying two time intervals that add up closest to a target duration.
4. Finding two temperature readings closest to a target temperature.
5. Determining two project costs whose combined value is closest to a budget limit.






### Problem 5: Find two distinct elements in an array that have a given sum closest to a target

#### Solution
```cpp
#include <vector>
#include <algorithm>
#include <limits.h>

std::pair<int, int> twoSumClosestDistinct(const std::vector<int>& nums, int target) {
    int n = nums.size();
    std::vector<int> sortedNums = nums;
    std::sort(sortedNums.begin(), sortedNums.end());
    int left = 0, right = n - 1;
    int closestSum = INT_MAX;
    int closestPair[2] = {0, 0};
    
    while (left < right) {
        int sum = sortedNums[left] + sortedNums[right];
        if (abs(target - sum) < abs(target - closestSum)) {
            closestSum = sum;
            closestPair[0] = sortedNums[left];
            closestPair[1] = sortedNums[right];
        }
        if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }
    return {closestPair[0], closestPair[1]};
}
```

#### Explanation
- **Example:** For `nums = [1, 3, 4, 7, 10]` and `target = 8`, the function returns `3` and `4` as their sum is closest to 8.
- **Time Complexity:** O(n log n), where n is the number of elements in the array due to sorting.
- **Space Complexity:** O(n), for storing elements in the sorted array.

#### Real-life Applications
1. Finding two distinct items in a warehouse whose total weight is closest to a shipping limit.
2. Matching two distinct expenses closest to a target reimbursement value.
3. Identifying two distinct temperature readings closest to a specific average temperature.
4. Finding two distinct study times closest to a target total study time.
5. Determining two distinct product prices whose combined value is closest to a promotion threshold.

These solutions illustrate the application of the 2-Sum pattern to various related problems, demonstrating the versatility and efficiency of this approach.