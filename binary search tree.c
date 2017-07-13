#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node *left,*right;
};
struct Node *addNode(struct Node *root,int data){
    if(root==NULL){
        struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp->data = data;
        tmp->left = NULL;
        tmp->right = NULL;
        return tmp;
    }
    if(root->data < data){
        root->right = addNode(root->right,data);
    }else{
       root->left = addNode(root->left,data);
    }
    return root;
}
void Print(struct Node *root){
    if(root){
        printf("%d ",root->data);
        Print(root->left);
        Print(root->right);
    }
}
int minimum(struct Node *root){
  if(root->left == NULL){
    return root->data;
  }
  return minimum(root->left);
}

int maximum(struct Node *root){
  if(root->right == NULL){
    return root->data;
  }
  return maximum(root->right);
}
int main(){
  struct Node *root=NULL;
  root = addNode(root,67);
  addNode(root,78);
  addNode(root,50);
  addNode(root,56);
  addNode(root,76);
  addNode(root,80);
  addNode(root,77);
  addNode(root,49);
  Print(root);
  printf("\nMinimum = %d",minimum(root));
  printf("\nMaximum = %d",maximum(root));
  return 0;
}
