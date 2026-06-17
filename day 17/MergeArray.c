#include <stdio.h>

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int mergedArr[]) {
    int i, j;

    for (i = 0; i < size1; i++) {
        mergedArr[i] = arr1[i];
    }

    for (j = 0; j < size2; j++) {
        mergedArr[i + j] = arr2[j]; 
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size1, size2;

    printf("Enter the number of elements for Array 1: ");
    if (scanf("%d", &size1) != 1 || size1 <= 0) {
        printf("Invalid size\n");
        return 1;
    }
    int arr1[size1];
    printf("Enter %d elements for Array 1:\n", size1);
    for (int i = 0; i < size1; i++) {
        printf("Element [%d]: ", i);
        if (scanf("%d", &arr1[i]) != 1) return 1;
    }
    printf("\nEnter the number of elements for Array 2: ");
    if (scanf("%d", &size2) != 1 || size2 <= 0) {
        printf("Invalid size\n");
        return 1;
    }
    int arr2[size2];
    printf("Enter %d elements for Array 2:\n", size2);
    for (int i = 0; i < size2; i++) {
        printf("Element [%d]: ", i);
        if (scanf("%d", &arr2[i]) != 1) return 1;
    }
    int mergedSize = size1 + size2;
    int mergedArr[mergedSize];

    mergeArrays(arr1, size1, arr2, size2, mergedArr);

    printf("\n--- Resulting Arrays ---\n");
    printf("Array 1: ");
    printArray(arr1, size1);
    
    printf("Array 2: ");
    printArray(arr2, size2);
    
    printf("Merged Array: ");
    printArray(mergedArr, mergedSize);

    return 0;
}
