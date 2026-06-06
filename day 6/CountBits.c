#include <stdio.h>

int main() {
    int num;
    int count = 0;

    // Ask user for input
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int originalNum = num; // Save original number for display

    // Brian Kernighan's Algorithm to count set bits
    while (num > 0) {
        num = num & (num - 1); // Clears the lowest set bit
        count++;
    }

    // Display the result
    printf("The number of set bits in %d is: %d\n", originalNum, count);

    return 0;
}
