#include <stdio.h>

// insert from rear and delete from front RIDF

#define n 5
int queue[n];
int front = -1, rear = -1;

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
            queuef(value);
        }
        printf("Enter 0 to exit");
        scanf("%d", &ch);
    }
    displayQueue();
}

void displayQueue()
{
    if (rear < front)
    {
        printf("The queue doesnt exist");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", queue[i]);
    }
}

void queuef(int value)
{
    if (front == -1)
    {
        front++; 
    }
    if (rear == n - 1)
    {
        printf("/n the queue is full");
    }
    rear++;
    queue[rear] = value;
}

void dequeue()
{
    if(front==-1){
        printf("No queue exists");
    }
    if(front == rear){
        front = -1;rear=-1;
    }
    if (rear < front)
    {
        printf("No element present in queue to dequeue");
    }
    front++;
}
