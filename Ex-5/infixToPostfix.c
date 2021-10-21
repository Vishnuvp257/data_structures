#include<stdio.h>
#include<ctype.h>
#define MAX 20

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop(){
    if(top == -1)
        return -1;
    return stack[top--];
}

int priority(char ch)
{
    if(ch =='(')
        return 0;
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/')
        return 2;
}

int main()
{
    char exp[MAX];
    char *i, ch;

    printf("Enter the Expression : ");
    scanf("%s",exp);

    i = exp;

    while(*i != '\0')
    {
        if(isalnum(*i))
            printf("%c",*i);
        else if(*i == '(')
            push(*i);
        else if(*i == ')')
        {
            while((ch=pop()) != '('){
              ///  printf("%c",pop());A
               printf("%c",ch);
            }
                
        }
        else
        {
            while(priority(stack[top]) >= priority(*i))
                printf("%c",pop());
            push(*i);
        }
        i++;
    }

    while(top != -1)
    {
        printf("%c",pop());
    }
}