Sure, let's go through each of the 15 matrix transformations with the requested details:

### 1. 90-Degree Clockwise Rotation
**Transformation:**
Each element \((i, j)\) moves to \((j, n-1-i)\).

#### Example Input and Output
**Input Matrix:**
```
1  2  3
4  5  6
7  8  9
```

**Output Matrix:**
```
7  4  1
8  5  2
9  6  3
```

**Explanation:**
- The first row becomes the last column.
- The second row becomes the second column.
- The third row becomes the first column.

#### Real Life Applications
1. **Image Rotation:**
   - **Explanation:** Used in rotating images in photo editing software.
   - **Benefit:** Allows for changing image orientation.
   
2. **Game Development:**
   - **Explanation:** Used to rotate game boards or pieces.
   - **Benefit:** Enhances gameplay and user experience.

3. **Data Visualization:**
   - **Explanation:** Rotating graphs or plots.
   - **Benefit:** Better data presentation.

4. **Robotics:**
   - **Explanation:** Rotating sensor data.
   - **Benefit:** Improves robot navigation.

5. **Medical Imaging:**
   - **Explanation:** Rotating MRI or CT scans.
   - **Benefit:** Better visualization for diagnosis.

#### Benefits
- Efficient transformation with minimal computational overhead.
- Easy to understand and implement.

#### Limitations
- Limited to square matrices for simplicity.
- Handling edge cases can complicate the implementation.

#### Time Complexity and Optimized Code
**Time Complexity:** \(O(N^2)\)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

void rotate90Clockwise(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int layer = 0; layer < n / 2; ++layer) {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; ++i) {
            int offset = i - first;
            int top = matrix[first][i];
            matrix[first][i] = matrix[last - offset][first];
            matrix[last - offset][first] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[i][last];
            matrix[i][last] = top;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotate90Clockwise(matrix);

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### 2. 90-Degree Counterclockwise Rotation
**Transformation:**
Each element \((i, j)\) moves to \((n-1-j, i)\).

#### Example Input and Output
**Input Matrix:**
```
1  2  3
4  5  6
7  8  9
```

**Output Matrix:**
```
3  6  9
2  5  8
1  4  7
```

**Explanation:**
- The first row becomes the first column (reversed).
- The second row becomes the second column (reversed).
- The third row becomes the third column (reversed).

#### Real Life Applications
1. **Image Rotation:**
   - **Explanation:** Used in rotating images in photo editing software.
   - **Benefit:** Allows for changing image orientation.
   
2. **Game Development:**
   - **Explanation:** Used to rotate game boards or pieces.
   - **Benefit:** Enhances gameplay and user experience.

3. **Data Visualization:**
   - **Explanation:** Rotating graphs or plots.
   - **Benefit:** Better data presentation.

4. **Robotics:**
   - **Explanation:** Rotating sensor data.
   - **Benefit:** Improves robot navigation.

5. **Medical Imaging:**
   - **Explanation:** Rotating MRI or CT scans.
   - **Benefit:** Better visualization for diagnosis.

#### Benefits
- Efficient transformation with minimal computational overhead.
- Easy to understand and implement.

#### Limitations
- Limited to square matrices for simplicity.
- Handling edge cases can complicate the implementation.

#### Time Complexity and Optimized Code
**Time Complexity:** \(O(N^2)\)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

void rotate90Counterclockwise(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int layer = 0; layer < n / 2; ++layer) {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; ++i) {
            int offset = i - first;
            int top = matrix[first][i];
            matrix[first][i] = matrix[i][last];
            matrix[i][last] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[last - offset][first];
            matrix[last - offset][first] = top;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotate90Counterclockwise(matrix);

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### 3. 180-Degree Rotation
**Transformation:**
Each element \((i, j)\) moves to \((n-1-i, n-1-j)\).

#### Example Input and Output
**Input Matrix:**
```
1  2  3
4  5  6
7  8  9
```

**Output Matrix:**
```
9  8  7
6  5  4
3  2  1
```

**Explanation:**
- The first row becomes the last row (reversed).
- The second row becomes the second row (reversed).
- The third row becomes the first row (reversed).

#### Real Life Applications
1. **Image Rotation:**
   - **Explanation:** Used in rotating images in photo editing software.
   - **Benefit:** Allows for changing image orientation.
   
2. **Game Development:**
   - **Explanation:** Used to rotate game boards or pieces.
   - **Benefit:** Enhances gameplay and user experience.

3. **Data Visualization:**
   - **Explanation:** Rotating graphs or plots.
   - **Benefit:** Better data presentation.

4. **Robotics:**
   - **Explanation:** Rotating sensor data.
   - **Benefit:** Improves robot navigation.

5. **Medical Imaging:**
   - **Explanation:** Rotating MRI or CT scans.
   - **Benefit:** Better visualization for diagnosis.

#### Benefits
- Efficient transformation with minimal computational overhead.
- Easy to understand and implement.

#### Limitations
- Limited to square matrices for simplicity.
- Handling edge cases can complicate the implementation.

#### Time Complexity and Optimized Code
**Time Complexity:** \(O(N^2)\)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

void rotate180(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < (n + 1) / 2; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            swap(matrix[i][j], matrix[n - 1 - i][n - 1 - j]);
            swap(matrix[n - 1 - i][j], matrix[i][n - 1 - j]);
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotate180(matrix);

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### 4. Transpose of the Matrix
**Transformation:**
Each element \((i, j)\) swaps with \((j, i)\).

#### Example Input and Output
**Input Matrix:**
```
1  2  3
4  5  6
7  8  9
```

**Output Matrix:**
```
1  4  7
2  5  8
3  6  9
```

**Explanation:**
- The first row becomes the first column.
- The second row becomes the second column.
- The third row becomes the third column.

#### Real Life Applications
1. **Matrix Multiplication:**
   - **Explanation:** Used in matrix multiplication algorithms.
   - **Benefit:** Facilitates efficient matrix operations.

2. **Data Analysis:**
   - **Explanation:** Transposing datasets in spreadsheets.
   - **Benefit:** Better data organization.

3. **Computer

 Graphics:**
   - **Explanation:** Transposing transformation matrices.
   - **Benefit:** Efficient rendering of 3D scenes.

4. **Signal Processing:**
   - **Explanation:** Transposing matrices in digital filters.
   - **Benefit:** Enhances signal processing efficiency.

5. **Scientific Computing:**
   - **Explanation:** Used in various scientific algorithms.
   - **Benefit:** Facilitates complex computations.

#### Benefits
- Simple and efficient transformation.
- Useful in various mathematical and computational applications.

#### Limitations
- Limited to square matrices for simplicity.
- Handling non-square matrices can complicate the implementation.

#### Time Complexity and Optimized Code
**Time Complexity:** \(O(N^2)\)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

void transpose(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    transpose(matrix);

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### 5. Reverse Rows
**Transformation:**
Each row is reversed.

#### Example Input and Output
**Input Matrix:**
```
1  2  3
4  5  6
7  8  9
```

**Output Matrix:**
```
3  2  1
6  5  4
9  8  7
```

**Explanation:**
- Each row is reversed independently.

#### Real Life Applications
1. **Image Processing:**
   - **Explanation:** Reversing rows of an image.
   - **Benefit:** Allows for flipping images horizontally.

2. **Data Analysis:**
   - **Explanation:** Reversing rows in datasets.
   - **Benefit:** Reorganizes data for better analysis.

3. **Game Development:**
   - **Explanation:** Reversing game board rows.
   - **Benefit:** Enhances gameplay mechanics.

4. **Robotics:**
   - **Explanation:** Reversing sensor data rows.
   - **Benefit:** Improves robot navigation.

5. **Medical Imaging:**
   - **Explanation:** Reversing rows in MRI or CT scans.
   - **Benefit:** Better visualization for diagnosis.

#### Benefits
- Simple and efficient transformation.
- Useful in various image processing and data analysis tasks.

#### Limitations
- Limited to reversing rows only.
- Does not change overall structure of the matrix.

#### Time Complexity and Optimized Code
**Time Complexity:** \(O(N^2)\)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

void reverseRows(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    reverseRows(matrix);

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### 6. Reverse Columns
**Transformation:**
Each column is reversed.

#### Example Input and Output
**Input Matrix:**
```
1  2  3
4  5  6
7  8  9
```

**Output Matrix:**
```
7  8  9
4  5  6
1  2  3
```

**Explanation:**
- Each column is reversed independently.

#### Real Life Applications
1. **Image Processing:**
   - **Explanation:** Reversing columns of an image.
   - **Benefit:** Allows for flipping images vertically.

2. **Data Analysis:**
   - **Explanation:** Reversing columns in datasets.
   - **Benefit:** Reorganizes data for better analysis.

3. **Game Development:**
   - **Explanation:** Reversing game board columns.
   - **Benefit:** Enhances gameplay mechanics.

4. **Robotics:**
   - **Explanation:** Reversing sensor data columns.
   - **Benefit:** Improves robot navigation.

5. **Medical Imaging:**
   - **Explanation:** Reversing columns in MRI or CT scans.
   - **Benefit:** Better visualization for diagnosis.

#### Benefits
- Simple and efficient transformation.
- Useful in various image processing and data analysis tasks.

#### Limitations
- Limited to reversing columns only.
- Does not change overall structure of the matrix.

#### Time Complexity and Optimized Code
**Time Complexity:** \(O(N^2)\)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

void reverseColumns(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n / 2; ++i) {
            swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    reverseColumns(matrix);

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### 7. Rotate Layers
**Transformation:**
Elements within concentric layers (rings) of the matrix are rotated.

#### Example Input and Output
**Input Matrix:**
```
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
```

**Output Matrix after rotating outer layer clockwise:**
```
13  9  5  1
14  6  7  2
15  10 11 3
16  12 8  4
```

**Explanation:**
- Elements in the outermost ring are rotated clockwise.
- Inner rings remain unchanged.

#### Real Life Applications
1. **Image Processing:**
   - **Explanation:** Rotating specific layers of an image.
   - **Benefit:** Allows for selective rotation within images.

2. **Game Development:**
   - **Explanation:** Rotating layers in game boards.
   - **Benefit:** Enhances gameplay mechanics.

3. **Data Visualization:**
   - **Explanation:** Rotating specific layers in visualizations.
   - **Benefit:** Better data presentation.

4. **Robotics:**
   - **Explanation:** Rotating layers of sensor data.
   - **Benefit:** Improves robot navigation.

5. **Medical Imaging:**
   - **Explanation:** Rotating layers in MRI or CT scans.
   - **Benefit:** Better visualization for diagnosis.

#### Benefits
- Allows selective rotation within a matrix.
- Useful in complex image processing and game development tasks.

#### Limitations
- Complex implementation for large matrices.
- May require additional memory for intermediate storage.

#### Time Complexity and Optimized Code
**Time Complexity:** \(O(N^2)\)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

void rotateLayer(vector<vector<int>>& matrix, int layer) {
    int n = matrix.size();
    int first = layer;
    int last = n - 1 - layer;
    for (int i = first; i < last; ++i) {
        int offset = i - first;
        int top = matrix[first][i];
        matrix[first][i] = matrix[last - offset][first];
        matrix[last - offset][first] = matrix[last][last - offset];
        matrix[last][last - offset] = matrix[i][last];
        matrix[i][last] = top;
    }
}

void rotateLayers(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int layer = 0; layer < n / 2; ++layer) {
        rotateLayer(matrix, layer);
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotateLayers(matrix);

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### 8. Diagonal Flip (Main Diagonal)
**Transformation:**
Each element \((i, j)\) swaps with \((j, i)\) on the main diagonal.

#### Example Input and Output
**Input Matrix:**
```
1  

 2  3
4   5  6
7   8  9
```

**Output Matrix:**
```
1   4  7
2   5  8
3   6  9
```

**Explanation:**
- Elements are swapped along the main diagonal.

#### Real Life Applications
1. **Image Processing:**
   - **Explanation:** Flipping images along the main diagonal.
   - **Benefit:** Useful for image transformations.

2. **Data Analysis:**
   - **Explanation:** Transposing data sets.
   - **Benefit:** Enhances data organization.

3. **Game Development:**
   - **Explanation:** Transposing game boards.
   - **Benefit:** Provides different perspectives in gameplay.

4. **Robotics:**
   - **Explanation:** Transposing sensor data.
   - **Benefit:** Better data interpretation.

5. **Medical Imaging:**
   - **Explanation:** Flipping medical scans.
   - **Benefit:** Different diagnostic views.

#### Benefits
- Simple transformation.
- Useful for data reorganization.

#### Limitations
- Limited to square matrices.
- May not be useful for non-square matrices.

#### Time Complexity and Optimized Code
**Time Complexity:** \(O(N^2)\)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

void diagonalFlipMain(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    diagonalFlipMain(matrix);

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### 9. Diagonal Flip (Anti-Diagonal)
**Transformation:**
Each element \((i, j)\) swaps with \((n-1-j, n-1-i)\) on the anti-diagonal.

#### Example Input and Output
**Input Matrix:**
```
1  2  3
4  5  6
7  8  9
```

**Output Matrix:**
```
9  6  3
8  5  2
7  4  1
```

**Explanation:**
- Elements are swapped along the anti-diagonal.

#### Real Life Applications
1. **Image Processing:**
   - **Explanation:** Flipping images along the anti-diagonal.
   - **Benefit:** Useful for image transformations.

2. **Data Analysis:**
   - **Explanation:** Transposing data sets.
   - **Benefit:** Enhances data organization.

3. **Game Development:**
   - **Explanation:** Transposing game boards.
   - **Benefit:** Provides different perspectives in gameplay.

4. **Robotics:**
   - **Explanation:** Transposing sensor data.
   - **Benefit:** Better data interpretation.

5. **Medical Imaging:**
   - **Explanation:** Flipping medical scans.
   - **Benefit:** Different diagnostic views.

#### Benefits
- Simple transformation.
- Useful for data reorganization.

#### Limitations
- Limited to square matrices.
- May not be useful for non-square matrices.

#### Time Complexity and Optimized Code
**Time Complexity:** \(O(N^2)\)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

void diagonalFlipAnti(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    diagonalFlipAnti(matrix);

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### 10. Reflect Over Middle Row
**Transformation:**
Each element \((i, j)\) swaps with \((n-1-i, j)\).

#### Example Input and Output
**Input Matrix:**
```
1  2  3
4  5  6
7  8  9
```

**Output Matrix:**
```
7  8  9
4  5  6
1  2  3
```

**Explanation:**
- Each row is swapped with its corresponding row from the bottom.

#### Real Life Applications
1. **Image Processing:**
   - **Explanation:** Flipping images vertically.
   - **Benefit:** Useful for image transformations.

2. **Data Analysis:**
   - **Explanation:** Flipping data sets.
   - **Benefit:** Enhances data organization.

3. **Game Development:**
   - **Explanation:** Flipping game boards.
   - **Benefit:** Provides different perspectives in gameplay.

4. **Robotics:**
   - **Explanation:** Flipping sensor data.
   - **Benefit:** Better data interpretation.

5. **Medical Imaging:**
   - **Explanation:** Flipping medical scans.
   - **Benefit:** Different diagnostic views.

#### Benefits
- Simple transformation.
- Useful for data reorganization.

#### Limitations
- Limited to square matrices.
- May not be useful for non-square matrices.

#### Time Complexity and Optimized Code
**Time Complexity:** \(O(N^2)\)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

void reflectMiddleRow(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n; ++j) {
            swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    reflectMiddleRow(matrix);

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### 11. Reflect Over Middle Column
**Transformation:**
Each element \((i, j)\) swaps with \((i, n-1-j)\).

#### Example Input and Output
**Input Matrix:**
```
1  2  3
4  5  6
7  8  9
```

**Output Matrix:**
```
3  2  1
6  5  4
9  8  7
```

**Explanation:**
- Each column is swapped with its corresponding column from the right.

#### Real Life Applications
1. **Image Processing:**
   - **Explanation:** Flipping images horizontally.
   - **Benefit:** Useful for image transformations.

2. **Data Analysis:**
   - **Explanation:** Flipping data sets.
   - **Benefit:** Enhances data organization.

3. **Game Development:**
   - **Explanation:** Flipping game boards.
   - **Benefit:** Provides different perspectives in gameplay.

4. **Robotics:**
   - **Explanation:** Flipping sensor data.
   - **Benefit:** Better data interpretation.

5. **Medical Imaging:**
   - **Explanation:** Flipping medical scans.
   - **Benefit:** Different diagnostic views.

#### Benefits
- Simple transformation.
- Useful for data reorganization.

#### Limitations
- Limited to square matrices.
- May not be useful for non-square matrices.

#### Time Complexity and Optimized Code
**Time Complexity:** \(O(N^2)\)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

void reflectMiddleColumn(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int j = 0; j < n / 2; ++j) {
        for (int i = 0; i < n; ++i) {
            swap(matrix[i][j], matrix[i][n - 1 - j]);
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    reflectMiddleColumn(matrix);

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### 12. Rotate Layer Counterclockwise
**Transformation:**
Elements within concentric layers (rings) of the matrix are rotated counterclockwise.

#### Example Input and Output
**Input Matrix:**
```
1  2  3  4
5  

 6  7  8
9  10 11 12
13 14 15 16
```

**Output Matrix after rotating outer layer counterclockwise:**
```
4  8  12 16
3  7  11 15
2  6  10 14
1  5  9  13
```

**Explanation:**
- Elements in the outermost ring are rotated counterclockwise.
- Inner rings remain unchanged.

#### Real Life Applications
1. **Image Processing:**
   - **Explanation:** Rotating specific layers of an image counterclockwise.
   - **Benefit:** Allows for selective rotation within images.

2. **Game Development:**
   - **Explanation:** Rotating layers in game boards counterclockwise.
   - **Benefit:** Enhances gameplay mechanics.

3. **Data Visualization:**
   - **Explanation:** Rotating specific layers in visualizations counterclockwise.
   - **Benefit:** Better data presentation.

4. **Robotics:**
   - **Explanation:** Rotating layers of sensor data counterclockwise.
   - **Benefit:** Improves robot navigation.

5. **Medical Imaging:**
   - **Explanation:** Rotating layers in MRI or CT scans counterclockwise.
   - **Benefit:** Better visualization for diagnosis.

#### Benefits
- Allows selective rotation within a matrix.
- Useful in complex image processing and game development tasks.

#### Limitations
- Complex implementation for large matrices.
- May require additional memory for intermediate storage.

#### Time Complexity and Optimized Code
**Time Complexity:** \(O(N^2)\)

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

void rotateLayerCounterclockwise(vector<vector<int>>& matrix, int layer) {
    int n = matrix.size();
    int first = layer;
    int last = n - 1 - layer;
    for (int i = first; i < last; ++i) {
        int offset = i - first;
        int top = matrix[first][i];
        matrix[first][i] = matrix[i][last];
        matrix[i][last] = matrix[last][last - offset];
        matrix[last][last - offset] = matrix[last - offset][first];
        matrix[last - offset][first] = top;
    }
}

void rotateLayersCounterclockwise(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int layer = 0; layer < n / 2; ++layer) {
        rotateLayerCounterclockwise(matrix, layer);
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotateLayersCounterclockwise(matrix);

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
```

---

## Summary

The described matrix transformations provide a wide range of tools for manipulating 2D arrays, each with unique applications and benefits. Whether you need to rotate, transpose, flip, or swap layers, these operations can help streamline complex image processing, data analysis, game development, and more. Each transformation includes practical code examples and explanations, making it easy to understand and implement.