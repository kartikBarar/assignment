#include <stdio.h>

// Function to calculate the frequency of a target element
int getElementFrequency(int arr[], int size, int target) {
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int size, target, frequency;

    // Ask user for the size of the array
    printf("Enter the number of elements: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    int arr[size];

    // Input array elements from the user
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element [%d]: ", i);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input\n");
            return 1;
        }
    }

    // Ask user for the target element to count
    printf("\nEnter the number to find its frequency: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid target element.\n");
        return 1;
    }

    // Call the function to compute frequency
    frequency = getElementFrequency(arr, size, target);

    // Display the result
    printf("The number %d appears %d time(s) in the array.\n", target, frequency);

    return 0;
}
