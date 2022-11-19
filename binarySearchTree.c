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
    //base condition
    
    if(temp->left == NULL && temp->right == NULL){
        free(temp);
        return NULL;
    }
 
    if(value> temp->data){
        temp-> right = deleteNode(temp-> right,value);
    }else if(value< temp->data){
        temp-> left = deleteNode(temp-> left,value);
    }else{
        inorderPredecessorNode= inorderPredecessor(temp);
        temp->data = inorderPredecessorNode-> data; 
        temp-> left = deleteNode(temp->left,inorderPredecessorNode->data);
    }
    
    return temp;
}

void insert(struct node *temp)
{
    int x;
    struct node *prev;
    struct node *newNode = createNode();
    int ch = -1;
    while (ch != 0)
    {
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
                return;
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
    struct node *root = createNode();
    root->data = 46;
    struct node *node1 = createNode();
    root->left = node1;
    node1->data = 20;
    struct node *node2 = createNode();
    root->right = node2;
    node2->data = 60;
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
