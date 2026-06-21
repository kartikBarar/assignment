#include <stdio.h>

// Function to calculate string length without strlen()
int findStringLength(char str[]) {
    int length = 0;

    // Loop runs until it encounters the null character '\0'
    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int main() {
    // Creating a buffer large enough to store a sentence
    char str[200];

    printf("Enter a string: ");
    
    // fgets() is safer than gets() as it prevents buffer overflow.
    // It reads inputs including spaces.
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

        // Calculate and display the length
        int len = findStringLength(str);
        printf("Length of the string is: %d\n", len);
    }

    return 0;
}
