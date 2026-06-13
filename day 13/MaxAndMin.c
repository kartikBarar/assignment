#include<stdio.h>
int main(){
int arr[5] = {5,-9,76,99,6}; 
   
int min=arr[0];
    for(int i=0;i<=4;i++){
        if(min>arr[i]){
            min=arr[i];
        }
    }
    int max=arr[0];
    for(int i=0;i<=4;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    printf("Smallest element are %d\n",min);
    printf("largest element are %d",max);
    return 0;
}