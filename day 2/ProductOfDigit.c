#include<stdio.h>
int main(){
 int n,product=1,last_digit;
  printf("Enter the digit : ");
  scanf("%d",&n);

  while(n!=0){
    last_digit=n%10;
    product=product * last_digit;
    n = n/10 ;
  }
  printf("%d",product);
  
    return 0;
}