#include<stdio.h>

void set(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter arr[%d] element:", i);
        scanf("%d", &arr[i]);
    }
}

void get(int arr[], int size)
{
    // Traversal
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void Deletion(int arr[],int size,int ind){
    for(int i=ind;i<size;i++){
        arr[i]=arr[i+1];
    }
}

int main(){
    int arr[10];
    int size, ele, index;
    printf("Enter array size you want to access:");
    scanf("%d", &size);
    set(arr, size);
    get(arr, size);
    printf("\nEnter the index of number you want to delete:");
    scanf("%d",&index);
    Deletion(arr,size,index);
    size-=1;
    get(arr,size);

    return 0;
}