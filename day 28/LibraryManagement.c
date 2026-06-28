#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BOOKS 100
#define TITLE_LEN 60
#define AUTHOR_LEN 40

// Structure to define a unique Book profile
typedef struct {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    bool isIssued; // true = borrowed, false = available inside library shelf
} Book;

// Utility function to thoroughly flush out the stdin stream buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to add a brand new book profile into inventory
void addBook(Book library[], int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("\n❌ Error: Library storage limits full! Cannot record more items.\n");
        return;
    }

    Book b;
    printf("\nEnter 4-Digit Unique Book ID: ");
    if (scanf("%d", &b.id) != 1 || b.id <= 0) {
        printf("❌ Invalid ID choice token format. Operation canceled.\n");
        clearInputBuffer();
        return;
    }

    // Check for ID duplication to maintain library index integrity
    for (int i = 0; i < *bookCount; i++) {
        if (library[i].id == b.id) {
            printf("❌ Error: A book with system reference ID %d already exists.\n", b.id);
            return;
        }
    }

    clearInputBuffer(); // Flush newline left behind by scanf before grabbing text strings

    printf("Enter Book Title: ");
    if (fgets(b.title, TITLE_LEN, stdin) != NULL) {
        b.title[strcspn(b.title, "\n")] = '\0'; // Strip trailing newline
    }

    printf("Enter Author Name: ");
    if (fgets(b.author, AUTHOR_LEN, stdin) != NULL) {
        b.author[strcspn(b.author, "\n")] = '\0';
    }

    b.isIssued = false; // Fresh books are marked as available by default

    // Insert the constructed record item token into our tracker array
    library[*bookCount] = b;
    (*bookCount)++;
    printf("✅ Success: Book profile recorded under catalog system index!\n");
}

// Function to view all library collection details as a formatted sheet table
void viewAllBooks(Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("\n📭 Notice: The library asset ledger registry is currently empty.\n");
        return;
    }

    printf("\n=========================================================================================\n");
    printf("%-7s %-35s %-25s %-12s\n", "Book ID", "Book Title", "Author / Writer", "Status");
    printf("-----------------------------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-7d %-35s %-25s %-12s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].isIssued ? "⚠️ BORROWED" : "✅ AVAILABLE");
    }
    printf("=========================================================================================\n");
}

// Function to lookup books inside catalog matching part of character phrases
void searchByTitle(Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("\n📭 Notice: Database registry empty. Nothing to lookup.\n");
        return;
    }

    char targetTitle[TITLE_LEN];
    clearInputBuffer();
    printf("\nEnter Book Title keywords to search: ");
    if (fgets(targetTitle, TITLE_LEN, stdin) != NULL) {
        targetTitle[strcspn(targetTitle, "\n")] = '\0';
    }

    bool matched = false;
    printf("\n🔍 Search Query Matches:\n");
    printf("-----------------------------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        // strstr checks if search term exists inside the book title string
        if (strstr(library[i].title, targetTitle) != NULL) {
            printf("[%d] \"%s\" by %s -> Status: %s\n", 
                   library[i].id, library[i].title, library[i].author, 
                   library[i].isIssued ? "BORROWED" : "AVAILABLE");
            matched = true;
        }
    }

    if (!matched) {
        printf("❌ No books matching title phrase found in index.\n");
    }
}

// Function to handle book issue and return transactions dynamically
void modifyIssueStatus(Book library[], int bookCount, bool issueState) {
    if (bookCount == 0) {
        printf("\n📭 Notice: System inventory empty. Action denied.\n");
        return;
    }

    int targetId;
    printf("\nEnter Book ID number: ");
    if (scanf("%d", &targetId) != 1) {
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == targetId) {
            if (issueState) { // Process Checkout Action Request
                if (library[i].isIssued) {
                    printf("❌ Transaction Denied: This item is already checked out to another user.\n");
                } else {
                    library[i].isIssued = true;
                    printf("✅ Success: Book safely checked out! Enjoy reading.\n");
                }
            } else { // Process Check-In/Return Action Request
                if (!library[i].isIssued) {
                    printf("❌ Transaction Error: This book is already sitting on library shelves.\n");
                } else {
                    library[i].isIssued = false;
                    printf("✅ Success: Book successfully returned to the shelf archive!\n");
                }
            }
            return;
        }
    }
    printf("❌ Error: No book found with system reference ID %d.\n", targetId);
}

int main() {
    Book libraryDatabase[MAX_BOOKS];
    int currentTotalBooks = 0;
    int adminMenuChoice;

    do {
        printf("\n========== DIGITAL LIBRARY SYSTEM INTERFACE ==========\n");
        printf("1. Register / Catalog New Book Profile\n");
        printf("2. View Entire Asset Inventory Sheet\n");
        printf("3. Lookup Book Profile by Title Phrase Query\n");
        printf("4. Checkout Book (Issue Transaction Log)\n");
        printf("5. Return Book (Check-in Transaction Log)\n");
        printf("6. Terminate Management Session Workspace\n");
        printf("Select organizational action choice (1-6): ");

        if (scanf("%d", &adminMenuChoice) != 1) {
            printf("\n❌ Error: Non-numeric action token code. Resetting terminal dashboard loop.\n");
            clearInputBuffer();
            adminMenuChoice = 0; // Prevent loop lockup conditions
            continue;
        }

        switch (adminMenuChoice) {
            case 1: addBook(libraryDatabase, &currentTotalBooks); break;
            case 2: viewAllBooks(libraryDatabase, currentTotalBooks); break;
            case 3: searchByTitle(libraryDatabase, currentTotalBooks); break;
            case 4: modifyIssueStatus(libraryDatabase, currentTotalBooks, true); break; // Issue flag = true
            case 5: modifyIssueStatus(libraryDatabase, currentTotalBooks, false); break; // Issue flag = false
            case 6: printf("\nClosing automated library index environment dashboard session. Goodbye!\n"); break;
            default: printf("\n❌ Error: Out of bounds. Select numerical option codes 1 to 6.\n"); break;
        }
    } while (adminMenuChoice != 6);

    return 0;
}
