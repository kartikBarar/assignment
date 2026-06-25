#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to find and print common characters
void findCommonCharacters(char str1[], char str2[]) {
    // Lookup tables initialized to false
    bool presentInStr1[256] = {false};
    bool presentInStr2[256] = {false};

    int i = 0;
    // Step 1: Mark characters present in the first string
    while (str1[i] != '\0') {
        presentInStr1[(unsigned char)str1[i]] = true;
        i++;
    }

    i = 0;
    // Step 2: Mark characters present in the second string
    while (str2[i] != '\0') {
        presentInStr2[(unsigned char)str2[i]] = true;
        i++;
    }

    printf("\n--- Common Characters ---\n");
    bool found = false;

    // Step 3: Find intersection of both boolean lookup tables
    for (int j = 0; j < 256; j++) {
        if (presentInStr1[j] && presentInStr2[j]) {
            // Make spaces visible in output cleanly
            if (j == ' ') {
                printf("[Space] ");
            } else if (j != '\t' && j != '\n') {
                printf("'%c' ", j);
            }
            found = true;
        }
    }

    if (!found) {
        printf("No common characters found.");
    }
    printf("\n");
}

int main() {
    char str1[1000];
    char str2[1000];

    printf("Enter the first string: ");
    if (fgets(str1, sizeof(str1), stdin) != NULL) {
        str1[strcspn(str1, "\n")] = '\0'; // Remove newline character
    }

    printf("Enter the second string: ");
    if (fgets(str2, sizeof(str2), stdin) != NULL) {
        str2[strcspn(str2, "\n")] = '\0'; // Remove newline character
    }

    // Call the function to find common characters
    findCommonCharacters(str1, str2);

    return 0;
}
