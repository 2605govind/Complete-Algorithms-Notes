```markdown
# 4-Sum Problem

## Problem
Given an array `nums` of `n` integers and an integer `target`, are there elements `a`, `b`, `c`, and `d` in `nums` such that `a + b + c + d = target`? Find all unique quadruplets in the array which give the sum of `target`.

## Solution

```cpp
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
        for (int j = i + 1; j < nums.size(); ++j) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue; // skip duplicates
            int left = j + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
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
    }
    return result;
}
```

## Pattern
1. Sort the array.
2. Iterate through the array, fixing two elements.
3. Use a two-pointer technique to find pairs that sum up to the target (target - sum of fixed elements).
4. Skip duplicates to ensure unique quadruplets.

## Problems
1. Find four numbers in an array that multiply to a given target.
2. Find four numbers in an array that add up to a given target.
3. Find four numbers in an array whose sum is closest to a given target.
4. Find all unique quadruplets in an array that multiply to a given target.
5. Find four distinct elements in an array that have a sum closest to a target.
```

### Problem 1: Find four numbers in an array that multiply to a given target

#### Solution
```cpp
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourProduct(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
        for (int j = i + 1; j < nums.size(); ++j) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue; // skip duplicates
            for (int k = j + 1; k < nums.size(); ++k) {
                if (k > j + 1 && nums[k] == nums[k-1]) continue; // skip duplicates
                for (int l = k + 1; l < nums.size(); ++l) {
                    if (l > k + 1 && nums[l] == nums[l-1]) continue; // skip duplicates
                    if (nums[i] * nums[j] * nums[k] * nums[l] == target) {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }
    }
    return result;
}
```

#### Explanation
- **Example:** For `nums = [1, 2, 3, 4, 6]` and `target = 24`, the function returns `[1, 2, 3, 4]` because `1 * 2 * 3 * 4 = 24`.
- **Time Complexity:** O(n^4), where n is the number of elements in the array.
- **Space Complexity:** O(1), excluding the space required for the result.

#### Real-life Applications
1. Finding four investment options that multiply to a desired return.
2. Identifying four production factors that yield a target output.
3. Matching four reactants in a chemical reaction to achieve a target product quantity.
4. Determining four time intervals that multiply to a specific total duration.
5. Finding four weights that multiply to a desired load in engineering applications.

### Problem 2: Find four numbers in an array that add up to a given target

#### Solution
```cpp
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourSumTarget(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
        for (int j = i + 1; j < nums.size(); ++j) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue; // skip duplicates
            int left = j + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
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
    }
    return result;
}
```

#### Explanation
- **Example:** For `nums = [1, 2, 3, 4, 5]` and `target = 10`, the function returns `[1, 2, 3, 4]` because `1 + 2 + 3 + 4 = 10`.
- **Time Complexity:** O(n^3), where n is the number of elements in the array.
- **Space Complexity:** O(1), excluding the space required for the result.

#### Real-life Applications
1. Finding four expenses that add up to a target budget.
2. Matching four ingredients in a recipe to achieve a target quantity.
3. Identifying four time slots that sum up to a target total time.
4. Determining four distances that add up to a specific total distance.
5. Finding four different weights that sum to a desired total load in engineering.

### Problem 3: Find four numbers in an array whose sum is closest to a given target

#### Solution
```cpp
#include <vector>
#include <algorithm>
#include <limits.h>

int fourSumClosest(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int closestSum = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
        for (int j = i + 1; j < nums.size(); ++j) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue; // skip duplicates
            int left = j + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
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
    }
    return closestSum;
}
```

#### Explanation
- **Example:** For `nums = [1, 2, 3, 4, 5]` and `target = 10`, the function returns `10` because `1 + 2 + 3 + 4 = 10` is the closest to 10.
- **Time Complexity:** O(n^3), where n is the number of elements in the array.
- **Space Complexity:** O(1), excluding the space required for the result.

#### Real-life Applications
1. Finding four expenses closest to a target budget.
2. Matching four different items in a list to achieve a sum closest to a specific value.
3. Identifying four time periods that sum closest to a target duration.
4. Determining four distances whose sum is closest to a specific distance.
5. Finding four financial transactions closest to a specific total value.

### Problem 4: Find all unique quadruplets in an array that multiply to a given target

#### Solution
```cpp
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourProductTarget(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i =

 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
        for (int j = i + 1; j < nums.size(); ++j) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue; // skip duplicates
            for (int k = j + 1; k < nums.size(); ++k) {
                if (k > j + 1 && nums[k] == nums[k-1]) continue; // skip duplicates
                for (int l = k + 1; l < nums.size(); ++l) {
                    if (l > k + 1 && nums[l] == nums[l-1]) continue; // skip duplicates
                    if (nums[i] * nums[j] * nums[k] * nums[l] == target) {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }
    }
    return result;
}
```

#### Explanation
- **Example:** For `nums = [1, 2, 3, 4, 6]` and `target = 24`, the function returns `[1, 2, 3, 4]` because `1 * 2 * 3 * 4 = 24`.
- **Time Complexity:** O(n^4), where n is the number of elements in the array.
- **Space Complexity:** O(1), excluding the space required for the result.

#### Real-life Applications
1. Finding four investment options that multiply to a desired return.
2. Identifying four production factors that yield a target output.
3. Matching four reactants in a chemical reaction to achieve a target product quantity.
4. Determining four time intervals that multiply to a specific total duration.
5. Finding four weights that multiply to a desired load in engineering applications.

### Problem 5: Find four distinct elements in an array that have a sum closest to a target

#### Solution
```cpp
#include <vector>
#include <algorithm>
#include <limits.h>

std::vector<int> fourSumClosestDistinct(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int closestSum = INT_MAX;
    std::vector<int> closestQuadruplet;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
        for (int j = i + 1; j < nums.size(); ++j) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue; // skip duplicates
            int left = j + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                    closestQuadruplet = {nums[i], nums[j], nums[left], nums[right]};
                }
                if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
    }
    return closestQuadruplet;
}
```

#### Explanation
- **Example:** For `nums = [1, 2, 3, 4, 5]` and `target = 10`, the function returns `[1, 2, 3, 4]` because `1 + 2 + 3 + 4 = 10` is the closest to 10.
- **Time Complexity:** O(n^3), where n is the number of elements in the array.
- **Space Complexity:** O(1), excluding the space required for the result.

#### Real-life Applications
1. Finding four expenses closest to a target budget.
2. Matching four different items in a list to achieve a sum closest to a specific value.
3. Identifying four time periods that sum closest to a target duration.
4. Determining four distances whose sum is closest to a specific distance.
5. Finding four financial transactions closest to a specific total value.
```