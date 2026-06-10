#include<stdio.h>
int main(){
    int m;
    printf("Enter the no of row : ");
    scanf("%d",&m);

      for(int i=1;i<=m;i++){ // outer loop -> no of line  =  no. of rows 
          for(int j=1;j<=m-i;j++){ // inner loop -> no of stars in each line  =  no. of columns
        
         printf(" ");
          }
          for(int k=1;k<=2*i-1;k++){
            printf("*");
          }
           printf("\n"); // har line ka baad next line per jana ka liya h
      }

    return 0;
}