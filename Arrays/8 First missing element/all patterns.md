Sure! Below are the solutions to each of the 10 patterns for finding the first missing integer, with explanations, time complexities, and real-life use cases for each.

### 1. First Missing Positive Integer

**Example:**
- Input: `[3, 4, -1, 1]`
- Output: `2`

**Time Complexity:** O(n)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int firstMissingPositive(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            std::swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}

int main() {
    std::vector<int> nums = {3, 4, -1, 1};
    std::cout << "First missing positive integer: " << firstMissingPositive(nums) << std::endl;
    return 0;
}
```

**Use Cases:**
1. **Inventory Management:** Assigning unique positive IDs to products.
2. **Task Scheduling:** Assigning unique IDs to processes.
3. **Database Auto-Increment Keys:** Managing unique row identifiers.




### 2. First Missing Non-Negative Integer

**Example:**
- Input: `[0, 2, 2, 1, 0, 5]`
- Output: `3`

**Time Complexity:** O(n)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int firstMissingNonNegative(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] >= 0 && nums[i] < n && nums[nums[i]] != nums[i]) {
            std::swap(nums[i], nums[nums[i]]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i) {
            return i;
        }
    }
    return n;
}

int main() {
    std::vector<int> nums = {0, 2, 2, 1, 0, 5};
    std::cout << "First missing non-negative integer: " << firstMissingNonNegative(nums) << std::endl;
    return 0;
}
```

**Use Cases:**
1. **Ticketing Systems:** Assigning non-negative ticket numbers.
2. **Parking Lot Management:** Assigning non-negative slot numbers.
3. **Queue Systems:** Assigning non-negative queue positions.






### 3. First Missing Integer in a Range

**Example:**
- Input: `[2, 5, 3, 7]`, Range: `[1, 6]`
- Output: `1`

**Time Complexity:** O(n)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int firstMissingInRange(std::vector<int>& nums, int low, int high) {
    int n = high - low + 1;
    std::vector<bool> present(n, false);

    for (int num : nums) {
        if (num >= low && num <= high) {
            present[num - low] = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!present[i]) {
            return low + i;
        }
    }
    return high + 1;
}

int main() {
    std::vector<int> nums = {2, 5, 3, 7};
    int low = 1, high = 6;
    std::cout << "First missing integer in range [" << low << ", " << high << "]: " << firstMissingInRange(nums, low, high) << std::endl;
    return 0;
}
```

**Use Cases:**
1. **IP Address Management:** Allocating IP addresses within a specific range.
2. **Resource Allocation:** Assigning resource IDs within a range.
3. **User ID Assignment:** Assigning user IDs within a specific range.




### 4. First Missing Integer with Duplicates

**Example:**
- Input: `[1, 1, 0, -1, -2]`
- Output: `2`

**Time Complexity:** O(n)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int firstMissingWithDuplicates(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            std::swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}

int main() {
    std::vector<int> nums = {1, 1, 0, -1, -2};
    std::cout << "First missing integer with duplicates: " << firstMissingWithDuplicates(nums) << std::endl;
    return 0;
}
```

**Use Cases:**
1. **User Authentication:** Ensuring unique user IDs despite duplicates.
2. **Product Catalog:** Assigning unique product IDs with duplicates.
3. **Event Registration:** Handling duplicate registration numbers.






### 5. First Missing Integer in a Sorted Array

**Example:**
- Input: `[-2, -1, 0, 1, 3]`
- Output: `2`

**Time Complexity:** O(n)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>

int firstMissingInSortedArray(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0 && nums[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}

int main() {
    std::vector<int> nums = {-2, -1, 0, 1, 3};
    std::cout << "First missing integer in sorted array: " << firstMissingInSortedArray(nums) << std::endl;
    return 0;
}
```

**Use Cases:**
1. **Financial Records:** Identifying missing transaction IDs.
2. **Student Records:** Finding missing student IDs.
3. **Order Tracking:** Identifying missing order numbers.

### 6. First Missing Integer in a Circular Array

**Example:**
- Input: `[3, 4, 1, 2]` (circular array)
- Output: `5`

**Time Complexity:** O(n)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>

int firstMissingInCircularArray(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            std::swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}

int main() {
    std::vector<int> nums = {3, 4, 1, 2};
    std::cout << "First missing integer in circular array: " << firstMissingInCircularArray(nums) << std::endl;
    return 0;
}
```

**Use Cases:**
1. **Circular Buffer Management:** Identifying missing data slots.
2. **Round-Robin Scheduling:** Assigning unique time slots.
3. **Network Packet Tracking:** Identifying missing packets.

### 7. First Missing Even/Odd Integer

**Example:**
- Input: `[1, 3, 5, 7]`
- Output (Even): `0`
- Output (Odd): `2`

**Time Complexity:** O(n)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>

int firstMissingEven(std::vector<int>& nums) {
    int maxEven = *std::max_element(nums.begin(), nums.end());
    std::vector<bool> present(maxEven / 2 + 1, false);

    for (int num : nums) {
        if (num % 2 == 0 && num >= 0) {
            present[num / 2] = true;
        }
    }

    for (int i = 0; i < present.size(); ++i) {
        if (!present[i]) {
            return i * 2;
        }
    }
    return (present.size()) * 2;
}

int firstMissingOdd(std::vector<int>& nums) {
    int maxOdd = *std::max_element(nums.begin

(), nums.end());
    std::vector<bool> present(maxOdd / 2 + 1, false);

    for (int num : nums) {
        if (num % 2 != 0 && num >= 0) {
            present[num / 2] = true;
        }
    }

    for (int i = 0; i < present.size(); ++i) {
        if (!present[i]) {
            return i * 2 + 1;
        }
    }
    return (present.size()) * 2 + 1;
}

int main() {
    std::vector<int> nums = {1, 3, 5, 7};
    std::cout << "First missing even integer: " << firstMissingEven(nums) << std::endl;
    std::cout << "First missing odd integer: " << firstMissingOdd(nums) << std::endl;
    return 0;
}
```

**Use Cases:**
1. **Employee Scheduling:** Assigning even/odd shift IDs.
2. **Event Management:** Assigning even/odd seat numbers.
3. **Queue Management:** Assigning even/odd queue positions.

### 8. First Missing Integer in Matrix

**Example:**
- Input: `[[1, 2, 3], [6, 5, 4], [9, 7, 8]]`
- Output: `10`

**Time Complexity:** O(m * n)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>

int firstMissingInMatrix(std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    std::vector<bool> present(m * n + 1, false);

    for (const auto& row : matrix) {
        for (int num : row) {
            if (num > 0 && num <= m * n) {
                present[num] = true;
            }
        }
    }

    for (int i = 1; i <= m * n; ++i) {
        if (!present[i]) {
            return i;
        }
    }
    return m * n + 1;
}

int main() {
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {6, 5, 4}, {9, 7, 8}};
    std::cout << "First missing integer in matrix: " << firstMissingInMatrix(matrix) << std::endl;
    return 0;
}
```

**Use Cases:**
1. **Grid-Based Games:** Identifying missing positions in a grid.
2. **Data Analysis:** Finding missing data points in a matrix.
3. **Geographic Information Systems (GIS):** Identifying missing geographic data.

### 9. First Missing Positive Integer in a Linked List

**Example:**
- Input: `1 -> 2 -> 0 -> -1 -> -2`
- Output: `3`

**Time Complexity:** O(n)

**C++ Code:**
```cpp
#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int firstMissingPositive(ListNode* head) {
    std::unordered_set<int> nums;
    int maxVal = 0;
    while (head) {
        if (head->val > 0) {
            nums.insert(head->val);
            maxVal = std::max(maxVal, head->val);
        }
        head = head->next;
    }

    for (int i = 1; i <= maxVal; ++i) {
        if (nums.find(i) == nums.end()) {
            return i;
        }
    }
    return maxVal + 1;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-1);
    head->next->next->next->next = new ListNode(-2);

    std::cout << "First missing positive integer in linked list: " << firstMissingPositive(head) << std::endl;
    return 0;
}
```

**Use Cases:**
1. **Memory Management:** Identifying missing memory blocks.
2. **Job Scheduling:** Assigning unique job IDs.
3. **Dynamic Data Structures:** Handling missing elements in linked data structures.

### 10. First Missing Integer with Constraints

**Example:**
- Input: `[2, 5, 1, 1]`
- Output: `3`

**Time Complexity:** O(n)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int firstMissingWithConstraints(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            std::swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}

int main() {
    std::vector<int> nums = {2, 5, 1, 1};
    std::cout << "First missing integer with constraints: " << firstMissingWithConstraints(nums) << std::endl;
    return 0;
}
```

**Use Cases:**
1. **IoT Devices:** Assigning unique device IDs with limited memory.
2. **Embedded Systems:** Handling missing IDs in resource-constrained environments.
3. **Mobile Applications:** Assigning unique identifiers with memory constraints.

These examples illustrate various patterns of finding the first missing integer and their respective real-life use cases in the industry.