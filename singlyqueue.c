#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
}*front = NULL, *rear = NULL;

void insert();
void delet();
void display();
int item;

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
	printf("Enter ITEM: ");
	scanf("%d", &item);
	if(rear == NULL)
	{
		rear = (struct node *)malloc(sizeof(struct node));
		rear->info = item;
		rear->link = NULL;
		front = rear;
	}
	else
	{
		rear->link=(struct node *)malloc(sizeof(struct node));
		rear = rear->link;
		rear->info = item;
		rear->link = NULL;
	}
}

void delet()
{
	struct node *ptr;
	if(front == NULL)
		printf("Queue is empty\n");
	else
	{
		ptr = front;
		item = front->info;
		front = front->link;
		free(ptr);
		printf("Item Deleted: %d\n", item);
		if(front == NULL)
			rear = NULL; 
	}
}

void display()
{
	struct node *ptr = front;
	if(rear == NULL)
		printf("Queue is empty\n");
	else
	{
		while(ptr != NULL)
		{
			printf("%d\t", ptr->info);
			ptr = ptr->link;
		}
	}
}
