#include <stdio.h>

// Function to perform linear search
// Returns the index of the element if found, otherwise returns -1
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Target found, return current index
        }
    }
    return -1; // Target not found after checking the entire array
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

    // Input array elements from the user
    printf("Enter %d elements:\n", size);
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

    // Call the linear search function
    resultIndex = linearSearch(arr, size, target);

    // Display the result
    if (resultIndex != -1) {
        printf("Element found! %d is present at index position %d.\n", target, resultIndex);
    } else {
        printf("Element not found! %d does not exist in the array.\n", target);
    }

    return 0;
}
