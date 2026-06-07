#include<stdio.h>
int sum(int n,int l){
    if (n==0) return 0;
    l=n%10;
    return l + sum(n/10,l);
    
}
int main(){
    int n,l;
    printf("Enter a number : ");
    scanf("%d",&n);
   int suum= sum(n,l);
   printf("%d",suum);
    return 0;
}