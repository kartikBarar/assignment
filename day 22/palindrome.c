#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Function to check if a string is a palindrome
bool isPalindrome(char str[]) {
    int start = 0;
    int end = 0;

    // Find the end index of the string
    while (str[end] != '\0') {
        end++;
    }
    end--; // Move back to point to the last valid character

    // Check characters from both ends moving inward
    while (start < end) {
        // Convert both characters to lowercase to make the check case-insensitive
        if (tolower(str[start]) != tolower(str[end])) {
            return false; // Mismatch found, not a palindrome
        }
        start++; // Move right
        end--;   // Move left
    }

    return true; // All characters matched
}

int main() {
    char str[100];

    printf("Enter a string: ");
    
    // Read input string securely including spaces
    if (fgets(str, sizeof(str), stdin) != NULL) {
        
        // Remove trailing newline character '\n' if added by fgets
        int i = 0;
        while (str[i] != '\0') {
            if (str[i] == '\n') {
                str[i] = '\0';
                break;
            }
            i++;
        }

        // Check palindrome status and display result
        if (isPalindrome(str)) {
            printf("\"%s\" IS a palindrome.\n", str);
        } else {
            printf("\"%s\" IS NOT a palindrome.\n", str);
        }
    }

    return 0;
}
