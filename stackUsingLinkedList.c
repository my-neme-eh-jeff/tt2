#include <stdio.h>

struct node{
    struct node* next;
    int data;
};

int topCounter =-1;

struct node* createNode(){
    struct node* temp;
    temp= (struct node*) (malloc(sizeof(struct node)));
    temp->next = NULL ;
    return temp;
} 

struct node * top;

void pop(){
    if(topCounter==-1){
        printf("No node exist in stack to pop");
    }else{
    printf("The value popped is %d",top->data);
    topCounter--;
    struct node *temp = top;
    top = top->next;
    free(temp);
    }
}

void push(int value){
    struct node* newNode = createNode();
    topCounter++;
    if (top==NULL){
        top = newNode;
        newNode->data = value;
        return ;
    }
    newNode->next = top;
    top = newNode;
}

void display(){
    printf("The stack contains:\n")
    struct node* temp;
    temp = top;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
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
            pop();
        }
        else if (choice == 2)
        {
            printf("enter data");
            int value;
            scanf("%d", &value);
            push(value);
        }
        printf("\nEnter 0 to exit");
        scanf("%d", &ch);
    }
    display();
}
