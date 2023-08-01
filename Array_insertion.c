#include <stdio.h>

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
        printf("%d\n", arr[i]);
    }
}

void insertion(int arr[], int size, int ele, int ind, int cap)
{

    if (size >= cap)
    {
        printf("No more space in array");
    }
    if (ind >= cap)
    {
        printf("index value exceeded");
    }
    for (int i = size - 1; i >= ind; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[ind] = ele;
   
}

int main()
{
    int arr[10];
    int size, ele, index;
    printf("Enter array size you want to access:");
    scanf("%d", &size);
    set(arr, size);
    get(arr, size);
    printf("Enter the element you want to insert:");
    scanf("%d", &ele);
    printf("Enter the index for insertion:");
    scanf("%d", &index);
    insertion(arr, size, ele, index, 10);
    size+=1;
    get(arr,size);

    return 0;
}