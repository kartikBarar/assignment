#include <stdio.h>

// Function to calculate x^n using Binary Exponentiation
double calculatePower(double base, long long exp) {
    double result = 1.0;
    long long p = exp;

    // Handle negative exponents by converting them to positive
    if (p < 0) {
        p = -p;
    }

    // Binary Exponentiation loop
    while (p > 0) {
        // If the current power is odd, multiply the result by the base
        if (p % 2 == 1) {
            result *= base;
        }
        base *= base;  // Square the base
        p /= 2;        // Divide the power by 2
    }

    // If the original exponent was negative, invert the final result
    if (exp < 0) {
        return 1.0 / result;
    }

    return result;
}

int main() {
    double base;
    long long exp;

    // Ask user for input
    printf("Enter base (x): ");
    if (scanf("%lf", &base) != 1) {
        printf("Invalid base input.\n");
        return 1;
    }

    printf("Enter exponent (n): ");
    if (scanf("%lld", &exp) != 1) {
        printf("Invalid exponent input.\n");
        return 1;
    }

    // Handle edge case: 0^0 is mathematically undefined, but often treated as 1
    if (base == 0 && exp < 0) {
        printf("Error: Division by zero condition (0 raised to a negative power).\n");
        return 1;
    }

    double finalResult = calculatePower(base, exp);

    // Display the result
    printf("%.4f^%lld = %.6f\n", base, exp, finalResult);

    return 0;
}
