#include <stdio.h>
#include <stdlib.h>

struct polynode
{
	float coeff;
	int exp;
	struct polynode *next;
};

void poly_append(struct polynode **, float, int);
void display_poly(struct polynode*);
void ploy_add(struct polynode *, struct polynode *, struct polynode **);

void poly_append(struct polynode **q, float x, int y)
{
	struct polynode *temp;
	temp = *q;

	if(*q == NULL)
	{
		*q = (struct polynode *)malloc(sizeof(struct polynode));
		temp = *q;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = (struct polynode *)malloc(sizeof(struct polynode));
		temp = temp->next;
	}

	temp->coeff = x;
	temp->exp = y;
	temp->next = NULL;
}

void display_poly(struct polynode *q)
{
	while(q != NULL)
	{
		printf("%.1fx^%d: ", q->coeff, q->exp);
		q = q->next;
	}
	printf("\b\b\b");
}

void poly_add(struct polynode *x, struct polynode *y, struct polynode **s)
{
	struct polynode *z;

	if(x == NULL && y == NULL)
		return;

	while(x != NULL && y != NULL)
	{
		if(*s == NULL)
		{
			*s = (struct polynode *)malloc(sizeof(struct polynode));
			z = *s;
		}
		else
		{
			z->next = (struct polynode *)malloc(sizeof(struct polynode));
			z = z->next;
		}
		

		if(x->exp < y->exp)
		{
			z->coeff = y->coeff;
			z->exp = y->exp;
			y = y->next;
		}
		else
		{
			if(x->exp >y->exp)
			{
				z->coeff = x->coeff;
				z->exp = x->exp;
				x = x->next;
			}
			else
			{
				if(x->exp == y->exp)
				{
					z->coeff = x->coeff + y->coeff;
					z->exp = x->exp;

					x = x->next;
					y = y->next;
				}
			}
		}
	}

	while(x != NULL)
	{
		if(*s == NULL)
		{
			*s = (struct polynode *)malloc(sizeof(struct polynode));
			z = *s;
		}
		else
		{
			z->next = (struct polynode *)malloc(sizeof(struct polynode));
			z = z->next;
		}

		z->coeff = x->coeff;
		z->exp = x->exp;
		x = x->next;
	}

	while(y != NULL)
	{
		if(*s == NULL)
		{
			*s = (struct polynode *)malloc(sizeof(struct polynode));
			z = *s;
		}
		else
		{
			z->next = (struct polynode *)malloc(sizeof(struct polynode));
			z = z->next;
		}

		z->coeff = y->coeff;
		z->exp = y->exp;
		y = y->next;
	}

	z->next = NULL;
}


void main()
{
	struct polynode *first, *second, *total;
	int i = 0;

	first = second = total = NULL;

	poly_append(&first, 1.4, 5);
	poly_append(&first, 1.5, 4);
	poly_append(&first, 1.7, 2);
	poly_append(&first, 1.8, 1);
	poly_append(&first, 1.9, 0);

	display_poly(first);

	poly_append(&second, 1.5, 6);
	poly_append(&second, 3.2, 5);
	poly_append(&second, -2.4, 4);
	poly_append(&second, 4.5, 2);
	poly_append(&second, 6.4, 1);

	printf("\n\n");
	display_poly(second);

	printf("\n");
	while(i++ < 79)
		printf("-");
	printf("\n\n");

	poly_add(first, second, &total);
	display_poly(total);
}	

