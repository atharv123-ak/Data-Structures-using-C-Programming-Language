#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int ele;
	struct Node *next;
};

struct Node *first;

void insert_node()
{
	struct Node *nn, *temp;
	int ch, sel;

	nn = (struct Node *) malloc(sizeof(struct Node));
	printf("Enter element for New Node : ");
	scanf("%d", &nn->ele);

	if(first == NULL)
	{
		nn->next = NULL;
		first = nn;
		printf("List created\n");
	}
	else
	{
		printf("Where you want to INSERT this new node?\n");
		printf("1 - At first position\n");
		printf("2 - At last position\n");
		printf("3 - At selected position\n");
		printf("Provide your choice : ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: // inserting new node at first position
				nn->next = first;
				first = nn;
				printf("New Node inserted at first position\n");
				break;
			case 2: // inserting new node at last position
				temp = first;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}//at the end, 'temp' points to last node
				nn->next = NULL;
				temp->next = nn;
				printf("New node inserted at last position\n");
				break;
			case 3: // inserting new node at selected position
				printf("Enter element of that node, after which you wanto to insert this nn : ");
				scanf("%d", &sel);
				temp = first;
				while(temp->ele != sel && temp!=NULL)
				{
					temp = temp->next;
				}
				if(temp==NULL)
				{
					printf("No such node found. NN is dropped\n");
				}
				else
				{
					// select node found
					nn->next = temp->next;
					temp->next = nn;
					printf("New node inserted after specific node\n");
				}
		} //end of switch-case
	} //end of outer else
}// end of insert_node()

void remove_node()
{
	struct Node *temp, *temp2;
	int ch, sel;
	if(first == NULL)
	{
		printf("List Underflow\n");
	}
	else
	{
		// if there is only one node
		if(first->next == NULL)
		{
			temp = first;
			first = NULL;
			free(temp);
			printf("There was only one node. It is deleted\n");
		}
		else
		{
			printf("Which node you want to Remove\n");
			printf("1 - To remove first node\n");
			printf("2 - To remove last node\n");
			printf("3 - To remove selected node\n");
			printf("Provide your choice : ");
			scanf("%d", &ch);
			switch(ch)
			{
				case 1: // removing first node
					temp = first;
					first = first->next;
					free(temp);
					printf("First node removed from List\n");
					break;
				case 2: // removing last node
					temp = first;
					while(temp->next != NULL)
					{
						temp = temp->next;
					} // at the end 'temp' points to last node

					temp2 = first;
					while(temp2->next != temp)
					{
						temp2 = temp2->next;
					}// at the end 'temp2' points to second last node

					temp2->next = NULL;
					free(temp);
					printf("Last node removed from List\n");
					break;
				case 3: // removing selected node
					printf("Enter element of that node, which you want to remove : ");
					scanf("%d", &sel);
					temp = first;
					while(temp->ele != sel && temp!=NULL)
					{
						temp = temp->next;
					}
					if(temp==NULL)
					{
						printf("No such node found\n");
					}
					else
					{
						// node found. 'temp' points to selected node
						if(temp==first)
						{
							// the selected node is first node
							first = first->next;
							free(temp);
						}
						else
						{
							temp2 = first;
							while(temp2->next != temp)
							{
								temp2 = temp2->next;
							}// at the end 'temp2' points to selected node's previous node

							temp2->next = temp->next;
							free(temp);
						}
						printf("Selected node is removed from List\n");
					}
			} //end of switch-case
		}
	} //end of outer else
} //end of remove_node()

void display_list()
{
	struct Node *temp;
	if(first == NULL)
	{
		printf("List is yet not created. Nothing to display\n");
	}
	else
	{
		printf("List contains\n");
		temp = first;
		while(temp!=NULL)
		{
			printf("%d\t", temp->ele);
			temp = temp->next;
		}
	}
} //end of display_list()

void main()
{
	int ch;
	first = NULL;

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








