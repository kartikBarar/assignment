#include<stdio.h>
int main(){
    int m;
    printf("Enter no of rows of 1st matrix : ");
    scanf("%d",&m);
    int n;
    printf("Enter no of col. of 1st matrix : ");
    scanf("%d",&n);
    int a[m][n];
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int p;
    printf("Enter no of rows of 2nd matrix : ");
    scanf("%d",&p);
    int q;
    printf("Enter no of rows of 2nd matrix : ");
    scanf("%d",&q);
    int b[p][q];
     for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&b[i][j]);
        }
    }
    //check
    if(n!=p){
        printf("The matrices cannot be multiplied");
    }
    else{
        //multiplication
        int res[m][q];
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                res[i][j]=0;
                //i row of a , j column of b
                for(int k=0;k<n;k++){
                    res[i][j] += a[i][k]*b[k][j];
                }
            }   
        }
        printf("The resultant matrix is :\n"); 
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                printf("%d ",res[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}