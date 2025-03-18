#include <stdio.h>
#include <stdlib.h>
#define size 5

void enQueue(int);
void deQueue();
void display();


void enQueue(int val)
{
    if(te==size)
    {
         printf("Queue is full");
    }
    else
    {
        REAR=(REAR+1)%size;
        queue[REAR]=n;
        te=te+1;
    }

}//Insert Element in Queue

void deQueue()
{


} //Remove element from Queue

void display()
{



} //Displaying Queue



int main()
{
    int queue[size],REAR=-1,FRONT=0,te=0,ch,n,i,x;

    for(;;)		// An infinite loop
    {
        
        system("cls");		// for clearing the screen
        printf("1. Add\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
             printf("Enter a number ");
                    scanf("%d",&n);
                    enQueue(n);
                }
                break;

            case 2:
                if(te==0)
                {
                    printf("Queue is empty");
                  // pause the loop to see the message
                }
                else
                {
                    printf("Number Deleted = %d",queue[FRONT]);
                    FRONT=(FRONT+1)%size;
                    te=te-1;
                 	// pause the loop to see the number
                }
                break;

            case 3:
                if(te==0)
                {
                    printf("Queue is empty");
                    	// pause the loop to see the message
                }
                else
                {
                    x=FRONT;
                    for(i=1; i<=te; i++)
                    {
                        printf("%d ",queue[x]);
                        x=(x+1)%size;
                    }
                   	// pause the loop to see the numbers
                }
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Wrong Choice");
        }      	// pause the loop to see the message
    }
    return 0;
}


