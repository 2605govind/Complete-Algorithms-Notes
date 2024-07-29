Here's a detailed breakdown of various problem patterns related to the "Next Permutation" algorithm:

### 1. **Basic Next Permutation**

#### Problem
Find the next lexicographically greater permutation of a list of numbers.

#### Example
- **Input**: [1, 2, 3]
- **Output**: [1, 3, 2]

#### 1. **Data Structure Used**
   - **Array or Vector**: To store the permutation.

#### 2. **Real-Life Applications**
   1. **Scheduling**: Generating the next possible schedule from a list of tasks.
   2. **Game Development**: Determining the next possible move or configuration in a game.
   3. **Lexicographical Sorting**: Finding the next permutation in a sequence to sort lexicographically.
   4. **Cryptography**: Generating the next sequence in key permutations for security algorithms.
   5. **Genetic Algorithms**: Evolving permutations to find optimal solutions.

#### 3. **Benefits**
   - **Efficiency**: Provides the next permutation in constant time relative to the size of the permutation.
   - **Simplicity**: Straightforward to implement with minimal operations.

#### 4. **Limitations**
   - **Space Complexity**: Involves operations on the entire array or vector.
   - **Order of Operations**: Requires a complete pass through the array to find the next permutation.

#### 5. **Time Complexity and Main Logic**

   - **Brute Force**: O(n!) - Generate all permutations and find the next one.
   - **Optimized**: O(n)
     1. Traverse from the end to find the first decreasing element.
     2. Find the smallest element larger than the first decreasing element.
     3. Swap the two elements.
     4. Reverse the sequence after the initial position.

   **C++ Code**

   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>

   void nextPermutation(std::vector<int>& nums) {
       int n = nums.size();
       int i = n - 2;

       // Find the first decreasing element
       while (i >= 0 && nums[i] >= nums[i + 1]) {
           i--;
       }

       if (i >= 0) {
           int j = n - 1;

           // Find the element just larger than nums[i]
           while (j >= 0 && nums[j] <= nums[i]) {
               j--;
           }

           // Swap them
           std::swap(nums[i], nums[j]);
       }

       // Reverse the array from i+1 to end
       std::reverse(nums.begin() + i + 1, nums.end());
   }

   int main() {
       std::vector<int> nums = {1, 2, 3};
       nextPermutation(nums);
       std::cout << "Next Permutation: ";
       for (int num : nums) {
           std::cout << num << " ";
       }
       std::cout << std::endl;
       return 0;
   }
   ```

### 2. **Previous Permutation**

#### Problem
Find the previous lexicographically smaller permutation of a list of numbers.

#### Example
- **Input**: [1, 3, 2]
- **Output**: [1, 2, 3]

#### 1. **Data Structure Used**
   - **Array or Vector**: To store the permutation.

#### 2. **Real-Life Applications**
   1. **Scheduling**: Finding the previous schedule configuration before a given one.
   2. **Game Development**: Determining the previous possible move or configuration in a game.
   3. **Lexicographical Sorting**: Finding the previous permutation in a sequence to sort lexicographically.
   4. **Cryptography**: Generating previous sequence permutations for key validation.
   5. **Genetic Algorithms**: Evolving permutations backward to find alternative solutions.

#### 3. **Benefits**
   - **Efficiency**: Provides the previous permutation in constant time relative to the size of the permutation.
   - **Simplicity**: Easily implemented with clear steps.

#### 4. **Limitations**
   - **Space Complexity**: Similar to the next permutation, involves operations on the entire array or vector.
   - **Order of Operations**: Requires a complete pass through the array to find the previous permutation.

#### 5. **Time Complexity and Main Logic**

   - **Brute Force**: O(n!) - Generate all permutations and find the previous one.
   - **Optimized**: O(n)
     1. Traverse from the end to find the first increasing element.
     2. Find the largest element smaller than the first increasing element.
     3. Swap the two elements.
     4. Reverse the sequence after the initial position.

   **C++ Code**

   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>

   void prevPermutation(std::vector<int>& nums) {
       int n = nums.size();
       int i = n - 2;

       // Find the first increasing element
       while (i >= 0 && nums[i] <= nums[i + 1]) {
           i--;
       }

       if (i >= 0) {
           int j = n - 1;

           // Find the element just smaller than nums[i]
           while (j >= 0 && nums[j] >= nums[i]) {
               j--;
           }

           // Swap them
           std::swap(nums[i], nums[j]);
       }

       // Reverse the array from i+1 to end
       std::reverse(nums.begin() + i + 1, nums.end());
   }

   int main() {
       std::vector<int> nums = {1, 3, 2};
       prevPermutation(nums);
       std::cout << "Previous Permutation: ";
       for (int num : nums) {
           std::cout << num << " ";
       }
       std::cout << std::endl;
       return 0;
   }
   ```

### 3. **All Permutations**

#### Problem
Generate all permutations of a list of numbers.

#### Example
- **Input**: [1, 2, 3]
- **Output**: [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]

#### 1. **Data Structure Used**
   - **Array or Vector**: To store the permutations.
   - **Stack or Recursion**: For generating permutations.

#### 2. **Real-Life Applications**
   1. **Scheduling**: Finding all possible schedules for a set of tasks.
   2. **Game Development**: Generating all possible moves or configurations in a game.
   3. **Cryptography**: Exploring all possible key combinations for encryption algorithms.
   4. **Genetic Algorithms**: Evaluating all possible solutions to find the optimal one.
   5. **Combinatorial Problems**: Solving problems involving all possible arrangements or combinations.

#### 3. **Benefits**
   - **Comprehensive**: Provides a complete set of permutations.
   - **Versatile**: Useful for a wide range of applications involving permutations.

#### 4. **Limitations**
   - **Time Complexity**: Factorial growth with respect to the number of elements.
   - **Space Complexity**: Requires storage for all permutations, which can be large.

#### 5. **Time Complexity and Main Logic**

   - **Brute Force**: O(n!) - Generate all permutations directly.
   - **Optimized**: O(n!) - Efficiently generate permutations using backtracking.

   **C++ Code**

   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>

   void generatePermutations(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
       if (start == nums.size()) {
           result.push_back(nums);
           return;
       }

       for (int i = start; i < nums.size(); ++i) {
           std::swap(nums[start], nums[i]);
           generatePermutations(nums, start + 1, result);
           std::swap(nums[start], nums[i]);
       }
   }

   std::vector<std::vector<int>> allPermutations(std::vector<int>& nums) {
       std::vector<std::vector<int>> result;
       generatePermutations(nums, 0, result);
       return result;
   }

   int main() {
       std::vector<int> nums = {1, 2, 3};
       std::vector<std::vector<int>> result = allPermutations(nums);
       std::cout << "All Permutations: " << std::endl;
       for (const auto& perm : result) {
           for (int num : perm) {
               std::cout << num << " ";
           }
           std::cout << std::endl;
       }
       return 0;
   }
   ```

### 4. **Next Permutation in Lexicographical Order**

#### Problem
Find the next permutation in lexicographical order given a list of numbers.

#### Example
- **Input**: [1, 2, 3]
- **Output**: [1, 3, 2]

#### 1. **Data Structure Used**
   - **Array or Vector**: To store the permutation.

#### 2. **Real-Life Applications**
   1. **Scheduling**: Finding the

 next possible schedule or order.
   2. **Game Development**: Generating the next move or configuration.
   3. **Lexicographical Sorting**: Generating permutations for lexicographical ordering.
   4. **Cryptography**: Generating next permutations for secure keys.
   5. **Genetic Algorithms**: Evolving permutations to find better solutions.

#### 3. **Benefits**
   - **Efficiency**: Generates the next permutation in linear time.
   - **Simplicity**: Clear and straightforward implementation.

#### 4. **Limitations**
   - **Space Complexity**: Operations on the entire array or vector.
   - **Order of Operations**: Requires a complete pass through the array.

#### 5. **Time Complexity and Main Logic**

   - **Brute Force**: O(n!) - Generate all permutations and find the next.
   - **Optimized**: O(n) - Efficiently find the next permutation using the Boyer-Moore Voting Algorithm.

   **C++ Code** (Same as above)

### 5. **Generating Permutations with Duplicates**

#### Problem
Generate all unique permutations of a list of numbers that may include duplicates.

#### Example
- **Input**: [1, 1, 2]
- **Output**: [1, 1, 2], [1, 2, 1], [2, 1, 1]

#### 1. **Data Structure Used**
   - **Array or Vector**: To store the permutations.
   - **Set**: To keep track of used permutations to avoid duplicates.

#### 2. **Real-Life Applications**
   1. **Scheduling**: Generating all unique schedules when some tasks are identical.
   2. **Game Development**: Finding unique configurations in games with repetitive elements.
   3. **Lexicographical Sorting**: Ensuring all permutations are unique.
   4. **Cryptography**: Generating unique key combinations.
   5. **Genetic Algorithms**: Evolving unique solutions in the presence of duplicates.

#### 3. **Benefits**
   - **Uniqueness**: Ensures that all permutations are unique, even with duplicate elements.
   - **Comprehensive**: Covers all possible unique arrangements.

#### 4. **Limitations**
   - **Time Complexity**: O(n!) - Factorial growth with unique permutations.
   - **Space Complexity**: Requires space to store all unique permutations.

#### 5. **Time Complexity and Main Logic**

   - **Brute Force**: O(n!) - Generate all permutations and filter out duplicates.
   - **Optimized**: O(n!) - Generate unique permutations using backtracking and sorting.

   **C++ Code**

   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>

   void generateUniquePermutations(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
       if (start == nums.size()) {
           result.push_back(nums);
           return;
       }

       std::set<int> seen;
       for (int i = start; i < nums.size(); ++i) {
           if (seen.find(nums[i]) != seen.end()) continue;
           seen.insert(nums[i]);
           std::swap(nums[start], nums[i]);
           generateUniquePermutations(nums, start + 1, result);
           std::swap(nums[start], nums[i]);
       }
   }

   std::vector<std::vector<int>> uniquePermutations(std::vector<int>& nums) {
       std::vector<std::vector<int>> result;
       std::sort(nums.begin(), nums.end());
       generateUniquePermutations(nums, 0, result);
       return result;
   }

   int main() {
       std::vector<int> nums = {1, 1, 2};
       std::vector<std::vector<int>> result = uniquePermutations(nums);
       std::cout << "Unique Permutations: " << std::endl;
       for (const auto& perm : result) {
           for (int num : perm) {
               std::cout << num << " ";
           }
           std::cout << std::endl;
       }
       return 0;
   }
   ```

These patterns and optimizations cover various aspects of the Next Permutation problem, ensuring that you can handle a range of scenarios efficiently.