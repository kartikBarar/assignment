#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define NAME_LEN 50

// Structure to define an individual Product/Item profile
typedef struct {
    int id;
    char name[NAME_LEN];
    int quantity;
    double price;
} Item;

// Utility function to thoroughly flush out the standard input buffer stream
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to safely add a new product item into inventory
void addItem(Item inventory[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("\n❌ Error: Inventory storage capacity full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("\nEnter Unique Product ID: ");
    if (scanf("%d", &newItem.id) != 1 || newItem.id <= 0) {
        printf("❌ Invalid ID format. Operation canceled.\n");
        clearBuffer();
        return;
    }

    // Check for ID duplication to maintain database index integrity
    for (int i = 0; i < *count; i++) {
        if (inventory[i].id == newItem.id) {
            printf("❌ Error: A product with system reference ID %d already exists.\n", newItem.id);
            return;
        }
    }

    clearBuffer(); // Flush newline left behind by scanf before grabbing text strings

    printf("Enter Product Name: ");
    if (fgets(newItem.name, NAME_LEN, stdin) != NULL) {
        newItem.name[strcspn(newItem.name, "\n")] = '\0'; // Trim trailing newline
    }

    printf("Enter Initial Quantity: ");
    if (scanf("%d", &newItem.quantity) != 1 || newItem.quantity < 0) {
        printf("❌ Invalid quantity entered. Operation canceled.\n");
        clearBuffer();
        return;
    }

    printf("Enter Unit Price ($): ");
    if (scanf("%lf", &newItem.price) != 1 || newItem.price < 0.0) {
        printf("❌ Invalid price amount. Operation canceled.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    // Append the completely configured object to the tracking array index
    inventory[*count] = newItem;
    (*count)++;
    printf("✅ Success: Product successfully added to warehouse registry!\n");
}

// Function to print all stored products as a clean, aligned summary table
void displayInventory(Item inventory[], int count) {
    if (count == 0) {
        printf("\n📭 Notice: The stock asset ledger registry is currently empty.\n");
        return;
    }

    double totalInventoryValue = 0.0;

    printf("\n====================================================================\n");
    printf("%-10s %-25s %-12s %-15s\n", "Prod ID", "Product Name", "Quantity", "Unit Price");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-12d $%-14.2f\n", 
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
        
        // Calculate total worth of stock on the fly
        totalInventoryValue += (inventory[i].quantity * inventory[i].price);
    }
    printf("====================================================================\n");
    printf("Total Asset Value of Warehouse Inventory: $%.2f\n", totalInventoryValue);
    printf("====================================================================\n");
}

// Function to look up a product profile using its unique ID
void searchItem(Item inventory[], int count) {
    if (count == 0) {
        printf("\n📭 Notice: Inventory is empty. Nothing to search.\n");
        return;
    }

    int targetId;
    printf("\nEnter Product ID to search: ");
    if (scanf("%d", &targetId) != 1) {
        printf("❌ Invalid ID format.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == targetId) {
            printf("\n🔍 Product Found:\n");
            printf("-------------------------\n");
            printf("Product ID:    %d\n", inventory[i].id);
            printf("Product Name:  %s\n", inventory[i].name);
            printf("Stock Level:   %d unit(s)\n", inventory[i].quantity);
            printf("Unit Price:    $%.2f\n", inventory[i].price);
            printf("Total Worth:   $%.2f\n", inventory[i].quantity * inventory[i].price);
            return; // Terminate execution early once matched
        }
    }
    printf("❌ Error: No product found with ID %d.\n", targetId);
}

// Function to dynamically update stock counts (Restocking or Sales)
void updateStock(Item inventory[], int count) {
    if (count == 0) {
        printf("\n📭 Notice: Inventory is empty. Update operation aborted.\n");
        return;
    }

    int targetId, adjustmentType, amount;
    printf("\nEnter Product ID to update stock: ");
    if (scanf("%d", &targetId) != 1) {
        clearBuffer();
        return;
    }

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == targetId) {
            printf("Product Match Found: %s (Current Stock: %d)\n", inventory[i].name, inventory[i].quantity);
            printf("1. Restock (Add Stock)\n");
            printf("2. Sell / Dispatch (Reduce Stock)\n");
            printf("Select action (1-2): ");
            if (scanf("%d", &adjustmentType) != 1 || (adjustmentType != 1 && adjustmentType != 2)) {
                printf("❌ Invalid selection. Stock update canceled.\n");
                clearBuffer();
                return;
            }

            printf("Enter quantity amount: ");
            if (scanf("%d", &amount) != 1 || amount <= 0) {
                printf("❌ Invalid quantity amount. Update aborted.\n");
                clearBuffer();
                return;
            }
            clearBuffer();

            if (adjustmentType == 1) {
                inventory[i].quantity += amount;
                printf("✅ Success: Restocked %d unit(s). New balance: %d\n", amount, inventory[i].quantity);
            } else {
                // Prevent inventory metrics from dropping below zero
                if (amount > inventory[i].quantity) {
                    printf("❌ Error: Stockout risk! Cannot sell %d units. Only %d available.\n", amount, inventory[i].quantity);
                } else {
                    inventory[i].quantity -= amount;
                    printf("✅ Success: Dispatched %d unit(s). Remaining balance: %d\n", amount, inventory[i].quantity);
                }
            }
            return;
        }
    }
    printf("❌ Error: No product found with ID %d.\n", targetId);
    clearBuffer();
}

int main() {
    Item warehouse[MAX_ITEMS];
    int productCount = 0;
    int choice;

    do {
        printf("\n========== INVENTORY WAREHOUSE PORTAL ==========\n");
        printf("1. Add New Product Profile\n");
        printf("2. Display Entire Asset Ledger Sheet\n");
        printf("3. Query Product Profile by ID\n");
        printf("4. Update Product Stock Level (Inbound/Outbound)\n");
        printf("5. Close Management Session Workspace\n");
        printf("Select organizational action choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\n❌ Error: Non-numeric action token code. Resetting terminal loop.\n");
            clearBuffer();
            choice = 0; // Guard variable to prevent infinite terminal loop crashes
            continue;
        }

        switch (choice) {
            case 1: addItem(warehouse, &productCount); break;
            case 2: displayInventory(warehouse, productCount); break;
            case 3: searchItem(warehouse, productCount); break;
            case 4: updateStock(warehouse, productCount); break;
            case 5: printf("\nClosing automated warehouse warehouse session. Goodbye!\n"); break;
            default: printf("\n❌ Error: Selected option out of structural limits. Pick choices 1 to 5.\n"); break;
        }
    } while (choice != 5);

    return 0;
}
