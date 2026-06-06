#include<stdio.h>
int main(){
 int n,r=0;
  printf("Enter the digit : ");
  scanf("%d",&n);

  int rev=0;
  while(n!=0){
    //   r=r*10;
    //   r=r+(n%10);
    //   n=n/10;
    r=n%10;
   rev=rev*10 + r;
  n=n/10;
  
  
  }
  printf("the revers is : %d",rev);
    return 0;
}