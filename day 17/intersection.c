#include <stdio.h>
#include <stdbool.h>

// Helper function to check if a value exists in an array
bool isPresent(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true; 
        }
    }
    return false; 
}

// Function to find the intersection of two arrays
// Returns the size of the intersection array
int findIntersection(int arr1[], int size1, int arr2[], int size2, int intersectArr[]) {
    int intersectSize = 0;

    // Scan through the first array
    for (int i = 0; i < size1; i++) {
        // Check if the element exists in the second array
        if (isPresent(arr2, size2, arr1[i])) {
            // Ensure the element is not already added to the result array
            if (!isPresent(intersectArr, intersectSize, arr1[i])) {
                intersectArr[intersectSize] = arr1[i];
                intersectSize++;
            }
        }
    }

    return intersectSize; 
}

// Helper function to print array elements
void printArray(int arr[], int size) {
    if (size == 0) {
        printf("[No common elements]\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size1, size2;

    // Input configuration for the First Array
    printf("Enter the number of elements for Array 1: ");
    if (scanf("%d", &size1) != 1 || size1 <= 0) {
        printf("Invalid size.\n");
        return 1;
    }
    int arr1[size1];
    printf("Enter %d elements for Array 1:\n", size1);
    for (int i = 0; i < size1; i++) {
        printf("Element [%d]: ", i);
        if (scanf("%d", &arr1[i]) != 1) return 1;
    }

    // Input configuration for the Second Array
    printf("\nEnter the number of elements for Array 2: ");
    if (scanf("%d", &size2) != 1 || size2 <= 0) {
        printf("Invalid size.\n");
        return 1;
    }
    int arr2[size2];
    printf("Enter %d elements for Array 2:\n", size2);
    for (int i = 0; i < size2; i++) {
        printf("Element [%d]: ", i);
        if (scanf("%d", &arr2[i]) != 1) return 1;
    }

    // The maximum possible size of intersection is the size of the smaller array
    int maxIntersectSize = (size1 < size2) ? size1 : size2;
    int intersectArr[maxIntersectSize];

    // Call the intersection function
    int actualIntersectSize = findIntersection(arr1, size1, arr2, size2, intersectArr);

    // Display the results
    printf("\n--- Resulting Intersection Set ---\n");
    printf("Array 1: ");
    printArray(arr1, size1);
    
    printf("Array 2: ");
    printArray(arr2, size2);
    
    printf("Intersection Array: ");
    printArray(intersectArr, actualIntersectSize);

    return 0;
}
