#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int expo;
    struct Node *next;
};

void display(struct Node* first){
    if (first == NULL)
    {
        printf("No result\n");
    }
    else
    {
        struct Node* temp = first;
        while (first != NULL)
        {
            printf("(%dx^%d)", temp->coeff, temp->expo);
            temp = temp->next;

            if(temp != NULL){
                printf(" + ");
            }
            else{
                printf("\n");
            }
        }    
        
    }
}

struct Node *insert(struct Node *first, int coef, int exp)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;

    ptr->coeff = coef;
    ptr->expo = exp;
    ptr->next = NULL;

    if (first == NULL || exp > first->expo)
    {
        ptr->next = first;
        first = ptr;
    }
    else
    {
        temp = first;
        while (temp->next != NULL && temp->next->expo >= exp)
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
    return first;
}

struct Node *create(struct Node *first)
{
    int n;
    int coeff;
    int expo;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient for the term %d: ", i + 1);
        scanf("%d", &coeff);

        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &expo);

        first = insert(first, coeff, expo);
    }
    return first;
}

void polyAdd(struct Node *p1, struct Node *p2)
{
    struct Node *ptr1 = p1;
    struct Node *ptr2 = p2;
    struct Node *p3 = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            p3 = insert(p3, (ptr1->coeff + ptr2->coeff), ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            p3 = insert(p3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            p3 = insert(p3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL)
    {
        p3 = insert(p3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        p3 = insert(p3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }
    printf("Added polynomial is: ");
    display(p3);
}

int main()
{
    struct Node *p1 = NULL;
    struct Node *p2 = NULL;

    printf("Enter the first polynomial\n");
    p1 = create(p1);
    printf("Enter the second polynomial\n");
    p2 = create(p2);

    polyAdd(p1, p2);
    return 0;
}