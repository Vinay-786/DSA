#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void addcirq(struct node **, struct node **, int);
int delcirq(struct node **, struct node **);
void cirq_display(struct node *);

void main()
{
	struct node *front, *rear;
	front = rear = NULL;

	addcirq(&front, &rear, 10);
	addcirq(&front, &rear, 44);
	addcirq(&front, &rear, 17);
	addcirq(&front, &rear, 364);
	addcirq(&front, &rear, 123);
	addcirq(&front, &rear, 23);

	printf("\nBefore deletion:\n");
	cirq_display(front);

	delcirq(&front, &rear);
	delcirq(&front, &rear);
	delcirq(&front, &rear);
	delcirq(&front, &rear);

	printf("\nAfter deletion:\n");
	cirq_display(front);
	addcirq(&front, &rear, 80);

	printf("\nAfter Insertion:\n");
	cirq_display(front);
	addcirq(&front, &rear, 80);
	printf("\nAfter Insertion:\n");
	cirq_display(front);
}

void addcirq(struct node **f, struct node **r, int item)
{
	struct node *q;

	//new node
	q = malloc(sizeof(struct node));
	q->data = item;

	//if the queue is empty
	if(*f == NULL)
		*f=q;
	else
		(*r)->next = q;
	*r = q;
	(*r)->next = *f;
}

int delcirq(struct node **f, struct node **r)
{
	struct node *q;
	int item;
	
	//if queue is empty
	if(*f == NULL)
		printf("queue is empty");
	else
	{
		if(*f == *r)
		{
			item = (*f)->data;
			free(*f);
			*f=NULL;
			*r=NULL;
		}
		else
		{
		//delete the node
			q = *f;
			item = q->data;
			*f=(*f)->next;
			(*r)->next = *f;
			free(q);
		}
		return(item);
	}
	return -1;
}

//display whole of the queue
void cirq_display(struct node *f)
{
	struct node *q = f, *p = NULL;

	while(q != p)
	{
		printf("%d\t", q->data);
		q = q->next;
		p = f;
	}
}
