#include <stdio.h>
#include <stdlib.h>


struct dnode
{
	struct dnode *prev;
	int data;
	struct dnode *next;
};

void d_append(struct dnode **, int);
void d_display(struct dnode *);
int d_count(struct dnode * q);
void d_addatbeg(struct dnode **s, int num);
void d_addafter(struct dnode *s, int loc, int num);
void d_delete(struct dnode **s, int num);

void main()
{
	struct dnode *p;
	int choice, item, loc;
	while(1)
	{
		printf("Operations:\n");
		printf("\t1)Traversal\n\t2)Append\n\t3)Count\n\t4)Add element at begining\n\t5)Add element next to\n\t6)Delete element\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("List: ");
				d_display(p);
				printf("\n");
				break;
			case 2:
				printf("Enter the element to insert: ");
				scanf("%d", &item);
				printf("Old list: ");
				d_display(p);
				d_append(&p, item);
				printf("New list: ");
				d_display(p);
				break;
			case 3:
				printf("The number of elements in the list are: %d\n", d_count(p));
				break;
			case 4:
				printf("Enter the element: ");
				scanf("%d", &item);
				printf("Old list: ");
				d_display(p);
				d_addatbeg(&p, item);
				printf("New list: ");
				d_display(p);
				break;
			case 5:
				printf("Enter the element: ");
				scanf("%d", &item);
				printf("Enter the location: ");
				scanf("%d", &loc);
				printf("Old list: ");
				d_display(p);
				d_addafter(p, loc, item);
				printf("New list: ");
				d_display(p);
				break;
			case 6:
				printf("Enter the element to delete: ");
				scanf("%d", &item);
				printf("List before: ");
				d_display(p);
				d_delete(&p, item);
				printf("List after");
				d_display(p);
				break;
			default:
				printf("Invalid argument\n");


		}
	}
}

void d_append(struct dnode **s, int num)
{
	struct dnode *r, *q = *s;
	if(*s == NULL)
	{
		*s = malloc(sizeof(struct dnode));
		(*s)->prev = NULL;
		(*s)->data = num;
		(*s)->next = NULL;
	}
	else
	{
		while(q->next != NULL)
			q = q->next;
		r = malloc(sizeof(struct dnode));
		r->data = num;
		r->next = NULL;
		r->prev = q;
		q->next = r;
	}
}

int d_count(struct dnode * q)
{
	int c = 0;
	while(q != NULL)
	{
		q = q->next;
		c++;
	}
	return c;
}

void d_display(struct dnode *q)
{
	printf("\n");
	while(q != NULL)
	{
		printf("%2d\t", q->data);
		q = q->next;
	}
}

void d_addatbeg(struct dnode **s, int num)
{
	struct dnode *q;
	q = malloc(sizeof(struct dnode));
	q->prev = NULL;
	q->data = num;
	q->next = *s;
	(*s)->prev = q;
	*s = q;
}

void d_addafter(struct dnode *s, int loc, int num)
{
	struct dnode *temp , *q;
	int i;
	q = s;
	for(i = 0; i < loc- 1; i++)
	{
		q = q->next;
		if(q == NULL)
		{
			printf("\nThere are less than %d elements", loc);
			return;
		}
	}
	temp = malloc(sizeof(struct dnode));
	temp->data = num;
	temp->prev = q;
	temp->next = q->next;
	temp->next->prev = temp;
	q->next = temp;
}

void d_delete(struct dnode **s, int num)
{
	struct dnode *q = *s;
	while(q != NULL)
	{
		if(q->data == num)
		{
			if(q == *s)
			{
				*s =(*s)->next;
				(*s)->prev = NULL;
			}
			else
			{
				if(q->next == NULL)
					q->prev->next = NULL;
				else
				{
					q->prev->next = q->next;
					q->next->prev = q->prev;
				}
				free(q);
			}
			return;
		}
		q = q->next;
	}
	printf("\n%d not found.", num);
}