#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int top;
    int size;
    char *arr;
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

int push(struct Stack *ptr, char val)
{
    if (isFull(ptr))
    {
        return -1;
    }
    ptr->top++;
    ptr->arr[ptr->top] = val;
    return 0;
}

char pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        return 'F';
    }
    char val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

int isOperator(char val)
{
    if (val == '+' || val == '-' || val == '*' || val == '/')
    {
        return 1;
    }
    return 0;
}

int precedence(char val)
{
    if (val == '*' || val == '/')
    {
        return 2;
    }
    else if (val == '+' || val == '-')
    {
        return 1;
    }
    return 0;
}

char *infixToPostfix(char *infix, struct Stack *ptr)
{
    char *postFix = (char *)malloc(strlen((infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postFix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(ptr->arr[ptr->top]))
            {
                push(ptr, infix[i]);
                i++;
            }
            else
            {
                char val = pop(ptr);
                postFix[j] = val;
                j++;
            }
        }
    }
    while (!isEmpty(ptr))
    {
        postFix[j] = pop(ptr);
        j++;
    }
    postFix[j] = '\0';

    return postFix;
}

int main()
{
    struct Stack *S = (struct Stack *)malloc(sizeof(struct Stack));
    char *exp = "x-y/z-k*d";
    S->size = 100;
    S->arr = (char *)malloc(S->size * sizeof(char));
    S->top = -1;
    printf("The post fix expression is:%s", infixToPostfix(exp, S));

    return 0;
}