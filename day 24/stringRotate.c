#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if str2 is a rotation of str1
bool checkStringRotation(char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Rule 1: If lengths are different, they cannot be rotations of each other
    if (len1 != len2) {
        return false;
    }

    // Create a temporary buffer to hold str1 concatenated with itself
    // Size must be (len1 * 2) + 1 for the null terminator
    char temp[len1 * 2 + 1];
    
    strcpy(temp, str1); // Copy str1 into temp
    strcat(temp, str1); // Append str1 to temp again (temp now holds str1 + str1)

    // Rule 2: If str2 is a substring of temp, then it is a valid rotation
    if (strstr(temp, str2) != NULL) {
        return true;
    }

    return false;
}

int main() {
    char str1[100];
    char str2[100];

    printf("Enter the first string: ");
    if (fgets(str1, sizeof(str1), stdin) != NULL) {
        // Strip trailing newline character
        str1[strcspn(str1, "\n")] = '\0';
    }

    printf("Enter the second string: ");
    if (fgets(str2, sizeof(str2), stdin) != NULL) {
        // Strip trailing newline character
        str2[strcspn(str2, "\n")] = '\0';
    }

    // Run rotation check
    if (checkStringRotation(str1, str2)) {
        printf("\nRESULT: \"%s\" IS a rotation of \"%s\"\n", str2, str1);
    } else {
        printf("\nRESULT: \"%s\" IS NOT a rotation of \"%s\"\n", str2, str1);
    }

    return 0;
}
