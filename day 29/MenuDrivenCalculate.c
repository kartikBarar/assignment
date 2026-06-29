#include <stdio.h>
#include <stdbool.h>

// Function to thoroughly clear the standard input buffer stream
void flushBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int choice;
    double num1, num2, result;

    printf("===========================================\n");
    printf("        COMPACT MATH CALCULATOR            \n");
    printf("===========================================\n");

    do {
        // Display the interactive menu
        printf("\n------------- OPERATIONAL MENU -------------\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit Program\n");
        printf("Select an operation (1-5): ");

        // Validate menu choice input format
        if (scanf("%d", &choice) != 1) {
            printf("\n❌ Error: Invalid selection type. Please use numbers 1 to 5.\n");
            flushBuffer();
            choice = 0; // Reset loop variable safely
            continue;
        }

        // If user chooses to exit, break the cycle early before prompting for numbers
        if (choice == 5) {
            printf("\nShutting down calculator session. Goodbye!\n");
            break;
        }

        // Handle out-of-bounds menu selections
        if (choice < 1 || choice > 5) {
            printf("\n❌ Error: Out of bounds. Please select a choice between 1 and 5.\n");
            continue;
        }

        // Prompt and safely read the two numbers for operation
        printf("Enter first number: ");
        if (scanf("%lf", &num1) != 1) {
            printf("❌ Error: Invalid numeric input.\n");
            flushBuffer();
            continue;
        }

        printf("Enter second number: ");
        if (scanf("%lf", &num2) != 1) {
            printf("❌ Error: Invalid numeric input.\n");
            flushBuffer();
            continue;
        }

        // Execute calculations using Switch-Case block structures
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("\n📊 RESULT: %.4f + %.4f = %.4f\n", num1, num2, result);
                break;

            case 2:
                result = num1 - num2;
                printf("\n📊 RESULT: %.4f - %.4f = %.4f\n", num1, num2, result);
                break;

            case 3:
                result = num1 * num2;
                printf("\n📊 RESULT: %.4f * %.4f = %.4f\n", num1, num2, result);
                break;

            case 4:
                // Mathematical Boundary Guard: Division by zero prevention
                if (num2 == 0.0) {
                    printf("\n❌ Mathematical Error: Division by zero is undefined!\n");
                } else {
                    result = num1 / num2;
                    printf("\n📊 RESULT: %.4f / %.4f = %.4f\n", num1, num2, result);
                }
                break;

            default:
                printf("\n❌ Error: Unexpected execution error state encountered.\n");
                break;
        }

    } while (choice != 5);

    printf("===========================================\n");
    return 0;
}
