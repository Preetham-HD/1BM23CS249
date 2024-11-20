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
    printf("\n the linked list is: ");
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
struct Node *sort(struct Node* start){
    struct Node *curr=start;
    while(curr!=NULL){
        struct Node* dup=curr;
        while(dup->Next!=NULL){
            if(dup->data>dup->Next->data){
                int temp=dup->data;
                dup->data=dup->Next->data;
                dup->Next->data=temp;
            }
            dup=dup->Next;
            }
            curr=curr->Next;
        }
    

    return start;
}
struct Node *concat(struct Node*start, struct Node *start1){
    struct Node *ptr=start;
    while(ptr->Next!=NULL){
        ptr=ptr->Next;
    }
    ptr->Next=start1;

    return start;
}
struct Node *rev(struct Node*start){
    struct Node *prev=NULL;
    struct Node *curr=start;
    struct Node *next=curr->Next;
    while(next!=NULL){
        curr->Next=prev;
        prev=curr;
        curr=next;
        next=next->Next;
    }
    curr->Next=prev;
    return curr;
}
void main(){
    struct Node* start=NULL;
    struct Node *start1=NULL;
    start=insert_beg(start,10);
    start=insert_beg(start,20);
    start=insert_end(start,50);
    start=insert_beg(start,70);
    start=insert_end(start,66);
    start=delete_end(start);
    start=delete_beg(start);
    start=insert_beg(start,890);
    start1=insert_beg(start1,100);
    start1=insert_beg(start1,101);
    start1=insert_beg(start1,104);
    start1=insert_beg(start1,107);
    display(start);
    start=sort(start);
    display(start);
    struct Node *r=rev(start);
    display(r);
    struct Node *con=concat(start,start1);
     display(con);
    
   
}

