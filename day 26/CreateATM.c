#include <stdio.h>
#include <stdbool.h>

int main() {
    // Simulation state variables
    const int CORRECT_PIN = 1234;
    double balance = 5000.00; // Starting default balance
    int enteredPin, choice;
    double amount;
    bool isAuthenticated = false;
    int pinAttempts = 0;

    printf("===========================================\n");
    printf("       WELCOME TO THE APEX DIGITAL ATM     \n");
    printf("===========================================\n");

    // Phase 1: Security PIN Verification Loop (Max 3 Attempts)
    while (pinAttempts < 3) {
        printf("Please enter your 4-digit PIN: ");
        if (scanf("%d", &enteredPin) != 1) {
            printf("Invalid input format.\n\n");
            while (getchar() != '\n'); // Clear input buffer
            pinAttempts++;
            continue;
        }

        if (enteredPin == CORRECT_PIN) {
            isAuthenticated = true;
            break;
        } else {
            pinAttempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n\n", 3 - pinAttempts);
        }
    }

    // Lock account if security attempts fail
    if (!isAuthenticated) {
        printf("❌ Security Alert: Max PIN attempts exceeded. Your card is blocked.\n");
        printf("===========================================\n");
        return 1;
    }

    // Phase 2: Main Transaction Menu Loop
    do {
        printf("\n------------- MAIN MENU -------------\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Funds\n");
        printf("3. Withdraw Cash\n");
        printf("4. Exit Transaction\n");
        printf("Select an option (1-4): ");

        // Validate menu choice selection format
        if (scanf("%d", &choice) != 1) {
            printf("\n❌ Invalid choice selection. Use numbers 1 to 4.\n");
            while (getchar() != '\n'); // Clear input stream buffer
            choice = 0; // Reset loop variable safely
            continue;
        }

        switch (choice) {
            case 1: // Balance inquiry
                printf("\n💰 Current Available Balance: $%.2f\n", balance);
                break;

            case 2: // Cash deposit operation
                printf("\nEnter amount to deposit: $");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf("❌ Invalid amount format. Transaction canceled.\n");
                } else {
                    balance += amount;
                    printf("✅ Success: $%.2f deposited.\n", amount);
                    printf("New Balance: $%.2f\n", balance);
                }
                while (getchar() != '\n'); // Flush remaining characters
                break;

            case 3: // Cash withdrawal operation
                printf("\nEnter amount to withdraw (Multiples of $10): $");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf("❌ Invalid amount format. Transaction canceled.\n");
                } 
                // Rule 1: Multiples of 10 check
                else if ((int)amount % 10 != 0) {
                    printf("❌ Transaction Denied: Machine only dispenses $10, $20, and $50 notes.\n");
                } 
                // Rule 2: Overdraft check
                else if (amount > balance) {
                    printf("❌ Transaction Denied: Insufficient available funds.\n");
                } 
                else {
                    balance -= amount;
                    printf("💸 Cash Dispensing: Please collect your $%.2f\n", amount);
                    printf("Remaining Balance: $%.2f\n", balance);
                }
                while (getchar() != '\n'); // Flush remaining characters
                break;

            case 4: // Graceful termination
                printf("\nThank you for banking with us. Goodbye!\n");
                break;

            default:
                printf("\n❌ Invalid option chosen. Please select 1, 2, 3, or 4.\n");
                break;
        }
    } while (choice != 4);

    printf("===========================================\n");
    return 0;
}
