#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traversal(struct Node *ptr)
{
    int i = 0;
    struct Node *p = ptr;
    do
    {
        i++;
        printf("Element at Node %d:%d\n", i, p->data);
        p = p->next;
    } while (p != ptr);
}

struct Node *insertion(struct Node *ptr, int num)
{
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = ptr->next;
    q->data = num;
    while (p->next != ptr)
    {
        p = p->next;
    }
    p->next = q;
    q->next = ptr;

    return q;
};

struct Node*insertionAtIndex(struct Node *ptr,int num,int index)
{   struct Node*q=(struct Node *)malloc(sizeof(struct Node));
    q->data=num;
    struct Node*p=ptr;
    int i=0;
    while(i!=index-1){
        i++;
        p=p->next;
    }
    q->next=p->next;
    p->next=q;

    return ptr;
};


int main()
{
    struct Node *head, *second, *third, *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 15;
    third->next = fourth;

    fourth->data = 17;
    fourth->next = head;

    Traversal(head);
//INSERTION AT HEAD NODE
    int num;
    printf("Enter the number:");
    scanf("%d", &num);
    head = insertion(head, num);
    printf("After Insertion\n");
    Traversal(head);
//INSERTION AT ANY NODE
    int num1,index;
    printf("Enter the number:");
    scanf("%d", &num1);
    printf("Enter the index:");
    scanf("%d",&index);
    printf("After insertion at any node\n");
    insertionAtIndex(head,num1,index);
    Traversal(head);
    return 0;
}