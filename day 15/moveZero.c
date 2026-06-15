#include<stdio.h>
void moveZero(int arr[]){
 int nonZero = 0;
 for(int i =0 ; i< 6 ; i++){
    if(arr[i]!=0){
        arr[nonZero] = arr[i];
        nonZero++;
    }
 }
 for(int i = nonZero; i<6; i++){
    arr[i] = 0;
 }
}
void printArray(int arr[]){
    for(int i = 0; i<6; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[7] = {1,0,0,3,0,8,7};
    moveZero(arr);
    printf("Array after moving zeroes to end : ");
    printArray(arr);

    return 0;
     
}