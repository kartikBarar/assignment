#include<stdio.h>
int main(){
    int arr[7] = {1,2,3,4,5,6,7};
    int evencount =0, oddcount =0;
    for(int i=0;i<=6;i++){
      if(i%2==0){
       evencount++;
    }
    else{
       oddcount++; 
    }
}

    printf(" there is %d odd\n ",evencount);   
    printf("there is %d even\n ",oddcount);
    
    return 0;
}