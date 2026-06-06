#include <stdio.h>


int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

   
    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input. Please enter integers only.\n");
        return 1;
    }

   
    int absNum1 = (num1 < 0) ? -num1 : num1;
    int absNum2 = (num2 < 0) ? -num2 : num2;

    
    if (absNum1 == 0 || absNum2 == 0) {
        printf("The LCM of %d and %d is: 0\n", num1, num2);
        return 0;
    }

    
    int gcd = findGCD(absNum1, absNum2);


    int lcm = (absNum1 / gcd) * absNum2;

  
    printf("The LCM of %d and %d is: %d\n", num1, num2, lcm);

    return 0;
}
