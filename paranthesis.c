#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
	char info;
	struct nodetype *next;
}stack;

typedef enum{false, true}boolean;

void createstack(stack **ps);
boolean isempty(stack *ps);
void push(stack **ps, char value);
char pop(stack **ps);
void disposestack(stack **ps);
void paranthesischecker(char *exp);
char getmatchingsymbol(char ch);

void main()
{
	char string[6];
	char *charexpression = "";
	printf("Enter any expression: ");
	scanf("%s", &string);
	charexpression = string;
	paranthesischecker(charexpression);
}

void paranthesischecker(char *exp)
{
	 char ch;
	 stack *top;
	 createstack(&top);
	 while(*exp)
	 {
	 	if(*exp == '(' || *exp == '{' || *exp == '[')
	 	{
	 		push(&top, *exp);
	 	}
	 	else if(*exp == ')' || *exp == '}' || *exp == ']')
	 	{
	 		if(isempty(top))
	 		{
		 		printf("Error: no matching open symbol\n");
		 		disposestack(&top);
		 		return;
	 		}
			else
			{
				ch = pop(&top);
				if(ch != getmatchingsymbol(*exp))
				{
					printf("Error: Incorrect nesting of symbol\n");
					disposestack(&top);
					return;
				}
			}
		}
	 	exp++;
	 }
	 if(isempty(top) == false)
	 {
	 	printf("Error: missing closing symbol(s)\n ");
	 	disposestack(&top);
	 	return;
	 }
	 else
	 {
	 	printf("Expression is Ok");
	 }
	 
}

char getmatchingsymbol(char ch)
{
	char matchingchar;
	switch(ch)
	{
		case '(':
			matchingchar = ')';
			break;
		case ')':
			matchingchar = '(';
			break;
		case '{':
			matchingchar = '}';
			break;
		case '}':
			matchingchar = '{';
			break;
		case '[':
			matchingchar = ']';
			break;
		case ']':
			matchingchar = '[';
			break;
	}
	return matchingchar;
}

void createstack(stack **top)
{
	*top = NULL;
}

boolean isempty(stack *top)
{
	if(top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push(stack **top, char value)
{
	stack *ptr;
	ptr = (stack *)malloc(sizeof(stack));
	if(ptr == NULL)
	{
		printf("Unable to allocate to memory for new node..");
		return;
	}
	ptr->info = value;
	ptr->next = *top;
	*top = ptr;
}

char pop(stack **top)
{
	char temp; stack *ptr;
	ptr = *top;
	*top = (*top)->next;
	temp = ptr->info;
	free(ptr);
	return temp;
}

void disposestack(stack **top)
{
	stack *ptr;
	while(*top != NULL)
	{
		ptr = *top;
		*top = (*top)->next;
		free(ptr);
	}
}