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