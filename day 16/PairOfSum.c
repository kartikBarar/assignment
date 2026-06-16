#include <stdio.h>
#include <stdbool.h>
bool findPairWithSum(int arr[], int size, int targetSum) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == targetSum) {
                printf("Pair found: %d + %d = %d (at indices %d and %d)\n", 
                       arr[i], arr[j], targetSum, i, j);
                return true; 
            }
        }
    }
    return false;
}

int main() {
    int size, targetSum;
    printf("Enter the number of elements: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element [%d]: ", i);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input\n");
            return 1;
        }
    }

    printf("\nEnter the target sum to search for: ");
    if (scanf("%d", &targetSum) != 1) {
        printf("Invalid target sum.\n");
        return 1;
    }

    if (!findPairWithSum(arr, size, targetSum)) {
        printf("No pair exists in the array with the sum %d.\n", targetSum);
    }

    return 0;
}
