#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;

    /* data */
}*p,*tmp,*tmp1;

void insert_end(int);
void insert_beg(int);
void delete_beg();
void delete_end();
void display(); 


int main()
{
    int val,n;
    char uchoice;
    p=NULL;

    do
    {
        printf("\n*************** MENU *******************");
        printf("\n1. INSERT AT BEGINNING ");
        printf("\n2. INSERT AT END ");
        printf("\n3. DELETE FROM BEGINNING ");
        printf("\n4. DELETE FROM END ");
        printf("\n5. DISPLAY "); 
        printf("\n6. EXIT ");
        printf("\n Enter your choice :");
        scanf("%d",&n);

        switch (n)
        {
        case 1: printf("Enter the value :\n");
            scanf("%d",&val);
            insert_beg(val);
            break;
        case 2:printf("Enter the value :\n");
            scanf("%d",&val);
            insert_end(val);
            break;
        case 3:
            delete_beg();
            break;
        case 4:
            delete_end();
            break;
        case 5:
           display();
           break;
        case 6:
         exit(0);
         break;

        default:printf("\n Wrong choice !!");
            break;
        }
        printf("Do you want to continue....(Y and N)");
        fflush(stdin);
        scanf("%c",&uchoice);
        /* code */
    } while(uchoice=='Y');  
}

void insert_end(int ele)
{
    tmp=p;
    tmp1=(struct node*)malloc(sizeof(struct node));
    tmp1->data=ele;
    tmp1->next=NULL;
     if(p==NULL)
     {
        p=tmp1;
     }
     else{
        while (tmp->next!=NULL)
        {
            tmp=tmp->next;
            tmp->next=tmp1;
            /* code */
        }
        
     }
  
}

void insert_beg(int ele)
{
    tmp=p;
    tmp1=(struct node*)malloc(sizeof(struct node));
    tmp1->data=ele;
    tmp1->next=p;
    p=tmp1;
}

void delete_beg()
{
     tmp=p;
     if(p==NULL)
     {
        printf("\n No elements to be deleted !!");

     }
     else{
       printf("\n Elements deleted - %d",p->data);
       p=p->next; 
     }

}

void delete_end()
{
    tmp=p;
    struct node *pre;
     if(p==NULL)
     {
        printf("\n No element to be deleted!!");
     }

     else if(p->next==NULL)
     {
        printf("\n Element deleted - %d",p->data);
        p=NULL;
     }

     else{
        while (tmp->next!=NULL)
        {
            pre=tmp->next;
            tmp=tmp->next;
            /* code */
        }
        pre->next=NULL;
        printf("\n Element deleted -%d",tmp->data);
     }
  
}

void display()
{
    tmp=p;
    while (tmp!=NULL)
    {
        printf("Displaying values ");
        printf("\n %d \n",tmp->data);
        tmp=tmp->next;
        /* code */
    }
    
}