#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to remove duplicate characters in place
void removeDuplicates(char str[]) {
    // A lookup checklist for all 256 standard ASCII characters. 
    // false = not seen yet, true = already processed
    bool seen[256] = {false};
    
    int readIndex = 0;
    int writeIndex = 0;

    // Single pass scan
    while (str[readIndex] != '\0') {
        unsigned char ch = (unsigned char)str[readIndex];

        // If this character has not been seen before
        if (!seen[ch]) {
            seen[ch] = true;             // Mark it as seen
            str[writeIndex] = str[readIndex]; // Keep it and write it forward
            writeIndex++;                // Move write pointer
        }
        readIndex++; // Always advance read pointer
    }

    // Explicitly place the null terminator to trim off remaining old characters
    str[writeIndex] = '\0';
}

int main() {
    char str[1000];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        // Strip trailing newline character if added by fgets
        str[strcspn(str, "\n")] = '\0';

        printf("Original String: %s\n", str);

        // Remove the duplicates
        removeDuplicates(str);

        printf("String after removing duplicates: %s\n", str);
    }

    return 0;
}
