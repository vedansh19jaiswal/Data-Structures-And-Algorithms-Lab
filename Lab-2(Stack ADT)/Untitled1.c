#include<stdio.h>
#include<stdlib.h>
struct stackarr;
typedef struct stackarr * Stack;

struct stackarr
{
	int c;
	int Top;
	int *Array;
};

void MakeEmpty(Stack s)
{
	s->Top = -1;
}

Stack CreateStack(int MaxElements)
{
	Stack s;
	s = (struct stackarr*) malloc(sizeof(struct stackarr));
	s->Array = (int *)malloc(sizeof(int) * MaxElements);
	s->c = MaxElements;
	MakeEmpty(s);
	return s;
}

int isFull(Stack s)
{
	return s->Top == s->c - 1;
}

int isEmpty(Stack s)
{
	return s->Top == -1;
}

void Push(int x, Stack s)
{
	if(isFull(s))
		printf("Full Stack\n\n");
	else
		s->Array[++s->Top] = x;
}

void Pop(Stack s)
{
	if(isEmpty(s))
		printf("Empty Stack\n");
	else
		s->Top--;
}

int Top(Stack s)
{
	if(isEmpty(s))
		printf("Empty Stack\n");
	else
		return s->Array[s->Top];
}

int peep(Stack s)
{   
	if(isEmpty(s))
		printf("Empty Stack\n");
	else
		return s->Array[s->Top--];
}

void Display(Stack s)
{
	int i;
	if(isEmpty(s))
		printf("Empty Stack\n\n");
	else
	{
		printf("The Stack Elements are : ");
		for(i=s->Top; i >= 0; i--)
			printf("%d  ",s->Array[i]);
		printf("\n\n");
	}
}
void exits(Stack s)
{
	if(s != NULL)
	{
		free(s->Array);
		free(s);
	}
}


void main()
{
	int n, x, ch, i;
	Stack s;
	printf("Enter max no. of elements in the stack : ");
	scanf("%d", &n);
	s = CreateStack(n);
	do
	{
		printf("\n1. PusH\n 2. PoP\n 3.ToP \n 4. PeeP\n 5. DisplaY\n 6. ExiT\nEnter the choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element to be pushed : ");
				scanf("%d",&x);
				Push(x,s);
				break;

			case 2:
				Pop(s);
				break;

			case 3:
				printf("The Top element in the stack : %d\n", Top(s));
				break;

			case 4:
				printf("The  element in the stack : %d\n", peep(s));
				break;

			case 5:
				Display(s);
				break;
		}
	}while(ch<6);
	exits(s);
	return 0;
}
