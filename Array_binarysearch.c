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
        printf("%d ", arr[i]);
    }
}

void sort(int arr[], int size)
{   //sorting
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                int a = arr[j];
                arr[j] = arr[i];
                arr[i] = a;
            }
        }
    }
}

void binarySearch(int arr[], int size, int num)
{   //searching
    int high = size - 1;
    int low = 0;
    int mid = (high + low) / 2;
    if (num == arr[high])
    {
        printf("Element found at arr[%d]", size - 1);
    }
    else if (num == arr[low])
    {
        printf("Element found at arr[0]");
    }
   while (low<=high)
   {
        if (num == arr[mid])
        {
            printf("Element found at arr[%d]", mid);
            break;
        }
        else if (num > arr[mid])
        {
            low = mid;
        }
        else if (num < arr[mid])
        {
            high = mid;
        }
    }  
}

int main()
{
    int size, ele, num;
    printf("Enter array size:");
    scanf("%d", &size);
    int arr[size];
    set(arr, size);
    // get(arr,size);
    sort(arr, size);
    get(arr, size);
    printf("\nEnter element to search:");
    scanf("%d", &num);
    binarySearch(arr, size, num);

    return 0;
}