#include<stdio.h>

int main(){
    int arr[]={2,1,6,3,7,4};
    int key;
    for (int i=0;i<sizeof(arr)/4;i++){
        for(int j=i+1;j<sizeof(arr)/4;j++){
            if(arr[j]<arr[i]){
                key=arr[j];
                arr[j]=arr[i];
                arr[i]=key; 
            }
        }
    }
    for(int i=0;i<sizeof(arr)/4;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}