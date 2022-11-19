#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left,*right;
};

struct node *createNode()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right= NULL;
    return temp;
}

struct node* createBinaryTree(){
    struct node* newNode=createNode();
    int x;
    printf("Enter the data for the node (-1 for no node)");
    scanf("%d",&x);
    if(x==-1){
        return NULL;
    }
    newNode->data = x;
    printf("Now for its left child");
    newNode->left =createBinaryTree();
    printf("Now for its right child");
    newNode-> right = createBinaryTree();

    return newNode;
}

void inorder(struct node* currentRoot){
    if(currentRoot==NULL){
        return;
    }
    inorder(currentRoot->left);
    printf("%d\t",currentRoot->data);
    inorder(currentRoot->right);
}

void preorder(struct node* currentRoot){
    if(currentRoot==NULL){
        return;
    }
    printf("%d\t",currentRoot->data);
    preorder(currentRoot->left);
    preorder(currentRoot->right);
}

void postorder(struct node* currentRoot){
    if(currentRoot==NULL){
        return;
    }
    postorder(currentRoot->left);
    postorder(currentRoot->right);
    printf("%d\t",currentRoot->data);
}

void main(){
    struct node* root;
    root = createBinaryTree();
    printf("Inorder traversal is \n");
    inorder(root); 
    printf("\nPostorder traversal is \n");
    postorder(root);
    printf("\nPreorder traversal is \n");
    preorder(root);
}

