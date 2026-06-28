#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ROWS 5
#define COLS 6
#define SEAT_PRICE 15.00 // Flat price per seat in dollars

// Structure to track ticket transactions and inventory status
typedef struct {
    char grid[ROWS][COLS]; // 'A' = Available, 'B' = Booked
    int totalTicketsSold;
    double totalRevenue;
} BookingSystem;

// Helper function to cleanly flush out the stdin stream buffer
void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to initialize the seating grid with available slots
void initializeGrid(BookingSystem *sys) {
    sys->totalTicketsSold = 0;
    sys->totalRevenue = 0.0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sys->grid[i][j] = 'A'; // Set all seats to 'A'vailable
        }
    }
}

// Function to display the interactive live seating map
void displaySeatingMap(BookingSystem *sys) {
    printf("\n============ STAGE / SCREEN ============\n\n");
    printf("       ");
    for (int j = 0; j < COLS; j++) {
        printf("[Col %d] ", j + 1);
    }
    printf("\n-----------------------------------------\n");

    for (int i = 0; i < ROWS; i++) {
        printf("[Row %d]  ", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (sys->grid[i][j] == 'A') {
                printf("  ✅    "); // Visual anchor for available seat
            } else {
                printf("  ❌    "); // Visual anchor for booked seat
            }
        }
        printf("\n\n");
    }
    printf("=========================================\n");
    printf("Legend:  ✅ = Available ($%.2f)   ❌ = Booked\n", SEAT_PRICE);
    printf("=========================================\n");
}

// Function to process a ticket reservation request
void reserveTicket(BookingSystem *sys) {
    int targetRow, targetCol;

    printf("\nEnter Row Number (1-%d): ", ROWS);
    if (scanf("%d", &targetRow) != 1 || targetRow < 1 || targetRow > ROWS) {
        printf("❌ Invalid row selection. Operation aborted.\n");
        flushInput();
        return;
    }

    printf("Enter Column Number (1-%d): ", COLS);
    if (scanf("%d", &targetCol) != 1 || targetCol < 1 || targetCol > COLS) {
        printf("❌ Invalid column selection. Operation aborted.\n");
        flushInput();
        return;
    }
    flushInput();

    // Convert user inputs (1-indexed) to programming indices (0-indexed)
    int r = targetRow - 1;
    int c = targetCol - 1;

    // Check availability state machine rules
    if (sys->grid[r][c] == 'B') {
        printf("❌ Selection Failed: Seat [Row %d, Col %d] is already taken.\n", targetRow, targetCol);
    } else {
        sys->grid[r][c] = 'B'; // Change state to 'B'ooked
        sys->totalTicketsSold++;
        sys->totalRevenue += SEAT_PRICE;
        
        printf("\n🎉 SUCCESS: Ticket confirmed for Row %d, Column %d!\n", targetRow, targetCol);
        printf("Charged Amount: $%.2f\n", SEAT_PRICE);
    }
}

// Function to cancel an existing ticket reservation
void cancelTicket(BookingSystem *sys) {
    if (sys->totalTicketsSold == 0) {
        printf("\n📭 Notice: No active tickets have been booked yet. Nothing to cancel.\n");
        return;
    }

    int targetRow, targetCol;
    printf("\nEnter Row Number to Cancel (1-%d): ", ROWS);
    if (scanf("%d", &targetRow) != 1 || targetRow < 1 || targetRow > ROWS) {
        printf("❌ Invalid row format.\n");
        flushInput();
        return;
    }

    printf("Enter Column Number to Cancel (1-%d): ", COLS);
    if (scanf("%d", &targetCol) != 1 || targetCol < 1 || targetCol > COLS) {
        printf("❌ Invalid column format.\n");
        flushInput();
        return;
    }
    flushInput();

    int r = targetRow - 1;
    int c = targetCol - 1;

    if (sys->grid[r][c] == 'A') {
        printf("❌ Error: Seat [Row %d, Col %d] is already sitting vacant.\n", targetRow, targetCol);
    } else {
        sys->grid[r][c] = 'A'; // Revert state back to 'A'vailable
        sys->totalTicketsSold--;
        sys->totalRevenue -= SEAT_PRICE;
        printf("✅ Success: Reservation canceled. $%.2f has been refunded.\n", SEAT_PRICE);
    }
}

// Function to view executive summary and total sales stats
void viewSalesSummary(BookingSystem *sys) {
    int totalSeats = ROWS * COLS;
    int vacantSeats = totalSeats - sys->totalTicketsSold;

    printf("\n=========================================\n");
    printf("        EXECUTIVE SALES REPORT           \n");
    printf("=========================================\n");
    printf(" Total Grid Capacity : %d Seats\n", totalSeats);
    printf(" Total Tickets Sold  : %d\n", sys->totalTicketsSold);
    printf(" Remaining Vacancy   : %d Seats\n", vacantSeats);
    printf("-----------------------------------------\n");
    printf(" Accumulated Revenue : $%.2f\n", sys->totalRevenue);
    printf("=========================================\n");
}

int main() {
    BookingSystem systemManager;
    int choice;

    // Build default matrix grid state configurations
    initializeGrid(&systemManager);

    do {
        printf("\n========== BOX OFFICE BOOKING SYSTEM ==========\n");
        printf("1. View Live Seating Layout Chart\n");
        printf("2. Reserve / Book a Seat Ticket\n");
        printf("3. Cancel a Seat Ticket Reservation\n");
        printf("4. View Total Revenue & Sales Ledger\n");
        printf("5. Shutdown Box Office Terminal\n");
        printf("Select functional system action (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\n❌ Error: Non-numeric action token code. Resetting console dashboard loop.\n");
            flushInput();
            choice = 0; // Guard variable to prevent terminal loop infinite crashes
            continue;
        }

        switch (choice) {
            case 1: displaySeatingMap(&systemManager); break;
            case 2: reserveTicket(&systemManager); break;
            case 3: cancelTicket(&systemManager); break;
            case 4: viewSalesSummary(&systemManager); break;
            case 5: printf("\nShutting down ticket distribution matrix engine. Goodbye!\n"); break;
            default: printf("\n❌ Error: Selected option out of structural limits. Pick 1 to 5.\n"); break;
        }
    } while (choice != 5);

    return 0;
}
