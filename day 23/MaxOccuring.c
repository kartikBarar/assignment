#include <stdio.h>

// Function to find the maximum occurring character
char findMaxOccurringChar(char str[]) {
    // Frequency array for all 256 standard ASCII characters, initialized to 0
    int frequency[256] = {0};
    int i = 0;

    // Pass 1: Populate the frequency array
    while (str[i] != '\0') {
        frequency[(unsigned char)str[i]]++;
        i++;
    }

    int maxCount = 0;
    char maxChar = '\0';

    // Pass 2: Find the character with the highest frequency
    for (int j = 0; j < 256; j++) {
        if (frequency[j] > maxCount) {
            maxCount = frequency[j];
            maxChar = (char)j;
        }
    }

    return maxChar;
}

int main() {
    char str[1000];

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

        // Find the maximum occurring character
        char result = findMaxOccurringChar(str);

        if (result != '\0' && result != ' ') {
            printf("The maximum occurring character is: '%c'\n", result);
        } else if (result == ' ') {
            printf("The maximum occurring character is: '[Space]'\n");
        } else {
            printf("The string is empty.\n");
        }
    }

    return 0;
}
