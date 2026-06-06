#include<stdio.h>
int main(){
int i, n, prime_no=1;
    printf("check the number : ");
    scanf("%d",&n);

    for(i=2; i<=n; i++){
        if (n%i==0)
        prime_no=0;
        
    }
    if (prime_no==1)
    {
        printf("prime");
    }
    else{
        printf("not prime");
    }
    return 0;

}