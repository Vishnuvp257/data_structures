#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* Insert_At_beginning(struct node *head,int data){

    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    struct node *temp = new;

    if(head == NULL){
        return new;
    }
    
    temp->next = head;
    head = temp;

    return head;
}

void Insert_At_End(struct node *head, int data){

    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    struct node *temp = head;
    //struct node *temp2 = head;
    
    if(head == NULL){
        temp = new;
        return;
    }

    if(head->next == NULL){
        temp->next = new;
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new;
}

struct node* Insert_At_InBetween(struct node *head,int data, int pos){

    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    struct node *temp1 = head;
    struct node *temp2 = head->next;

    while(pos > 1){
        temp1 = temp1->next;
        temp2 = temp2->next;
        pos--;
    }
    temp1->next = new;
    new->next = temp2;

    return head;
}

struct node* Delete_At_Beginning(struct node *head){

    if(head == NULL){
        return head;
    }

    if(head->next == NULL){
        free(head);
        head = NULL;
        return head;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

void Delete_At_End(struct node *head){

     if(head == NULL){
        return;
    }

    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;

    while(temp->next->next!= NULL){
        temp = temp->next;
    }
    
    struct node *temp2 = temp;
    temp =temp->next;
    free(temp);
    temp2->next = NULL;
}

void Delete_At_InBetween(struct node *head, int pos){
    
}

void display(struct node *head){

    struct node *temp = head;

    printf("List Data : ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");

    // printf("%d",temp->data);
    // printf("%d",temp->next->data);
    // printf("%d",temp->next->next->data);
}


int main(){

    int data, choice, wish , pos;

    struct node *head = malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;


    while(1){

        printf("\nMenu\n1.Insert a Node\n2.Delete a Node\n3.Display\n4.Exit\n\n");
        printf("Enter Your Choice = ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("\n1.Insert At Beginning  2.Insert At End  3.Insert In Between  4.back<<\n");
            printf("\nEnter any one : ");
            scanf("%d",&wish);

            switch (wish)
            {
            case 1:
                printf("Enter a data : ");
                scanf("%d",&data);
                
                head = Insert_At_beginning(head,data);
                break;
            case 2:
                printf("Enter a data : ");
                scanf("%d",&data);
                
                Insert_At_End(head,data);
                break;
            case 3:
                printf("Enter a data : ");
                scanf("%d",&data);

                printf("Enter the position to insert : ");
                scanf("%d",&pos);

                Insert_At_InBetween(head,pos,data);
                break;
            case 4:
                break;
            default:
                printf("wrong input!!\n");
                break;
            }
            break;

        case 2:
            printf("\n1.Delet At Beginning  2.Delete At End  3.Delete In Between  4.back<<\n");
            printf("\nEnter any one : ");
            scanf("%d",&wish);

            switch (wish)
            {
            case 1:
                head = Delete_At_Beginning(head);
                printf("one node deleted at the beginning\n");
                
                break;
            case 2:
                Delete_At_End(head);
                printf("one node deleted at the end\n");
                break;
            case 3:
                printf("Enter the postion : ");
                scanf("%d",&pos);

                //Delete_At_InBetween(head,pos);
                //printf("");
                break;
            case 4:
                break;
            default:
                printf("wrong input!!\n");
                break;
            }
            break;

        case 3:
            display(head);
            break;
        
        case 4:
            exit(1);

        default:
            printf("wrong input!!\n");
        }
    }
}   
