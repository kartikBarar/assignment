#include <stdio.h>

// Function to perform Binary Search (Iterative Approach)
// Returns the index of the element if found, otherwise returns -1
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        // Calculate mid point (Preventing overflow variant of low + high / 2)
        int mid = low + (high - low) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid; // Target found, return index
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            low = mid + 1;
        } 
        // If target is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }

    return -1; // Target not found in the array
}

int main() {
    int size, target, resultIndex;

    // Ask user for the size of the array
    printf("Enter the number of elements: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    int arr[size];

    // Input array elements from the user (Must be entered in ascending order)
    printf("Enter %d elements in SORTED (Ascending) order:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element [%d]: ", i);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Exiting program.\n");
            return 1;
        }
    }

    // Ask user for the search target
    printf("\nEnter the number to search for: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid search element.\n");
        return 1;
    }

    // Call the binary search function
    resultIndex = binarySearch(arr, size, target);

    // Display the result
    if (resultIndex != -1) {
        printf("Element found! %d is present at index position %d.\n", target, resultIndex);
    } else {
        printf("Element not found! %d does not exist in the array.\n", target);
    }

    return 0;
}
