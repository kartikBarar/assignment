#include <stdio.h>

int main() {
    long long n;

    // Ask user for input
    printf("Enter a positive integer (N): ");
    if (scanf("%lld", &n) != 1 || n < 1) {
        printf("Invalid input. Please enter a positive integer greater than 0.\n");
        return 1;
    }

    // Calculate sum using the formula: N * (N + 1) / 2
    // Using long long prevents integer overflow for large numbers
    long long sum = (n * (n + 1)) / 2;

    // Display the result
    printf("The sum of the first %lld natural numbers is: %lld\n", n, sum);

    return 0;
}
