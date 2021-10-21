// Program to add like term polynomial

#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coeff;
    int expo;
    struct node *link;
};

struct node *insert(struct node *head, int coeff, int expo)
{
    struct node *temp;

    struct node *new = malloc(sizeof(struct node));
    new->coeff = coeff;
    new->expo = expo;
    new->link = NULL;

    if (head == NULL || expo > head->expo)
    {
        new->link = head;
        head = new;
    }
    else
    {
        temp = head;
        while (temp->link != NULL && temp->expo > new->expo)
        {
            temp = temp->link;
        }
        new->link = temp->link;
        temp->link = new;
    }
    return head;
}

struct node *create(struct node *head)
{
    int n;
    float coeff;
    int expo;

    printf("\nEnter how many no of terms : ");
    scanf("%d", &n);
    

    int i;
    for (i = 0; i < n; i++)
    {
        printf("enter the coeff of term %d :", i + 1);
        scanf("%f", &coeff);

        printf("enter the exponent of term %d :", i + 1);
        scanf("%d", &expo);

        head = insert(head, coeff, expo);
    }
    return head;
}

struct node *add(struct node *head1, struct node *head2)
{
    struct node *add = NULL;

    struct node *ptr1 = head1;
    struct node *ptr2 = head2;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            add = insert(add, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            add = insert(add, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->link;
        }
        else
        {
            add = insert(add, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }

    while (ptr1 != NULL)
    {
        add = insert(add, ptr1->coeff , ptr1->expo);
        ptr1 = ptr1->link;
    }

    while (ptr2 != NULL)
    {
        add = insert(add, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->link;
    }

    return add;
}

void print(struct node *head)
{
    struct node *temp = head;

    while (temp != NULL)
    {
        if (temp->expo == 0)
            printf("(%.1f)", temp->coeff);
        else
            printf("(%.1fX^%d)", temp->coeff, temp->expo);

        if (temp->link != NULL)
            printf(" + ");
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    struct node *head1 = NULL;
    head1 = create(head1);

    printf("\nFirst Polynomial P1 = ");
    print(head1);

    struct node *head2 = NULL;
    head2 = create(head2);

    printf("\nSecond Polynomial P2 = ");
    print(head2);

    struct node *add_eqn = add(head1, head2);

    printf("\nP1 + P2 = ");
    print(add_eqn);

    return 0;
}
