#include <stdio.h>

int main() {
    int decimalNum;
    int binaryNum[32]; // Array to store binary digits (up to 32 bits)
    int i = 0;

    // Ask user for input
    printf("Enter a positive decimal number: ");
    if (scanf("%d", &decimalNum) != 1 || decimalNum < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    // Handle edge case where input is exactly 0
    if (decimalNum == 0) {
        printf("Binary equivalent: 0\n");
        return 0;
    }

    // Convert decimal to binary by repeated division
    while (decimalNum > 0) {
        binaryNum[i] = decimalNum % 2; // Store the remainder (0 or 1)
        decimalNum = decimalNum / 2;   // Divide the quotient by 2
        i++;                           // Move to the next array index
    }

    // Display the binary result in reverse order
    printf("Binary equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
    printf("\n");

    return 0;
}
