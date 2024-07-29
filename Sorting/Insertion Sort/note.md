Insertion sort is a simple and intuitive sorting algorithm that builds the final sorted array one item at a time.

advantage => stable, in-place


How Insertion Sort Works
1. Start with the second element: Assume the first element is already sorted. Take the second element and compare it with the first. If the second element is smaller, swap them.

2. Move to the next element: Take the next element in the array and compare it with the elements in the sorted part (to its left). Insert this element into the correct position by shifting all larger elements one position to the right.

3. Repeat: Continue this process for all remaining elements in the array.


## Time Complexity

- **Best case:** \( O(n) \) - when the array is already sorted
- **Average case:** \( O(n^2) \)
- **Worst case:** \( O(n^2) \) - when the array is sorted in reverse order



```cpp

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, 
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

```
