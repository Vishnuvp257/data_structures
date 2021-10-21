#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data){

    if((rear+1)%MAX == front){
        printf("Queue is Full !\n");
        return;
    }
    else if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = data;
    }
    else{
        rear = (rear+1)%MAX;
        queue[rear] = data;
    }
}

void dequeue(){
    int value;

    if(front == -1 && rear == -1){
        printf("Queue is Empty !\n");
        return;
    }
    else if(front == rear){
        value = queue[front];
        front = -1;
        rear = -1; 
    }
    else{
        value = queue[front];
        front = (front+1)%MAX;
    }
    printf("%d is deleted from the queue\n",value);
}

void display(){

    int i;

    if(front == -1 && rear == -1){
        printf("Queue is Empty !\n");
        return;
    }

    printf("Elements in the queue : \n");

    for(i=front; i!=rear; i = (i+1)%MAX)
        printf("%d ",queue[i]);
    printf("%d",queue[rear]);
}


int main(){

    int choose,data;

    while(1){

        printf("\nMenu:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n\n");
    
        printf("Enter Your choice : ");
        scanf("%d",&choose);

        switch (choose)
        {
        case 1:
            printf("Enter the element to insert : ");
            scanf("%d",&data);
            enqueue(data);
            break;
    
        case 2:
            dequeue();
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