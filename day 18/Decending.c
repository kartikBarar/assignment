#include <stdio.h>
#include <stdbool.h>

// Function to perform Bubble Sort in Descending Order
void sortDescending(int arr[], int size) {
    // Outer loop runs for each pass across the dataset
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false; // Flag to track if any element changed position

        // Inner loop performs adjacent comparisons
        for (int j = 0; j < size - i - 1; j++) {
            // Swap if the current element is LESS than the next element
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = true; // Mark that a swap occurred
            }
        }

        // Optimization: Break early if the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

// Helper function to print array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;

    // Ask user for the size of the array
    printf("Enter the number of elements: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    int arr[size];

    // Input array elements from the user
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element [%d]: ", i);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Exiting program.\n");
            return 1;
        }
    }

    printf("\nOriginal array: ");
    printArray(arr, size);

    // Call the sorting function
    sortDescending(arr, size);

    printf("Sorted array (Descending): ");
    printArray(arr, size);

    return 0;
}
