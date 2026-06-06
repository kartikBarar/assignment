#include <stdio.h>

int main() {
    int num, originalNum, remainder, reversedNum = 0;

    // Ask user for input
    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num; // Save original number for final comparison

    // Reverse the digits of the number
    while (num > 0) {
        remainder = num % 10;                     // Extract the last digit
        reversedNum = (reversedNum * 10) + remainder; // Append it to the reversed number
        num = num / 10;                           // Remove the last digit
    }

    // Check if the reversed number matches the original number
    if (originalNum == reversedNum && originalNum >= 0) {
        printf("%d is a Palindrome number.\n", originalNum);
    } else {
        printf("%d is NOT a Palindrome number.\n", originalNum);
    }

    return 0;
}
