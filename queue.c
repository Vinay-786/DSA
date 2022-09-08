#include <stdio.h>

#define MAX 50
void insert();
void delet();
void display();
int queue[MAX], rear=-1, front=-1, item;

void main()
{
	int ch;
	do{
		printf("Choose:\n\t1)Insert\n\t2)Delete\n\t3)Display\n\t4)Exit\n\nEnter your choice: ");
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
				printf("Invalid entry. Please try again\n");
		}
	}while(1);
}

void insert()
{
	if(rear == MAX-1)
		printf("Queue is full\n");
	else
	{
		printf("Enter item to be inserted: ");
		scanf("%d", &item);
		if(rear == -1 && front == -1)
		{
			rear = 0;
			front = 0;
		}
		else
			rear++;

	queue[rear] = item;
	printf("Item inserted: %d\n", item);
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
		else
		{
			front++;
		}
	printf("Item deleted: %d\n", item);
	}
}

void display()
{
	int i;
	if(front == -1)
		printf("Queue is empty\n");
	else
	{
		printf("\n\n");
		for(i = front; i<= rear; i++)
			printf("%d\t", queue[i]);
		printf("\n\n");
	}
}