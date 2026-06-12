#include <stdio.h>

// Function definition to find the nth Fibonacci number
unsigned long long getFibonacci(int n) {
    // Base cases
    if (n <= 0) return 0;
    if (n == 1) return 1;

    unsigned long long t1 = 0; // Represents F(n-2)
    unsigned long long t2 = 1; // Represents F(n-1)
    unsigned long long nextTerm = 0;

    // Loop to calculate values up to the nth term
    for (int i = 2; i <= n; i++) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    
    return t2;
}

int main() {
    int n;

    // Ask user for input
    printf("Enter the position (n) for the Fibonacci term: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    // Call the function
    unsigned long long result = getFibonacci(n);

    // Display the result
    printf("The Fibonacci term at position %d is: %llu\n", n, result);

    return 0;
}
