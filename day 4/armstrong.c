#include<stdio.h>
int main(){
    int n,i,sum,r;
    
    for(i=1;i<=500;i++){
       n=i;
       sum=0;
       while (n!=0)
       {
        r=n%10;
        sum = sum + (r*r*r);
        n=n/10;
       }
       if(sum==i){
           printf("%d\n",i);
      
       }
    }
    return 0;
}