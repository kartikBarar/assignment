#include <stdio.h>

// Function definition to find the maximum of two numbers
double findMaximum(double a, double b) {
    // Ternary operator: if a is greater than b, return a; otherwise return b
    return (a > b) ? a : b;
}

int main() {
    double num1, num2, maxResult;

    // Ask user for input
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &num1, &num2) != 2) {
        printf("Invalid input. Please enter valid numbers.\n");
        return 1;
    }

    // Call the function and store the result
    maxResult = findMaximum(num1, num2);

    // Display the result
    printf("The maximum number between %.2f and %.2f is: %.2f\n", num1, num2, maxResult);

    return 0;
}
