// Online C compiler to run C program online
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *Next;
};
struct Node * newNode(int data){
    struct Node* new;
    new= (struct Node *)malloc(sizeof(struct Node));
    new->data=data;
    new->Next=NULL;
    return new;
}
struct Node *enqueue(struct Node *front,struct Node **rear,int data){
    struct Node *newN=newNode(data);
    if(front==NULL){
        front=newN;
        *rear=newN;
    }
    else{
        (*rear)->Next=newN;
        *rear=newN;
    }
    printf("\n %d inserted",data);
    return front;
}
struct Node *dequeue(struct Node *front){
if(front==NULL){
    printf("underflow");
    return NULL;
}
struct Node *ptr=front;
front=front->Next;
printf("\n %d removed from queue",ptr->data);
free(ptr);
return front;
}
void display(struct Node *front){
    struct Node *ptr;
    ptr=front;
    printf("\n The Queue is: ");
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->Next;
    }
    printf("NULL");
}
void main(){
    struct Node *front=NULL;
    struct Node *rear=NULL;
    front=enqueue(front,&rear,20);
    front=enqueue(front,&rear,40);
    front=enqueue(front,&rear,50);
    front=enqueue(front,&rear,60);
    front=dequeue(front);
    display(front);
}

/*
 OUTPUT:

 20 inserted
 40 inserted
 50 inserted
 60 inserted
 20 removed from queue
 The Queue is: 40 -> 50 -> 60 -> NULL
*/
