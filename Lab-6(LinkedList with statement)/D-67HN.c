#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[50];
    int enroll_no;
    float cgpa;
    struct node *next;
}*head;

typedef struct node Node;
Node *fir, *ptr, *tem;

void main()
{
    int choice, n, pos;
    void create(int num);
    void display();
    void insert();
    void update(int n);
    void delete();

    head = (Node*)malloc(sizeof(Node));
    head->enroll_no = 0;
    head->next = NULL;


    while(1)
    {
        printf("\n\n1.Create Linked list \n2.Display list \n3.Display no. of studens having cgpa > 7.0 \n4.Insert \n5.Update a node \n6.Delete node \n7.Exit\n\nChoice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the number of nodes you want to create: ");
            scanf("%d",&n);
            create(n);
            break;

        case 2:
            display();
            break;

        case 3:
            printf("\n%d students have CGPA greater than 7.0",head->enroll_no);
            break;

        case 4:
            insert();
            break;

        case 5:
            printf("\nEnter the position of node to be updated: ");
            scanf("%d",&pos);
            update(pos);
            break;

        case 6:
            delete();
            break;

        case 7:
            exit(0);
            break;
        }
    }
}

void create(int num)
{
    int e_no;
    float c;
    char n[20];
    fir = NULL;

    for (int i = 1; i <= num; i++)
    {
        printf("\nEnter Name of student: ");
        scanf("%s",n);
        printf("Enter enrollment no: ");
        scanf("%d",&e_no);
        printf("Enter CGPA: ");
        scanf("%f",&c);

        // Incrementing the enroll of head node i.e. count if the cgpa is greater than 7.0
        if(c > 7.0)
        {
            head->enroll_no += 1;
        }

        tem = (Node*)malloc(sizeof(Node));
        
        strcpy(tem->name,n);
        tem->enroll_no = e_no;
        tem->cgpa = c;

        tem->next=NULL;

      
        if (fir == NULL)
        {
            fir = tem;
     
            head->next = fir;
        }

        else
        {
            ptr = fir;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next=tem;
        }
    }
    printf("\nLinked list is created");
}

void display()
{
    ptr = fir;
    printf("\nData is as followed: ");
    while (ptr != NULL) {
        printf("\n\nName: %s",ptr->name);
        printf("\nEnrollment no: %d",ptr->enroll_no);
        printf("\nCGPA: %f",ptr->cgpa);
        ptr = ptr->next;
    }
}

void insert()
{
    ptr = fir;
    int e_no;
    float c;
    char n[20];
    
    while (ptr->next != NULL)
    {
        ptr = ptr->next;    
    }
    tem = (Node*)malloc(sizeof(Node));
    printf("\nEnter Name of student: ");
    scanf("%s",n);
    printf("Enter enrollment no: ");
    scanf("%d",&e_no);
    printf("Enter CGPA: ");
    scanf("%f",&c);

    // If cgpa is greater than 7.0 then increment value in the enroll of head
    if(c > 7.0)
    {
        head->enroll_no += 1;
    }
    strcpy(tem->name,n);
    tem->enroll_no = e_no;
    tem->cgpa = c;

    ptr->next = tem;
    tem->next = NULL;
}

void update(int n)
{
    ptr = fir;
    float new_cgpa, old_cgpa;

    if(n != 1)
    {
        // Moving to the specified position
        while (n != 1)
        {
            ptr = ptr->next;
            n--;
        }
    }

    printf("\nEnter the new CGPA of %s: ",ptr->name);
    scanf("%f",&new_cgpa);

    old_cgpa = ptr->cgpa;

    if (old_cgpa < 7.0 && new_cgpa > 7.0){
        head->enroll_no += 1;
    }
    else if (old_cgpa > 7.0 && new_cgpa < 7.0){
        head->enroll_no -= 1;
    }
    ptr->cgpa = new_cgpa;
    printf("\nCGPA updated successfully");
}


void delete()
{
    ptr = fir;

    if (ptr == NULL)
    {
        printf("\nNo node present in the list to delete");
    }
    // If single node is present in the list
    else if(ptr->next == NULL)
    {
        if(ptr->cgpa > 7.0){
            head->enroll_no -= 1;
        }  
        free(ptr);
        fir = NULL;
        head->next = NULL;
        printf("\nNode deleted successfully");
    }

    else
    {
        while (ptr->next != NULL){
            tem = ptr;
            ptr = ptr->next;
        }
        if(ptr->cgpa > 7.0){
            head->enroll_no -= 1;
        }    
        tem->next = NULL;
        free(ptr);
        printf("\nNode deleted successfully");
    }
}