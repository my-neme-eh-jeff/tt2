#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int stack[100];
int top = -1;

bool isOperand(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(int value)
{
    top++;
    stack[top] = value;
}

int pop()
{
    int l = stack[top];
    top--;
    return l;
}

int evaluatePostix(char input[])
{
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        char ch = input[i];
        if (isOperand(ch) == true)
        {
            push((int)(ch-'0'));
        }
        else
        {
            int value;
            int op1 = pop();
            int op2 = pop();
            switch (ch)
            {
            case '+':
                value = op2 + op1;
                break;
            case '/':
                value = op2 / op1;
                break;
            case '*':
                value = op2 * op1;
                break;
            case '-':
                value = op2 - op1;
                break;
            }
            push(value);
        }
    }
    return stack[top];
}

void main()
{
    char input[100];
    printf("Enter the postfix expression please");
    gets(input);
    printf("The final answer is %d", evaluatePostix(input));
}