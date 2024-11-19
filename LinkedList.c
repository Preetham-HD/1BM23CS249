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
 struct Node * insert_beg(struct Node * start,int data){
      struct Node *newN;
      newN=newNode(data);
      newN->Next=start;
      start=newN;
      printf("\n inserted %d at beginning",data);
      return start;
}
struct Node * insert_end(struct Node * start,int data){
      struct Node *newN,*ptr;
      newN=newNode(data);
      ptr=start;
      while(ptr->Next!=NULL){
        ptr=ptr->Next;
      }
      ptr->Next=newN;
      printf("\n inserted %d at end",data);
      return start;
}
struct Node *insert_pos(struct Node *start,int data, int pos){
    struct Node *new,*ptr;
    new=newNode(data);
    int idx=1;
    ptr=start;
    if(pos==0){
        return insert_beg(start,data);
    }
    while(idx<pos-1&&ptr!=NULL){
    ptr=ptr->Next;
    idx++;
    }
    
    new->Next=ptr->Next;
    ptr->Next=new;
    printf("\n inserted %d at position %d",data,pos);
    return start;
}
void display(struct Node *start){
    struct Node *ptr;
    ptr=start;
    printf("\n");
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->Next;
    }
    printf("NULL");
}
struct Node * delete_beg(struct Node * start){
    struct Node *ptr=start;
    start=start->Next;
    printf("\n %d is deleted from beginning",ptr->data);
    free(ptr);
    return start;
}
struct Node * delete_end(struct Node * start){
    struct Node *ptr,*n;
    n=start;
    ptr=start;
    while(ptr->Next->Next!=NULL){
        ptr=ptr->Next;
    }
    n=ptr->Next;
    ptr->Next=NULL;
    printf("\n %d is deleted from end",n->data);
    free(n);
    return start;
}
struct Node * delete_pos(struct Node * start,int pos){
    struct Node *ptr,*n;
    ptr=start;
    n=start;
    int idx=1;
    while(idx<pos-1&&ptr!=NULL){
    ptr=ptr->Next;
    idx++;
    }
    n=ptr->Next;
    ptr->Next=ptr->Next->Next;
    printf("\n %d is deleted from pos %d",n->data,pos);
    free(n);
    return start;
}
void main(){
    struct Node* start=NULL;
    start=insert_beg(start,10);
    start=insert_beg(start,20);
    start=insert_beg(start,50);
    start=insert_beg(start,70);
    start=insert_end(start,66);
    start=insert_pos(start,888,3);
    display(start);
    start=delete_end(start);
    start=delete_beg(start);
    display(start);
}

/*
OUTPUT:
 inserted 10 at beginning
 inserted 20 at beginning
 inserted 50 at beginning
 inserted 70 at beginning
 inserted 66 at end
 inserted 888 at position 3
70 -> 50 -> 888 -> 20 -> 10 -> 66 -> NULL
 66 is deleted from end
 70 is deleted from beginning
50 -> 888 -> 20 -> 10 -> NULL
*/ 
