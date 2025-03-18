#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int ele;
	struct Node *next;
};

struct Node *FRONT, *REAR;

void enqueue_op()
{
	struct Node *nn;

	nn = (struct Node*) malloc(sizeof(struct Node));
	printf("Enter element to ENQUEUE : ");
	scanf("%d", &nn->ele);
	if(FRONT==NULL && REAR==NULL)
	{
		nn->next = NULL;
		FRONT = nn;
		REAR = nn;
	}
	else
	{
		// inserting new node at first position
		nn->next = REAR;
		REAR = nn;
	}

} //end of enqueue_op()

void dequeue_op()
{
	struct Node *temp;
	int val;
	if(FRONT==NULL && REAR==NULL)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		val = FRONT->ele;
		if(FRONT == REAR)
		{
			FRONT = NULL;
			REAR = NULL;
		}
		else
		{
			temp = REAR;
			while(temp->next != FRONT)
			{
				temp = temp->next;
			} // at the end 'temp' points to second last node
			temp->next = NULL;
			FRONT = temp;
		}
		printf("FRONT element %d is Removed\n", val);
	}
}//end of dequeue_op()

void display_op()
{
	struct Node *temp;
	if(FRONT==NULL && REAR==NULL)
	{
		printf("Queue is Empty. Nothing to Display\n");
	}
	else
	{
		printf("Queue Contains\n");
		temp = REAR;
		while(temp!=NULL)
		{
			printf("%d\t", temp->ele);
			temp = temp->next;
		}
	}
}// end of display_op()

int main()
{
	int uchoice;
	FRONT = NULL;
	REAR = NULL;

	do
	{
		printf("\nSelect an operation\n");
		printf("1 - ENQUEUE operation\n");
		printf("2 - DEQUEUE operation\n");
		printf("3 - DISPLAY operation\n");
		printf("4 - EXIT\n");
		printf("Provide your choice : ");
		scanf("%d", &uchoice);

		switch(uchoice)
		{
			case 1: enqueue_op();
				break;
			case 2: dequeue_op();
				break;
			case 3: display_op();
				break;
			case 4: exit(0);
		} // end of switch-case
	}while(1);
	return 0;
}