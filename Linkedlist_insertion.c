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

struct Node *insertionAtFirst(struct Node *head, int data)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;

    return ptr;
}

struct Node *insertionAtBetween(struct Node *head, int data, int index)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->data = data;
    p->next = ptr;

    return 0;
}

struct Node *insertionAtEnd(struct Node *head, int data)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->data = data;

    return 0;
}

struct Node *insertionAfterNode(struct Node *head, int data, struct Node *preNode)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = preNode->next;
    preNode->next = ptr;
    return ptr;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 15;
    third->next = NULL;
    printf("Linkedlist before insertion\n");
    LinkedListTraversal(head);
    printf("Linkedlist after insertion at start\n");
    head = insertionAtFirst(head, 17);
    LinkedListTraversal(head);
    printf("Linkedlist after insertion at between\n");
    insertionAtBetween(head, 19, 2);
    LinkedListTraversal(head);
    printf("Linkedlist after insertion at end\n");
    insertionAtEnd(head, 21);
    LinkedListTraversal(head);
    printf("Linkedlist after insertion after a node\n");
    insertionAfterNode(head, 25, third);
    LinkedListTraversal(head);

    return 0;
}