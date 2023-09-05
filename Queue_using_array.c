#include<stdio.h>
#include<stdlib.h>

struct Queue
{
   int size;
   int f;
   int r;
   int* arr;
};

int isFull(struct Queue *ptr){
    if(ptr->r==ptr->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *ptr){
    if(ptr->f==ptr->r){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *ptr,int val){
    if(isFull(ptr)){
        printf("Queue overflow\n");
    }
    else{
        ptr->r++;
        ptr->arr[ptr->r]=val;
    }
}

int dequeue(struct Queue *ptr){
    if(isEmpty(ptr)){
        return -1;
    }
    else{
        ptr->f++;
        int a = ptr->arr[ptr->f];
        return a;
    }
}

int main(){
    struct Queue *q;
    int size;
    printf("Enter the size of queue:");
    scanf("%d",&size); 
    q->size = size;
    q->f=q->r=-1;
    q->arr = (int *)malloc(q->size*sizeof(int));
    int ch =1;
    int choice;
    int value,a;
    
    while (ch==1)
    {  printf("Enter your choice:\n1.Enqueue\n2.Dequeue\n3.isEmpty\n4.isFull\n5.exit\n");
       scanf("%d",&choice);
       switch (choice)
        {
        case 1:
            printf("Enter the value to be enqueued:");
            scanf("%d",&value);
            enqueue(q,value);
            break;
        case 2:
            a =dequeue(q);
            if(a==-1){
                printf("No elements to dequeue\n");
                break;
            }
            printf("dequeuing element:%d\n",a);
            break;
        case 3:
            if(isEmpty(q)){
                printf("Queue is empty\n");
                break;
            }    
            printf("Queue is not empty\n");
            break;
        case 4:
            if(isFull(q)){
                printf("Queue is full\n");
                break;
            }    
            printf("Queue is not full\n");
            break;
        case 5:
            ch=0;
            printf("program exited successfully!");
            break;                
        default:
            printf("Invalid Input\n");
            break;
        }
    }    
    return 0;
}