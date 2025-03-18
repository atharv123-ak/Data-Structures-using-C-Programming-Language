#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *prev;
	int ele;
	struct Node *next;
};

struct Node *first, *last;

void insert_node()
{
	int ch, sel;
	struct Node *nn, *temp, *temp2;

	nn = (struct Node *) malloc(sizeof(struct Node));

	printf("Enter element for New Node : ");
	scanf("%d", &nn->ele);

	if(first==NULL && last==NULL)
	{
		// list is yet not created
		nn->next = NULL;
		nn->prev = NULL;
		first = nn;
		last = nn;
		printf("List Created\n");
	}
	else
	{
		printf("Where you want to Insert this New Node\n");
		printf("1 - At First Position\n");
		printf("2 - At Last Position\n");
		printf("3 - At Selected Position\n");
		printf("Provide your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: // inserting nn at first position
				nn->prev = NULL;
				nn->next = first;
				first->prev = nn;
				first = nn;
				printf("NN inserted at First Position\n");
				break;
			case 2: // inserting nn at last position
				nn->next = NULL;
				nn->prev = last;
				last->next = nn;
				last = nn;
				printf("NN inserted at Last Position\n");
				break;
			case 3: // inesrting NN after selected node
				printf("Enter element of that node after which you want to Insert this NN : ");
				scanf("%d", &sel);
				temp = first;
				while(temp->ele != sel && temp!=NULL)
				{
					temp = temp->next;
				}

				if(temp==NULL)
				{
					printf("No such Node is Present. NN is Dropped\n");
				}
				else
				{
					// means selected node found
					// 'temp' points to selected node
					if(temp==last)
					{
						nn->next = NULL;
						nn->prev = last;
						last->next = nn;
						last = nn;
					}
					else
					{
						temp2 = temp->next;
						nn->prev = temp;
						nn->next = temp2;
						temp->next = nn;
						temp2->prev = nn;
					}
					printf("NN Inserted After Selected Node\n");
				}
				break;
		}// end of switch-case
	}//end of outer else
}//end of insert_node()

void remove_node()
{
	int ch, sel;
	struct Node *temp, *temp2, *temp3;
	if(first==NULL && last==NULL)
	{
		printf("List Underflow\n");
	}
	else
	{
		if(first==last)
		{
			first = NULL;
			last = NULL;
			printf("There was only one Node. It is Removed\n");
		}
		else
		{
			printf("Which Node you want to Remove\n");
			printf("1 - Remove First Node\n");
			printf("2 - Remove Last Node\n");
			printf("3 - Remove Selected Node\n");
			printf("Provide Your Choice : ");
			scanf("%d", &ch);
			switch(ch)
			{
				case 1: //remove first node
					first = first->next;
					first->prev = NULL;
					printf("First Node is Removed\n");
					break;
				case 2: //remove last node
					last = last->prev;
					last->next = NULL;
					printf("Last Node is Removed\n");
					break;
				case 3: // remove selected node
					printf("Enter element of that Node, which you want to Remove : ");
					scanf("%d", &sel);
					temp = first;
					while(temp->ele!=sel && temp!=NULL)
					{
						temp = temp->next;
					}

					if(temp==NULL)
					{
						printf("No Such Node found\n");
					}
					else
					{
						// means selected node found
						// 'temp' points to selected node

						if(temp==first)
						{
							// means selected node is first node
							first = first->next;
							first->prev = NULL;
						}
						else if(temp==last)
						{
							// means selected node is last node
							last = last->prev;
							last->next = NULL;
						}
						else
						{
							// means selected node is other than first and last node
							temp2 = temp->prev;
							temp3 = temp->next;
							temp2->next = temp3;
							temp3->prev = temp2;
						}
						printf("Selected Node is Removed\n");
					}//end of inner else
					break;
			}//end of switch-case
		}//end of inner else
	} //end of outer else
} //end of remove_node()

void display_list()
{
	struct Node *temp;
	int ch;

	if(first==NULL && last==NULL)
	{
		printf("List is yet not Created. Nothing to Display\n");
	}
	else
	{
		if(first==last)
		{
			printf("%d\n", first->ele);
		}
		else
		{
		   printf("How you want to Display the List\n");
		   printf("1 - Display First to Last\n");
		   printf("2 - Display Last to First\n");
		   printf("Provide your choice : ");
		   scanf("%d", &ch);
		   switch(ch)
		   {
			case 1: //display first to last
				printf("List Contains\n");
				temp = first;
				while(temp!=NULL)
				{
					printf("%d\t", temp->ele);
					temp = temp->next;
				}
				break;
			case 2: //display last to first
				temp = last;
				while(temp!=NULL)
				{
					printf("%d\t", temp->ele);
					temp = temp->prev;
				}
		   } //end of switch-case
		}//end of innter else
	}//end of outer else
} //end of display_list()

void main()
{
	int ch;
	first = NULL;
	last = NULL;

	do
	{
		printf("\nSelect an operation\n");
		printf("1 - INSERT node\n");
		printf("2 - REMOVE node\n");
		printf("3 - DISPLAY list\n");
		printf("4 - EXIT\n");
		printf("Provide your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: insert_node();
				break;
			case 2: remove_node();
				break;
			case 3: display_list();
				break;
			case 4: exit(0);
		}
	}while(1);
}




