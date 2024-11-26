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
struct Node *push(struct Node *top,int data){
    struct Node *newN=newNode(data);
    if(top==NULL){
        top=newN;
    }
    else{
        newN->Next=top;
        top=newN;
    }
    printf("\n %d inserted",data);
    return top;
}
struct Node *pop(struct Node *top){
if(top==NULL){
    printf("underflow");
    return NULL;
}
struct Node *ptr=top;
top=top->Next;
printf("\n %d popped from stack",ptr->data);
free(ptr);
return top;
}
void display(struct Node *top){
    struct Node *ptr;
    ptr=top;
    printf("\n the stack is: ");
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->Next;
    }
    printf("NULL");
}
void main(){
    struct Node *top=NULL;
    top=push(top,20);
    top=push(top,45);
    top=push(top,67);
    display(top);
    top=pop(top);
    display(top);
}

/*
OUTPUT:
 20 inserted
 45 inserted
 67 inserted
 the stack is: 67 -> 45 -> 20 -> NULL
 67 popped from stack
 the stack is: 45 -> 20 -> NULL
*/
