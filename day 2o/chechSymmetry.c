#include <stdio.h>
#include <stdbool.h>

// Function to check if a square matrix is symmetric
bool isSymmetric(int size, int matrix[size][size]) {
    // We only need to check elements above the main diagonal
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            // Compare mirror elements across the main diagonal
            if (matrix[i][j] != matrix[j][i]) {
                return false; // Not symmetric, exit early
            }
        }
    }
    return true; // All mirror elements matched
}

int main() {
    int size;

    // Only square matrices can be symmetric
    printf("Enter the size of the square matrix (N x N): ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    int matrix[size][size];

    // Input elements for the matrix
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

    // Display the matrix
    printf("\nYour Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Check symmetry and display the final result
    if (isSymmetric(size, matrix)) {
        printf("\nRESULT: The matrix IS symmetric.\n");
    } else {
        printf("\nRESULT: The matrix IS NOT symmetric.\n");
    }

    return 0;
}
