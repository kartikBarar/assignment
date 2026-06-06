#include <stdio.h>

int main() {
    int num, originalNum, rem, sum = 0;

    // Ask user for input
    printf("Enter a number: ");
    scanf("%d", &num);

    originalNum = num; // Save original number for final comparison

    // Process each digit of the number
    while (num > 0) {
        rem = num % 10; // Extract the last digit

        // Calculate factorial of the extracted digit
        int fact = 1;
        for (int i = 1; i <= rem; i++) {
            fact = fact * i;
        }

        sum = sum + fact; // Add the factorial to total sum
        num = num / 10;   // Remove the last digit from number
    }

    // Check if the sum of factorials matches the original number
    if (sum == originalNum && originalNum > 0) {
        printf("%d is a Strong Number.\n", originalNum);
    } else {
        printf("%d is NOT a Strong Number.\n", originalNum);
    }

    return 0;
}
