#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15
#define EMAIL_LEN 40

// Structure to define an individual Contact Object profile
typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
} Contact;

// Utility function to cleanly flush out the standard input buffer stream
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to safely add a new contact record
void addContact(Contact book[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("\n❌ Error: Address book capacity full! Cannot add more contacts.\n");
        return;
    }

    Contact newContact;
    clearBuffer(); // Flush any lingering input characters

    printf("\nEnter Contact Full Name: ");
    if (fgets(newContact.name, NAME_LEN, stdin) != NULL) {
        newContact.name[strcspn(newContact.name, "\n")] = '\0'; // Trim trailing newline
    }

    // Check for duplicate names to protect directory integrity
    for (int i = 0; i < *count; i++) {
        if (strcasecmp(book[i].name, newContact.name) == 0) {
            printf("❌ Error: A contact named \"%s\" already exists.\n", newContact.name);
            return;
        }
    }

    printf("Enter Phone Number: ");
    if (fgets(newContact.phone, PHONE_LEN, stdin) != NULL) {
        newContact.phone[strcspn(newContact.phone, "\n")] = '\0';
    }

    printf("Enter Email Address: ");
    if (fgets(newContact.email, EMAIL_LEN, stdin) != NULL) {
        newContact.email[strcspn(newContact.email, "\n")] = '\0';
    }

    // Append the completely configured object to the tracking array index
    book[*count] = newContact;
    (*count)++;
    printf("✅ Success: Contact registered successfully!\n");
}

// Function to print all stored contacts as a neat summary grid table
void displayAllContacts(Contact book[], int count) {
    if (count == 0) {
        printf("\n📭 Notice: Your contact management book is currently empty.\n");
        return;
    }

    printf("\n===============================================================================\n");
    printf("%-5s %-25s %-18s %-25s\n", "S.No", "Contact Full Name", "Phone Number", "Email Address");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-25s %-18s %-25s\n", i + 1, book[i].name, book[i].phone, book[i].email);
    }
    printf("===============================================================================\n");
    printf("Total Contacts Managed: %d\n", count);
}

// Function to lookup a contact matching continuous phrase keywords
void searchContact(Contact book[], int count) {
    if (count == 0) {
        printf("\n📭 Notice: Database is empty. Nothing to search.\n");
        return;
    }

    char targetQuery[NAME_LEN];
    clearBuffer();
    printf("\nEnter Name keyword to look up: ");
    if (fgets(targetQuery, NAME_LEN, stdin) != NULL) {
        targetQuery[strcspn(targetQuery, "\n")] = '\0';
    }

    bool matched = false;
    printf("\n🔍 Directory Search Query Results:\n");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        // strstr performs phrase keyword substring matching checks
        if (strstr(book[i].name, targetQuery) != NULL) {
            printf("👉 [%d] Name: %-22s | Phone: %-13s | Email: %s\n", 
                   i + 1, book[i].name, book[i].phone, book[i].email);
            matched = true;
        }
    }

    if (!matched) {
        printf("❌ No contact profiles matching that name phrase found.\n");
    }
}

// Function to delete a contact and rearrange the structural data cells
void deleteContact(Contact book[], int *count) {
    if (*count == 0) {
        printf("\n📭 Notice: Directory empty. Delete operation rejected.\n");
        return;
    }

    char targetName[NAME_LEN];
    clearBuffer();
    printf("\nEnter the exact Full Name of the contact to delete: ");
    if (fgets(targetName, NAME_LEN, stdin) != NULL) {
        targetName[strcspn(targetName, "\n")] = '\0';
    }

    for (int i = 0; i < *count; i++) {
        if (strcasecmp(book[i].name, targetName) == 0) {
            // Shift elements backwards from the deleted index position to compress the structure gap
            for (int j = i; j < (*count) - 1; j++) {
                book[j] = book[j + 1];
            }
            (*count)--; // Decrement structural item counter token globally
            printf("✅ Success: Contact profile safely deleted from repository memory.\n");
            return;
        }
    }
    printf("❌ Error: No contact matched the exact name \"%s\".\n", targetName);
}

int main() {
    Contact addressBook[MAX_CONTACTS];
    int contactCounter = 0;
    int controlChoice;

    do {
        printf("\n========== CONTACT DIRECTORY MANAGEMENT ==========\n");
        printf("1. Create / Add New Contact\n");
        printf("2. Display Entire Address Book Ledger\n");
        printf("3. Query Contact Profile by Name Phrase\n");
        printf("4. Remove / Delete Contact Record\n");
        printf("5. Terminate Directory Terminal Session\n");
        printf("Select administrative option (1-5): ");

        if (scanf("%d", &controlChoice) != 1) {
            printf("\n❌ Error: Non-numeric action token code. Resetting console dashboard loop.\n");
            clearBuffer();
            controlChoice = 0; // Prevent infinite array loop lockups
            continue;
        }

        switch (controlChoice) {
            case 1: addContact(addressBook, &contactCounter); break;
            case 2: displayAllContacts(addressBook, contactCounter); break;
            case 3: searchContact(addressBook, contactCounter); break;
            case 4: deleteContact(addressBook, &contactCounter); break;
            case 5: printf("\nClosing automated contact database session environment. Goodbye!\n"); break;
            default: printf("\n❌ Error: Out of structural limits. Select choices 1 to 5.\n"); break;
        }
    } while (controlChoice != 5);

    return 0;
}
