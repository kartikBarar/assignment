#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to find the longest word in a sentence
void findLongestWord(char sentence[], char longestWord[]) {
    int i = 0;
    int currentStart = 0;
    int currentLength = 0;
    int maxLength = 0;
    int maxStart = 0;
    int len = strlen(sentence);

    while (i <= len) {
        // A word character is anything that is not a space or punctuation
        // (Treating null terminator '\0' as a word boundary)
        if (sentence[i] != ' ' && sentence[i] != '\t' && sentence[i] != '\0' && !ispunct(sentence[i])) {
            if (currentLength == 0) {
                currentStart = i; // Mark the beginning index of the current word
            }
            currentLength++;
        } 
        // Word boundary reached (space, punctuation, or end of string)
        else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                maxStart = currentStart; // Save the starting point of the longest word
            }
            currentLength = 0; // Reset length tracker for the next word
        }
        i++;
    }

    // Copy the longest word from the original sentence into the destination buffer
    if (maxLength > 0) {
        strncpy(longestWord, &sentence[maxStart], maxLength);
        longestWord[maxLength] = '\0'; // Explicitly append null terminator
    } else {
        longestWord[0] = '\0'; // Empty string if no word found
    }
}

int main() {
    char sentence;
    char longestWord; // Buffer to hold the extracted longest word

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        // Strip trailing newline character if added by fgets
//        sentence[strcspn(sentence, "\n")] = '\0';

        // Find the longest word
        findLongestWord(sentence, longestWord);

        if (strlen(longestWord) > 0) {
            printf("The longest word is: \"%s\" (Length: %d)\n", longestWord, (int)strlen(longestWord));
        } else {
            printf("No valid words found.\n");
        }
    }

    return 0;
}
