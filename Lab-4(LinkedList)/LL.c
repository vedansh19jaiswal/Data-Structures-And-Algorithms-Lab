#include <stdio.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL, *ptr, *t;

void count()
{
    struct node *ptr;
    int cnt = 0;
    ptr = first;
    while (ptr != NULL)
    {
        cnt++;
        ptr = ptr->next;
    }
    printf("\nNo Of Nodes Are %d", cnt);
}

void create(int data)

{
    struct node *ptr, *d;
    d = (struct node *)malloc(sizeof(struct node));
    d->data = data;
    d->next = NULL;
    if (first == NULL)
    {
        first = d;
    }
    else
    {
        ptr = first;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = d;
    }
}
void Display()
{
    struct node *ptr;
    if (first == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        ptr = first;
        while (ptr != NULL)
        {
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }
        
    }
}
void Searching(int data)
{
    struct node *ptr, *d;
    ptr = first;
    while (ptr != NULL)
    {
        if (ptr->data == data)
        {
            printf("\nElement Is Found");
            break;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    if (ptr == NULL)
    {
        printf("\nElement is Not Found");
    }
}
void InsertingAtBeginning()
{
    int num;
    t = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &num);
    t->data = num;

    if (first == NULL) 
    {
        t->next = NULL;
        first = t;
    }
    else
    {
        t->next = first;
        first = t;
    }
}

void InsertingAtEnd()
{
    int num;
    t = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &num);
    t->data = num;
    t->next = NULL;

    if (first == NULL) 
    {
        first = t;
    }
    else
    {
        ptr = first;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = t;
    }
}

int InsertingAtPOS()
{
    int pos, i, num;
    if (first == NULL)
    {
        printf("List is empty!!");
        return 0;
    }

    t = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &num);
    printf("Enter position to Inserting:");
    scanf("%d", &pos);
    t->data = num;

    ptr = first;
    for (i = 1; i < pos - 1; i++)
    {
        if (ptr->next == NULL)
        {
            printf("There are less elements!!");
            return 0;
        }

        ptr = ptr->next;
    }

    t->next = ptr->next;
    ptr->next = t;
    return 0;
}
void DeleteAtBeginning()
{
    if (first == NULL)
    {
        printf("The list is empty!!");
    }
    else
    {
        ptr = first;
        first = first->next;
        printf("Deleted element is %d", ptr->data);
        free(ptr);
    }
}

void DeleteATEnd()
{
    if (first == NULL)
    {
        printf("The list is empty!!");
    }
    else
    {
        ptr = first;
        while (ptr->next->next != NULL)
            ptr = ptr->next;

        t = ptr->next;
        ptr->next = NULL;
        printf("Deleted element is %d", t->data);
        free(t);
    }
}

int DeletePOS()
{
    int pos, i;

    if (first == NULL)
    {
        printf("List is empty!!");
        return 0;
    }

    printf("Enter position to delete:");
    scanf("%d", &pos);

    ptr = first;
    for (i = 1; i < pos - 1; i++)
    {
        if (ptr->next == NULL)
        {
            printf("There are less elements!!");
            return 0;
        }
        ptr = ptr->next;
    }

    t = ptr->next;
    ptr->next = t->next;
    printf("Deleted element is %d", t->data);
    free(t);

    return 0;
}
void ReverseL()
{
    struct node *previousNode, *currentNode;
    if(first != NULL)
    {  previousNode = first;
        currentNode = first->next;
        first = first->next;

        previousNode->next = NULL; 

        while(first != NULL)  {
            first = first->next;
            currentNode->next = previousNode;

            previousNode = currentNode;
            currentNode = first;
        }  first = previousNode; 

        printf("List is reversed\n");
    }
}
void main()
{
    int p, n, i, r, a, pos;
    first = NULL;
    do
    {
        printf("1.Create\n");
        printf("2.Display\n");
        printf("3.Length\n");
        printf("4.Search \n");
        printf("5.From where to insert\n");
        printf("6.Delete\n");
        printf("7.Reverse\n");
        printf("8.EXIT\n");
        printf("Enter your choice\n");
        scanf("%d", &p);
        switch (p)
        {
        case 1:
            printf("How many nodes to create ?\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("\nEnter Data\n");
                scanf("%d", &r);
                create(r);
            }
            break;
        case 3:
            count();
            break;
        case 2:
            Display();
            break;
        case 4:
            printf("\nEnter element to search\n");
            scanf("%d", &r);
            Searching(r);
            break;
        case 5:
            
            printf("\n1.Inserting at beginning\n2.Inserting at end\n3.Inserting at specified position\n4.Exit");
            printf("\n\nEnter your choice : ");
            scanf("%d", &p);

            switch (p)
            {
            case 1:
                InsertingAtBeginning();
                break;
            case 2:
                InsertingAtEnd();
                break;
            case 3:
                InsertingAtPOS();
                break;
            case 4:
                exit(0);
            
            }
            break;
        case 6:
            
            printf("\n1.Delete from beginning\n2.Delete from end\n3.Delete from specified position\n4.Exit");
            printf("\nEnter your choice :");
            scanf("%d", &p);

            switch (p)
            {
            case 1:
                DeleteAtBeginning();
                break;
            case 2:
                DeleteATEnd();
                break;
            case 3:
                DeletePOS();
                break;
            case 4:
                exit(0); 
                }
                break;
            case 7:
            ReverseL();
            break;
            case 8:
            exit(0);
        }
    } while (p != 9);
   
}
