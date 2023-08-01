#include <stdio.h>

void set(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter arr[%d] element:", i);
        scanf("%d", &arr[i]);
    }
}

// void get(int arr[], int size)
// {
//     // Traversal
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
// }

void linearSearch(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            printf("Element found at arr[%d]", i);
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
    printf("\nEnter element to search:");
    scanf("%d", &num);
    linearSearch(arr, size, num);
    return 0;
}