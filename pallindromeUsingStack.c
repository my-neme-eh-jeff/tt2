#include <stdio.h>
#include <string.h>

#define n 100
char stack[n];
char string[n];
int top = -1;
int lenght;

void main()
{
    int flag=-1;
    printf("Please enter the word");
    gets(string);
    lenght = strlen(string);
    for (int i = 0; i < lenght; i++)
    {
        push(string[i]);
    }

    for (int i = 0; i < lenght; i++)
    {
        if (string[i] == pop())
        {
            top--;
            continue;
        }
        flag = 0;
        break;
    }
    if (flag == 0)
    {
        printf("Its pallindrome");
    }
    else
    {
        printf("not pallindrome ");
    }
}

void push(char data)
{
    top++;
    stack[top] = data;
}

void pop()
{
    return stack[top];   
}
