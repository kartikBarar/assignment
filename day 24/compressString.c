#include <stdio.h>
#include <string.h>

// Function to compress a string using Run-Length Encoding
void compressString(char src[], char dest[]) {
    int srcLen = strlen(src);
    int writeIndex = 0;

    // Handle empty string edge case
    if (srcLen == 0) {
        dest[0] = '\0';
        return;
    }

    for (int i = 0; i < srcLen; i++) {
        // Copy the current character to the destination buffer
        dest[writeIndex++] = src[i];

        // Count consecutive occurrences of the current character
        int count = 1;
        while (i + 1 < srcLen && src[i] == src[i + 1]) {
            count++;
            i++; // Advance the main pointer forward
        }

        // Convert the integer count to characters and add to destination
        // sprintf returns the number of digits added, advancing writeIndex
        writeIndex += sprintf(&dest[writeIndex], "%d", count);
    }

    // Append null terminator to finalize the compressed string
    dest[writeIndex] = '\0';

    // Safety Optimization: If the compressed string is not shorter than 
    // the original, revert back to the original string.
    if (strlen(dest) >= srcLen) {
        strcpy(dest, src);
    }
}

int main() {
    char src[500];
    char dest[1000]; // Allocation buffer large enough to safely hold counts

    printf("Enter a string to compress: ");
    if (fgets(src, sizeof(src), stdin) != NULL) {
        // Strip trailing newline character
        src[strcspn(src, "\n")] = '\0';

        printf("Original String: %s\n", src);

        // Compress the input string
        compressString(src, dest);

        printf("Resulting String: %s\n", dest);
    }

    return 0;
}
