#include <stdio.h>

// Function to calculate and display character frequencies
void findCharFrequency(char str[]) {
    // Array to store frequencies of all 256 possible ASCII characters
    // Initialized to 0
    int frequency[256] = {0};
    int i = 0;

    // Count frequencies by using ASCII values as array indices
    while (str[i] != '\0') {
        frequency[(unsigned char)str[i]]++;
        i++;
    }

    printf("\n--- Character Frequencies ---\n");
    printf("Char\tFrequency\n");
    printf("---------------------\n");

    // Print results for characters that appeared at least once
    for (int j = 0; j < 256; j++) {
        if (frequency[j] > 0) {
            // Handle space character visibility in the output
            if (j == ' ') {
                printf("[Space]\t%d\n", frequency[j]);
            } else if (j == '\t') {
                printf("[Tab]\t%d\n", frequency[j]);
            } else {
                printf("%c\t%d\n", j, frequency[j]);
            }
        }
    }
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

        // Run frequency counter
        findCharFrequency(str);
    }

    return 0;
}
