#include <stdio.h>
#include <stdbool.h>

// Helper function to check if a value already exists in an array
bool isAlreadyTracked(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true; 
        }
    }
    return false; 
}

// Function to find common elements and print them
void printCommonElements(int arr1[], int size1, int arr2[], int size2) {
    int commonBuffer[100]; // Temporary buffer to track elements already printed
    int commonCount = 0;
    bool foundAny = false;

    printf("\nCommon elements are: ");

    // Compare each element of Array 1 with Array 2
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                // Verify if this common element has already been processed/printed
                if (!isAlreadyTracked(commonBuffer, commonCount, arr1[i])) {
                    printf("%d ", arr1[i]);
                    commonBuffer[commonCount] = arr1[i];
                    commonCount++;
                    foundAny = true;
                }
                break; // Break inner loop once a match is found for the current item
            }
        }
    }

    if (!foundAny) {
        printf("[No common elements found]");
    }
    printf("\n");
}

int main() {
    int size1, size2;

    // Input configuration for Array 1
    printf("Enter the number of elements for Array 1: ");
    if (scanf("%d", &size1) != 1 || size1 <= 0) {
        printf("Invalid size.\n");
        return 1;
    }
    int arr1[size1];
    printf("Enter %d elements for Array 1:\n", size1);
    for (int i = 0; i < size1; i++) {
        printf("Element [%d]: ", i);
        if (scanf("%d", &arr1[i]) != 1) return 1;
    }

    // Input configuration for Array 2
    printf("\nEnter the number of elements for Array 2: ");
    if (scanf("%d", &size2) != 1 || size2 <= 0) {
        printf("Invalid size.\n");
        return 1;
    }
    int arr2[size2];
    printf("Enter %d elements for Array 2:\n", size2);
    for (int i = 0; i < size2; i++) {
        printf("Element [%d]: ", i);
        if (scanf("%d", &arr2[i]) != 1) return 1;
    }

    // Call the function to display common items
    printCommonElements(arr1, size1, arr2, size2);

    return 0;
}
