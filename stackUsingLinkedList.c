#include <stdio.h>
#include <stdlib.h>

#define N 5
int topCounter=-1;

struct node
{
    int data;
    struct node *next;
};

struct node *createNode()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    return temp;
}

struct node* head;


void push(value){
    struct node* newNode = createNode();
    newNode->data = value;
    if(topCounter==n-1){
        printf("max limit reached");
    }
    topCounter++;
    if(head==NULL){
        head=newNode;
    }
    newNode->next=head;
    head=newNode;
}

void pop(){
    if(topCounter==-1){
        printf("NO more elements left in stack cannot pop");
        return;
    }
    struct node* temp;
    temp = head;
    head = temp->next;
    free(temp);
    topCounter--;
}

void main()
{
    int ch = -1;
    while (ch != 0)
    {
        int choice;
        printf("Enter choice 1 for pop and 2 for push");
        scanf("%d", &choice);
        if (choice == 1)
        {
        }
        else if (choice == 2)
        {
            printf("enter data");
            int value;
            scanf("%d", &value);
            push(value);
        }

        printf("Enter 0 to exit");
        scanf("%d", &ch);
    }
}


