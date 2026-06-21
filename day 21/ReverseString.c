#include <stdio.h>

// Function to reverse a string in place
void reverseString(char str[]) {
    int start = 0;
    int end = 0;

    // Step 1: Find the length of the string (locate the end index)
    while (str[end] != '\0') {
        end++;
    }
    end--; // Move index back by 1 to point to the last valid character

    // Step 2: Swap characters from both ends moving toward the center
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++; // Move right
        end--;   // Move left
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    
    // Read input including spaces safely using fgets
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

        printf("Original String: %s\n", str);

        // Reverse the string
        reverseString(str);

        printf("Reversed String: %s\n", str);
    }

    return 0;
}
