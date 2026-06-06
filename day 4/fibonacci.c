#include<stdio.h>
int main(){
    int n,f1=0,f2=1,sum=0;
    printf("enter n: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        sum=f1+f2;
        printf("%d ",f1);
        f1=f2;
        f2=sum;
        
    }
    return 0;
}