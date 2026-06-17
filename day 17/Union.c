#include <stdio.h>
#include <stdbool.h>

bool isPresent(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true; 
        }
    }
    return false; 
}

int findUnion(int arr1[], int size1, int arr2[], int size2, int unionArr[]) {
    int unionSize = 0;

    for (int i = 0; i < size1; i++) {
        if (!isPresent(unionArr, unionSize, arr1[i])) {
            unionArr[unionSize] = arr1[i];
            unionSize++;
        }
    }

    for (int i = 0; i < size2; i++) {
        if (!isPresent(unionArr, unionSize, arr2[i])) {
            unionArr[unionSize] = arr2[i];
            unionSize++;
        }
    }

    return unionSize;
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
        printf("Invalid size.\n");
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
        printf("Invalid size.\n");
        return 1;
    }
    int arr2[size2];
    printf("Enter %d elements for Array 2:\n", size2);
    for (int i = 0; i < size2; i++) {
        printf("Element [%d]: ", i);
        if (scanf("%d", &arr2[i]) != 1) return 1;
    }

    int maxUnionSize = size1 + size2;
    int unionArr[maxUnionSize];

    int actualUnionSize = findUnion(arr1, size1, arr2, size2, unionArr);

    printf("\n--- Resulting Union Set ---\n");
    printf("Array 1: ");
    printArray(arr1, size1);
    
    printf("Array 2: ");
    printArray(arr2, size2);
    
    printf("Union Array: ");
    printArray(unionArr, actualUnionSize);

    return 0;
}
