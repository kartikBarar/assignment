#include <stdio.h>
int findMissingNumber(int arr[], int size) {  
    int n = size + 1; 
    int expectedSum = (n * (n + 1)) / 2;
    int actualSum = 0;
    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }
    return expectedSum - actualSum;
}

int main() {
    int size;

    // Ask user for the size of the array
    printf("Enter the number of elements present (n - 1): ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    int arr[size];
    printf("Enter %d distinct elements in the range [1 to %d]:\n", size, size + 1);
    for (int i = 0; i < size; i++) {
        printf("Element [%d]: ", i);
        if (scanf("%d", &arr[i]) != 1 || arr[i] <= 0) {
            printf("Invalid input\n");
            return 1;
        }
    }
    int missingNum = findMissingNumber(arr, size);
    printf("\nThe missing number is: %d\n", missingNum);

    return 0;
}
