#include <stdio.h>
int findMaxFrequencyElement(int arr[], int size) {
    int maxElement = arr[0];
    int maxCount = 0;
    for (int i = 0; i < size; i++) {
        int currentCount = 0;
        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) {
                currentCount++;
            }
        }
        if (currentCount > maxCount) {
            maxCount = currentCount;
            maxElement = arr[i];
        }
    }
    return maxElement;
}

int main() {
    int size;
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
    int modeElement = findMaxFrequencyElement(arr, size);
    printf("\nThe element with the maximum frequency is: %d\n", modeElement);

    return 0;
}
