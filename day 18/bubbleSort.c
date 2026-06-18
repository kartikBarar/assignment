#include <stdio.h>
#include <stdbool.h>

// Function to perform Bubble Sort on an array
void bubbleSort(int arr[], int size) {
    // Outer loop runs for each pass across the data set
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false; // Flag to check if any swapping occurred in this pass

        // Inner loop does adjacent comparisons; shifts boundary back as large items settle
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = true; // Mark that a swap occurred
            }
        }

        // Optimization: If no two elements were swapped, the array is already sorted
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
    bubbleSort(arr, size);

    printf("Sorted array:   ");
    printArray(arr, size);

    return 0;
}
