#include <stdio.h>
#include <ctype.h> // Required for tolower() and isalpha()

// Function to count vowels and consonants
void countVowelsAndConsonants(char str[], int *vowels, int *consonants) {
    *vowels = 0;
    *consonants = 0;
    int i = 0;

    while (str[i] != '\0') {
        char ch = tolower(str[i]); // Convert to lowercase to simplify condition checking

        // Check if the character is an alphabet letter
        if (isalpha(ch)) {
            // Check if the letter is a vowel
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                (*vowels)++;
            } else {
                (*consonants)++; // If it's an alphabet and not a vowel, it's a consonant
            }
        }
        i++;
    }
}

int main() {
    char str[200];
    int vowelCount = 0;
    int consonantCount = 0;

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

        // Calculate counts using pass-by-reference pointers
        countVowelsAndConsonants(str, &vowelCount, &consonantCount);

        // Display results
        printf("\n--- Analysis Results ---\n");
        printf("Total Vowels:     %d\n", vowelCount);
        printf("Total Consonants: %d\n", consonantCount);
    }

    return 0;
}
