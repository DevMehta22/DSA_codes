#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr)
{
    int n = 0;
    do
    {
        n++;
        printf("Data of Node %d: %d\n", n, ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocated memory for nodes in heap..
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // linking nodes..
    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 15;
    third->next = NULL;

    // Linked list traversal
    LinkedListTraversal(head);

    return 0;
}