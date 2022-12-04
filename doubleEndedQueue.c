# include<stdio.h>
# define Size 5
int deque_arr[Size];
int front = -1;
int rear = -1;
void insert_rear()
{
    int added_item;
    if((front == 0 && rear == Size-1) || (front == rear+1))
    {   printf("Queue Overflow\n");
        return;}
    if (front == -1)
    {   front = 0;
        rear = 0;}
    else
    if(rear == Size-1)  
        rear = 0;
    else
        rear = rear+1;
         
    printf("Input the element for adding in queue : ");
    scanf("%d", &added_item);
    deque_arr[rear] = added_item ;
}
void insert_front()
{   int added_item;
    if((front == 0 && rear == Size-1) || (front == rear+1))
    {   printf("Queue Overflow \n");
    }
    if (front == -1)
    {   front = 0;
        rear = 0;    }
    else
    if(front== 0)
        front=Size-1;
    else
        front=front-1;
    printf("Input the element for adding in queue : ");
    scanf("%d", &added_item);
    deque_arr[front] = added_item ;  }
void delete_front()
{   if (front == -1)
    {   printf("Queue Underflow\n");
        return ;
    }
    printf("Element deleted from queue is : %d\n",deque_arr[front]);
    if(front == rear)
    {   front = -1;
        rear=-1;
    }
    else
        if(front == Size-1)
            front = 0;
        else
            front = front+1;
}
void delete_rear()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return ;
    }
    printf("Element deleted from queue is : %d\n",deque_arr[rear]);
    if(front == rear)
    {
        front = -1;
        rear=-1;
    }
    else
        if(rear == 0)
            rear=Size-1;
        else
            rear=rear-1;    }

void display_queue()
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
            printf("%d\t", deque_arr[i]);
        }
    }
    if (front > rear)
    {
        for (int i = front; i < Size; i++)
        {
            printf("%d\t", deque_arr[i]);
        }
        for (int i = 0; i <= rear;i++)
        {
            printf("%d\t", deque_arr[i]);
        }
    }
}

void input_que()
{   int choice;
    do
    {   printf("1.Insert at rear\n");
        printf("2.Delete from front\n");
        printf("3.Delete from rear\n4)Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
 
        switch(choice)
        {   case 1:
            insert_rear();
            break;
         case 2:
            delete_front();
            break;
         case 3:
            delete_rear();
            break;
         case 4:break;
         default:
            printf("Wrong choice\n");
        }
    }while(choice!=4);
}

void output_que()
{   int choice;
    do
    {   printf("1.Insert at rear\n");
        printf("2.Insert at front\n");
        printf("3.Delete from front\n4)Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
         case 1:
            insert_rear();
            break;
         case 2:
            insert_front();
            break;
         case 3:
            delete_front();
            break;
            case 4:break;
         default:
            printf("Wrong choice\n");
        }
    }while(choice!=4);
}

void main()
{   int choice;
    do
    {
    printf("1.Input restricted dequeue\n");
    printf("2.Output restricted dequeue\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1 :
        input_que();
        break;
     case 2:
        output_que();
        break;
    case 3:display_queue();
        break;
        case 4:printf("Bye");
        break;
     default:
        printf("Wrong choice\n");
    }
    }while(choice!=4);
}
