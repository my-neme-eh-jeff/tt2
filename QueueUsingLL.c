#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    return temp;
}

struct node *rear, *front;

void enqueu(int value)
{
    struct node *newNode = createNode();
    newNode -> data = value;
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("no queue exists to dequeue");
        return;
    }
    struct node *temp = front;
    front = temp->next;
    free(temp);
}

void displayQueue()
{
    struct node *temp = front;
    while(temp!=NULL){
        printf("%d\t", temp->data);
    }
}

void main()
{
    int ch = -1;
    while (ch != 0)
    {
        int choice;
        printf("Enter choice 1 for queue and 2 for dequeue");
        scanf("%d", &choice);
        if (choice == 2)
        {
            dequeue();
        }
        else if (choice == 1)
        {
            printf("enter data");
            int value;
            scanf("%d", &value);
            enqueu(value);
        }
        printf("Enter 0 to exit");
        scanf("%d", &ch);
    }
    displayQueue();
}