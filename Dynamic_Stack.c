#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int ele;
	struct Node *next;
};

struct Node *TOP;

void push_op()
{
	struct Node *nn;

	nn = (struct Node*) malloc(sizeof(struct Node));
	printf("Enter element to PUSH : ");
	scanf("%d", &nn->ele);
	if(TOP==NULL)
	{
		nn->next = NULL;
		TOP = nn;
	}
	else
	{
		nn->next = TOP;
		TOP = nn;
	}
	printf("Element PUSHed into the Stack\n");
} //end of push_op()

void pop_op()
{
	int val;
	if(TOP == NULL)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		val = TOP->ele;
		TOP = TOP->next;
		printf("TOP Element %d is POPped from Stack\n", val);
	}
}//end of pop_op()

void display_op()
{
	struct Node *temp;
	if(TOP==NULL)
	{
		printf("Stack is Empty. Nothing to Display\n");
	}
	else
	{
		printf("Stack Contains\n");
		temp = TOP;
		while(temp!=NULL)
		{
			printf("%d\n", temp->ele);
			temp = temp->next;
		}
	}
}// end of display_op()

int main()
{
	int uchoice;
	TOP = NULL;

	do
	{
		printf("\nSelect an operation\n");
		printf("1 - PUSH operation\n");
		printf("2 - POP operation\n");
		printf("3 - DISPLAY operation\n");
		printf("4 - EXIT\n");
		printf("Provide your choice : ");
		scanf("%d", &uchoice);

		switch(uchoice)
		{
			case 1: push_op();
				break;
			case 2: pop_op();
				break;
			case 3: display_op();
				break;
			case 4: exit(0);
		} // end of switch-case
	}while(1);
	return 0;
}