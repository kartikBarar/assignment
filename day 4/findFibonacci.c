#include <stdio.h>

// Function to find the nth Fibonacci number
unsigned long long findNthFibonacci(int n) {
    // Base cases
    if (n <= 0) return 0;
    if (n == 1) return 1;

    unsigned long long a = 0; // Represents F(n-2)
    unsigned long long b = 1; // Represents F(n-1)
    unsigned long long c;     // Represents F(n)

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;

    // Prompt user for input
    printf("Enter the position (n) to find the Fibonacci term: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    unsigned long long result = findNthFibonacci(n);

    // Display the result
    printf("The Fibonacci term at position %d is: %llu\n", n, result);

    return 0;
}
