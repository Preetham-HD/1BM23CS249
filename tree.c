#include<stdio.h>
#include<stdlib.h>

 struct Node{
    int data;
    struct Node *left;
    struct Node *right;
 };
  struct Node *newN(int data){
    struct Node *new=(struct Node *)malloc(sizeof(struct Node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    return new;
  }
  struct Node * insert(struct Node *root,int data){
    if(root==NULL){
        return newN(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }

    return root;
  }

  void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
  }
  void preorder(struct Node* root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
  }
  void postorder(struct Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
  }
  void main(){
    struct Node *root=NULL;
     int choice;
    printf("\n 1.insert");
    printf("\n 2.display inorder");
    printf("\n 3.display postorder");
    printf("\n 4.display preorder");
    printf("\n 5.exit");
    printf("\n enter the choice:");
    scanf("%d",&choice);
    while(choice!=0){
        switch (choice)
        {
        case 1: {
            int data;
            printf("enter the data:");
            scanf("%d",&data);
            root=insert(root,data);
            break;
        }
         case 2: {
            printf("the inorder is:");
            inorder(root);
            break;
        }
         case 3: {
               printf("the postorder is:");
            postorder(root);
            break;
        }
         case 4: {
               printf("the preorder is:");
            preorder(root);
            break;
        }
        case 5: exit(0);

        default:{printf("enter the valid choice");
            break;
        }}
         printf("\n enter the choice:");
    scanf("%d",&choice);
    }
    
  
  }
  /*
  output:
   1.insert
 2.display inorder
 3.display postorder
 4.display preorder
 5.exit
 enter the choice:1
enter the data:10

 enter the choice:1
enter the data:5

 enter the choice:1
enter the data:4

 enter the choice:1
enter the data:7

 enter the choice:1
enter the data:15

 enter the choice:1
enter the data:17

 enter the choice:2
the inorder is:4 5 7 10 15 17 
 enter the choice:3
the postorder is:4 7 5 17 15 10 
 enter the choice:4
the preorder is:10 5 4 7 15 17 
 enter the choice:5*/
