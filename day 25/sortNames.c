#include <stdio.h>
#include <string.h>

// Function to sort names alphabetically
void sortNames(int count, int maxLen, char names[count][maxLen]) {
    char temp[maxLen];

    // Standard Bubble Sort implementation for strings
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            
            // strcmp returns > 0 if names[j] comes alphabetically after names[j+1]
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap the names using strcpy
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

int main() {
    int count;
    int maxLen = 50; // Maximum length allowed for a single name

    printf("Enter the number of names to sort: ");
    if (scanf("%d", &count) != 1 || count <= 0) {
        printf("Invalid count.\n");
        return 1;
    }

    // Clear the input buffer to prevent fgets from skipping the first input
    while (getchar() != '\n');

    // Declare a 2D array: 'count' number of strings, each of max length 'maxLen'
    char names[count][maxLen];

    printf("\nEnter %d names:\n", count);
    for (int i = 0; i < count; i++) {
        printf("Name %d: ", i + 1);
        if (fgets(names[i], maxLen, stdin) != NULL) {
            // Remove trailing newline character added by fgets
            names[i][strcspn(names[i], "\n")] = '\0';
        }
    }

    // Call the sorting function
    sortNames(count, maxLen, names);

    // Display the sorted names
    printf("\n--- Names in Alphabetical Order ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }

    return 0;
}
