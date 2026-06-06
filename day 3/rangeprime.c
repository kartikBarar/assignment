#include<stdio.h>
#include<stdbool.h>

bool prime_no(int n){
  if(n<=1)return false;
  if(n==2||n==3)return true;
  if(n%2==0 || n%3==0)return false;

  for(int i=5;i*i<=n;i+=6){
    if(n%i==0|| n%(i+2)==0){
        return false;
    }
  }
    return true;
}
    int main(){
        int a,b;
        printf("enter lower range : ");
        scanf("%d",&a);
        printf("enter higher range : ");
        scanf("%d",&b);
        printf("prime numbers between %d and %d are :\n",a,b);
        for(int i = a;i<=b;i++){
            if(prime_no(i)){
                printf("%d ",i);
            }
        }
        printf("\n");
        return 0;
    }  