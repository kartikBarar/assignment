#include<stdio.h>
int rev(int n,int l){
    if (n==0) return l;
    l = (l*10) + (n%10);
    return rev(n/10,l);
    
}
int main() {
    int num;

    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    
    int isNegative = (num < 0);
    int absNum = isNegative ? -num : num;

    int result = rev(absNum, 0);

    if (isNegative) {
        result = -result;
    }

    printf("The reversed number is: %d\n", result);

    return 0;
}