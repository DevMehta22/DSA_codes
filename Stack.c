#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack*ptr){
    if(ptr->top==-1){
        return 1;
    }
    return 0;
}

int isFull(struct Stack*ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    return 0;
}

int main(){
    struct Stack *S;
    S->size=4;
    S->top=-1;
    S->arr=(int*)malloc(S->size*sizeof(int));
    //pushing elements manually
    S->arr[0]=7;
    S->top++;
    S->arr[1]=5;
    S->top++;
    S->arr[2]=3;
    S->top++;
    S->arr[3]=1;
    S->top++;

    if (isEmpty(S))
    {
       printf("Stack is Empty");
    }
    if(isFull(S)){
        printf("No more elements could be pushed!");
    }
    

    return 0;
}