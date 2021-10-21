#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20

int stack[MAX];
int top = -1;

void push(int data)
{
   // printf("%d ",data);
    stack[++top] = data;
}

char pop()
{
    if(top == -1)
        return -1;
    return stack[top--];
}

int main(){

    char exp[MAX], *i ;
    int op1, op2;

    printf("Enter the Postfix Expression : ");
    scanf("%s",exp);

    i = exp;

    while(*i != '\0'){

        if(isalnum(*i))
            push(*i - 48);
        else{
            op2 = pop();
            op1 = pop();
           // printf("%d %d %c",op1 , op2, *i);

            switch (*i)
            {
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push( op1/op2 );
                break;
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            default:
                printf("wrong input %d",*i);
                exit(1);
            }
        }
        i++;
    }

    printf("Value = %d\n",stack[top]);

    return 0;
}