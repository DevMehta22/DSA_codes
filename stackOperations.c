#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int push(struct Stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack overflow!\ncannot push %d to stack\n", val);
        return 0;
    }
    ptr->top++;
    ptr->arr[ptr->top] = val;
    return 0;
}

int pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow!\ncannot pop from stack\n");
        return 0;
    }
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

int main()
{
    struct Stack *S = (struct Stack *)malloc(sizeof(struct Stack));
    S->size = 4;
    S->top = -1;
    S->arr = (int *)malloc(S->size * sizeof(int));

    printf("Before pushing\n");
    if (isEmpty(S))
    {
        printf("Stack is Empty\n");
    }
    if (isFull(S))
    {
        printf("No more elements could be pushed!\n");
    }

    // push operation
    printf("After pushing\n");
    push(S, 23);
    push(S, 3);
    push(S, 32);
    push(S, 2);
    push(S, 232);

    if (isEmpty(S))
    {
        printf("Stack is Empty");
    }
    if (isFull(S))
    {
        printf("No more elements could be pushed!");
    }

    // pop operation
    printf("After poping\n");
    printf("Element %d successfully poped from stack!", pop(S));

    return 0;
}