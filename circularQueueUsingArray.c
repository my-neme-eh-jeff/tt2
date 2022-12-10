// This is used so as so save extra space that is generated
// when we dequeue as front moves forwards but we normally
// dont refill the now empty spaces
// we use (x + 1)%n for checking if full or incrementing

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
            enqueu(value);
        }
        printf("Enter 0 to exit");
        scanf("%d", &ch);
    }
    displayQueue();
}

void displayQueue()
{
    if (front == -1)
    {
        printf("The queue doesnt exist");
        return;
    }
    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
    }
    if (front > rear)
    {
        for (int i = front; i < n; i++)
        {
            printf("%d\t", queue[i]);
        }
        for (int i = 0; i <= rear;i++)
        {
            printf("%d\t", queue[i]);
        }
    }
}

void enqueu(int value)
{
    if (front == -1)
    {
        front++;
        rear++;
        queue[rear]=value;
    }else if(front==(rear+1)%n){
        printf("queue is full");
        return;
    }else{
        rear = (rear+1)%n;
        queue[rear]= value;
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("No queue exists");
        return;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }else{
        front = (front+1)%n;
    }
}