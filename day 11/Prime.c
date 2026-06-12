#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    // 0 and 1 are not prime numbers
    if (num <= 1) {
        return false;
    }
    
    // 2 and 3 are prime numbers
    if (num <= 3) {
        return true;
    }
    
    // Eliminate multiples of 2 and 3 quickly
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    
    // Check remaining factors up to the square root using 6k +/- 1 rule
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int num;

    // Ask user for input
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    // Call the function and print the result
    if (isPrime(num)) {
        printf("%d is a Prime Number.\n", num);
    } else {
        printf("%d is NOT a Prime Number.\n", num);
    }

    return 0;
}
