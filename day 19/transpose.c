#include<stdio.h>
int main(){
    int m;
    printf("enter row of matrix : ");
    scanf("%d",&m);
    int n;
    printf("enter colmn of matrix : ");
    scanf("%d",&n);
    
    int arr[m][n];
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){       
          scanf("%d",&arr[i][j]); 
                
        }
    }
    printf("\n");
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){       
          printf("%d ",arr[j][i]);                 
        }
        printf("\n");
    }
    return 0;
}