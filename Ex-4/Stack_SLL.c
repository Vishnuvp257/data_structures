#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *top = NULL;

void push(int data){

    struct node *stack_List = malloc(sizeof(struct node));
    stack_List->data = data;

    struct node *temp = stack_List;
    temp->next = top;
    top = temp;
}

void pop(){

    if(top == NULL){
        printf("Stack Underflow");
        return;
    }

    struct node *temp = top;
    top = temp->next;

    printf("%d is popped out from stack\n",temp->data);
}

void display(){

    if(top==NULL){
        printf("Stack Underflow");
        return;
    }

    struct node *temp = top;

    printf("stack elements are :\n");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){

    int choice, data;

    while(1){
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("\nenter your choice = ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter a data to push : ");
            scanf("%d",&data);
            push(data);
            break;

        case 2:
            pop();
            break;
        
        case 3:
            display();
            printf("\n");
            break;

        case 4:
            exit(1);
        
        default:
            printf("\nwrong input X x x X!");
        }
    }
}   
   