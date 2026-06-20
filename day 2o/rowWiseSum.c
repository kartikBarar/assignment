#include <stdio.h>

// Function to calculate and display row-wise sums
void findRowSums(int rows, int cols, int matrix[rows][cols]) {
    printf("\n--- Row-wise Sum Results ---\n");
    
    // Outer loop iterates through each row
    for (int i = 0; i < rows; i++) {
        int rowSum = 0; // Reset sum accumulator for the new row
        
        // Inner loop iterates through all elements of the current row
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        
        printf("Sum of Row %d: %d\n", i + 1, rowSum);
    }
}

int main() {
    int rows, cols;

    // Get matrix dimensions from the user
    printf("Enter the number of rows: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Invalid input for rows.\n");
        return 1;
    }

    printf("Enter the number of columns: ");
    if (scanf("%d", &cols) != 1 || cols <= 0) {
        printf("Invalid input for columns.\n");
        return 1;
    }

    int matrix[rows][cols];

    // Input matrix elements
    printf("\nEnter elements for a %d x %d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input. Exiting program.\n");
                return 1;
            }
        }
    }

    // Display the original matrix
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculate and print the row sums
    findRowSums(rows, cols, matrix);

    return 0;
}
