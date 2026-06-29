#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function to thoroughly clear the standard input buffer stream
void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to print the current state of the array
void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("\n📭 Notice: The array is currently empty.\n");
        return;
    }

    printf("\nCurrent Array Elements: [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\nSize: %d / %d slots filled.\n", size, MAX_SIZE);
}

// Function to insert an element at a specific index position
void insertElement(int arr[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("\n❌ Error: Array capacity full! Cannot insert more items.\n");
        return;
    }

    int element, position;

    printf("\nEnter the element value to insert: ");
    if (scanf("%d", &element) != 1) {
        printf("❌ Invalid number entry.\n");
        cleanBuffer();
        return;
    }

    printf("Enter target position (1 to %d): ", *size + 1);
    if (scanf("%d", &position) != 1 || position < 1 || position > *size + 1) {
        printf("❌ Out of bounds: Invalid position entered.\n");
        cleanBuffer();
        return;
    }
    cleanBuffer();

    // Convert 1-based position to 0-based programming index
    int index = position - 1;

    // Shift all elements from right to left to open a gap for the new entry
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    // Assign element to the vacant slot and update size tracking
    arr[index] = element;
    (*size)++;
    printf("✅ Success: Element %d inserted at position %d.\n", element, position);
}

// Function to delete an element from a specific position
void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("\n📭 Notice: Array is empty. Nothing to remove.\n");
        return;
    }

    int position;
    printf("\nEnter position to delete (1 to %d): ", *size);
    if (scanf("%d", &position) != 1 || position < 1 || position > *size) {
        printf("❌ Out of bounds: Invalid position entered.\n");
        cleanBuffer();
        return;
    }
    cleanBuffer();

    int index = position - 1;
    int deletedValue = arr[index];

    // Compress the array structure by shifting elements leftward to close the gap
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--; // Decrement the global element counter tracker
    printf("✅ Success: Element %d removed from position %d.\n", deletedValue, position);
}

// Function to search for an element using Linear Search algorithm
void searchElement(int arr[], int size) {
    if (size == 0) {
        printf("\n📭 Notice: Array empty. Search operation canceled.\n");
        return;
    }

    int target;
    printf("\nEnter item value to look up: ");
    if (scanf("%d", &target) != 1) {
        printf("❌ Invalid input entry.\n");
        cleanBuffer();
        return;
    }
    cleanBuffer();

    // Sequential linear scan pass through array boundary
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("🔍 Match Found: Element %d exists at Position %d (Index %d).\n", target, i + 1, i);
            return; // Exit function early once matched
        }
    }
    printf("❌ Match Failed: Element %d does not exist inside current array.\n", target);
}

int main() {
    int array[MAX_SIZE];
    int currentSize = 0;
    int choice;

    do {
        printf("\n========== MULTI-ACTION ARRAY MANAGER ==========\n");
        printf("1. Display Current Array Elements\n");
        printf("2. Insert Element at a Specific Position\n");
        printf("3. Delete Element from a Specific Position\n");
        printf("4. Search for an Element (Linear Lookup)\n");
        printf("5. Exit System Terminal Workspace\n");
        printf("Select organizational action choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\n❌ Error: Non-numeric choice token. Resetting console dashboard loop.\n");
            cleanBuffer();
            choice = 0; // Guard variable to prevent terminal loop infinite crashes
            continue;
        }

        switch (choice) {
            case 1: displayArray(array, currentSize); break;
            case 2: insertElement(array, &currentSize); break;
            case 3: deleteElement(array, &currentSize); break;
            case 4: searchElement(array, currentSize); break;
            case 5: printf("\nClosing automated array operations workspace. Goodbye!\n"); break;
            default: printf("\n❌ Error: Out of bounds. Select numerical option codes 1 to 5.\n"); break;
        }
    } while (choice != 5);

    return 0;
}
