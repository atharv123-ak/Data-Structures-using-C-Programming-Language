#include<stdio.h>
#include<stdlib.h>
struct student 
{
    int sroll, sage;
    float savg;
    char sgen;
    /* data */
};
int main()
{
    struct student *p;
    p = (struct student*)malloc(sizeof(struct student));

    printf("Enter roll number :\n");
    scanf("%d",&p->sroll);

    printf("Enter age :\n");
    scanf("%d",&p->sage);

    printf("Enter average marks :\n");
    scanf("%f",&p->savg);

    printf("Enter gender :\n");
    fflush(stdin);
    scanf("%c",&p->sgen);

    printf("Details of student\n");
    printf("Roll number : %d\n",p->sroll);
    printf("Age is : %d\n",p->sage);
    printf("Average is : %.2f\n",p->savg);
    printf("Gender is : %c\n",p->sgen);

    return 0;

}
