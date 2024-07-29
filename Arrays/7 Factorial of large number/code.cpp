#include <iostream>
#include <vector>

// Function to multiply a number with the array and store the result back in the array
void multiply(int x, std::vector<int>& result) {
    int carry = 0;  // Initialize carry

    // Multiply x with each digit in the result array
    for (int i = 0; i < result.size(); i++) {
        int prod = result[i] * x + carry;
        result[i] = prod % 10;  // Store last digit of prod in result
        carry = prod / 10;      // Update carry
    }

    // Store remaining carry in result
    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }
}

// Function to compute factorial of a large number
void factorial(int n) {
    std::vector<int> result;
    result.push_back(1);  // Initialize result with 1

    for (int x = 2; x <= n; x++) {
        multiply(x, result);
    }

    // Print the result in reverse order
    for (int i = result.size() - 1; i >= 0; i--) {
        std::cout << result[i];
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    factorial(n);
    return 0;
}
