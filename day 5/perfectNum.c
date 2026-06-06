#include <stdio.h>

int main() {
    int num, sum = 0;

    // Ask user for input
    printf("Enter a number: ");
    scanf("%d", &num);

    // Find and add up all proper divisors
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum = sum + i;
        }
    }

    // Check if the sum of divisors equals the original number
    if (sum == num && num > 0) {
        printf("%d is a Perfect Number.\n", num);
    } else {
        printf("%d is NOT a Perfect Number.\n", num);
    }

    return 0;
}
