#include <stdio.h>
#include <stdlib.h>

struct node  
{
	int info;
	struct node *link;
};


void push(struct node **, int);
int pop(struct node **);
void display(struct node **);

int main()
{
	struct node *top = NULL;
	int choice, item;
	do
	{
		printf("\n1. PUSH ");
		printf("\n2. POP ");
		printf("\n3. TRAVERSE ");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter the value: ");
				scanf("%d", &item);
				push(&top, item);
				break;
			case 2:
				item = pop(&top);
				if(item != -1)
				printf("The deleted element is %d\n", item);
				break;
			case 3:
				display(&top);
				break;
			default: printf("\nYou Entered Wrong Choice\n");
		}
		while(getchar() != '\n');
		printf("Do You Wish To Continue (Y/N): ");
		scanf("%c",&choice);

	}while(choice=='Y' || choice=='y');
}


void push(struct node **top, int item)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));

	if(temp == NULL) //if memory is not available
	{
		printf("Stack is full\n");
		return;
	}
	temp->info = item;
	temp->link = *top;
	*top = temp;
}

int pop(struct node **top)
{
	struct node *temp;
	int item;
	if(*top == NULL)
	{
		printf("Stack is empty\n");
		return -1;
	}

	temp = *top;
	item = temp->info;
	*top = (*top)->link;
	free(temp);
	return item;
}

void display(struct node **top)
{
	struct node *ptr;
	if(top == NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		ptr = *top;
		while(ptr != NULL)
		{
			printf("%d\t", ptr->info);
			ptr = ptr->link;
		}
	}
	printf("\n");
}
