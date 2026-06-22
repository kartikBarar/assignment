#include <stdio.h>
#include <stdbool.h>

// Function to count words in a string
int countWords(char str[]) {
    int wordCount = 0;
    bool inWord = false; // Flag to track if we are currently inside a word
    int i = 0;

    while (str[i] != '\0') {
        // Check if the current character is a whitespace element
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            inWord = false; // We hit a space, so we are no longer in a word
        } 
        // If it's a non-space character and we weren't already tracking a word
        else if (!inWord) {
            inWord = true;  // Mark that we have entered a new word
            wordCount++;    // Increment the word counter
        }
        i++;
    }

    return wordCount;
}

int main() {
    char str[1000]; // Large buffer to hold long sentences

    printf("Enter a sentence: ");
    
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

        // Calculate and display the final word count
        int totalWords = countWords(str);
        printf("Total number of words: %d\n", totalWords);
    }

    return 0;
}
