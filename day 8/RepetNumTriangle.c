#include<stdio.h>
int main(){
    int m;
    printf("Enter the no of row : ");
    scanf("%d",&m);

    int a=0; 
    for(int i=1;i<=m;i++){ // outer loop -> no of line  =  no. of rows
      a++;
        for(int j=1;j<=i;j++){ // inner loop -> no of stars in each line  =  no. of columns
             printf(" %d",a);
          }
           printf("\n"); // har line ka baad next line per jana ka liya h
      }

    return 0;
}