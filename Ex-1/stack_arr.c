//Stack ADT.

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack_arr[MAX];
int top = -1;

int isFull(){
    if (top == MAX-1)
        return 1;
    else
        return 0;
}

int isEmpty(){
    if (top ==-1)
        return 1;
    else
        return 0;
}

void push(int data){
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    top +=1;
    stack_arr[top] = data;
}

void pop(){
    if(isEmpty()){
        printf("Stack underflow\n");
        return;
    }
    int data = stack_arr[top];
    top-=1;
    printf("%d is popped out from stack\n\n",data);
}

void display(){
    if(top==-1){
        printf("stack underflow");
        return;
    }

    int i;
    printf("stack elements :\n");
    for(i=top; i>=0;i--){
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}

int main(){
    int choose,data;

    while(1){

    printf("\nMenu: ");
    printf("\n1.Push");
    printf("\n2.Pop");
    printf("\n3.Display");
    printf("\n4.Exit\n\n");
    
    printf("Enter Your choice : ");
    scanf("%d",&choose);

    switch (choose)
    {
    case 1:
        printf("Enter the element to push : ");
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
        printf("wrong choice..xxx\n");
    }
    }
}
    















// int peek(){
//     return stack_arr[top];
// }
 //printf("\n4.Print the top most element");