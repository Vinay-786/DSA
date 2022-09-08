#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void insert();
void delet();
void display();
int queue[SIZE], rear=-1, front=-1, item;

void main()
{
	int ch;
	do
	{
		printf("Choose:\n\t1)Insert\n\t2)Delete\n\t3)Display\n\t4)Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				delet();
				break;
			case 3:
				display();
				break;
			case 4:
				return;
			default:
				printf("Invalid choice.Please try again..\n");
		}
	}while(1);
}

void insert()
{
	if((front ==0 && rear==SIZE-1) || (front==rear+1))
		printf("Queue is full\n");
	else{
		printf("Enter Item: ");
		scanf("%d", &item);
		if(rear==-1)
		{
			rear=0;
			front=0;
		}
		else if(rear==SIZE-1)
			rear=0;
		else
			rear++;

		queue[rear] = item;
		printf("Item inserted %d\n", item);
	}
}

void delet()
{
	if(front == -1)
		printf("Queue is empty\n");
	else
	{
		item = queue[front];
		if(front == rear)
		{
			front = -1;
			rear = -1;
		}
		else if(front == SIZE-1)
			front = 0;
		else
			front++;
		printf("Item deleted: %d\n", item);
	}
}

void display()
{
	int i;
	if((front == -1) || (front == rear+1))
		printf("Queue is empty\n");
	else
	{
		for(i = front; i<=rear; i++)
		{
			printf("%d\t", queue[i]);
		}
	}	
}