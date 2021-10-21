#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue_arr[MAX];
int front = -1,rear = -1;

int isEmpty(){
    if(front == -1 && rear == -1)
        return 1;
    else 
        return 0;
}

int isFull(){
    if(rear== MAX-1)
        return 1;
    else
        return 0;
        
}

void insert(int data)
{
    if(isFull()){
        printf("Queue overflow\n");
        return;
    }
    rear++;
    queue_arr[rear] = data;

    if(front==-1){
        front++;
    }
}

void delete(){
    int value;

    if(isEmpty()){
        printf("Queue underflow\n");
        return;
    }
    value = queue_arr[front];
    printf("%d is deleted out of the queue\n",value);

    if(front == rear){
        front = -1;
        rear = -1;
    }
    else
        front++;
}

void display(){
    int i;
    if(isEmpty()){
        printf("Queue underflow\n");
        return;
    }

    printf("Queue elements :\n");
    for(i=front; i<=rear; i++)
        printf("%d ",queue_arr[i]);

    printf("\n");
}

int main(){

    int choose,data;

    while(1){

    printf("\nMenu: ");
    printf("\n1.Insert");
    printf("\n2.Delete");
    printf("\n3.Display");
    printf("\n4.Exit\n\n");
    
    printf("Enter Your choice : ");
    scanf("%d",&choose);

    switch (choose)
    {
    case 1:
        printf("Enter the element to insert : ");
        scanf("%d",&data);
        insert(data);
        break;
    
    case 2:
        delete();
        break;

    case 3:
        display();
        
        break;
    
    case 4:
        exit(1);
    
    default:
        printf("wrong choice..xxx\n");
    }
    }
}

