#include <stdio.h>

int main() {
    int size;
    int sum = 0;
    double average;

    // Ask user for the size of the array
    printf("Enter the number of elements: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    // Declare the array with the user-defined size
    int arr[size];

    // Input array elements from the user
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element [%d]: ", i);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Exiting program.\n");
            return 1;
        }
        // Add each element directly to the running sum
        sum += arr[i];
    }

    // Calculate average (Typecasting sum to double to get accurate decimal values)
    average = (double)sum / size;

    // Display the results
    printf("\n--- Results ---\n");
    printf("Sum of array elements = %d\n", sum);
    printf("Average of array elements = %.2f\n", average);

    return 0;
}
