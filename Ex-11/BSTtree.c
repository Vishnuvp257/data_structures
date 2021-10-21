#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *right;
    struct node *left;
};

struct node* create(int data){
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;

    return new;
}

struct node* insert(struct node *root,int data){

    if(root == NULL) root = create(data);
    else if(data <= root->data) root->left = insert(root->left,data);
    else root->right = insert(root->right,data);

    return root;

}

struct node* find_minimum(struct node* root){

    if(root == NULL) return NULL;
    else if(root->left != NULL) return find_minimum(root->left);

    return root;
}

struct node* delete(struct node *root,int data){

    if(root == NULL) return NULL;
    else if(data < root->data) delete(root->left,data);
    else if(data > root->data) delete(root->right,data);
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        else if(root->left == NULL || root->right == NULL){
            struct node *temp;
            if(root->left == NULL) temp = root->right;
            else temp = root->left;

            free(root);
            return temp;
        }
        else{
            struct node *temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
        }
    }
    return root;

}

void display(struct node *root){

    if(root == NULL)
        return;
    display(root->left);
    display(root->right);
    printf("%d ",root->data);
}


int main(){
   struct node *root;
   int choice, data;

   while(1){
       printf("\n\nBINARY SEARCH TREE\n\n");
       printf("Main Menu\n");
       printf("1.Create\n2.Insert\n3.Delete\n4.Display\n5.Exit");

       printf("\nEnter your choice : ");
       scanf("%d",&choice);

       switch (choice)
       {
       case 1:
           printf("\nEnter the data : ");
           scanf("%d",&data);
           root = create(data);
           break;
        case 2:
           printf("\nEnter the data : ");
           scanf("%d",&data);
           root = insert(root,data);
           break;
        case 3:
           printf("\nEnter the elemment to delete : ");
           scanf("%d",&data);
           root = delete(root,data);
           break;
        case 4:
           printf("\nThe BST tree elements are \n");
           display(root);
           break;
        case 5:
           exit(1);
           break;
        default:
           printf("Wrong input");
       }
    }
}