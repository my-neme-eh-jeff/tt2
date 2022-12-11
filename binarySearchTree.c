#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *createNode()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* inorderPredecessor(struct node* temp){
    //inorder predecessor for a node is the rightmost element in the nodes left subtree
    temp = temp-> left;
    while(temp->right!=NULL){
        temp= temp-> right;
    }
    return temp;
}

struct node* deleteNode(struct node *temp, int value)
{
    struct node* inorderPredecessorNode;

    
 
    if(value> temp->data){
        temp-> right = deleteNode(temp-> right,value);
    }else if(value< temp->data){
        temp-> left = deleteNode(temp-> left,value);
    }else{
        if(temp->left == NULL && temp->right ==NULL && temp->data==value){
        free(temp);
        return NULL;
        }
        else if(temp->left==NULL){
            struct node * rightChild = temp->right;
            free(temp);
            return(rightChild);
        }else if(temp->right== NULL){
            struct node* leftChild = temp->left;
            free(temp);
            return(leftChild);
        }else{
        inorderPredecessorNode= inorderPredecessor(temp);
        temp->data = inorderPredecessorNode-> data; 
        temp-> left = deleteNode(temp->left,inorderPredecessorNode->data);
    }}
    
    return temp;
}

void insert(struct node *root)
{
    int x;
    struct node *prev,*temp;
    int ch = -1;
    while (ch != 0)
    {
        temp = root;
        struct node *newNode = createNode();
        printf("Enter the data you want to insert");
        scanf("%d", &x);
        newNode->data = x;
        while (temp != NULL)
        {
            prev = temp;
            if (x > temp->data)
            {
                temp = temp->right;
            }
            else if (x < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                printf("Duplicates not allowed");
                break;
            } 
        }
        if (x < prev->data)
        {
            prev->left = newNode;
        }
        else
        {
            prev->right = newNode;
        }

        printf("Enter 0 to exit");
        scanf("%d", &ch);
    }
}

void inorder(struct node *currentRoot)
{
    if (currentRoot == NULL)
    {
        return;
    }
    inorder(currentRoot->left);
    printf("%d\t", currentRoot->data);
    inorder(currentRoot->right);
}

void preorder(struct node *currentRoot)
{
    if (currentRoot == NULL)
    {
        return;
    }
    printf("%d\t", currentRoot->data);
    preorder(currentRoot->left);
    preorder(currentRoot->right);
}

void postorder(struct node *currentRoot)
{
    if (currentRoot == NULL)
    {
        return;
    }
    postorder(currentRoot->left);
    postorder(currentRoot->right);
    printf("%d\t", currentRoot->data);
}

void main()
{
    int x;
    printf("Enter the data into the root");
    scanf("%d",&x);
    struct node *root = createNode();
    root->data = x;
    printf("For the rest of the tree-\n ");
    insert(root);

    printf("The tree created is:\n");
    printf("Inorder traversal is \n");
    inorder(root);
    printf("\nPostorder traversal is \n");
    postorder(root);
    printf("\nPreorder traversal is \n");
    preorder(root);

    int w;
    printf("\nEnter the value to be deleted");
    scanf("%d",&w);
    deleteNode(root,w);
    printf("Inorder traversal is \n");
    inorder(root);
    printf("\nPostorder traversal is \n");
    postorder(root);
    printf("\nPreorder traversal is \n");
    preorder(root);


}
