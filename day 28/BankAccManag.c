#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50
#define ACC_NUM_LEN 15

// Structure to define Customer Bank Account details
typedef struct {
    char accountNumber[ACC_NUM_LEN];
    char accountHolderName[NAME_LEN];
    double balance;
} BankAccount;

// Utility function to clear the standard input buffer stream cleanly
void flushStream() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to open / register a new bank account
void createAccount(BankAccount branch[], int *totalAccounts) {
    if (*totalAccounts >= MAX_ACCOUNTS) {
        printf("\n❌ Error: Bank registry capacity reached! Cannot open more accounts.\n");
        return;
    }

    BankAccount acc;

    printf("\nEnter New 5-Digit Unique Account Number: ");
    if (scanf("%14s", acc.accountNumber) != 1) {
        printf("❌ Invalid input formatting. Operation canceled.\n");
        flushStream();
        return;
    }

    // Check for Account Number duplication to maintain ledger integrity
    for (int i = 0; i < *totalAccounts; i++) {
        if (strcmp(branch[i].accountNumber, acc.accountNumber) == 0) {
            printf("❌ Error: An account with Account Number %s already exists.\n", acc.accountNumber);
            flushStream();
            return;
        }
    }

    flushStream(); // Clear trailing newline before taking name input string

    printf("Enter Account Holder's Full Name: ");
    if (fgets(acc.accountHolderName, NAME_LEN, stdin) != NULL) {
        acc.accountHolderName[strcspn(acc.accountHolderName, "\n")] = '\0'; // Trim trailing newline
    }

    printf("Enter Initial Opening Deposit Amount ($): ");
    if (scanf("%lf", &acc.balance) != 1 || acc.balance < 0) {
        printf("❌ Invalid initial deposit amount. Opening balance cannot be negative.\n");
        flushStream();
        return;
    }
    flushStream();

    // Insert the configured account into the database tracking array
    branch[*totalAccounts] = acc;
    (*totalAccounts)++;
    printf("✅ Success: Account safely opened! Welcome to our bank.\n");
}

// Function to print a master list of all registered accounts (Ledger Summary)
void displayAllAccounts(BankAccount branch[], int totalAccounts) {
    if (totalAccounts == 0) {
        printf("\n📭 Notice: The bank account database ledger is currently empty.\n");
        return;
    }

    printf("\n=========================================================\n");
    printf("%-18s %-25s %-12s\n", "Account No", "Account Holder Name", "Balance");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < totalAccounts; i++) {
        printf("%-18s %-25s $%-11.2f\n", 
               branch[i].accountNumber, branch[i].accountHolderName, branch[i].balance);
    }
    printf("=========================================================\n");
}

// Function to look up an account and execute financial updates (Deposit / Withdrawal)
void performTransaction(BankAccount branch[], int totalAccounts, bool isDeposit) {
    if (totalAccounts == 0) {
        printf("\n📭 Notice: Bank registry is empty. Cannot process transactions.\n");
        return;
    }

    char targetAcc[ACC_NUM_LEN];
    printf("\nEnter Account Number: ");
    scanf("%14s", targetAcc);
    flushStream();

    for (int i = 0; i < totalAccounts; i++) {
        if (strcmp(branch[i].accountNumber, targetAcc) == 0) {
            double amount;
            printf("Account Match Found: %s (Current Balance: $%.2f)\n", 
                   branch[i].accountHolderName, branch[i].balance);

            if (isDeposit) { // Process Cash Deposit Action
                printf("Enter amount to deposit ($): ");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf("❌ Transaction Canceled: Invalid transaction amount format.\n");
                } else {
                    branch[i].balance += amount;
                    printf("✅ Success: $%.2f safely deposited.\n", amount);
                    printf("Updated Available Balance: $%.2f\n", branch[i].balance);
                }
            } else { // Process Cash Withdrawal Action with strict protection rules
                printf("Enter amount to withdraw ($): ");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf("❌ Transaction Canceled: Invalid transaction amount format.\n");
                } else if (amount > branch[i].balance) { // Strict Overdraft Protection Rule
                    printf("❌ Transaction Denied: Insufficient funds available to clear draft.\n");
                } else {
                    branch[i].balance -= amount;
                    printf("💸 Success: $%.2f safely withdrawn.\n", amount);
                    printf("Updated Remaining Balance: $%.2f\n", branch[i].balance);
                }
            }
            flushStream();
            return;
        }
    }
    printf("❌ Error: No registered account matched Account Number %s.\n", targetAcc);
}

int main() {
    BankAccount bankingDatabase[MAX_ACCOUNTS];
    int accountTrackingCount = 0;
    int interactiveChoice;

    do {
        printf("\n========== DIGITAL RIDGE BANKING PORTAL ==========\n");
        printf("1. Open / Register New Bank Account\n");
        printf("2. View Master Ledger (Display All Accounts)\n");
        printf("3. Process Cash Deposit Transaction\n");
        printf("4. Process Cash Withdrawal Transaction\n");
        printf("5. Terminate Portal Management Session\n");
        printf("Select organizational action choice (1-5): ");

        if (scanf("%d", &interactiveChoice) != 1) {
            printf("\n❌ Error: Non-numeric action option input. Resetting terminal loop.\n");
            flushStream();
            interactiveChoice = 0; // Guard against menu execution lockups
            continue;
        }

        switch (interactiveChoice) {
            case 1: createAccount(bankingDatabase, &accountTrackingCount); break;
            case 2: displayAllAccounts(bankingDatabase, accountTrackingCount); break;
            case 3: performTransaction(bankingDatabase, accountTrackingCount, true); break;  // isDeposit = true
            case 4: performTransaction(bankingDatabase, accountTrackingCount, false); break; // isDeposit = false
            case 5: printf("\nLogging off digital branch system terminal session safely. Goodbye!\n"); break;
            default: printf("\n❌ Error: Selected option out of bounds. Pick choices 1 to 5.\n"); break;
        }
    } while (interactiveChoice != 5);

    return 0;
}
