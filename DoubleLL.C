#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *Next;
};
struct Node *newNode(int data){
    struct Node *new;
    new=(struct Node *)malloc(sizeof(struct Node));
    new->data=data;
    new->Next=NULL;
    new->prev=NULL;
    return new;
}
struct Node * insertleft(struct Node *start,int data,int val){
    struct Node *new=newNode(data);
    struct Node *ptr=start;
    if(start==NULL){
        start=new;
        return start;
    }
    while(ptr->data!=val){
        ptr=ptr->Next;
    }
    if(ptr->prev==NULL){
         
         new->Next=start;
         start->prev=new;
         start=new;
         return start;
    }
    ptr->prev->Next=new;
    new->prev=ptr->prev;
    new->Next=ptr;
    ptr->prev=new;
    return start;
    
}
struct Node *dele(struct Node *start,int val){
     struct Node *ptr=start;

     while(ptr->data!=val){
        ptr=ptr->Next;
     }
     if(ptr->prev==NULL&&ptr->Next==NULL){
        free(ptr);
        return NULL;
     }
     if(ptr->prev==NULL&&ptr->Next!=NULL){
        ptr->Next->prev=NULL;
        start=ptr->Next;
        free(ptr);
        return start;
     }
     if(ptr->prev!=NULL&&ptr->Next==NULL){
        ptr->prev->Next=NULL;
        free(ptr);
        return start;
     }
     (ptr->prev)->Next=ptr->Next;
     (ptr->Next)->prev=ptr->prev;
     free(ptr);

     return start;
}

void display(struct Node *start){
    struct Node *ptr=start;
    if(start==NULL){
        printf("the linked list is empty:");
    }
    else{
        printf("\n the linked lsit is:");
        while(ptr!=NULL){
            printf("%d ->",ptr->data);
            ptr=ptr->Next;
        }
        printf("NULL");
    }
}
void main(){
    struct Node *start=NULL;
    int choice;
    printf("\n 1.insert left");
    printf("\n 2.delete the specified element");
    printf("\n 3.display");
    printf("\n 4.exit");
    printf("\n enter the choice:");
    scanf("%d",&choice);
    while(choice!=0){
        switch (choice)
        {
        case 1: {
            int data,val;
            printf("enter the data:");
            scanf("%d",&data);
             printf("enter the element :");
            scanf("%d",&val);
            start=insertleft(start,data,val);
            break;
        }
         case 2: {
            int data;
            printf("enter the element to be deleted :");
            scanf("%d",&data);
            start=dele(start,data);
            break;
        }
         case 3: {
             display(start);
            break;
        }
        case 4: exit(0);
        default:{printf("enter the valid choice");
            break;
        }}
         printf("\n enter the choice:");
    scanf("%d",&choice);
    }
    /*
   output:  


 1.insert left
 2.delete the specified element
 3.display
 4.exit
 enter the choice:1
enter the data:23

 enter the choice:1
enter the data:45

 enter the choice:1
enter the data:56

 enter the choice:1  
enter the data:67

 enter the choice:1  
enter the data:78

 enter the choice:1
enter the data:90

 enter the choice:1
enter the data:56

 enter the choice:3

 the linked lsit is:56 ->90 ->78 ->67 ->56 ->45 ->23 ->NULL
 enter the choice:2
enter the element to be deleted :78

 enter the choice:2
enter the element to be deleted :56

 enter the choice:3

 the linked lsit is:90 ->67 ->56 ->45 ->23 ->NULL
 enter the choice:4
PS C:\Users\Admin\Desktop\1bm23cs249> cd "c:\Users\Admin\Desktop\1bm23cs249\" ; if ($?) { gcc doubleLL.c -o doubleLL } ; if ($?) { .\doubleLL }

 1.insert left
 2.delete the specified element
 3.display
 4.exit
 enter the choice:1
enter the data:34
enter the element :34

 enter the choice:3

 the linked lsit is:34 ->NULL
 enter the choice:1
enter the data:45
enter the element :34

 enter the choice:1
enter the data:67
enter the element :34

 enter the choice:67
enter the valid choice
 enter the choice:1
enter the data:78
enter the element :34

 enter the choice:3

 the linked lsit is:45 ->67 ->78 ->34 ->NULL
 enter the choice:1
enter the data:88
enter the element :45

 enter the choice:3

 the linked lsit is:88 ->45 ->67 ->78 ->34 ->NULL
 enter the choice:2
enter the element to be deleted :67

 enter the choice:3

 the linked lsit is:88 ->45 ->78 ->34 ->NULL
 enter the choice:1
enter the data:48
enter the element :88

 enter the choice:3

 the linked lsit is:48 ->88 ->45 ->78 ->34 ->NULL
 enter the choice:2
enter the element to be deleted :45

 enter the choice:3

 the linked lsit is:48 ->88 ->78 ->34 ->NULL
 enter the choice:4
 */
}
