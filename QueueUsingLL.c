#include <stdio.h>
#include <stlib.h>

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

struct node *rear, front;
rear = createNode();
front = createNode();

void enqueu(int value)
{
    struct node *newNode = createNode();
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
    rear->data = value;
}

void dequeue()
{
    if (front == NULL)
    {
        printf("") return;
    }
    struct node *temp = front;
    front = temp->next;
    free(temp);
}

void displayQueue()
{
    struct node *temp = front do
    {
        printf("%d\t", temp->data)
    }
    while (temp->next != NULL)
        ;
}

/*
if(front == null){
    front = nn
    rear = nn
}
else
{
    rear-> next = nn; rear = nn;
}

*/