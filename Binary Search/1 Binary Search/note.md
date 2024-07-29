## Basics of Data Structures
- **Data Structure:** A way of organizing and storing data so that it can be accessed and manipulated efficiently.
- **Arrays:** A fundamental data structure storing elements of the same type in contiguous memory locations.

## Real-Life Application of Binary Search
- **Application:** Finding an item in a sorted list quickly.
- **Example:** Searching for a word in a dictionary, searching for a contact in a sorted phonebook.

## Notes on Binary Search Code
- **Time Complexity:** `O(log n)` for //both iterative and recursive versions.
  - **Explanation:** Each comparison reduces the search space by half, making it logarithmic.
- **Main Logic (Brute Force to Optimize):**
  - **Brute Force:** Linear search (`O(n)` complexity) where each element is checked sequentially until the target is found or the list ends.
  - **Optimized Approach:** Binary search reduces the search space by half with each comparison, making it much faster (`O(log n)` complexity).
