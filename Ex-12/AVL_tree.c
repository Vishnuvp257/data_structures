#include<stdio.h>
#include<stdlib.h>

//node
struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

//calculate height
int height(struct node *root){
    if(root == NULL) return 0;

    return root->height;
}

int max(int a,int b){
    return (a>b)? a : b;
}

//right rotate
struct node* right_rotate(struct node *root){
    struct node *n1 = root->left;
    struct node *n2 = n1->right;

    n1->right = root;
    root->left = n2;

    root->height = max(height(root->left),height(root->right)) + 1;
    n1->height = max(height(n1->left),height(n1->right)) + 1;

    return n1;
}

//left rotate
struct node* left_rotate(struct node *root){
    struct node *n1 = root->right;
    struct node *n2 = n1->left;

    n1->left = root;
    root->right = n2;

    root->height = max(height(root->left),height(root->right)) + 1;
    n1->height = max(height(n1->left),height(n1->right)) + 1;

    return n1;
}

//check balance 
int check_balance(struct node *root){
    if(root == NULL) return 0;

    return height(root->left) - height(root->right);
}

//set balance
struct node* set_balance(struct node *root,int data){

    int balance = check_balance(root);

    if(balance > 1 && data < root->left->data) return right_rotate(root);
    if(balance < -1 && data > root->right->data) return left_rotate(root);

    if(balance > 1 && data > root->left->data){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    if(balance < -1 && data < root->right->data){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;

}

//create node
struct node* create(int data){
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    new->height = 1;

    return new;
}

//insert node
struct node* insert(struct node *root,int data){
    if(root == NULL) return create(data);

    if(data < root->data) 
        root->left = insert(root->left,data);
    else if(data > root->data)
        root->right = insert(root->right,data);
    else 
        return root;

    //update height and balance 
    root->height = max(height(root->left),height(root->right)) + 1;
    return set_balance(root,data);
}

//finding minimum in the right sub-tree (successor)
struct node* find_minimum(struct node *root){
    if(root == NULL) return NULL;
    else if(root->left != NULL) return find_minimum(root->left);

    return root;
}

//delete node
struct node* delete(struct node *root,int data){
    if(root == NULL) return NULL;
    else if(data < root->data) return delete(root->left,data);
    else if(data > root->data) return delete(root->right,data);
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            return root;
        }
        else if(root->left !=NULL || root->right !=NULL){
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

    if(root == NULL) return root;

    
    //update height and balance 
    root->height = max(height(root->left),height(root->right)) + 1;
    return set_balance(root,data);
}

//traversel and display
void display(struct node *root){
    if(root != NULL){
        printf("%d ",root->data);
        display(root->left);
        display(root->right);
    }
}

int main(){
    struct node *root = NULL;

    root = create(1);
    root = insert(root,2);

    display(root);

    root = delete(root,1);

    printf("after deletion\n");
    display(root);
}