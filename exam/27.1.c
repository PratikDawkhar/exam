Write a program that adds two single variable polynomials. Each polynomial should be represented as a list with linked list implementation.

Solution:
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct node
{
    int coeff;
    int pow;
    struct node *next;
};
struct node *poly1=NULL,*poly2=NULL,*poly=NULL;
void create(struct node *node)
{
    char ch;
    do
    {
        printf("\nEnter coeff:");
        scanf("%d",&node->coeff);
        printf("\nEnter power:");
        scanf("%d",&node->pow);
        node->next=(struct node*)malloc(sizeof(struct node));
        node=node->next;
        node->next=NULL;
        printf("\n To Continue(y/n):");
        ch=getch();
    }
while(ch=='y' || ch=='Y');
}
void show(struct node *node)
{
while(node->next!=NULL)
{
    printf("%dx^%d",node->coeff,node->pow);
    node=node->next;
    if(node->next!=NULL)
    printf("+");
}
}
void polyadd(struct node *poly1,struct node *poly2,struct node *poly)
{
    while(poly1->next &&  poly2->next)
    {
        if(poly1->pow>poly2->pow)
        {
            poly->pow=poly1->pow;
            poly->coeff=poly1->coeff;
            poly1=poly1->next;
        }
        else if(poly1->pow<poly2->pow)
        {
            poly->pow=poly2->pow;
            poly->coeff=poly2->coeff;
            poly2 =poly2->next;
        }
        else
        {
            poly->pow=poly1->pow;
            poly->coeff=poly1->coeff+poly2->coeff;
            poly1=poly1->next;
            poly2=poly2->next;
        }
        poly->next=(struct node *)malloc(sizeof(struct node));
          poly=poly->next;
          poly->next=NULL;
    }
    while(poly1->next || poly2->next)
    {
        if(poly1->next)
        {
            poly->pow=poly1->pow;
            poly->coeff=poly1->coeff;
            poly1=poly1->next;
        }
        if(poly2->next)
        {
            poly->pow=poly2->pow;
            poly->coeff=poly2->coeff;
            poly2=poly2->next;
        }
        poly->next=(struct node *)malloc(sizeof(struct node));
        poly=poly->next;
        poly->next=NULL;
    }
}
main()
{
    char ch;
    poly1=(struct node *)malloc(sizeof(struct node));
    poly2=(struct node *)malloc(sizeof(struct node));
    poly=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter 1st Polynomial in Decending Order:");
    create(poly1);
    printf("\nEnter 2nd Polynomial in Decending Order::");
    create(poly2);
    printf("\n1st Polynomial:");
    show(poly1);
    printf("\n2nd Polynomial:");
    show(poly2);
    polyadd(poly1,poly2,poly);
    printf("\nAdded polynomial:");
    show(poly);
}
