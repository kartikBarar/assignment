#include <stdio.h>

// Function to remove all spaces from a string in place
void removeSpaces(char str[]) {
    int readIndex = 0;
    int writeIndex = 0;

    // Loop through each character of the string
    while (str[readIndex] != '\0') {
        // If the current character is not a space, overwrite at writeIndex
        if (str[readIndex] != ' ' && str[readIndex] != '\t') {
            str[writeIndex] = str[readIndex];
            writeIndex++; // Move the write pointer forward
        }
        readIndex++; // Always move the read pointer forward
    }

    // Explicitly add the null terminator to mark the new end of the string
    str[writeIndex] = '\0';
}

int main() {
    char str[1000];

    printf("Enter a string with spaces: ");
    
    // Read input securely including spaces using fgets
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

        printf("Original String: [%s]\n", str);

        // Remove spaces
        removeSpaces(str);

        printf("Modified String: [%s]\n", str);
    }

    return 0;
}
