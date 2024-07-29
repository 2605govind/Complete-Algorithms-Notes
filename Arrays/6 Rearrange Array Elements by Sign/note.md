https://youtu.be/h4aBagy4Uok?si=6i6aNr903WYuXXpV

problem = https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

### Rearrange Array Elements by Sign

**1. Data Structure Use**

Typically, arrays (or lists in Python) are used to solve this problem. Two separate arrays might be used initially to store positive and negative numbers, and then the result can be merged back into a single array.

**2. Real-Time, Real-Life Applications of This Algorithm**

In a layman’s way, this algorithm can be useful in:

- **Financial Analysis:** When analyzing stock market data, you might want to separate periods of gains (positive values) from losses (negative values) for better visualization or analysis.
- **Temperature Readings:** For weather data, you might want to separate days with above-average (positive deviation) and below-average (negative deviation) temperatures.
- **Medical Data:** In healthcare, you might need to separate positive and negative changes in patient vital signs for better monitoring and response.

**3. Benefits of This Algorithm**

- **Organized Data:** It helps in organizing data for easier analysis and processing.
- **Improved Readability:** Makes it easier to interpret data by separating different types of information.
- **Efficient Processing:** By separating the elements by their sign, you can perform sign-specific operations more efficiently.

**4. Limitations of Data Structure**

- **Memory Usage:** Using separate arrays or lists to store positive and negative numbers may consume extra memory.
- **Time Complexity:** If not optimized, the process of rearranging can be time-consuming, especially for large datasets.
- **Inflexibility:** Arrays have fixed sizes (in some languages), which may limit their use if the number of elements is not known in advance.

**5. Time Complexity and Main Logic for Brute Force to Optimize**

### Brute Force Approach

**Time Complexity:** \(O(n)\) for traversing the array and \(O(n)\) for rearranging, resulting in a total of \(O(n)\) time complexity.

**Main Logic:**

1. Traverse the array and collect positive and negative numbers in separate lists.
2. Combine the positive and negative lists by alternating their elements into a new result list.



Sure, here is the C++ code for both the brute force and optimized approaches to rearrange array elements by sign.

### Brute Force Approach

```cpp
#include <iostream>
#include <vector>

std::vector<int> rearrangeBySign(const std::vector<int>& arr) {
    std::vector<int> pos;
    std::vector<int> neg;
    
    // Separate positive and negative numbers
    for (int num : arr) {
        if (num > 0) {
            pos.push_back(num);
        } else if (num < 0) {
            neg.push_back(num);
        }
    }
    
    std::vector<int> result;
    int i = 0, j = 0;
    
    // Alternate between positive and negative numbers
    while (i < pos.size() && j < neg.size()) {
        result.push_back(pos[i++]);
        result.push_back(neg[j++]);
    }
    
    // Add remaining positive numbers
    while (i < pos.size()) {
        result.push_back(pos[i++]);
    }
    
    // Add remaining negative numbers
    while (j < neg.size()) {
        result.push_back(neg[j++]);
    }
    
    return result;
}

int main() {
    std::vector<int> arr = {1, -2, 3, -4, 5, -6};
    std::vector<int> result = rearrangeBySign(arr);
    
    for (int num : result) {
        std::cout << num << " ";
    }
    
    return 0;
}
```


// this code does not give correct output of some cases
### Optimized Approach

```cpp
#include <iostream>
#include <vector>

// using shifting process
void rearrangeBySignOptimized(std::vector<int>& arr) {
    int n = arr.size();
    int posIndex = 0;
    int negIndex = 1;
    
    while (true) {
        // Find the first misplaced positive at even index
        while (posIndex < n && arr[posIndex] > 0) {
            posIndex += 2;
        }
        
        // Find the first misplaced negative at odd index
        while (negIndex < n && arr[negIndex] < 0) {
            negIndex += 2;
        }
        
        // If either index goes out of bounds, rearrangement is done
        if (posIndex >= n || negIndex >= n) {
            break;
        }
        
        // Swap misplaced positive and negative elements
        std::swap(arr[posIndex], arr[negIndex]);
    }
}

int main() {
    std::vector<int> arr = {1, -2, 3, -4, 5, -6};
    rearrangeBySignOptimized(arr);
    
    for (int num : arr) {
        std::cout << num << " ";
    }
    
    return 0;
}
```

Both codes achieve the rearrangement of array elements by sign, with the optimized approach doing it in-place to save space. The brute force approach uses extra space to store separate positive and negative numbers before combining them.