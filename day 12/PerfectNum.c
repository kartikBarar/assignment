#include <stdio.h>
#include <stdbool.h>

// Function definition to check if a number is a perfect number
bool isPerfect(int num) {
    // Numbers less than or equal to 1 cannot be perfect numbers
    if (num <= 1) {
        return false;
    }

    int sum = 1; // 1 is always a proper divisor for any number > 1

    // Optimized loop: only check up to the square root of the number
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i; // Add the divisor
            
            // If the divisors are distinct, add the matching divisor pair
            if (i * i != num) {
                sum += num / i;
            }
        }
    }

    // Return true if the sum of proper divisors equals the original number
    return (sum == num);
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
    if (isPerfect(num)) {
        printf("%d is a Perfect Number.\n", num);
    } else {
        printf("%d is NOT a Perfect Number.\n", num);
    }

    return 0;
}