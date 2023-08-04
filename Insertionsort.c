#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[]={1,6,2,10,4};
    int j,key;
    for(int i=1;i<sizeof(arr)/4;i++)
    {
       key = arr[i];
       j=i-1;
       while (j>=0 && arr[j]>key)
       {
         arr[j+1]= arr[j];
         j=j-1;
       }
       arr[j+1]=key;
    }
    for(int i=0;i<sizeof(arr)/4;i++)
    {
        printf("%d ",arr[i]);
    } 
    return 0;
}