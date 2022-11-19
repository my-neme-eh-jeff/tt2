#include <stdio.h>

#define n 5
int stack1[n], stack2[n];
int top1 = -1, top2 = -1;

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
            pop1();
        }
        else if (choice == 1)
        {
            int value;
            printf("enter data");
            scanf("%d", &value);
            push1(value);
        }
        printf("\nEnter 0 to exit");
        scanf("%d", &ch);
    }
    display();
}

void push1(int data)
{
    if (top1 == n - 1)
    {
        printf("stack overflow");
        return;
    }
    else
    {
        top1++;
        stack1[top1] = data;
    }
}

void push2(int data)
{
    top2++;
    stack2[top2] = data;
}

void pop1()
{
    while (top1 != 0)
    {
        int x = stack1[top1];
        top1--;
        push2(x);
    }
    printf("The number getting dequeued is %d", stack1[top1]);
    top1--;
    while (top2 != -1)
    {
        int x = stack2[top2];
        pop2();
        push1(x);
    }

}

void pop2()
{
    top2--;
}

void display()
{
    if (top1 == -1)
    {
        printf("STack is empty omggg");
    }
    for (int i = 0; i <= top1; i++)
    {
        printf("%d \t", stack1[i]);
    }
}
