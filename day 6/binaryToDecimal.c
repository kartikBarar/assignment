#include <stdio.h>

int main() {
    long long binaryNum;
    int decimalNum = 0, base = 1, remainder;

    // Ask user for input
    printf("Enter a binary number: ");
    if (scanf("%lld", &binaryNum) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    long long originalNum = binaryNum; // Save original number for final print

    // Convert binary to decimal
    while (binaryNum > 0) {
        remainder = binaryNum % 10; // Extract the last digit (0 or 1)
        
        // Validate if the digit is actually binary
        if (remainder != 0 && remainder != 1) {
            printf("Error: %lld is not a valid binary number.\n", originalNum);
            return 1;
        }

        decimalNum = decimalNum + (remainder * base); // Multiply digit by power of 2
        base = base * 2;                             // Increase power of 2 (1, 2, 4, 8...)
        binaryNum = binaryNum / 10;                   // Remove the last digit
    }

    // Display the result
    printf("The decimal equivalent of binary %lld is: %d\n", originalNum, decimalNum);

    return 0;
}
