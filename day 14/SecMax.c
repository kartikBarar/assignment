#include<stdio.h>
int main(){
    int arr[5]={1,2,3,4,5};
    int max=arr[0];
    int secmax=arr[0];
 
    for(int i=0;i<=4;i++){
        if(max<arr[i]){
            secmax=max;
            max=arr[i];
        }
        else if (secmax<arr[i]&&max!=arr[i])
        {
            secmax=arr[i];
        }
        
    }
    printf("%d",secmax);
    return 0;
}