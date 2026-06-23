#include <stdio.h>

// Function to find the first non-repeating character
char findFirstNonRepeating(char str[]) {
    // Frequency array for all 256 standard ASCII characters, initialized to 0
    int frequency = {0};
    int i = 0;

    // First Pass: Count the frequency of each character in the string
    while (str[i] != '\0') {
        frequency[(unsigned char)str[i]]++;
        i++;
    }

    // Second Pass: Traverse the string again to find the first character with a count of 1
    i = 0;
    while (str[i] != '\0') {
        if (frequency[(unsigned char)str[i]] == 1) {
            return str[i]; // Return the first character that does not repeat
        }
        i++;
    }

    return '\0'; // Return null character if every character repeats
}

int main() {
    char str;

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

        // Find the non-repeating character
        char result = findFirstNonRepeating(str);

        if (result != '\0') {
            printf("The first non-repeating character is: '%c'\n", result);
        } else {
            printf("All characters repeat, or the string is empty.\n");
        }
    }

    return 0;
}
