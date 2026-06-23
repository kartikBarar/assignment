#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Function to check if two strings are anagrams
bool checkAnagram(char str1[], char str2[]) {
    // Frequency array for 256 ASCII characters, initialized to 0s
    int charCounts[256] = {0};
    int i = 0;

    // Step 1: Count characters in the first string (increment counts)
    // Convert to lowercase to make the check case-insensitive
    while (str1[i] != '\0') {
        // Skip spaces to compare actual letters
        if (str1[i] != ' ' && str1[i] != '\t') {
            unsigned char ch = (unsigned char)tolower(str1[i]);
            charCounts[ch]++;
        }
        i++;
    }

    // Step 2: Deduct characters using the second string (decrement counts)
    i = 0;
    while (str2[i] != '\0') {
        if (str2[i] != ' ' && str2[i] != '\t') {
            unsigned char ch = (unsigned char)tolower(str2[i]);
            charCounts[ch]--;
        }
        i++;
    }

    // Step 3: Check if all character balance out to exactly 0
    for (int j = 0; j < 256; j++) {
        if (charCounts[j] != 0) {
            return false; // Mismatch found, not an anagram
        }
    }

    return true; // All counts balanced perfectly
}

int main() {
    char str1[256];
    char str2[256];

    printf("Enter the first string: ");
    if (fgets(str1, sizeof(str1), stdin) != NULL) {
        // Strip trailing newline character
        int i = 0;
        while (str1[i] != '\0') {
            if (str1[i] == '\n') { str1[i] = '\0'; break; }
            i++;
        }
    }

    printf("Enter the second string: ");
    if (fgets(str2, sizeof(str2), stdin) != NULL) {
        // Strip trailing newline character
        int i = 0;
        while (str2[i] != '\0') {
            if (str2[i] == '\n') { str2[i] = '\0'; break; }
            i++;
        }
    }

    // Evaluate anagram check
    if (checkAnagram(str1, str2)) {
        printf("\nRESULT: The strings ARE anagrams.\n");
    } else {
        printf("\nRESULT: The strings ARE NOT anagrams.\n");
    }

    return 0;
}
