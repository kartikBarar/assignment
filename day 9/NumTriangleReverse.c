#include<stdio.h>
int main(){
    int n;
    printf("Enter the no of row : ");
    scanf("%d",&n);

      for(int i=n;i>=1;i--){ // outer loop -> no of line  =  no. of rows 
          for(int j=1;j<=i;j++){ // inner loop -> no of stars in each line  =  no. of columns
             printf("%d ",j);
          }
           printf("\n"); // har line ka baad next line per jana ka liya h
      }

    return 0;
}