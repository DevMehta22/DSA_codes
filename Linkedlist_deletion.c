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
    while (ptr != NULL)
    {
        n++;
        printf("Element of Node %d:%d\n", n, ptr->data);
        ptr = ptr->next;
    }
}

struct Node *DeletingFirstNode(struct Node *ptr)
{
    struct Node *p = ptr;
    ptr = p->next;
    free(p);

    return ptr;
}

struct Node *DeletingNodeAtMid(struct Node *ptr, int index)
{
    struct Node *p = ptr;
    int i = 0;
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    struct Node *q = p->next;
    p->next = q->next;
    free(q);

    return ptr;
}

struct Node *DeletingNodeAtEnd(struct Node *ptr)
{
    struct Node *p = ptr;
    struct Node *q = p->next;
    while (q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);

    return ptr;
}

struct Node *DeletingNodeAtValue(struct Node *ptr, int value)
{
    struct Node *p = ptr;
    struct Node *q = p->next;
    if (p->data == value)
    {
        ptr = p->next;
        free(p);
    }
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }

    return ptr;
}

int main()
{
    struct Node *head, *second, *third;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 15;
    third->next = NULL;

    // original list
    LinkedListTraversal(head);

    // deletion at first node
    head = DeletingFirstNode(head);
    LinkedListTraversal(head);

    // deleting Node at an index
    int ind;
    printf("Enter the index:");
    scanf("%d", &ind);
    DeletingNodeAtMid(head, ind);
    LinkedListTraversal(head);

    // deleting node at end
    DeletingNodeAtEnd(head);
    LinkedListTraversal(head);

    // deleting node at a given
    int val;
    printf("Enter the value:");
    scanf("%d", &val);
    head = DeletingNodeAtValue(head, val);
    LinkedListTraversal(head);

    return 0;
}