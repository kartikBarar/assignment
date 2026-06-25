#include <stdio.h>
#include <string.h>

// Function to sort words by their length
void sortWordsByLength(int count, int maxLen, char words[count][maxLen]) {
    char temp[maxLen];

    // Standard Bubble Sort implementation based on string length
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            
            // Compare the lengths of adjacent words
            if (strlen(words[j]) > strlen(words[j + 1])) {
                // Swap the words if the current word is longer than the next one
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }
}

int main() {
    int count;
    int maxLen = 30; // Maximum characters allowed for a single word

    printf("Enter the number of words to sort: ");
    if (scanf("%d", &count) != 1 || count <= 0) {
        printf("Invalid count.\n");
        return 1;
    }

    // Clear the input buffer to prevent fgets from skipping the first input
    while (getchar() != '\n');

    // Declare a 2D array: 'count' rows of strings, each up to 'maxLen' characters
    char words[count][maxLen];

    printf("\nEnter %d words:\n", count);
    for (int i = 0; i < count; i++) {
        printf("Word %d: ", i + 1);
        if (scanf("%29s", words[i]) != 1) { // Prevents buffer overflow and stops at spaces
            printf("Invalid input.\n");
            return 1;
        }
    }

    // Call the sorting function
    sortWordsByLength(count, maxLen, words);

    // Display the sorted words
    printf("\n--- Words Sorted by Length ---\n");
    printf("Word\t\tLength\n");
    printf("------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d\n", words[i], (int)strlen(words[i]));
    }

    return 0;
}
