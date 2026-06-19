#include <stdio.h>

// Function to calculate the sum of the main diagonal elements
int getDiagonalSum(int size, int matrix[size][size]) {
    int sum = 0;

    // Optimized single loop to access diagonal elements directly
    for (int i = 0; i < size; i++) {
        sum += matrix[i][i]; // Elements where row index equals column index
    }

    return sum;
}

int main() {
    int size;

    // Ask user for the dimensions of the square matrix
    printf("Enter the size of the square matrix (N x N): ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    // Declare the 2D Variable Length Array
    int matrix[size][size];

    // Input matrix elements from the user
    printf("Enter elements for a %d x %d matrix:\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Element [%d][%d]: ", i, j);
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input. Exiting program.\n");
                return 1;
            }
        }
    }

    // Display the matrix visually
    printf("\n--- Entered Matrix ---\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Call the function to calculate diagonal sum
    int diagSum = getDiagonalSum(size, matrix);

    // Display the final result
    printf("\nSum of the main diagonal elements = %d\n", diagSum);

    return 0;
}
