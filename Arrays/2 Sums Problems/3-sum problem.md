```markdown
# 3-Sum Problem

## Problem
Given an array `nums` of `n` integers, are there elements `a`, `b`, `c` in `nums` such that `a + b + c = 0`? Find all unique triplets in the array which give the sum of zero.

## Solution

```cpp
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
        int target = -nums[i];
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left+1]) ++left; // skip duplicates
                while (left < right && nums[right] == nums[right-1]) --right; // skip duplicates
                ++left;
                --right;
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }
    return result;
}
```

## Pattern
1. Sort the array.
2. Iterate through the array, fixing one element.
3. Use a two-pointer technique to find pairs that sum up to the target (-fixed element).
4. Skip duplicates to ensure unique triplets.

## Problems
1. Find three numbers in an array that multiply to a given target.
2. Find three numbers in an array that add up to a given target.
3. Find three numbers in an array whose sum is closest to a given target.
4. Find all unique triplets in an array that multiply to a given target.
5. Find three distinct elements in an array that have a sum closest to a target.
``

### Problem 1: Find three numbers in an array that multiply to a given target

#### Solution
```cpp
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeProduct(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
        for (int j = i + 1; j < nums.size(); ++j) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue; // skip duplicates
            for (int k = j + 1; k < nums.size(); ++k) {
                if (k > j + 1 && nums[k] == nums[k-1]) continue; // skip duplicates
                if (nums[i] * nums[j] * nums[k] == target) {
                    result.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
    }
    return result;
}
```

#### Explanation
- **Example:** For `nums = [1, 2, 3, 4, 5, 6]` and `target = 24`, the function returns `2, 3, 4` because `2 * 3 * 4 = 24`.
- **Time Complexity:** O(n^3), where n is the number of elements in the array.
- **Space Complexity:** O(1), excluding the space required for the result.

#### Real-life Applications
1. Finding three investment options that multiply to a desired return.
2. Identifying three production factors that yield a target output.
3. Matching three reactants in a chemical reaction to achieve a target product quantity.
4. Determining three time intervals that multiply to a specific total duration.
5. Finding three weights that multiply to a desired load in engineering applications.





### Problem 2: Find three numbers in an array that add up to a given target

#### Solution
```cpp
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSumTarget(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left+1]) ++left; // skip duplicates
                while (left < right && nums[right] == nums[right-1]) --right; // skip duplicates
                ++left;
                --right;
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }
    return result;
}
```

#### Explanation
- **Example:** For `nums = [1, 2, 3, 4, 5, 6]` and `target = 10`, the function returns `1, 3, 6` because `1 + 3 + 6 = 10`.
- **Time Complexity:** O(n^2), where n is the number of elements in the array.
- **Space Complexity:** O(1), excluding the space required for the result.

#### Real-life Applications
1. Finding three financial transactions that add up to a target amount.
2. Matching three ingredients in a recipe to achieve a target quantity.
3. Identifying three time slots that sum up to a target total time.
4. Determining three distances that add up to a specific total distance.
5. Finding three different weights that sum to a desired total load in engineering.







### Problem 3: Find three numbers in an array whose sum is closest to a given target

#### Solution
```cpp
#include <vector>
#include <algorithm>
#include <limits.h>

int threeSumClosest(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int closestSum = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(target - sum) < abs(target - closestSum)) {
                closestSum = sum;
            }
            if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }
    return closestSum;
}
```

#### Explanation
- **Example:** For `nums = [1, 2, 3, 4, 5]` and `target = 10`, the function returns `10` because `1 + 3 + 6 = 10` is the closest to 10.
- **Time Complexity:** O(n^2), where n is the number of elements in the array.
- **Space Complexity:** O(1), excluding the space required for the result.

#### Real-life Applications
1. Finding three expenses closest to a target budget.
2. Matching three different items in a list to achieve a sum closest to a specific value.
3. Identifying three time periods that sum closest to a target duration.
4. Determining three distances whose sum is closest to a specific distance.
5. Finding three financial transactions closest to a specific total value.








### Problem 4: Find all unique triplets in an array that multiply to a given target

#### Solution
```cpp
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeProductTarget(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
        for (int j = i + 1; j < nums.size(); ++j) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue; // skip duplicates
            for (int k = j + 1; k < nums.size(); ++k) {
                if (k > j + 1 && nums[k] == nums[k-1]) continue; // skip duplicates
                if (nums[i] * nums[j] * nums[k] == target) {
                    result.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
    }
    return result;
}
```

#### Explanation
- **Example:** For `nums = [1, 2, 3, 4, 6]` and `target = 24`, the function returns `1, 3, 8` because `1 * 3 * 8 = 24`.
- **Time Complexity:**

 O(n^3), where n is the number of elements in the array.
- **Space Complexity:** O(1), excluding the space required for the result.

#### Real-life Applications
1. Finding three ingredients in a recipe that multiply to a target quantity.
2. Matching three investments that multiply to a target return.
3. Identifying three production factors that yield a target output.
4. Determining three speeds that multiply to a target velocity.
5. Finding three weights that multiply to a desired total in engineering.







### Problem 5: Find three distinct elements in an array that have a sum closest to a target

#### Solution
```cpp
#include <vector>
#include <algorithm>
#include <limits.h>

std::vector<int> threeSumClosestDistinct(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int closestSum = INT_MAX;
    std::vector<int> closestTriplet;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(target - sum) < abs(target - closestSum)) {
                closestSum = sum;
                closestTriplet = {nums[i], nums[left], nums[right]};
            }
            if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }
    return closestTriplet;
}
```

#### Explanation
- **Example:** For `nums = [1, 2, 3, 4, 5]` and `target = 10`, the function returns `1, 3, 6` because `1 + 3 + 6 = 10` is the closest to 10.
- **Time Complexity:** O(n^2), where n is the number of elements in the array.
- **Space Complexity:** O(1), excluding the space required for the result.

#### Real-life Applications
1. Finding three different expenses closest to a target budget.
2. Matching three different items in a list to achieve a sum closest to a specific value.
3. Identifying three time periods that sum closest to a target duration.
4. Determining three distances whose sum is closest to a specific distance.
5. Finding three financial transactions closest to a specific total value.
```