#include <stdio.h>

int main() {
    long long num;

    // Ask user for input
    printf("Enter a positive integer: ");
    if (scanf("%lld", &num) != 1 || num <= 1) {
        printf("Invalid input. Please enter an integer greater than 1.\n");
        return 1;
    }

    long long originalNum = num;
    long long maxPrimeFactor = -1;

    // Divide out all the 2s first
    while (num % 2 == 0) {
        maxPrimeFactor = 2;
        num /= 2;
    }

    // Check odd numbers starting from 3 up to sqrt(num)
    for (long long i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            maxPrimeFactor = i;
            num /= i;
        }
    }

    // If num is still greater than 2, then the remaining num is prime
    if (num > 2) {
        maxPrimeFactor = num;
    }

    // Display the result
    printf("The largest prime factor of %lld is: %lld\n", originalNum, maxPrimeFactor);

    return 0;
}
