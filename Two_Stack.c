#include<stdio.h>
#include<stdlib.h>


int stack[20];
int PTOP = 9;
int STOP = 10;

void display_primary_stack()
{
	int i;
	if(PTOP==9)
	{
		printf("\tPrimary Stack is empty. Nothing to Display\n");
	}
	else
	{
		printf("\tPrimary stack contains\n");
		for(i=PTOP; i>=10; i--)
		{
			printf("\t%d\n", stack[i]);
		}
	}
} // end of display_primary_stack()

void display_secondary_stack()
{
	int i;
	if(STOP == 10)
	{
		printf("\tSecondary Stack is empty. Nothing to Display\n");
	}
	else
	{
		printf("\tSecondary Stack contains\n");
		for(i=9; i>=STOP; i--)
		{
			printf("\t%d\n", stack[i]);
		}
	}
} // end of display_secondary_stack()

void discard_element()
{
	int ele;
	ele = stack[STOP];
	printf("\t\tElement %d is POPped and Discarded from Secondary Stack\n", ele);
	STOP++;
} // end of discard_element()

void restore_element()
{
	int ele;
	ele = stack[STOP];
	stack[PTOP+1] = ele;
	PTOP++;
	STOP++;
	printf("\t\tElement %d is POPed from Secondary Stack and Restored in Primary Stack\n", ele);
} //end of restore_element()

void pop_from_primary_stack()
{
	int ele;
	ele = stack[PTOP];
	stack[STOP-1] = ele;
	printf("\t\tElement %d is POPped from Primary stack and PUSHed into Secondary stack\n", ele);
	PTOP--;
	STOP--;
} // end of pop_from_primary_stack()

void pop_from_secondary_stack()
{
	char uch;
	fflush(stdin);
	printf("What to do with POPped element\n");
	printf("\t\tD - Discard\n");
	printf("\t\tR - Restore\n\t\t");
	scanf("%c", &uch);

	switch(uch)
	{
		case 'D' : discard_element();
			break;
		case 'R' : restore_element();
			break;
	}
} //end of pop_from_secondary_stack()

void push_op()
{
	int ele;
	if(PTOP == 19)
	{
		printf("Primary Stack Overflow\n");
	}
	else
	{
		printf("Enter element to PUSH into primary stack : ");
		scanf("%d", &ele);
		stack[PTOP+1] = ele;
		PTOP++;
		printf("Element pushed into Primary Stack\n");
	}
}// end of push_op()

void pop_op()
{
	char uch;
	fflush(stdin);
	printf("\tFrom which Stack you want to POP element\n");
	printf("\tP - Primary Stack\n");
	printf("\tS - Secondary Stack\n\t");
	scanf("%c", &uch);
	switch(uch)
	{
		case 'P' : pop_from_primary_stack();
			break;
		case 'S' : pop_from_secondary_stack();
			break;
	}
} // end of pop_op()

void display_op()
{
	char uch;
	fflush(stdin);
	printf("\tWhich stack you want to Display\n");
	printf("\tP - Primary Stack\n");
	printf("\tS - Secondary Stack\n");
	printf("\tProvide your choice : " );
	scanf("%c", &uch);

	switch(uch)
	{
		case 'P' : display_primary_stack();
			break;
		case 'S' : display_secondary_stack();
			break;
	}
} // end of display_op()

int main()
{
	int uch;

	do
	{
		printf("\nSelect an operation\n");
		printf("1 - PUSH\n");
		printf("2 - POP\n");
		printf("3 - DISPLAY\n");
		printf("4 - EXIT\n");
		printf("Provide your choice : ");
		scanf("%d", &uch);

		switch(uch)
		{
			case 1: push_op();
				break;
			case 2 :pop_op();
				break;
			case 3: display_op();
				break;
			case 4: exit(0);
		}
	}while(1);
}