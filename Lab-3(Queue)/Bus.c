#include <stdio.h>
#include <stdlib.h>
        void display();
    void eFront(int x);
    int dFront();
    int dRear();
    int Empty();
    int Full();
    int size;
	int front;
    int rear;
    int* Q;
 
void eFront(int x) {
    if (front == -1){
        printf("Seats Full\n");
    } else {
        Q[front] = x;
        front--;
    }
}
int Empty() {
    if (front == rear){
        return 1;
    }
    return 0;
}
int Full() {
    if (rear == size - 1){
        return 1;
    }
    return 0;
}
int dFront() {
    int x = -1;
    if (Empty()){
        printf("Seats empty\n");
    } else {
        x = Q[front];
        front++;
    }
    return x;
}
 
int dRear() {
    int x = -1;
    if (rear == -1){
        printf("Seats empty\n");
    } else {
        x = Q[rear];
        rear--;
    }
    return x;
}

void display() {
    for (int i=front+1; i<=rear; i++) {
        printf("%d ",Q[i]);
        if (i < rear){
            printf(" <- ");
        }
    }
    printf("\n");
}

int main()
{
 size=30;
 while(1){
 printf("1. Insert element \n");
 printf("2. Exit from Right\n");
 printf("3. Exit from Left\n");
 printf("4. Want to Display\n");
 printf("5. Exit\n");
 int a;
 printf("Enter your choice : ");
 scanf("%d",&a);
 int b;
 switch(a){	  
	case 1: 
	      
	      printf("Enter the element to enter : ");
	      scanf("%d",&b);
	      eFront(b);
 	      break;
 	case 2: 
	      dRear();
	       display();
	      break;
	case 3:
		  dFront();
		  display();
		  break;
	case 4:
	       	display();
			break;  
	case 5:
	      exit(1);
		  break;	  	
 }
}
 return 0;
}
