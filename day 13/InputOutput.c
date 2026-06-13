#include<stdio.h>
int main(){
    int size ;
    int arr[size];
    printf("enter the size : ");
    scanf("%d",&size);
   for(int i=0;i<=size-1;i++){
    printf("Enter element no %d ",i+1);
    scanf("%d",&arr[i]);
   }
   for(int i=0;i<=4;i++){
    printf("%d ",arr[i]);
}
return 0;
}