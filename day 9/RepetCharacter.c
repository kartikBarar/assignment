#include<stdio.h>
int main(){
    int n;
    printf("Enter the no of row : ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){ // outer loop -> no of line  =  no. of rows 
      for(int j=1;j<=i;j++){ // inner loop -> no of stars in each line  =  no. of columns
        int a=0;
            int d =i+a+64;
            char ch = (char)d;
             printf("%c ",ch);
             
             a++;
          }
          printf("\n"); // har line ka baad next line per jana ka liya h
      }

    return 0;
}