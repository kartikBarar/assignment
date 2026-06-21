#include <stdio.h>

// Function to convert lowercase characters to uppercase
void convertToUpperCase(char str[]) {
    int i = 0;

    while (str[i] != '\0') {
        // Check if the current character is a lowercase letter (ASCII 97 to 122)
        if (str[i] >= 'a' && str[i] <= 'z') {
            // Subtract 32 from its ASCII value to convert it to uppercase
            str[i] = str[i] - 32;
        }
        i++;
    }
}

int main() {
    char str[100];

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

        printf("Original String: %s\n", str);

        // Convert the string to uppercase
        convertToUpperCase(str);

        printf("Uppercase String: %s\n", str);
    }

    return 0;
}
