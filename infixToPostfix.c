#include <stdio.h>
#include <stdbool.h>

int stack[1000];
int top=-1;

void push(int value){
    top++;
    stack[top]=value;
}

int pop(){
    if(top==-1){
        printf("There is nothing to pop");
    }
    top--;
}

bool isOperator(char ch){
    if(ch=='+'||ch=='*'||ch=='-'||ch=='/'||ch=='^'){
        return true;
    }else{
        return false;
    }
}

bool isOperand(char ch){
    if((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z')){
        return true;
    }else{
        return false;
    }
}

char associativity(char ch){
    if(ch=='^'){
        return 'R';
    }else{
        return 'L';
    }
}

int peek(){
    return top;
}

int precedence(char ch){
    if(ch=='+'||ch=='-'){
        return 1;
    }else if(ch=='*'||ch=='/'){
        return 2;
    }else{
        return 3;
    }
}

void main(){
    printf("Enter the infix expression PWEAASEEEEE DADDDYYY");
    char data [1000];
    gets(data);
    char ch;

    for(int i=0;i<strlen(data);i++){
        ch = data[i];
        if(isOperand(ch)){
            printf("%c",ch);
        }else if(isOperator(ch)&&(top==-1 || stack[top] == '(')){
            push(ch);
        }else if(ch=='('){
            push(ch);
        }else if(ch==')'){
            while(stack[top]!='('){
                printf("%c",stack[top]);
                pop();
            }
            pop();
        }else if(isOperator(ch)){
            if( precedence(stack[top]) > precedence(ch) ){
                printf("%c",stack[top]);
                pop();
                i--;
            }else if(precedence(stack[top])==precedence(ch) ){
                if(associativity(ch)=='R'){
                    push(ch);
                }else{
                    printf("%c",stack[top]);
                    pop();
                    i--;
                }
            }else{
                push(ch);
            }
        }         
    }
    
    for(int i=top;i>=0;i--){
        printf("%c",stack[top]);
        pop();
    }
}