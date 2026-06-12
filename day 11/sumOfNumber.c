#include <stdio.h>

// Function definition to find the sum of two numbers
double findSum(double a, double b) {
    return a + b;
}

int main() {
    double num1, num2, result;

    // Ask user for input
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &num1, &num2) != 2) {
        printf("Invalid input. Please enter valid numbers.\n");
        return 1;
    }

    // Call the function and store the result
    result = findSum(num1, num2);

    // Display the result
    printf("The sum of %.2f and %.2f is: %.2f\n", num1, num2, result);

    return 0;
}