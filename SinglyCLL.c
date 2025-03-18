#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int ele;
	struct Node *next;
};

struct Node *first, *last;

void insert_nn_at_first(struct Node *nnode)
{
	nnode->next = first;
	last->next = nnode;
	first = nnode;
}

void insert_nn_at_last(struct Node *nnode)
{
	nnode->next = first;
	last->next = nnode;
	last = nnode;
}

void insert_nn_at_selected(struct Node *nnode)
{
	int sel, flag=1;
	struct Node *temp;
	printf("Enter element of that node, After which you want to insert this NN : ");
	scanf("%d", &sel);
	temp = first;
	do
	{
		if(temp->ele == sel)
		{
			flag = 2;
			break;
		}
		temp = temp->next;
	}while(temp!=first);

	if(temp==first && flag==1)
	{
		printf("No such node found. NN is dropped\n");
	}
	else if(temp == first && flag==2)
	{
		// means first node is selected node
		nnode->next = temp->next;
		temp->next = nnode;
		printf("New Node Inserted after selected Node\n");
	}
	else if(temp==last)
	{
		// means selected node is last node
		insert_nn_at_last(nnode);
		printf("New Node Inserted after selected Node\n");
	}
	else
	{
		// temp points to selected node
		nnode->next = temp->next;
		temp->next = nnode;
		printf("New Node Inserted after selected Node\n");
	}
}

void insert_node()
{
	struct Node *nn, *temp;
	int sel, uchoice;
	nn = (struct Node *) malloc(sizeof(struct Node));

	printf("Enter element for New Node : ");
	scanf("%d", &nn->ele);

	if(first == NULL && last == NULL)
	{
		nn->next = nn;
		first = nn;
		last = nn;
		printf("List Created\n");
	}
	else
	{
		if(first == last)
		{
			// means exact one node is in list
			printf("Where you want to insert this New Node\n");
			printf("1 - At First Position\n");
			printf("2 - At Last Position\n");
			printf("Provide your choice : ");
			scanf("%d", &uchoice);
			switch(uchoice)
			{
				case 1: insert_nn_at_first(nn);
					break;
				case 2: insert_nn_at_last(nn);
					break;
			} //end of switch-case
		}
		else
		{
			// means there are more than one nodes in list
			printf("Where you want to insert this New Node\n");
			printf("1 - At First Position\n");
			printf("2 - At Last Position\n");
			printf("3 - At Selected Position\n");
			printf("Provide your choice : ");
			scanf("%d", &uchoice);
			switch(uchoice)
			{
				case 1: insert_nn_at_first(nn);
					break;
				case 2: insert_nn_at_last(nn);
					break;
				case 3: insert_nn_at_selected(nn);
					break;
			}//end of switch-case
		}//end of inner-else-block
	} //end of outer else-block
}// end of insert_node()

void remove_node()
{
	struct Node *temp, *temp2;
	int sel, uchoice, flag=1;

	if(first == NULL && last == NULL)
	{
		printf("List Underflow\n");
	}
	else if(first == last)
	{
		first = NULL;
		last = NULL;
		printf("There was only one node. It is deleted\n");
	}
	else
	{
		printf("Which node you want to Remove\n");
		printf("1 - Remove First Node\n");
		printf("2 - Remove Last Node\n");
		printf("3 - Remove Selected Node\n");
		printf("Provide your choice : ");
		scanf("%d", &uchoice);
		switch(uchoice)
		{
			case 1: // remvoing first node
				first = first->next;
				last->next = first;
				printf("First Node is Removed\n");
				break;
			case 2: // removing last node
				temp = first;
				while(temp->next != last)
				{
					temp = temp->next;
				} //at the end 'temp' points to second last node
				temp->next = first;
				last = temp;
				printf("Last Node is Removed\n");
				break;
			case 3: // removing selected node
				printf("Enter element of that node, which you want to Remove : ");
				scanf("%d", &sel);
				temp = first;
				do
				{
					if(temp->ele == sel)
					{
						flag=2;
						break;
					}
					temp = temp->next;
				}while(temp!=first);

				if(temp==first && flag==1)
				{
					printf("No such Node Found\n");
				}
				else if(temp == first && flag==2)
				{
					// selected node is first node
					first = first->next;
					last->next = first;
					printf("Selected Node is Removed\n");
				}
				else if(temp==last && flag==2)
				{
					temp = first;
					while(temp->next != last)
					{
						temp = temp->next;
					}//at the end'temp' points to second last node
					temp->next = first;
					last = temp;
					printf("Selected Node is Removed\n");
				}
				else
				{
					// selected node is in-between
					temp2 = first;
					while(temp2->next != temp)
					{
						temp2 = temp2->next;
					} // at the end 'temp2' points to selected node's previous node
					temp2->next = temp->next;
					printf("Selected Node is Removed\n");
				}
		} //end of switch-case
	} //end of outer else
} //end of remove_node()

void display_list()
{
	struct Node *temp;
	if(first == NULL && last == NULL)
	{
		printf("List is yet not Created.\n");
	}
	else
	{
		printf("List Contains\n");
		temp = first;
		do
		{
			printf("%d\t", temp->ele);
			temp = temp->next;
		}while(temp!=first);
		printf("\n");
	}
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




