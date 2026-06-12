#include <stdio.h>
#include <stdbool.h>

// Function definition to check if a number is a palindrome
bool isPalindrome(int num) {
    // Negative numbers are not palindromes due to the minus sign
    if (num < 0) {
        return false;
    }

    int originalNum = num;
    int reversedNum = 0;
    int remainder;

    // Reverse the digits of the number
    while (num > 0) {
        remainder = num % 10;
        
        // Safety check to prevent integer overflow before shifting digits
        if (reversedNum > (2147483647 - remainder) / 10) {
            return false; // Returns false if the reverse exceeds standard int size
        }

        reversedNum = (reversedNum * 10) + remainder;
        num = num / 10;
    }

    // Return true if the reversed number matches the original input
    return (originalNum == reversedNum);
}

int main() {
    int num;

    // Ask user for input
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    // Call the function and handle the true/false response
    if (isPalindrome(num)) {
        printf("%d is a Palindrome number.\n", num);
    } else {
        printf("%d is NOT a Palindrome number.\n", num);
    }

    return 0;
}
