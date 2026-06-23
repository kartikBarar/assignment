#include <stdio.h>

// Function to find the first repeating character
char findFirstRepeating(char str[]) {
    // Frequency array for all 256 standard ASCII characters, initialized to 0
    int frequency = {0};
    int i = 0;

    // Single pass tracking
    while (str[i] != '\0') {
        unsigned char ch = (unsigned char)str[i];

        // If the character has been seen before, it is our first duplicate
        if (frequency[ch] > 0) {
            return str[i];
        }

        // Mark the character as seen
        frequency[ch]++;
        i++;
    }

    return '\0'; // Return null character if no characters repeat
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

        // Find the repeating character
        char result = findFirstRepeating(str);

        if (result != '\0') {
            printf("The first repeating character is: '%c'\n", result);
        } else {
            printf("No repeating characters found.\n");
        }
    }

    return 0;
}
