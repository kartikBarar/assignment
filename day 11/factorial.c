#include <stdio.h>

// Function definition to calculate factorial
unsigned long long findFactorial(int num) {
    unsigned long long factorial = 1;

    // Loop from 1 up to num to calculate the running product
    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }

    return factorial;
}

int main() {
    int num;

    // Ask user for input
    printf("Enter a positive integer (max 20): ");
    if (scanf("%d", &num) != 1 || num < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    // Limit input to 20 to prevent data overflow
    if (num > 20) {
        printf("Error: Input too large. Maximum supported value is 20.\n");
        return 1;
    }

    // Call the function
    unsigned long long result = findFactorial(num);

    // Display the result
    printf("The factorial of %d is: %llu\n", num, result);

    return 0;
}