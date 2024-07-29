### 1. Basic Majority Element

#### Problem
Find the element that appears more than ⌊n/2⌋ times in an array.

#### Example
- **Input**: [3, 2, 3]
- **Output**: 3

#### Details
1. **Data Structure Used**:
   - **Array**: For storing the input elements.
   - **Hash Map**: To count the frequency of each element.
   - **Boyer-Moore Voting Algorithm**: Uses variables to maintain a candidate and its count.

2. **Real-Life Application**:
   - **Election**: Finding the candidate with more than half the votes.
   - **Sales Data Analysis**: Identifying the most popular product.

3. **Benefits**:
   - **Efficiency**: Linear time complexity.
   - **Space**: Boyer-Moore Voting Algorithm uses constant space.

4. **Limitations**:
   - **Hash Map**: Requires extra space, not suitable for memory-constrained environments.

5. **Time Complexity**:
   - **Brute Force**: O(n^2)
   - **Optimized**: O(n) with Boyer-Moore Voting Algorithm

#### C++ Code

**Brute Force Approach**:
```cpp
#include <iostream>
#include <vector>

int majorityElement(const std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (nums[j] == nums[i]) {
                count++;
            }
        }
        if (count > n / 2) {
            return nums[i];
        }
    }
    return -1;
}

int main() {
    std::vector<int> nums = {3, 2, 3};
    std::cout << "Majority Element: " << majorityElement(nums) << std::endl;
    return 0;
}
```

**Optimized Approach (Boyer-Moore Voting Algorithm)**:
```cpp
#include <iostream>
#include <vector>

int majorityElement(const std::vector<int>& nums) {
    int candidate = -1;
    int count = 0;

    // Phase 1: Find a candidate
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Phase 2: Verify the candidate
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    if (count > nums.size() / 2) {
        return candidate;
    } else {
        return -1;
    }
}

int main() {
    std::vector<int> nums = {3, 2, 3};
    std::cout << "Majority Element: " << majorityElement(nums) << std::endl;
    return 0;
}
```

### 2. Majority Element II

#### Problem
Find all elements that appear more than ⌊n/3⌋ times.

#### Example
- **Input**: [1, 1, 1, 3, 3, 2, 2, 2]
- **Output**: [1, 2]

#### Details
1. **Data Structure Used**:
   - **Array**: For storing the input elements.
   - **Hash Map**: To count the frequency of each element.
   - **Boyer-Moore Voting Algorithm (Modified)**: Uses variables to maintain two candidates and their counts.

2. **Real-Life Application**:
   - **Social Media Analysis**: Identifying trending topics.

3. **Benefits**:
   - **Efficiency**: Linear time complexity.
   - **Space**: Uses constant space with the modified Boyer-Moore Voting Algorithm.

4. **Limitations**:
   - **Hash Map**: Requires extra space, not suitable for memory-constrained environments.

5. **Time Complexity**:
   - **Brute Force**: O(n^2)
   - **Optimized**: O(n) with modified Boyer-Moore Voting Algorithm

#### C++ Code

**Brute Force Approach**:
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

std::vector<int> majorityElementII(const std::vector<int>& nums) {
    std::unordered_map<int, int> countMap;
    int n = nums.size();
    std::vector<int> result;

    for (int num : nums) {
        countMap[num]++;
    }

    for (const auto& pair : countMap) {
        if (pair.second > n / 3) {
            result.push_back(pair.first);
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};
    std::vector<int> result = majorityElementII(nums);
    std::cout << "Majority Elements: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

**Optimized Approach (Modified Boyer-Moore Voting Algorithm)**:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> majorityElementII(const std::vector<int>& nums) {
    int candidate1 = -1, candidate2 = -1, count1 = 0, count2 = 0;

    for (int num : nums) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;
    for (int num : nums) {
        if (num == candidate1) count1++;
        else if (num == candidate2) count2++;
    }

    std::vector<int> result;
    if (count1 > nums.size() / 3) result.push_back(candidate1);
    if (count2 > nums.size() / 3) result.push_back(candidate2);
    return result;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};
    std::vector<int> result = majorityElementII(nums);
    std::cout << "Majority Elements: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

### 3. Majority Element Generalization

#### Problem
Find all elements that appear more than ⌊n/k⌋ times for any given k.

#### Example
- **Input**: For k = 4 and [1, 1, 1, 3, 3, 2, 2, 2, 4]
- **Output**: [1, 2]

#### Details
1. **Data Structure Used**:
   - **Array**: For storing the input elements.
   - **Hash Map**: To count the frequency of each element.

2. **Real-Life Application**:
   - **Customer Reviews Analysis**: Finding frequently mentioned products.

3. **Benefits**:
   - **Efficiency**: Linear time complexity.
   - **Space**: Uses constant space with the optimized algorithm.

4. **Limitations**:
   - **Hash Map**: Requires extra space, not suitable for memory-constrained environments.

5. **Time Complexity**:
   - **Brute Force**: O(n^2)
   - **Optimized**: O(n)

#### C++ Code

**Brute Force Approach**:
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> majorityElementGeneralization(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> countMap;
    int n = nums.size();
    std::vector<int> result;

    for (int num : nums) {
        countMap[num]++;
    }

    for (const auto& pair : countMap) {
        if (pair.second > n / k) {
            result.push_back(pair.first);
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2, 4};
    int k = 4;
    std::vector<int> result = majorityElementGeneralization(nums, k);
    std::cout << "Majority Elements: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

**Optimized Approach**:
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> majorityElementGeneralization(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> candidateCount;
    int n = nums.size

();
    for (int num : nums) {
        if (candidateCount.find(num) != candidateCount.end()) {
            candidateCount[num]++;
        } else if (candidateCount.size() < k - 1) {
            candidateCount[num] = 1;
        } else {
            for (auto it = candidateCount.begin(); it != candidateCount.end();) {
                if (--(it->second) == 0) {
                    it = candidateCount.erase(it);
                } else {
                    ++it;
                }
            }
        }
    }

    for (auto& pair : candidateCount) {
        pair.second = 0;
    }

    for (int num : nums) {
        if (candidateCount.find(num) != candidateCount.end()) {
            candidateCount[num]++;
        }
    }

    std::vector<int> result;
    for (const auto& pair : candidateCount) {
        if (pair.second > n / k) {
            result.push_back(pair.first);
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2, 4};
    int k = 4;
    std::vector<int> result = majorityElementGeneralization(nums, k);
    std::cout << "Majority Elements: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

### 4. Find Majority Element in a Sorted Array

#### Problem
Given a sorted array, find the majority element.

#### Example
- **Input**: [1, 2, 2, 2, 3, 3]
- **Output**: 2

#### Details
1. **Data Structure Used**:
   - **Array**: For storing the input elements.

2. **Real-Life Application**:
   - **Statistical Analysis**: Finding the most common value in sorted data.

3. **Benefits**:
   - **Efficiency**: Binary search can be used for optimization.

4. **Limitations**:
   - **Sorted Array**: Assumes the input array is sorted.

5. **Time Complexity**:
   - **Brute Force**: O(n)
   - **Optimized**: O(log n) using binary search

#### C++ Code

**Brute Force Approach**:
```cpp
#include <iostream>
#include <vector>

int findMajorityElementSorted(const std::vector<int>& nums) {
    int n = nums.size();
    int candidate = nums[n / 2];
    int count = 0;

    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    if (count > n / 2) {
        return candidate;
    } else {
        return -1;
    }
}

int main() {
    std::vector<int> nums = {1, 2, 2, 2, 3, 3};
    std::cout << "Majority Element: " << findMajorityElementSorted(nums) << std::endl;
    return 0;
}
```

**Optimized Approach (Binary Search)**:
```cpp
#include <iostream>
#include <vector>

bool isMajorityElement(const std::vector<int>& nums, int candidate) {
    int n = nums.size();
    int left = std::lower_bound(nums.begin(), nums.end(), candidate) - nums.begin();
    int right = std::upper_bound(nums.begin(), nums.end(), candidate) - nums.begin();
    return right - left > n / 2;
}

int findMajorityElementSorted(const std::vector<int>& nums) {
    int candidate = nums[nums.size() / 2];
    if (isMajorityElement(nums, candidate)) {
        return candidate;
    } else {
        return -1;
    }
}

int main() {
    std::vector<int> nums = {1, 2, 2, 2, 3, 3};
    std::cout << "Majority Element: " << findMajorityElementSorted(nums) << std::endl;
    return 0;
}
```

### 5. Check if an Array Has a Majority Element

#### Problem
Determine if an array contains a majority element.

#### Example
- **Input**: [1, 2, 3, 3, 3]
- **Output**: False

#### Details
1. **Data Structure Used**:
   - **Array**: For storing the input elements.
   - **Hash Map**: To count the frequency of each element.

2. **Real-Life Application**:
   - **Polls and Surveys**: Checking if a certain opinion is predominant.

3. **Benefits**:
   - **Efficiency**: Linear time complexity with hash map.
   - **Space**: Uses linear space with hash map.

4. **Limitations**:
   - **Hash Map**: Requires extra space, not suitable for memory-constrained environments.

5. **Time Complexity**:
   - **Brute Force**: O(n^2)
   - **Optimized**: O(n)

#### C++ Code

**Brute Force Approach**:
```cpp
#include <iostream>
#include <vector>

bool hasMajorityElement(const std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (nums[j] == nums[i]) {
                count++;
            }
        }
        if (count > n / 2) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 3, 3};
    std::cout << "Has Majority Element: " << (hasMajorityElement(nums) ? "True" : "False") << std::endl;
    return 0;
}
```

**Optimized Approach**:
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

bool hasMajorityElement(const std::vector<int>& nums) {
    std::unordered_map<int, int> countMap;
    int n = nums.size();

    for (int num : nums) {
        countMap[num]++;
        if (countMap[num] > n / 2) {
            return true;
        }
    }

    return false;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 3, 3};
    std::cout << "Has Majority Element: " << (hasMajorityElement(nums) ? "True" : "False") << std::endl;
    return 0;
}
```

### 6. Find k Most Frequent Elements

#### Problem
Find the k most frequent elements in an array.

#### Example
- **Input**: [1, 1, 1, 2, 2, 3], k = 2
- **Output**: [1, 2]

#### Details
1. **Data Structure Used**:
   - **Array**: For storing the input elements.
   - **Hash Map**: To count the frequency of each element.
   - **Priority Queue (Min-Heap)**: To store the top k elements.

2. **Real-Life Application**:
   - **Recommendation Systems**: Finding the most frequently viewed items.

3. **Benefits**:
   - **Efficiency**: Linear time complexity with optimized approach.
   - **Space**: Uses linear space for hash map.

4. **Limitations**:
   - **Hash Map**: Requires extra space, not suitable for memory-constrained environments.

5. **Time Complexity**:
   - **Brute Force**: O(n log n)
   - **Optimized**: O(n log k)

#### C++ Code

**Brute Force Approach**:
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> countMap;
    for (int num : nums) {
        countMap[num]++;
    }

    std::vector<std::pair<int, int>> frequencyPairs(countMap.begin(), countMap.end());
    std::sort(frequencyPairs.begin(), frequencyPairs.end(), [](const auto& a, const auto& b) {
        return b.second < a.second;
    });

    std::vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(frequencyPairs[i].first);
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    std::vector<int> result = topKFrequent(nums, k);
    std::cout << "Top " << k << " Frequent Elements: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

**Optimized Approach**:
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> countMap;
    for (int num : nums) {
        countMap[num]++;
   

 }

    auto comp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> minHeap(comp);

    for (const auto& pair : countMap) {
        minHeap.push(pair);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    std::vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().first);
        minHeap.pop();
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    std::vector<int> result = topKFrequent(nums, k);
    std::cout << "Top " << k << " Frequent Elements: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

### 7. Majority Element in Subarrays

#### Problem
Given an array and multiple subarrays, find the majority element in each subarray.

#### Example
- **Input**: array = [1, 2, 2, 2, 3, 3], subarrays = [[0, 3], [1, 5]]
- **Output**: [2, 2]

#### Details
1. **Data Structure Used**:
   - **Array**: For storing the input elements.
   - **Hash Map**: To count the frequency of each element in subarrays.

2. **Real-Life Application**:
   - **Segment Analysis**: Finding predominant elements in different segments of data.

3. **Benefits**:
   - **Efficiency**: Linear time complexity for each subarray with the optimized approach.

4. **Limitations**:
   - **Hash Map**: Requires extra space, not suitable for memory-constrained environments.

5. **Time Complexity**:
   - **Brute Force**: O(n * m), where n is the number of subarrays and m is the average length of subarrays.
   - **Optimized**: O(n * m)

#### C++ Code

**Brute Force Approach**:
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> majorityElementInSubarrays(const std::vector<int>& nums, const std::vector<std::vector<int>>& subarrays) {
    std::vector<int> result;

    for (const auto& subarray : subarrays) {
        std::unordered_map<int, int> countMap;
        int start = subarray[0];
        int end = subarray[1];
        int length = end - start + 1;
        int majorityElement = -1;

        for (int i = start; i <= end; ++i) {
            countMap[nums[i]]++;
            if (countMap[nums[i]] > length / 2) {
                majorityElement = nums[i];
                break;
            }
        }

        result.push_back(majorityElement);
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 2, 2, 2, 3, 3};
    std::vector<std::vector<int>> subarrays = {{0, 3}, {1, 5}};
    std::vector<int> result = majorityElementInSubarrays(nums, subarrays);
    std::cout << "Majority Elements in Subarrays: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

### 8. Dynamic Majority Element

#### Problem
Update the array dynamically and find the majority element after each update.

#### Example
- **Input**: [1, 2, 3], updates = [(1, 3), (2, 3)]
- **Output**: [3, 3]

#### Details
1. **Data Structure Used**:
   - **Array**: For storing the input elements.
   - **Hash Map**: To count the frequency of each element.

2. **Real-Life Application**:
   - **Dynamic Data Streams**: Finding the most frequent element in real-time data streams.

3. **Benefits**:
   - **Efficiency**: Efficient updates and queries with optimized approach.

4. **Limitations**:
   - **Hash Map**: Requires extra space, not suitable for memory-constrained environments.

5. **Time Complexity**:
   - **Brute Force**: O(n * m), where n is the number of updates and m is the size of the array.
   - **Optimized**: O(n)

#### C++ Code

**Brute Force Approach**:
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> dynamicMajorityElement(std::vector<int>& nums, const std::vector<std::pair<int, int>>& updates) {
    std::vector<int> result;

    for (const auto& update : updates) {
        nums[update.first] = update.second;

        std::unordered_map<int, int> countMap;
        int n = nums.size();
        int majorityElement = -1;

        for (int num : nums) {
            countMap[num]++;
            if (countMap[num] > n / 2) {
                majorityElement = num;
                break;
            }
        }

        result.push_back(majorityElement);
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::pair<int, int>> updates = {{1, 3}, {2, 3}};
    std::vector<int> result = dynamicMajorityElement(nums, updates);
    std::cout << "Majority Elements After Updates: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

### 9. Majority Element in Matrix

#### Problem
Find the majority element in each row of a matrix.

#### Example
- **Input**: [[1, 2, 2], [2, 2, 3], [1, 1, 1]]
- **Output**: [2, 2, 1]

#### Details
1. **Data Structure Used**:
   - **Matrix (2D Array)**: For storing the input elements.
   - **Hash Map**: To count the frequency of each element in each row.

2. **Real-Life Application**:
   - **Survey Data Analysis**: Finding predominant opinions in different groups.

3. **Benefits**:
   - **Efficiency**: Linear time complexity for each row with the optimized approach.

4. **Limitations**:
   - **Hash Map**: Requires extra space, not suitable for memory-constrained environments.

5. **Time Complexity**:
   - **Brute Force**: O(m * n), where m is the number of rows and n is the number of columns.
   - **Optimized**: O(m * n)

#### C++ Code

**Brute Force Approach**:
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> majorityElementInMatrix(const std::vector<std::vector<int>>& matrix) {
    std::vector<int> result;

    for (const auto& row : matrix) {
        std::unordered_map<int, int> countMap;
        int majorityElement = -1;
        int n = row.size();

        for (int num : row) {
            countMap[num]++;
            if (countMap[num] > n / 2) {
                majorityElement = num;
                break;
            }
        }

        result.push_back(majorityElement);
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> matrix = {{1, 2, 2}, {2, 2, 3}, {1, 1, 1}};
    std::vector<int> result = majorityElementInMatrix(matrix);
    std::cout << "Majority Elements in Matrix Rows: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

### 10. Majority Element in Streams

#### Problem
Process a stream of data and find the majority element at any point.

#### Example
- **Input**: For a stream 1, 2, 2, 3, 3, 3, after processing each element, output [1, 2, 2, 3, 3, 3]

#### Details
1. **Data Structure Used**:
   - **Array**: For storing the input elements.
   - **Hash Map**: To count the frequency of each element.

2. **Real-Life Application**:
   - **Live Polls**: Finding the most popular choice in real-time voting.

3. **Benefits**:
   - **Efficiency**: Real-time processing with linear time complexity.

4. **Limitations**:
   - **Hash Map**: Requires extra space, not suitable for memory-constrained environments.

5. **Time Complexity**:
   - **Brute Force**: O(n * m), where n is the number of elements processed

 and m is the size of the stream.
   - **Optimized**: O(n)

#### C++ Code

**Brute Force Approach**:
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> majorityElementInStream(const std::vector<int>& stream) {
    std::vector<int> result;
    std::unordered_map<int, int> countMap;
    int majorityElement = -1;
    int n = stream.size();

    for (int num : stream) {
        countMap[num]++;
        if (countMap[num] > n / 2) {
            majorityElement = num;
        }
        result.push_back(majorityElement);
    }

    return result;
}

int main() {
    std::vector<int> stream = {1, 2, 2, 3, 3, 3};
    std::vector<int> result = majorityElementInStream(stream);
    std::cout << "Majority Elements in Stream: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

optimize

```cpp
#include <iostream>
#include <vector>

std::vector<int> majorityElementInStream(const std::vector<int>& stream) {
    int candidate = -1;
    int count = 0;
    std::vector<int> result;

    for (int num : stream) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
        result.push_back(candidate);
    }

    return result;
}

int main() {
    std::vector<int> stream = {1, 2, 2, 3, 3, 3};
    std::vector<int> result = majorityElementInStream(stream);
    std::cout << "Majority Elements in Stream: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
```



These solutions cover a wide range of problems related to the majority element, from basic to more advanced and optimized approaches.

