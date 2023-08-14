#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int push(struct stack *ptr, char val)
{
    ptr->top++;
    ptr->arr[ptr->top] = val;

    return 0;
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        return -1;
    }

    int temp = ptr->arr[ptr->top];
    ptr->top--;
    return 0;
}

int main()
{
    struct stack *s;
    char exp[] = "(2+(7)*(3/4)+(1))";
    s->size = sizeof(exp) / sizeof(char);
    s->arr = (char *)malloc(s->size * sizeof(char));
    s->top = -1;
    int n = 0;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(s, '(');
        }
        if (exp[i] == ')')
        {
            int l = pop(s);
            if (l == -1)
            {
                break;
            }
        }
        n++;
    }
    if (!isEmpty(s) || n != s->size - 1)
    {
        printf("Expression Unbalanced");
    }
    if (isEmpty(s) && n == s->size - 1)
    {
        printf("Expression Balanced");
    }
    printf("%d", s->size);

    return 0;
}