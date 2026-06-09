#include<stdio.h>
int main(){
    int n;
    printf("Enter the no of row : ");
    scanf("%d",&n);

      for(int i=1;i<=n;i++){ // outer loop -> no of line  =  no. of rows 
          for(int j=1;j<=n;j++){ // inner loop -> no of stars in each line  =  no. of columns
             if(i==1||i==n||j==1||j==n){
                printf("*");
             }
             else{
                printf(" ");
             }
          }
           printf("\n"); // har line ka baad next line per jana ka liya h
      }

    return 0;
}