#include<stdio.h>
#include<stdlib.h>

int a[10], pos, elem;
int n = 0;
void create();
void display();
void insert();
void search();
void sort();
void del();
void main()

{
            int choice;
            while(1)
            {
             printf("\n\n-----------MENU------------");
             printf("\n 1. Create an array of N integers");
             printf("\n 2. Display of array elements");
             printf("\n 3. Insert element at a given position");
             printf("\n 4. Search the array for the given element");
             printf("\n 5. Sort the array");
             printf("\n 6. Delete an element at a given position");
             printf("\n 7. Exit");
             printf("\nEnter your choice: ");

           scanf("%d", &choice);

           switch(choice)
           {
             case 1: create();
                  break;
            case 2: display();
                  break;
           case 3: insert();
                  break;
           case 4: search();
                  break;
           case 5: sort();
                  break;
           case 6:del();
                  break;
           case 7:exit(1);
                  break;
        default:printf("\nPlease enter a valid choice:");
                        }
            }
}
void create()
{
            int i;
            printf("\nEnter the number of elements: ");
            scanf("%d", &n);
            printf("\nEnter the elements: ");
            for(i=0; i<n; i++)
            {
                        scanf("%d", &a[i]);
            }
}
void display()
{
            int i;
            if(n == 0)
            {
                        printf("\nNo elements to display");
                        return;
            }
            printf("\nArray elements are: ");
            for(i=0; i<n;i++)
                        printf("%d\t ", a[i]);
}
void insert()
{
            int i;
            
printf("\nEnter a valid position where element to be inserted:    ");
scanf("%d", &pos);
            if(n > pos){
            printf("\nEnter the value to be inserted:   ");
            scanf("%d", &elem);
            for(i=n-1; i>=pos ; i--)
            {
                        a[i+1] = a[i];
            }
            a[pos] = elem;
            n = n+1;
            }
            else{printf("\nArray is full. Insertion is not possible");}
            
            display();
}
void search()
{
    int i,s=0;
    printf("Enter element to search\n");
    scanf("%d",&elem);
    
    for(i=0;i<n;i++){
        if(a[i]==elem){
            printf ("%d is the required position",(i+1));
            s=s+1;
            break;
        }
        }
        if(s!=1){printf("Element not found");}
    }

void sort()
{
    int i,j,temp;
  for(i=0;i<n;i++)
  {
      for(j=0;j<n-i-1;j++)
      {
          if(a[j]>a[j+1])
          {
             temp=a[j];
             a[j]=a[j+1];
             a[j+1]=temp;
          }
      }
  }
printf("After Bubble sort Elements are : ");
display();     
}
void del()
{
            int i;
            if(n == 0)
            {
                        printf("\nArray is empty and no elements to delete");
                        return;
            }
            do
            {
                        printf("\nEnter a valid position from where element to be deleted:    ");
                        scanf("%d", &pos);
            }while(pos>=n);
            elem = a[pos];
            printf("\nDeleted element is : %d \n", elem);
            for( i = pos; i< n-1; i++)
            {
                        a[i] = a[i+1];
            }
            n = n-1;
            display();
}