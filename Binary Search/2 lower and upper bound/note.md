lower bound = smallest index such that ( wo value jaha pe target value exits karti hai)

condition arr[mid] >= target move left side

   0  1  2  3   4
=> 3, 5, 8, 15, 19

target = 8, ans = 2
target = 9, ans = 3
target = 16, ans = 4
target = 20, ans = 5 , hypothetical


using stl
index = lower_bound(arr, arr+n) - arr




lower bound = smallest index such that 

condition arr[mid] > target => move left side

   0  1  2  3  4  5  6   7   8   9
=> 2, 3, 6, 7, 8, 8, 11, 11, 11, 12

target = 6, ans = 3
target = 11, ans = 9
target = 13, ans = 10 hypothetical
target = 0, ans = 0 


using stl
index = upper_bound(arr, arr+n) - arr





problems based on it
1. search insert position (kaha pe insert hoga)
2. floor and ceil in sorted array
    floor = largest no in array <= x
    ceil = smallest no in array >= x  => lower bound
3. find first and last occurrence of array (lower and upper boud) ()
4. finding number of occurrence 








### Lower Bound Algorithm: Key Points

#### 1. Data Structures Used
- **Arrays:** For storing and processing sequences where a lower bound is needed.
- **Binary Search Trees (BST):** Efficient for finding lower bounds in sorted data.
- **Heaps:** Useful for priority queue operations, such as finding the minimum element.
- **Dynamic Programming Tables:** To store intermediate results and compute lower bounds in optimization problems.

#### 2. Real-Time, Real-Life Applications (Use Cases)
- **Searching in Sorted Data:**
  - **Scenario:** Finding the earliest available appointment in a sorted schedule.
  - **Use:** Use a lower bound algorithm to quickly locate the first available time slot.
- **Job Scheduling:**
  - **Scenario:** Assigning tasks to workers to minimize total completion time.
  - **Use:** Determine the minimum possible time to complete all tasks, helping to optimize worker assignments.
- **Route Planning:**
  - **Scenario:** Finding the shortest route for delivery trucks.
  - **Use:** Calculate the minimum distance or time needed to deliver all packages, ensuring efficient route planning.
- **Resource Allocation:**
  - **Scenario:** Allocating limited resources (like hospital beds) efficiently.
  - **Use:** Determine the minimum number of beds needed to handle peak demand, aiding in resource management.

#### 3. Benefits of the Algorithm
- **Efficiency Benchmark:** Provides a benchmark for the minimum possible effort or cost, helping to evaluate the efficiency of other algorithms.
- **Optimization Guide:** Helps guide optimization efforts by indicating the best possible outcome.
- **Resource Planning:** Assists in efficient resource allocation and planning in various fields like logistics, scheduling, and manufacturing.
- **Performance Measurement:** Useful for measuring and improving the performance of systems and processes.

#### 4. Limitations of Data Structures
- **Arrays:** Fixed size, less flexible for dynamic data.
- **Binary Search Trees (BST):** Can become unbalanced, leading to inefficient operations.
- **Heaps:** Limited to specific operations (like finding minimum or maximum), not suitable for general-purpose use.
- **Dynamic Programming Tables:** Can consume a lot of memory for large problems, leading to inefficiency.

#### 5. Time Complexity and Main Logic

**Brute Force Approach:**
- **Main Logic:** Explore all possible solutions to find the minimum.
- **Time Complexity:** \(O(n!)\) for problems like the Traveling Salesman Problem (TSP), as it involves checking all permutations of routes.

**Optimized Approach:**
- **Main Logic:** Use more efficient algorithms, like Dynamic Programming or Divide and Conquer, to reduce the number of operations.
- **Time Complexity:**
  - **Dynamic Programming (TSP):** \(O(n^2 \cdot 2^n)\), significantly better than \(O(n!)\).
  - **Binary Search for Lower Bound in Sorted Array:** \(O(\log n)\).

**Example: Lower Bound in a Sorted Array**
- **Brute Force:** Linear search to find the first element greater than or equal to a target.
  - **Logic:** Iterate through each element until the condition is met.
  - **Time Complexity:** \(O(n)\).

**Optimized Approach: Binary Search**
- **Main Logic:** Use binary search to efficiently find the lower bound.
  - **Algorithm:**
    1. Initialize `low` to 0 and `high` to the last index.
    2. While `low` is less than or equal to `high`:
       - Calculate `mid` as the middle index.
       - If the middle element is less than the target, move `low` to `mid + 1`.
       - Else, move `high` to `mid - 1`.
    3. `low` will be the index of the lower bound.
  - **Time Complexity:** \(O(\log n)\).















  ### Upper Bound Algorithm: Key Points

#### 1. Data Structures Used
- **Arrays:** Commonly used for storing and processing sequences where an upper bound is needed.
- **Binary Search Trees (BST):** Efficient for finding upper bounds in sorted data.
- **Heaps:** Useful for priority queue operations, such as finding the maximum element.
- **Dynamic Programming Tables:** To store intermediate results and compute upper bounds in optimization problems.

#### 2. Real-Time, Real-Life Applications (Use Cases)
- **Finding the Latest Available Time:**
  - **Scenario:** Determining the latest available appointment slot in a schedule.
  - **Use:** Use an upper bound algorithm to quickly locate the latest time slot that meets specific criteria.
- **Maximum Capacity Planning:**
  - **Scenario:** Determining the maximum capacity a venue can handle without exceeding safety limits.
  - **Use:** Calculate the maximum number of people or resources that can be accommodated, ensuring efficient planning.
- **Inventory Management:**
  - **Scenario:** Ensuring inventory does not exceed storage capacity.
  - **Use:** Determine the maximum amount of inventory that can be stored, helping to optimize space usage.
- **Investment Planning:**
  - **Scenario:** Determining the maximum investment amount that does not exceed budget constraints.
  - **Use:** Calculate the upper limit for investments, ensuring efficient financial planning.

#### 3. Benefits of the Algorithm
- **Efficiency Benchmark:** Provides a benchmark for the maximum possible effort or cost, helping to evaluate the efficiency of other algorithms.
- **Optimization Guide:** Helps guide optimization efforts by indicating the worst-case scenario.
- **Resource Planning:** Assists in efficient resource allocation and planning in various fields like logistics, scheduling, and inventory management.
- **Performance Measurement:** Useful for measuring and improving the performance of systems and processes.

#### 4. Limitations of Data Structures
- **Arrays:** Fixed size, less flexible for dynamic data.
- **Binary Search Trees (BST):** Can become unbalanced, leading to inefficient operations.
- **Heaps:** Limited to specific operations (like finding minimum or maximum), not suitable for general-purpose use.
- **Dynamic Programming Tables:** Can consume a lot of memory for large problems, leading to inefficiency.

#### 5. Time Complexity and Main Logic

**Brute Force Approach:**
- **Main Logic:** Explore all possible solutions to find the maximum.
- **Time Complexity:** \(O(n!)\) for problems like the Traveling Salesman Problem (TSP), as it involves checking all permutations of routes.

**Optimized Approach:**
- **Main Logic:** Use more efficient algorithms, like Dynamic Programming or Divide and Conquer, to reduce the number of operations.
- **Time Complexity:**
  - **Dynamic Programming (TSP):** \(O(n^2 \cdot 2^n)\), significantly better than \(O(n!)\).
  - **Binary Search for Upper Bound in Sorted Array:** \(O(\log n)\).

**Example: Upper Bound in a Sorted Array**
- **Brute Force:** Linear search to find the first element greater than a target.
  - **Logic:** Iterate through each element until the condition is met.
  - **Time Complexity:** \(O(n)\).

**Optimized Approach: Binary Search**
- **Main Logic:** Use binary search to efficiently find the upper bound.
  - **Algorithm:**
    1. Initialize `low` to 0 and `high` to the last index.
    2. While `low` is less than or equal to `high`:
       - Calculate `mid` as the middle index.
       - If the middle element is less than or equal to the target, move `low` to `mid + 1`.
       - Else, move `high` to `mid - 1`.
    3. `low` will be the index of the upper bound.
  - **Time Complexity:** \(O(\log n)\).