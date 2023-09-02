#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

struct Node *push(struct Node *ptr, int x)
{
    if (isFull())
    {
        printf("Stack overflow\n");
    }
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = x;
    p->next = ptr;
    ptr = p;
    return ptr;
}

int pop(struct Node **ptr)
{
    if (isEmpty(*ptr))
    {
        printf("Stack underflow.\n");
        return 0;
    }
    struct Node *n = *ptr;
    *ptr = (*ptr)->next;
    int x = n->data;
    free(n);
    return x;
}

int peek(struct Node *ptr, int index)
{
    struct Node *p = ptr;
    for (int i = 0; i < index - 1 && ptr != NULL; i++)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        printf("INvalid Index\n");
        return -1;
    }
    printf("The element at position %d is %d\n", index, p->data);
    return 0;
}

int display(struct Node *ptr)
{
    printf("The stack elements are:\n");
    struct Node *p = ptr;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    return 0;
}

int stackTop(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("Empty Stack\n");
        return -1;
    }
    printf("The topmost element of stack is %d\n", ptr->data);
    return 0;
}

int stackBottom(struct Node *ptr)
{
    struct Node *p = ptr;
    if (ptr == NULL)
    {
        printf("Empty Stack\n");
        return -1;
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    printf("The bottommost element of stack is %d\n", p->data);
    return 0;
}

int main()
{
    struct Node *top = NULL;
    int ch = 1;
    int num, x, pos;
    while (ch)
    {
        printf("Enter your choice\n1.push\n2.pop\n3.peek\n4.display\n5.stackTop\n6.stackBottom\n7.exit\n");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            printf("Enter the element to push:");
            scanf("%d", &x);
            top = push(top, x);
            break;
        case 2:
            printf("The popped element is: %d\n", pop(&top));
            break;
        case 3:
            printf("Enter the position of element:");
            scanf("%d", &pos);
            peek(top, pos);
            break;
        case 4:
            display(top);
            break;
        case 5:
            stackTop(top);
            break;
        case 6:
            stackBottom(top);
            break;
        case 7:
            ch = 0;
            printf("Program successfully closed!");
            break;
        default:
            printf("Invalid input");
            break;
        }
    }
    return 0;
}
