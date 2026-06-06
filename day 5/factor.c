#include <stdio.h>

int main() {
    int num;

    // Ask user for input
    printf("Enter a positive integer: ");
    if (scanf("%d", &num) != 1 || num <= 0) {
        printf("Invalid input. Please enter a positive integer greater than 0.\n");
        return 1;
    }

    printf("The factors of %d are: ", num);

    // Loop through all numbers from 1 up to the number itself
    for (int i = 1; i <= num; i++) {
        // If remainder is 0, then i is a factor
        if (num % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
