#include <stdio.h>

// Function to merge two sorted arrays into a third sorted array
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0; // Index pointer for arr1
    int j = 0; // Index pointer for arr2
    int k = 0; // Index pointer for the merged array

    // Step 1: Traverse both arrays and copy the smaller element
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Step 2: Copy any remaining elements of arr1 (if any)
    while (i < size1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    // Step 3: Copy any remaining elements of arr2 (if any)
    while (j < size2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int size1, size2;

    // Input size and elements for the first sorted array
    printf("Enter the number of elements in the first array: ");
    if (scanf("%d", &size1) != 1 || size1 <= 0) return 1;
    
    int arr1[size1];
    printf("Enter %d sorted elements for the first array:\n", size1);
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    // Input size and elements for the second sorted array
    printf("\nEnter the number of elements in the second array: ");
    if (scanf("%d", &size2) != 1 || size2 <= 0) return 1;

    int arr2[size2];
    printf("Enter %d sorted elements for the second array:\n", size2);
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // The size of the merged array is the sum of both individual sizes
    int mergedSize = size1 + size2;
    int merged[mergedSize];

    // Merge the arrays
    mergeSortedArrays(arr1, size1, arr2, size2, merged);

    // Display the resulting merged array
    printf("\nMerged Sorted Array:\n");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
