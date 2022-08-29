#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

void push();
int pop();
void traverse();
void clear_stdin(void);
int stack[MAXSIZE];
int Top = -1;


int main()
{
	int choice; char ch;
	do
	{
		printf("\n1. PUSH ");
		printf("\n2. POP ");
		printf("\n3. TRAVERSE ");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:push();
			break;
			case 2: printf("\nThe deleted element is %d\n",pop());
			break;
			case 3:traverse();
			break;
			default: printf("\nYou Entered Wrong Choice\n");
		}
		while(getchar() != '\n');
		printf("Do You Wish To Continue (Y/N): ");
		scanf("%c",&ch);

	}while(ch=='Y' || ch=='y');
}

void push()
{
	int item;
	if(Top == MAXSIZE - 1)
	{
		printf("\nThe Stack Is OVERFLOW");
		exit(0);
	}
	else
	{
		printf("Enter the element to be inserted: ");
		scanf("%d",&item);
		Top= Top+1;
		stack[Top] = item;
	}
}

int pop()
{
	int item;
	if(Top == -1)
	{
		printf("The stack is Empty");
		exit(0);
	}
	else
	{
		item = stack[Top];
		Top = Top-1;
	}
	return(item);
}

void traverse()
{
	int i;
	if(Top == -1)
	{
		printf("The Stack is Empty");
		exit(0);
	}
	else
	{
		for(i=Top;i>=0;i--)
		{
			printf("\n%d",stack[i]);
		}
		printf("\n");
	}
}


