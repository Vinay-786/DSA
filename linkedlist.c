#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void display(struct node *q);
int count(struct node *q);
void append(struct node **q, int num);
void addatbeg(struct node **q, int num);
void addafter(struct node *q, int loc, int num);
void add(struct node **q, int num);
void delete(struct node **q, int num);
void move_to_end(struct node **q);
void reverse(struct node **q);
struct node* erase(struct node *q);

void main()
{
	struct node *p;
	int num, i, ch, loc;
	p=NULL;
	do
	{
		printf("\n\t\t---------------- M E N U ----------------\n");
		printf("\n\n\t\t 1 - ADD WHEN THE LIST IS EMPTY OR AT THE END ");
		printf("\n\n\t\t 2 - ADD AT THE BEGINNING");
		printf("\n\n\t\t 3 - ADD AFTER THE SPECIFIED NUMBER OF NODES");
		printf("\n\n\t\t 4 - ADDITION IN ASCENDING ORDER");
		printf("\n\n\t\t 5 - DELETION FROM LINKED LIST");
		printf("\n\n\t\t 6 - MOVING 1st NODE OF A LIST AT THE END OF LIST");
		printf("\n\n\t\t 7 - REVERSE OF A LINKED LIST");
		printf("\n\n\t\t 8 - ERASING THE LIST");
		printf("\n\n\t\t 9 - EXIT");
		printf("\n\n\n\tENTER YOUR CHOICE(1-9) : \nFirst time u must have to choose 1:-");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the number which u want 2 insert in the list:-\n");
				scanf("%d",&num);
				append(&p,num);
				printf("\nList after inserting the element:-\n");
				display(p);
				printf("\nNumber of elements in the list are:- %d\n",count(p));
				break;
			case 2:
				printf("\nEnter the number which u want 2 insert in the list at the beginning:-\n");
				scanf("%d",&num);
				addatbeg(&p,num);
				printf("\nList after inserting the element:-\n");
				display(p);
				printf("\nNumber of elements in the list are:- %d\n",count(p));
				break;
			case 3:
				printf("\nEnter the number and location:-\n");
				scanf("%d%d",&num,&loc);
				addafter(p,loc,num);
				printf("\nList after inserting the element after the specified location:-\n");
				display(p);
				printf("\nNumber of elements in the list are:- %d\n",count(p));
				break;
			case 4:
				printf("\nEnter the number :-\n");
				scanf("%d",&num);
				add(&p,num);
				printf("\nList after inserting the element in ascending order:-\n");
				display(p);
				printf("\nNumber of elements in the list are:- %d\n",count(p));
				break;
			case 5:
				printf("\nList Before Deletion:-\n");
				display(p);
				printf("\nNumber of elements in the list are:- %d\n",count(p));
				printf("\nEnter the number u want 2 delete from the list:-\n");
				scanf("%d",&num);
				delete(&p,num);
				printf("\nList after deleting the element:-\n");
				display(p);
				printf("\nNumber of elements in the list are:- %d\n",count(p));
				break;
			case 6:
				printf("\nList before moving 1st element to the end:-\n");
				display(p);
				printf("\nNumber of elements in the list are:- %d\n",count(p));
				move_to_end(&p);
				printf("\nList after moving the 1st element at the end:-\n");
				display(p);
				printf("\nNumber of elements in the list are:- %d\n",count(p));
				break;
			case 7:
				printf("\nList before Reversing:-\n");
				display(p);
				printf("\nNumber of elements in the list are:- %d\n",count(p));
				reverse(&p);
				printf("\nList after moving the 1st element at the end:-\n");
				display(p);
				printf("\nNumber of elements in the list are:- %d\n",count(p));
				break;
			case 8:
				printf("\nList before erasing the list:\n");
				display(p);
				printf("\nNumber of elements in the list are: %d\n", count(p));
				p = erase(p);
				printf("\nList after erasing the list:\n");
				display(p);
				break;
			case 9:
				return;
			default:
				printf("\nInvalid option\n");
		}
	}while(ch!=11);
}

void append(struct node **q, int num)
{
	struct node *temp, *r;
	if(*q == NULL)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data = num;
		temp->next = NULL;
		*q = temp;
	}
	else
	{
		temp=*q;
		while(temp->next != NULL)
		{
			temp=temp->next;
		}

		r = (struct node *)malloc(sizeof(struct node));
		r->data = num;
		r->next = NULL;
		temp->next = r;
	}


}

void addatbeg(struct node **q, int num)
{
	struct node *r;
	r = (struct node *)malloc(sizeof(struct node));
	r->data = num;
	r->next = *q;
	*q = r;
}

void addafter(struct node *q, int loc, int num)
{
	struct node *temp = q, *r;
	int i;

	for(i = 1; i < loc; i++)
	{
		if(temp==NULL)
		{
			printf("\nThere are less than %d elements.\n", loc);
			return;

		}
		temp = temp->next;
	}

	r = (struct node *)malloc(sizeof(struct node));
	r->data	= num;
	r->next = temp->next;
	temp->next = r;
}

void add(struct node **q, int num)
{
	struct node *temp, *r;
	temp = *q;

	r = (struct node *)malloc(sizeof(struct node));
	r->data = num;
	//at the begining of the list or empty list
	if(*q==NULL || (*q)->data > num)
	{
		*q = r;
		(*q)->next = temp;
	}

	else
	{
		while(temp != NULL)
		{
			//in between and at last

			if(temp->data <= num && (temp->next->data > num || temp->next == NULL))
			{
				r->next = temp->next;
				temp->next = r;
				return;
			}
		temp = temp->next;
		}
	}
}

void delete(struct node **q, int num)
{
	struct node *old, *temp = *q;

	while(temp != NULL)
	{
		if(temp->data == num)
		{
			if(temp == *q)
			{
				*q = temp->next;
			}
			else
			{
				old->next = temp->next;
			
			free(temp);
			return;
			}
		}
		else
		{
			old = temp;
			temp = temp->next;
		}
	}

	printf("\nElement %d is not found in the list\n", num);
}

void move_to_end(struct node **q)
{
	struct node *temp, *last;
	temp = last = *q;

	while(last->next != NULL)
	{
		last = last->next;
	}
	//now last point to the end of the list

	last->next = *q;
	*q = temp->next;
	temp->next = NULL;
}

void reverse(struct node **q)
{
	struct node *temp, *r, *s;
	temp = *q;
	r = NULL;

	while(temp != NULL)
	{
		s = r;
		r = temp;
		temp = temp->next;
		r->next = s;
	}
	*q = r;
}

struct node* erase(struct node *q)
{
	struct node *temp;
	while(q!=NULL)
	{
		temp = q->next;
		free(q);
		q = temp;
	}
	return NULL;
}


void display(struct node *q)
{
	struct node *temp = q;
	while(temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
}

int count(struct node *q)
{
	struct node *temp = q;
	int c = 0;

	while(temp != NULL)
	{
		c++;
		temp = temp->next;
	}

	return c;
}
