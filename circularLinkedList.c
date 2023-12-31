#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

void Traversal(struct Node *ptr){
    int i=0;
    struct Node*p=ptr;
    do
    {   i++;
        printf("Element at Node %d:%d\n",i,p->data);
        p= p->next;
    }while (p!=ptr);
    
}

int main(){
    struct Node*head,*second,*third,*fourth;

    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;

    second->data=11;
    second->next=third;

    third->data=15;
    third->next=fourth;

    fourth->data=17;
    fourth->next=head;

    Traversal(head);

    return 0;
}