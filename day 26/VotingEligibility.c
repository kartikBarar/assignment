#include <stdio.h>
#include <stdbool.h>

int main() {
    int age;
    const int VOTING_AGE = 18; // Standard voting age threshold

    printf("===========================================\n");
    printf("        VOTING ELIGIBILITY SYSTEM          \n");
    printf("===========================================\n");
    
    printf("Please enter your age: ");
    
    // Input validation: Ensure user inputs a valid integer
    if (scanf("%d", &age) != 1) {
        printf("\n❌ Error: Invalid input type. Age must be a number.\n");
        return 1;
    }

    // Logical Validation: Check for impossible age scenarios
    if (age <= 0 || age > 120) {
        printf("\n❌ Error: Invalid age entered. Please enter a value between 1 and 120.\n");
        return 1;
    }

    // Eligibility Assessment
    printf("\n--- Assessment Report ---\n");
    if (age >= VOTING_AGE) {
        printf("Status:  ELIGIBLE TO VOTE\n");
        printf("Message: You have full voting rights. Please vote responsibly!\n");
    } else {
        int yearsRemaining = VOTING_AGE - age;
        printf("Status:  NOT ELIGIBLE TO VOTE (MINOR)\n");
        printf("Message: You are too young to vote.\n");
        printf("Notice:  You will become eligible in exactly %d year(s).\n", yearsRemaining);
    }
    printf("===========================================\n");

    return 0;
}
