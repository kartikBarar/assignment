#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Helper function to clear the standard input buffer stream
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Helper function to safely read a string including spaces
void readString(char str[]) {
    if (fgets(str, MAX_SIZE, stdin) != NULL) {
        // Remove trailing newline character '\n' if added by fgets
        int i = 0;
        while (str[i] != '\0') {
            if (str[i] == '\n') {
                str[i] = '\0';
                break;
            }
            i++;
        }
    }
}

// 1. Manual String Length Function
int manualLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// 2. Manual String Reverse Function (In-Place)
void manualReverse(char str[]) {
    int start = 0;
    int end = manualLength(str) - 1;
    
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// 3. Manual String Concatenation Function
void manualConcatenate(char base[], char append[]) {
    int baseLen = manualLength(base);
    int i = 0;
    
    // Append characters while ensuring we don't overflow the base array boundary
    while (append[i] != '\0' && (baseLen + i) < (MAX_SIZE - 1)) {
        base[baseLen + i] = append[i];
        i++;
    }
    base[baseLen + i] = '\0'; // Append crucial null terminator
}

// 4. Manual Palindrome Check Function
bool manualIsPalindrome(char str[]) {
    int start = 0;
    int end = manualLength(str) - 1;
    
    while (start < end) {
        char char1 = str[start];
        char char2 = str[end];
        
        // Normalize uppercase letters to lowercase manually using ASCII values
        if (char1 >= 'A' && char1 <= 'Z') char1 += 32;
        if (char2 >= 'A' && char2 <= 'Z') char2 += 32;
        
        if (char1 != char2) {
            return false; // Mismatch found
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    int choice;
    char primaryStr[MAX_SIZE];
    char secondaryStr[MAX_SIZE];

    do {
        printf("\n========== MULTI-ACTION STRING MANAGER ==========\n");
        printf("1. Find String Length\n");
        printf("2. Reverse a String\n");
        printf("3. Concatenate Two Strings\n");
        printf("4. Check if Palindrome\n");
        printf("5. Exit System Terminal Workspace\n");
        printf("Select organizational action choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\n❌ Error: Non-numeric choice token. Resetting console dashboard loop.\n");
            clearInputBuffer();
            choice = 0; // Guard value to prevent infinite terminal loop crashes
            continue;
        }
        clearInputBuffer(); // Flush newline out of stream before gathering string inputs

        switch (choice) {
            case 1:
                printf("\nEnter a string: ");
                readString(primaryStr);
                printf("📊 Result: The length of the string is %d character(s).\n", manualLength(primaryStr));
                break;

            case 2:
                printf("\nEnter a string to reverse: ");
                readString(primaryStr);
                printf("Original String: [%s]\n", primaryStr);
                manualReverse(primaryStr);
                printf("🔄 Result: Reversed String: [%s]\n", primaryStr);
                break;

            case 3:
                printf("\nEnter the primary (base) string: ");
                readString(primaryStr);
                printf("Enter the string to append: ");
                readString(secondaryStr);
                manualConcatenate(primaryStr, secondaryStr);
                printf("🔗 Result: Concatenated String: [%s]\n", primaryStr);
                break;

            case 4:
                printf("\nEnter a string to check: ");
                readString(primaryStr);
                if (manualIsPalindrome(primaryStr)) {
                    printf("✅ Result: \"%s\" IS a valid palindrome.\n", primaryStr);
                } else {
                    printf("❌ Result: \"%s\" IS NOT a palindrome.\n", primaryStr);
                }
                break;

            case 5:
                printf("\nClosing automated string operations workspace. Goodbye!\n");
                break;

            default:
                printf("\n❌ Error: Out of bounds. Select numerical option codes 1 to 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
