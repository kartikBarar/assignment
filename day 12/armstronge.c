#include <stdio.h>
#include <stdbool.h>

// Helper function to calculate base^exp without using math.h pow()
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// Function to check if a number is an Armstrong number
bool isArmstrong(int num) {
    // Negative numbers cannot be Armstrong numbers
    if (num < 0) {
        return false;
    }

    int originalNum = num;
    int temp = num;
    int digits = 0;
    int sum = 0;

    // Step 1: Count the total number of digits
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    // Step 2: Calculate the sum of power of digits
    temp = num;
    while (temp > 0) {
        int remainder = temp % 10;
        sum += power(remainder, digits);
        temp /= 10;
    }

    // Step 3: Compare total sum with the original number
    return (sum == originalNum);
}

int main() {
    int num;

    // Ask user for input
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    // Call the function and print the result
    if (isArmstrong(num)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is NOT an Armstrong number.\n", num);
    }

    return 0;
}